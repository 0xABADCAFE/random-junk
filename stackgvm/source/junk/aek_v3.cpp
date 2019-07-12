// De-golfed version of the Business Card Raytracer by Andrew Kensler
//
// Changes
//   * Renaming of types, functions and variables
//   * Replaced operator overloads with vanilla functions
//   * Added functions for explicit vector subtract which was realised
//     previously as v1 + (v2 * -1);
//   * Optimised away a pow() call for the sky gradient
//   * Moved the specular calculation to the point where the ray definitely
//     intersects a sphere.
//
// Optimisations
//   * Convert the aek bitmap to an array of sphere coordinates.
//   * Implement a material probe before performing the ray trace calculation, in which the probe is tuned to
//     return the sky material for pixels that will only contain sky, floor for pixels that will only contain floor
//     and mirror for materials that will generally be the mirrored sphere but could be floor or sky as the probe
//     treats the spheres as slightly larger.
//   * Optimised trace functions based on material probe, e.g. single ray for sky, single bounce and no bounce
//     versions of the regular sample function.

#include "aek.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __LP64__
    #define PPMNAME "aek_v3_64.ppm"
#else
    #define PPMNAME "aek_v3_32.ppm"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Profiling
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef PROFILE

namespace Profiling {

    struct Entry {
        enum {
            I_RENDER = 0,
            I_SAMPLE,
            I_SAMPLE_NO_BOUNCE,
            I_SAMPLE_FIRST_BOUNCE,
            I_TRACE,
            I_TRACE_NO_BOUNCE,
            I_TRACE_MATERIAL_ONLY,
            I_MAX
        };
        uint64      u_ns;
        const char* s_name;
        uint32      u_calls;
    };

    Entry ao_entries[Entry::I_MAX] = {
        { 0, "Scene::render()", 0 },
        { 0, "Sample::sample()", 0 },
        { 0, "Sample::sampleNoBounce()", 0 },
        { 0, "Sample::sampleFirstBounce()", 0 },
        { 0, "Ray::trace()", 0 },
        { 0, "Ray::traceNoBounce()", 0 },
        { 0, "Ray::traceMaterialOnly()", 0 },
    };

    void dump() {
        for (int i = 0; i < Entry::I_MAX; ++i) {
            std::printf(
                "%-22s | %9" FU32 " | %9.6f | %.3f\n",
                ao_entries[i].s_name,
                ao_entries[i].u_calls,
                1e-9 * ao_entries[i].u_ns,
                (float64)ao_entries[i].u_ns / (float64)ao_entries[i].u_calls
            );
        }
    }
}
    #define PROF_ENTER(_f) ++Profiling::ao_entries[(_f)].u_calls; Profiling::Nanotime __u_nt = Profiling::mark()
    #define PROF_EXIT(_f)    Profiling::ao_entries[(_f)].u_ns += Profiling::mark() - __u_nt;
    #define PROF_DUMP()      Profiling::dump()
    #define TIME_RENDER_INIT()
    #define TIME_RENDER_DONE()
#else
    #define PROF_ENTER(_f)
    #define PROF_EXIT(_f)
    #define PROF_DUMP()
    #define TIME_RENDER_INIT() Profiling::Nanotime u_render_start = Profiling::mark()
    #define TIME_RENDER_DONE() Profiling::Nanotime u_render_end   = Profiling::mark(); \
    std::printf( \
        "Total render() time %0.6f seconds\n", \
        (float64)(u_render_end - u_render_start) * 1e-9 \
    )
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Ray Density Map
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EMIT_RAY_DENSITY_MAP
    #define INIT_RAY_DENSITY_MAP(n) \
        std::FILE* r_ray_density_out = std::fopen((n), "wb"); \
        if (!r_ray_density_out) { \
            return; \
        } \
        std::fprintf(r_ray_density_out, "P5 %d %d 255 ", I_IMAGE_SIZE, I_IMAGE_SIZE)

    #define WRITE_RAY_DENSITY(d) std::fprintf(r_ray_density_out, "%c", ((d)>255) ? 255 : (d) );
    #define DONE_RAY_DENSITY_MAP() std::fclose(r_ray_density_out)
#else
    #define INIT_RAY_DENSITY_MAP(n)
    #define WRITE_RAY_DENSITY(d)
    #define DONE_RAY_DENSITY_MAP()
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {
    Vec3* av_spheres    = 0;
    int   i_num_spheres = 0;

    void init() {
        // Calclulate how many spheres we have, allocate space and unpack the bitmap
        av_spheres    = 0;
        i_num_spheres = 0;
        int i_column  = 0;
        for (int i = 0; i < I_BITMAP_ROWS; ++i) {
            i_num_spheres += __builtin_popcount(AI_BITMAP[i]);
            i_column |= AI_BITMAP[i];
        }

        i_column = 8 * sizeof(int32) - __builtin_clz(i_column);

        av_spheres = new Vec3[i_num_spheres];
        for (int i = 0; i_column--;) {
            for (int i_row = I_BITMAP_ROWS; i_row--;) {
                if (AI_BITMAP[i_row] & 1 << i_column) {
                    av_spheres[i].x = i_column;
                    av_spheres[i].y = 0;
                    av_spheres[i].z = i_row + 4;
                    ++i;
                }
            }
        }
    }

    void done() {
        if (av_spheres) {
            delete[] av_spheres;
        }
        av_spheres = 0;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Ray
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Ray {

    /**
     * Vanilla trace behaviour, tests for intersection with all Scene objects
     */
    Material::Kind trace(const Vec3& v_origin, const Vec3& v_direction, float32& f_distance, Vec3& v_normal) {

        PROF_ENTER(Profiling::Entry::I_TRACE);

        f_distance = 1e9f;

        // Assume trace hits nothing
        Material::Kind i_material = Material::I_SKY;
        float32        f_p        = -v_origin.z / v_direction.z;

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            f_distance = f_p;
            v_normal   = Scene::V_NORMAL_UP;
            i_material = Material::I_FLOOR;
        }

        // Check if trace maybe hits a sphere
        for (int i = 0; i < Scene::i_num_spheres; i++) {
            Vec3 v_p = Vec3::sub(
                v_origin,
                Scene::av_spheres[i] // Sphere coordinate
            );

            float32
                f_b          = Vec3::dot(v_p, v_direction),
                f_eye_offset = Vec3::dot(v_p, v_p) - 1.0f,
                f_q          = f_b * f_b - f_eye_offset
            ;

            if (f_q > 0.0f) {
                float32 f_sphere_distance = -f_b - std::sqrt(f_q);
                if (f_sphere_distance < f_distance && f_sphere_distance > 0.01f) {
                    f_distance = f_sphere_distance,
                    v_normal   = Vec3::normalize(
                        Vec3::add(v_p, Vec3::scale(v_direction, f_distance))
                    ),
                    i_material = Material::I_MIRROR;
                }
            }
        }

        PROF_EXIT(Profiling::Entry::I_TRACE);

        return i_material;
    }

    /**
     * Variant trace behaviour, tests for floor and sky intersection only
     */
    Material::Kind traceNoBounce(const Vec3& v_origin, const Vec3& v_direction, float32& f_distance, Vec3& v_normal) {

        PROF_ENTER(Profiling::Entry::I_TRACE_NO_BOUNCE);

        f_distance  = 1e9f;
        float32 f_p = -v_origin.z / v_direction.z;

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            f_distance = f_p,
            v_normal   = Scene::V_NORMAL_UP;

            PROF_EXIT(Profiling::Entry::I_TRACE_NO_BOUNCE);

            return Material::I_FLOOR;
        }

        PROF_EXIT(Profiling::Entry::I_TRACE_NO_BOUNCE);

        return Material::I_SKY;
    }

    /**
     * Variant trace behaviour, tests only which material was hit. Accepts tuning parameters that adjust the apparent
     * radius of objects and the pitch of the horizon. This is to allow us to provide an estimation of what material
     * was hit so that we can use the correct version later for stochastic sampling.
     */
    Material::Kind traceMaterialOnly(
        const Vec3& v_origin,
        const Vec3& v_direction,
        const float32 f_sphere_size_mod = 1.0f,
        const float32 f_floor_mod = 0.0f
    ) {

        PROF_ENTER(Profiling::Entry::I_TRACE_MATERIAL_ONLY);

        // Assume trace hits sky
        Material::Kind i_material = Material::I_SKY;
        float32        f_p        = -v_origin.z / (v_direction.z + f_floor_mod);

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            i_material = Material::I_FLOOR;
        }

        // Check if trace maybe hits a sphere
        for (int i = 0; i < Scene::i_num_spheres; i++) {
            Vec3 v_p = Vec3::sub(
                v_origin,
                Scene::av_spheres[i] // Sphere coordinate
            );

            float32
                f_b          = Vec3::dot(v_p, v_direction),
                f_eye_offset = Vec3::dot(v_p, v_p) - f_sphere_size_mod,
                f_q          = f_b * f_b - f_eye_offset
            ;

            if (f_q > 0.0f) {
                float32 f_sphere_distance = -f_b - std::sqrt(f_q);
                if (f_sphere_distance < 1e9f && f_sphere_distance > 0.01f) {
                    i_material = Material::I_MIRROR;
                    break;
                }
            }
        }

        PROF_EXIT(Profiling::Entry::I_TRACE_MATERIAL_ONLY);

        return i_material;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    enum {
        I_ADAPTIVE_BUFFER_SIZE = 8
    };

    const float32 F_RGB_SIMILARITY_LIMIT = 1e-4f;

    typedef Vec3 (*Function)(const Vec3& v_origin, const Vec3& v_direction);

    inline float32 calculateLambertian(const Vec3& v_intersection, const Vec3& v_normal, Vec3& v_light) {
        // Calculate the lighting vector
        v_light = Vec3::normalize(
            Vec3::sub(
                Vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f
                ),
                v_intersection
            )
        );

        // Calculate the lambertian illumuination factor
        float32 f_lambertian = Vec3::dot(v_light, v_normal);
        if (f_lambertian < 0.0f || Ray::traceMaterialOnly(v_intersection, v_light)) {
            f_lambertian = 0.0f; // in shadow
        }
        return f_lambertian;
    }


    Vec3 sample(const Vec3& v_origin, const Vec3& v_direction) {
        PROF_ENTER(Profiling::Entry::I_SAMPLE);

        Vec3    v_normal;
        float32 f_distance;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (i_material == Material::I_SKY) {

            PROF_EXIT(Profiling::Entry::SAMPLE);

            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = Vec3::add(v_origin, Vec3::scale(v_direction, f_distance))
        ;

        float32 f_lambertian = calculateLambertian(v_intersection, v_normal, v_light);

        // Hit the floor plane
        if (i_material == Material::I_FLOOR) {

            PROF_EXIT(Profiling::Entry::SAMPLE);

            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        Vec3 v_half_vector = calculateHalfVector(v_direction, v_normal);

        // Compute the specular highlight power
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        PROF_EXIT(Profiling::Entry::I_SAMPLE);

        // Hit a sphere
        return Vec3::add(
            Vec3(f_specular),
            Vec3::scale(
                sample(v_intersection, v_half_vector),
                Material::F_MIRROR_ALBEDO
            )
        );
    }


    Vec3 sampleNoBounce(const Vec3& v_origin, const Vec3& v_direction) {

        PROF_ENTER(Profiling::Entry::I_SAMPLE_NO_BOUNCE);

        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::traceNoBounce(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (i_material == Material::I_SKY) {

            PROF_EXIT(Profiling::Entry::I_SAMPLE_NO_BOUNCE);

            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = Vec3::add(v_origin, Vec3::scale(v_direction, f_distance))
        ;

        float32 f_lambertian = calculateLambertian(v_intersection, v_normal, v_light);

        PROF_EXIT(Profiling::Entry::I_SAMPLE_NO_BOUNCE);

        return Material::shadeFloor(v_intersection, f_lambertian);
    }


    Vec3 sampleFirstBounce(const Vec3& v_origin, const Vec3& v_direction) {

        PROF_ENTER(Profiling::Entry::I_SAMPLE_FIRST_BOUNCE);

        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (i_material == Material::I_SKY) {

            PROF_EXIT(Profiling::Entry::SAMPLE_FIRST_BOUNCE);

            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = Vec3::add(v_origin, Vec3::scale(v_direction, f_distance))
        ;

        float32 f_lambertian = calculateLambertian(v_intersection, v_normal, v_light);

        // Hit the floor plane
        if (i_material == Material::I_FLOOR) {

            PROF_EXIT(Profiling::Entry::SAMPLE_FIRST_BOUNCE);

            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        Vec3 v_half_vector = calculateHalfVector(v_direction, v_normal);

        Function samplefn = (v_half_vector.y > 0.15f) ? sampleNoBounce : sample;

        // Compute the specular highlight power
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        PROF_EXIT(Profiling::Entry::I_SAMPLE_FIRST_BOUNCE);

        // Hit a sphere
        return Vec3::add(
            Vec3(f_specular),
            Vec3::scale(
                samplefn(v_intersection, v_half_vector),
                Material::F_MIRROR_ALBEDO
            )
        );
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    void render(std::FILE* out) {

        INIT_RAY_DENSITY_MAP("aek3b_rays.ppm");

        std::fprintf(out, "P6 %d %d 255 ", I_IMAGE_SIZE, I_IMAGE_SIZE);

        // Only the profile call or the render timing call will be compiled in, never both
        PROF_ENTER(Profiling::Entry::I_RENDER);
        TIME_RENDER_INIT();

        // camera direction vectors
        Vec3
            v_camera_forward = Vec3::normalize( // Unit forwards
                Scene::V_CAMERA_DIR
            ),

            v_camera_up = Vec3::scale( // Unit up - Z is up in this system
                Vec3::normalize(
                    Vec3::cross(
                        Scene::V_NORMAL_UP,
                        v_camera_forward
                    )
                ),
                F_IMAGE_SCALE
            ),

            v_camera_right = Vec3::scale( // Unit right
                Vec3::normalize(
                    Vec3::cross(v_camera_forward, v_camera_up)
                ),
                F_IMAGE_SCALE
            ),

            v_eye_offset = Vec3::add( // Offset frm eye to coner of focal plane
                Vec3::scale(
                    Vec3::add(v_camera_up, v_camera_right),
                    -(I_IMAGE_SIZE >> 1)
                ),
                v_camera_forward
            ),

            v_probe_delta = Vec3::add(
                v_camera_up,
                v_camera_right
            ),

            v_probe_origin = Vec3::add(
                Scene::V_FOCAL_POINT,
                v_probe_delta
            )
        ;

        for (int y = I_IMAGE_SIZE; y--;) {
            int i_min_adaptive_ray_count = Sample::I_ADAPTIVE_BUFFER_SIZE;
            for (int x = I_IMAGE_SIZE; x--;) {
                // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
                Vec3 v_pixel(0.0f);

                // Perform a material probe first. If we don't hit a sphere we can use an optimised sample function
                Vec3 v_probe_direction = Vec3::normalize(
                    Vec3::sub(
                        Vec3::scale(
                            Vec3::add(
                                Vec3::scale(v_camera_up, 0.5f + x),
                                Vec3::add(
                                    Vec3::scale(v_camera_right, 0.5f + y),
                                    v_eye_offset
                                )
                            ),
                            16.0f
                        ),
                        v_probe_delta
                    )
                );

                Material::Kind i_material = Ray::traceMaterialOnly(v_probe_origin, v_probe_direction, 1.10f, -0.01f);

                if (i_material != Material::I_SKY) {
                    Vec3 av_samples[Sample::I_ADAPTIVE_BUFFER_SIZE];
                    Sample::Function samplefn = (i_material == Material::I_MIRROR) ?
                        Sample::sampleFirstBounce :
                        Sample::sampleNoBounce
                    ;

                    int i_ray_count = 0;

                    // Cast up to MAX_RAYS rays per pixel for sampling
                    for (; i_ray_count < I_MAX_RAYS; ++i_ray_count) {

                        // Random delta to be added for depth of field effects
                        Vec3 v_delta = Vec3::add(
                            Vec3::scale(v_camera_up,    (frand() - 0.5f) * 99.0f),
                            Vec3::scale(v_camera_right, (frand() - 0.5f) * 99.0f)
                        );

                        // Buffer the most recent sample
                        Vec3& v_sample = av_samples[i_ray_count & (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)];

                        v_sample = samplefn(
                            Vec3::add(
                                Scene::V_FOCAL_POINT,
                                v_delta
                            ),
                            Vec3::normalize(
                                Vec3::sub(
                                    Vec3::scale(
                                        Vec3::add(
                                            Vec3::scale(v_camera_up, frand() + x),
                                            Vec3::add(
                                                Vec3::scale(v_camera_right, frand() + y),
                                                v_eye_offset
                                            )
                                        ),
                                        16.0f
                                    ),
                                    v_delta
                                )
                            )
                        );

                        // Accumulate the sample result into the current pixel
                        v_pixel = Vec3::add(
                            v_sample,
                            v_pixel
                        );


                        // Check if the short duration average is close enough to the all time average that we believe
                        // the pixel value to be stable.
                        if (
                            i_ray_count >= i_min_adaptive_ray_count &&
                            (i_ray_count & (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)) == (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)
                        ) {
                            Vec3 v_average = Vec3::scale(
                                v_pixel,
                                1.0f/(i_ray_count + 1)
                            );

                            Vec3 v_last = av_samples[0];
                            for (int s = 1; s < Sample::I_ADAPTIVE_BUFFER_SIZE; ++s) {
                                v_last = Vec3::add(v_last, av_samples[s]);
                            }

                            v_last = Vec3::sub(
                                Vec3::scale(v_last, 1.0f/Sample::I_ADAPTIVE_BUFFER_SIZE),
                                v_average
                            );

                            float32 f_dot_sum = Vec3::dot(v_last, v_last);

                            if (f_dot_sum < Sample::F_RGB_SIMILARITY_LIMIT) {
                                v_pixel = Vec3::scale(
                                    v_pixel,
                                    (float32)I_MAX_RAYS / (float32)(i_ray_count + 1)
                                );
                                break;
                            }
                        }
                    }

                    i_min_adaptive_ray_count = i_ray_count >> 1;
                    if (i_min_adaptive_ray_count < Sample::I_ADAPTIVE_BUFFER_SIZE) {
                        i_min_adaptive_ray_count = Sample::I_ADAPTIVE_BUFFER_SIZE;
                    }
                    v_pixel = Vec3::scale(v_pixel, F_SAMPLE_SCALE);
                    WRITE_RAY_DENSITY(ray_count);

                } else {
                    v_pixel = Vec3::scale(Material::shadeSky(v_probe_direction), I_MAX_RAYS * F_SAMPLE_SCALE);
                    WRITE_RAY_DENSITY(0);
                }

                v_pixel = Vec3::add(v_pixel, Scene::V_AMBIENT_RGB);

                // Convert to integers and push out to ppm output stream
                std::fprintf(out, "%c%c%c", (int)v_pixel.x, (int)v_pixel.y, (int)v_pixel.z);
            }
        }

        // Only the profile call or the render timing call will be compiled in, never both
        TIME_RENDER_DONE();
        PROF_EXIT(Profiling::Entry::RENDER);
        DONE_RAY_DENSITY_MAP();
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::FILE* out = fopen(PPMNAME, "wb");
    if (out) {
        std::printf("Rendering to " PPMNAME "...\n");
        Scene::init();
        Scene::render(out);
        Scene::done();
        std::fclose(out);
        PROF_DUMP();
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}
