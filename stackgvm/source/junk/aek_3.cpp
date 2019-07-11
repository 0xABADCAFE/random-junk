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
    #define PPMNAME "aek3_64.ppm"
#else
    #define PPMNAME "aek3_32.ppm"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Profiling options
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef PROFILE
    struct FunctionProfle {
        enum {
            RENDER = 0,
            SAMPLE,
            SAMPLE_NO_BOUNCE,
            SAMPLE_FIRST_BOUNCE,
            TRACE,
            TRACE_NO_BOUNCE,
            TRACE_MATERIAL_ONLY,
            MAX
        };
        uint64 ns;
        const char* name;
        uint32 calls;
    };

    static FunctionProfle function_profile[FunctionProfle::MAX] = {
        { 0, "Scene::render()", 0 },
        { 0, "Sample::sample()", 0 },
        { 0, "Sample::sample_no_bounce()", 0 },
        { 0, "Sample::sample_first_bounce()", 0 },
        { 0, "Ray::trace()", 0 },
        { 0, "Ray::trace_no_bounce()", 0 },
        { 0, "Ray::trace_material_only()", 0 },
    };

    static void dump_profile() {
        for (int i = 0; i < FunctionProfle::MAX; i++) {
            std::printf(
                "%-22s | %9" FU32 " | %9.6f | %.3f\n",
                function_profile[i].name,
                function_profile[i].calls,
                1e-9 * function_profile[i].ns,
                (float64)function_profile[i].ns / (float64)function_profile[i].calls
            );
        }
    }

    #define PROF_ENTER(_f) ++function_profile[(_f)].calls; NanoTime::Value __nt = NanoTime::mark()
    #define PROF_EXIT(_f)    function_profile[(_f)].ns += NanoTime::mark() - __nt;
    #define PROF_DUMP()      dump_profile()
    #define TIME_RENDER_INIT()
    #define TIME_RENDER_DONE()
#else
    #define PROF_ENTER(_f)
    #define PROF_EXIT(_f)
    #define PROF_DUMP()
    #define TIME_RENDER_INIT() NanoTime::Value render_start = NanoTime::mark()
    #define TIME_RENDER_DONE() NanoTime::Value render_end = NanoTime::mark(); \
    std::printf( \
        "Total render() time %0.6f seconds\n", \
        (float64)(render_end - render_start) * 1e-9 \
    )
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EMIT_RAY_DENSITY_MAP
    #define INIT_RAY_DENSITY_MAP(n) \
        std::FILE* ray_density_out = fopen((n), "wb"); \
        if (!ray_density_out) { \
            return; \
        } \
        std::fprintf(ray_density_out, "P5 %d %d 255 ", IMAGE_SIZE, IMAGE_SIZE)

    #define WRITE_RAY_DENSITY(d) std::fprintf(ray_density_out, "%c", ((d)>255) ? 255 : (d) );
    #define DONE_RAY_DENSITY_MAP() std::fclose(ray_density_out)
#else
    #define INIT_RAY_DENSITY_MAP(n)
    #define WRITE_RAY_DENSITY(d)
    #define DONE_RAY_DENSITY_MAP()
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Material {

    inline Vec3 shade_sky_rgb(cvr3 direction) {
        float32 gradient = 1.0f - direction.z;
        gradient *= gradient;
        gradient *= gradient;
        return Vec3::scale(
            sky_rgb, // Blueish sky colour
            gradient
        );
    }

    inline Vec3 shade_floor_rgb(Vec3& intersection, float32 lambertian) {
        intersection = Vec3::scale(intersection, 0.2f);
        return Vec3::scale(
            (
                // Compute check colour based on the position
                (int) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
                    tile_red_rgb :
                    tile_white_rgb
            ),
            (lambertian * 0.2f + 0.1f)
        );
    }

    inline float32 specularity(cvr3 light, cvr3 half_vector, float32 lambertian) {
        return (lambertian > 0.0) ?
            pow(Vec3::dot(light, half_vector), 99.0f) :
            0.0f;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {
    static Vec3  spheres[18*8];
    static int   num_spheres = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Ray
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Ray {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Material::Kind trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal)
    //
    //  General purpose trace routine that calculates the material, distance to point of intersection and the normal at
    //  the point of intersection. Since sphere volumes overlap, this version exhaustively tests every sphere to
    //  determine exact point of intersection.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Material::Kind trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal) {
        PROF_ENTER(FunctionProfle::TRACE);

        distance = 1e9f;

        // Assume trace hits nothing
        Material::Kind material = Material::SKY;
        float32        p        = -origin.z / direction.z;

        // Check if trace maybe hits floor
        if (0.01f < p) {
            distance = p,
            normal   = Scene::normal_up,
            material = Material::FLOOR;
        }

        // Check if trace maybe hits a sphere
        for (int i = 0; i < Scene::num_spheres; i++) {
            Vec3 p = Vec3::sub(
                origin,
                Scene::spheres[i] // Sphere coordinate
            );

            float32
                b = Vec3::dot(p, direction),
                eye_offset = Vec3::dot(p, p) - 1.0f,
                q = b * b - eye_offset
            ;
            if (q > 0.0f) {
                float32 sphere_distance = -b - std::sqrt(q);
                if (sphere_distance < distance && sphere_distance > 0.01f) {
                    distance = sphere_distance,
                    normal   = Vec3::normalize(
                        Vec3::add(p, Vec3::scale(direction, distance))
                    ),
                    material = Material::MIRROR;
                }
            }
        }
        PROF_EXIT(FunctionProfle::TRACE);
        return material;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Material::Kind trace_no_bounce(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal)
    //
    //  General purpose trace routine that calculates the material, distance to point of intersection and the normal at
    //  the point of intersection. Completely ignores sphere intersection tests. We use this routine when we know that a
    //  ray cannot intersect any of the spheres in the scene.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Material::Kind trace_no_bounce(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal) {
        PROF_ENTER(FunctionProfle::TRACE_NO_BOUNCE);
        distance  = 1e9f;
        float32 p = -origin.z / direction.z;

        // Check if trace maybe hits floor
        if (0.01f < p) {
            distance = p,
            normal   = Scene::normal_up;
            PROF_EXIT(FunctionProfle::TRACE_NO_BOUNCE);
            return Material::FLOOR;
        }
        PROF_EXIT(FunctionProfle::TRACE_NO_BOUNCE);
        return Material::SKY;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Material::Kind trace_material_only(cvr3 origin, cvr3 direction)
    //
    //  Shortcut version of the trace routine that only tests what material is intersected first by the ray. As the
    //  distance and normal are not required here. if the ray hits a sphere we early exit out of the test.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Material::Kind trace_material_only(
        cvr3 origin,
        cvr3 direction,
        const float32 sphere_size_mod = 1.0f,
        const float32 floor_mod = 0.0f
    ) {
        PROF_ENTER(FunctionProfle::TRACE_MATERIAL_ONLY);

        // Assume trace hits sky
        Material::Kind material = Material::SKY;
        float32 p = -origin.z / (direction.z + floor_mod);

        // Check if trace maybe hits floor
        if (0.01f < p) {
            material = Material::FLOOR;
        }

        // Check if trace maybe hits a sphere
        for (int i = 0; i < Scene::num_spheres; i++) {
            Vec3 p = Vec3::sub(
                origin,
                Scene::spheres[i] // Sphere coordinate
            );

            float32
                b = Vec3::dot(p, direction),
                eye_offset = Vec3::dot(p, p) - sphere_size_mod,
                q = b * b - eye_offset
            ;
            if (q > 0.0f) {
                float32 sphere_distance = -b - std::sqrt(q);
                if (sphere_distance < 1e9f && sphere_distance > 0.01f) {
                    material = Material::MIRROR;
                    break;
                }
            }
        }
        PROF_EXIT(FunctionProfle::TRACE_MATERIAL_ONLY);
        return material;
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    enum {
        ADAPTIVE_BUFFER_SIZE = 8
    };

    static const float32 RGB_SIMILARITY_LIMIT = 1e-4f;

    typedef Vec3 (*Function)(cvr3 origin, cvr3 direction);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Helpers
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline float32 calculate_lighting(cvr3 intersection, cvr3 normal, Vec3& light) {
        // Calculate the lighting vector
        light = Vec3::normalize(
            Vec3::sub(
                Vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f
                ),
                intersection
            )
        );

        // Calculate the lambertian illumuination factor
        float32 lambertian = Vec3::dot(light, normal);
        if (lambertian < 0.0f || Ray::trace_material_only(intersection, light)) {
            lambertian = 0.0f; // in shadow
        }
        return lambertian;
    }

    inline Vec3 calculate_half_vector(cvr3 direction, cvr3 normal) {
        return Vec3::add(
            direction,
            Vec3::scale(
                normal,
                Vec3::dot(normal, direction) * -2.0f
            )
        );
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Vec3 sample(cvr3 origin, cvr3 direction)
    //
    //  Generic sampling method that uses the most expensive trace() and recursively samples when hitting a reflective
    //  surface.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Vec3 sample(cvr3 origin, cvr3 direction) {
        PROF_ENTER(FunctionProfle::SAMPLE);

        Vec3    normal;
        float32 distance;

        // Find where the ray intersects the world
        Material::Kind material = Ray::trace(origin, direction, distance, normal);

        // Hit nothing? Sky shade
        if (material == Material::SKY) {
            PROF_EXIT(FunctionProfle::SAMPLE);
            return Material::shade_sky_rgb(direction);
        }

        Vec3
            light,
            intersection = Vec3::add(origin, Vec3::scale(direction, distance))
        ;

        float32 lambertian = calculate_lighting(intersection, normal, light);

        // Hit the floor plane
        if (material == Material::FLOOR) {
            PROF_EXIT(FunctionProfle::SAMPLE);
            return Material::shade_floor_rgb(intersection, lambertian);
        }

        Vec3 half_vector = calculate_half_vector(direction, normal);

        // Compute the specular highlight power
        float32 specular = Material::specularity(light, half_vector, lambertian);

        PROF_EXIT(FunctionProfle::SAMPLE);

        // Hit a sphere
        return Vec3::add(
            Vec3(specular, specular, specular),
            Vec3::scale(
                sample(intersection, half_vector),
                Material::MIRROR_ALBEDO
            )
        );
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Vec3 no_bounce(cvr3 origin, cvr3 direction)
    //
    //  Tuned sample method for rays that we know will not hit a reflective surface.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Vec3 no_bounce(cvr3 origin, cvr3 direction) {

        PROF_ENTER(FunctionProfle::SAMPLE_NO_BOUNCE);

        float32 distance;
        Vec3    normal;

        // Find where the ray intersects the world
        Material::Kind material = Ray::trace_no_bounce(origin, direction, distance, normal);

        // Hit nothing? Sky shade
        if (material == Material::SKY) {
            PROF_EXIT(FunctionProfle::SAMPLE_NO_BOUNCE);
            return Material::shade_sky_rgb(direction);
        }

        Vec3
            light,
            intersection = Vec3::add(origin, Vec3::scale(direction, distance))
        ;

        float32 lambertian = calculate_lighting(intersection, normal, light);

        PROF_EXIT(FunctionProfle::SAMPLE_NO_BOUNCE);
        return Material::shade_floor_rgb(intersection, lambertian);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Vec3 first_bounce(cvr3 origin, cvr3 direction)
    //
    //  Tuned sample method for primary rays that we expect to bounce only once. This determination is made by checking
    //  the calculated half_vector's y component to see if it's heading away from the plane containing the spheres.
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Vec3 first_bounce(cvr3 origin, cvr3 direction) {

        PROF_ENTER(FunctionProfle::SAMPLE_FIRST_BOUNCE);

        float32 distance;
        Vec3    normal;

        // Find where the ray intersects the world
        Material::Kind material = Ray::trace(origin, direction, distance, normal);

        // Hit nothing? Sky shade
        if (material == Material::SKY) {
            PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);
            return Material::shade_sky_rgb(direction);
        }

        Vec3
            light,
            intersection = Vec3::add(origin, Vec3::scale(direction, distance))
        ;

        float32 lambertian = calculate_lighting(intersection, normal, light);

        // Hit the floor plane
        if (material == Material::FLOOR) {
            PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);
            return Material::shade_floor_rgb(intersection, lambertian);
        }

        Vec3 half_vector = calculate_half_vector(direction, normal);

        Function samplefn = (half_vector.y > 0.15f) ? no_bounce : sample;

        // Compute the specular highlight power
        float32 specular = Material::specularity(light, half_vector, lambertian);

        PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);

        // Hit a sphere
        return Vec3::add(
            Vec3(specular),
            Vec3::scale(
                samplefn(intersection, half_vector),
                Material::MIRROR_ALBEDO
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

    bool init() {
        for (int k = 19; k--;) {
            for (int j = 9; j--;) {
                if (bitmap[j] & 1 << k) {
                    spheres[num_spheres].x = k;
                    spheres[num_spheres].y = 0;
                    spheres[num_spheres].z = j + 4;
                    num_spheres++;
                }
            }
        }
        return true;
    }

    void done() {

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  void render(std::FILE* out)
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void render(std::FILE* out) {

        INIT_RAY_DENSITY_MAP("aek3b_rays.ppm");

        std::fprintf(out, "P6 %d %d 255 ", IMAGE_SIZE, IMAGE_SIZE);

        // Only the profile call or the render timing call will be compiled in, never both
        PROF_ENTER(FunctionProfle::RENDER);
        TIME_RENDER_INIT();

        // camera direction vectors
        Vec3
            camera_forward = Vec3::normalize( // Unit forwards
                Scene::camera_dir
            ),

            camera_up = Vec3::scale( // Unit up - Z is up in this system
                Vec3::normalize(
                    Vec3::cross(
                        Scene::normal_up,
                        camera_forward
                    )
                ),
                IMAGE_SCALE
            ),

            camera_right = Vec3::scale( // Unit right
                Vec3::normalize(
                    Vec3::cross(camera_forward, camera_up)
                ),
                IMAGE_SCALE
            ),

            eye_offset = Vec3::add( // Offset frm eye to coner of focal plane
                Vec3::scale(
                    Vec3::add(camera_up, camera_right),
                    -(IMAGE_SIZE >> 1)
                ),
                camera_forward
            ),

            probe_delta = Vec3::add(
                camera_up,
                camera_right
            ),

            probe_origin = Vec3::add(
                Scene::focal_point,
                probe_delta
            )
        ;

        for (int y = IMAGE_SIZE; y--;) {
            int min_adaptive_ray_count = Sample::ADAPTIVE_BUFFER_SIZE;
            for (int x = IMAGE_SIZE; x--;) {
                // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
                Vec3 pixel(0.0f);

                // Perform a material probe first. If we don't hit a sphere we can use an optimised sample function
                Vec3 probe_direction = Vec3::normalize(
                    Vec3::sub(
                        Vec3::scale(
                            Vec3::add(
                                Vec3::scale(camera_up, 0.5 + x),
                                Vec3::add(
                                    Vec3::scale(camera_right, 0.5 + y),
                                    eye_offset
                                )
                            ),
                            16.0f
                        ),
                        probe_delta
                    )
                );

                Material::Kind material = Ray::trace_material_only(probe_origin, probe_direction, 1.10f, -0.01f);

                if (material != Material::SKY) {
                    Vec3 samples[Sample::ADAPTIVE_BUFFER_SIZE];
                    Sample::Function samplefn = (material == Material::MIRROR) ?
                        Sample::first_bounce :
                        Sample::no_bounce
                    ;

                    int ray_count = 0;

                    // Cast up to MAX_RAYS rays per pixel for sampling
                    for (; ray_count < MAX_RAYS; ++ray_count) {

                        // Random delta to be added for depth of field effects
                        Vec3 delta = Vec3::add(
                            Vec3::scale(camera_up,    (frand() - 0.5f) * 99.0f),
                            Vec3::scale(camera_right, (frand() - 0.5f) * 99.0f)
                        );

                        // Buffer the most recent sample
                        Vec3& sample = samples[ray_count & (Sample::ADAPTIVE_BUFFER_SIZE-1)];

                        sample = samplefn(
                            Vec3::add(
                                Scene::focal_point,
                                delta
                            ),
                            Vec3::normalize(
                                Vec3::sub(
                                    Vec3::scale(
                                        Vec3::add(
                                            Vec3::scale(camera_up, frand() + x),
                                            Vec3::add(
                                                Vec3::scale(camera_right, frand() + y),
                                                eye_offset
                                            )
                                        ),
                                        16.0f
                                    ),
                                    delta
                                )
                            )
                        );

                        // Accumulate the sample result into the current pixel
                        pixel = Vec3::add(
                            sample,
                            pixel
                        );


                        // Check if the short duration average is close enough to the all time average that we believe
                        // the pixel value to be stable.
                        if (
                            ray_count >= min_adaptive_ray_count &&
                            (ray_count & (Sample::ADAPTIVE_BUFFER_SIZE-1)) == (Sample::ADAPTIVE_BUFFER_SIZE-1)
                        ) {
                            Vec3 average = Vec3::scale(
                                pixel,
                                1.0f/(ray_count + 1)
                            );

                            Vec3 last = samples[0];
                            for (int s = 1; s < Sample::ADAPTIVE_BUFFER_SIZE; ++s) {
                                last = Vec3::add(last, samples[s]);
                            }
                            last = Vec3::sub(
                                Vec3::scale(last, 1.0f/Sample::ADAPTIVE_BUFFER_SIZE),
                                average
                            );
                            float32 dot_sum = Vec3::dot(last, last);
                            if (dot_sum < Sample::RGB_SIMILARITY_LIMIT) {
                                pixel = Vec3::scale(
                                    pixel,
                                    (float32)MAX_RAYS / (float32)(ray_count + 1)
                                );
                                break;
                            }
                        }
                    }

                    min_adaptive_ray_count = ray_count >> 1;
                    if (min_adaptive_ray_count < Sample::ADAPTIVE_BUFFER_SIZE) {
                        min_adaptive_ray_count = Sample::ADAPTIVE_BUFFER_SIZE;
                    }
                    pixel = Vec3::scale(pixel, SAMPLE_SCALE);
                    WRITE_RAY_DENSITY(ray_count);

                } else {
                    pixel = Vec3::scale(Material::shade_sky_rgb(probe_direction), MAX_RAYS * SAMPLE_SCALE);
                    WRITE_RAY_DENSITY(0);
                }
                pixel = Vec3::add(pixel, Scene::ambient_rgb);

                // Convert to integers and push out to ppm output stream
                std::fprintf(out, "%c%c%c", (int)pixel.x, (int)pixel.y, (int)pixel.z);
            }
        }

        // Only the profile call or the render timing call will be compiled in, never both
        TIME_RENDER_DONE();
        PROF_EXIT(FunctionProfle::RENDER);
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
        if (Scene::init()) {
            Scene::render(out);
            Scene::done();
        }
        std::fclose(out);
        PROF_DUMP();
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}
