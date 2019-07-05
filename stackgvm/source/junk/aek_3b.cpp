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
    #define PPMNAME "aek3b_64.ppm"
#else
    #define PPMNAME "aek3b_32.ppm"
#endif

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
        { 0, "render()", 0 },
        { 0, "sample()", 0 },
        { 0, "sample_no_bounce()", 0 },
        { 0, "sample_first_bounce()", 0 },
        { 0, "trace()", 0 },
        { 0, "trace_no_bounce()", 0 },
        { 0, "trace_material_only()", 0 },
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
#else
    #define PROF_ENTER(_f)
    #define PROF_EXIT(_f)
    #define PROF_DUMP()
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const float32 RGB_SIMILARITY_LIMIT = 1e-4f;
static Vec3  spheres[18*8];
static int   num_spheres = 0;

void init_spheres() {
    // Check if trace maybe hits a sphere
    for (int k = 19; k--;) {
        for (int j = 9; j--;) {
            if (data[j] & 1 << k) {
                spheres[num_spheres].x = k;
                spheres[num_spheres].y = 0;
                spheres[num_spheres].z = j + 4;
                num_spheres++;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Since sphere volumes overlap, this version exhaustively tests every sphere to determine the
//  exact point of intersection.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal) {
    PROF_ENTER(FunctionProfle::TRACE);

    distance = 1e9f;

    // Assume trace hits nothing
    Material   material = M_SKY;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up,
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i < num_spheres; i++) {
        Vec3 p = Vec3::sub(
            origin,
            spheres[i] // Sphere coordinate
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
                material = M_MIRROR; // Returning here is fast, but we'd get z fighting
            }
        }
    }
    PROF_EXIT(FunctionProfle::TRACE);
    return material;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace_no_bounce(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Completely ignores sphere intersection tests. We use this routine when we know that a ray
//  cannot intersect any of the spheres in the scene,
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace_no_bounce(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal) {
    PROF_ENTER(FunctionProfle::TRACE_NO_BOUNCE);
    distance  = 1e9f;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up;
        PROF_EXIT(FunctionProfle::TRACE_NO_BOUNCE);
        return M_FLOOR;
    }
    PROF_EXIT(FunctionProfle::TRACE_NO_BOUNCE);
    return M_SKY;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace_material_only(cvr3 origin, cvr3 direction)
//
//  Shortcut version of the trace routine that only tests what material is intersected first by the ray. As the distance
//  and nprmal are not required here. if the ray hits a sphere we early exit;
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace_material_only(cvr3 origin, cvr3 direction, const float32 sphere_size_mod = 1.0f, const float32 floor_mod = 0.0f) {

    PROF_ENTER(FunctionProfle::TRACE_MATERIAL_ONLY);

    // Assume trace hits sky
    Material material = M_SKY;
    float32 p = -origin.z / (direction.z + floor_mod);

    // Check if trace maybe hits floor
    if (0.01f < p) {
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i < num_spheres; i++) {
        Vec3 p = Vec3::sub(
            origin,
            spheres[i] // Sphere coordinate
        );

        float32
            b = Vec3::dot(p, direction),
            eye_offset = Vec3::dot(p, p) - sphere_size_mod,
            q = b * b - eye_offset
        ;
        if (q > 0.0f) {
            float32 sphere_distance = -b - std::sqrt(q);
            if (sphere_distance < 1e9f && sphere_distance > 0.01f) {
                material = M_MIRROR;
                break;
            }
        }
    }
    PROF_EXIT(FunctionProfle::TRACE_MATERIAL_ONLY);
    return material;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Helpers
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    if (lambertian < 0.0f || trace_material_only(intersection, light)) {
        lambertian = 0.0f; // in shadow
    }
    return lambertian;
}


inline Vec3 material_sky_rgb(cvr3 direction) {
    float32 gradient = 1.0f - direction.z;
    gradient *= gradient;
    gradient *= gradient;
    return Vec3::scale(
        sky_rgb, // Blueish sky colour
        gradient
    );
}


inline Vec3 material_floor_rgb(Vec3& intersection, float32 lambertian) {
    intersection = Vec3::scale(intersection, 0.2f);
    return Vec3::scale(
        (
            // Compute check colour based on the position
            (int) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
                floor_red_rgb :
                floor_white_rgb
        ),
        (lambertian * 0.2f + 0.1f)
    );
}

inline Vec3 calc_half_vector(cvr3 direction, cvr3 normal) {
    return Vec3::add(
        direction,
        Vec3::scale(
            normal,
            Vec3::dot(normal, direction) * -2.0f
        )
    );
}

inline float32 calculate_specularity(cvr3 light, cvr3 half_vector, float32 lambertian) {
    return (lambertian > 0.0) ?
        pow(Vec3::dot(light, half_vector), 99.0f) :
        0.0f;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Vec3 sample(cvr3 origin, cvr3 direction)
//
//  Generic sampling method that uses the most expensive trace() and recursively samples when hitting a reflective
//  surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef Vec3 (*SampleFunction)(cvr3 origin, cvr3 direction);

Vec3 sample(cvr3 origin, cvr3 direction) {
    PROF_ENTER(FunctionProfle::SAMPLE);

    Vec3 normal;
    float32 distance;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        PROF_EXIT(FunctionProfle::SAMPLE);
        return material_sky_rgb(direction);
    }

    Vec3
        light,
        intersection = Vec3::add(origin, Vec3::scale(direction, distance))
    ;

    float32 lambertian = calculate_lighting(intersection, normal, light);

    // Hit the floor plane
    if (material == M_FLOOR) {
        PROF_EXIT(FunctionProfle::SAMPLE);
        return material_floor_rgb(intersection, lambertian);
    }

    Vec3 half_vector = calc_half_vector(direction, normal);

    // Compute the specular highlight power
    float32 specular = calculate_specularity(light, half_vector, lambertian);

    PROF_EXIT(FunctionProfle::SAMPLE);

    // Hit a sphere
    return Vec3::add(
        Vec3(specular, specular, specular),
        Vec3::scale(
            sample(intersection, half_vector),
            SPHERE_ALBEDO
        )
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Vec3 sample_no_bounce(cvr3 origin, cvr3 direction)
//
//  Tuned sample method for rays that we know will not hit a reflective surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vec3 sample_no_bounce(cvr3 origin, cvr3 direction) {

    PROF_ENTER(FunctionProfle::SAMPLE_NO_BOUNCE);

    float32 distance;
    Vec3 normal;

    // Find where the ray intersects the world
    Material material = trace_no_bounce(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        PROF_EXIT(FunctionProfle::SAMPLE_NO_BOUNCE);
        return material_sky_rgb(direction);
    }

    Vec3
        light,
        intersection = Vec3::add(origin, Vec3::scale(direction, distance))
    ;

    float32 lambertian = calculate_lighting(intersection, normal, light);

    PROF_EXIT(FunctionProfle::SAMPLE_NO_BOUNCE);
    return material_floor_rgb(intersection, lambertian);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Vec3 sample_first_bounce(cvr3 origin, cvr3 direction)
//
//  Tuned sample method for primary rays that we expect to bounce only once. This determination is made by checking
//  the calculated half_vector's y component to see if it's heading away from the plane containing the spheres.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vec3 sample_first_bounce(cvr3 origin, cvr3 direction) {

    PROF_ENTER(FunctionProfle::SAMPLE_FIRST_BOUNCE);

    float32 distance;
    Vec3 normal;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);
        return material_sky_rgb(direction);
    }

    Vec3
        light,
        intersection = Vec3::add(origin, Vec3::scale(direction, distance))
    ;

    float32 lambertian = calculate_lighting(intersection, normal, light);

    // Hit the floor plane
    if (material == M_FLOOR) {
        PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);
        return material_floor_rgb(intersection, lambertian);
    }

    Vec3 half_vector = calc_half_vector(direction, normal);

    SampleFunction samplefn = (half_vector.y > 0.15f) ? sample_no_bounce : sample;

    // Compute the specular highlight power
    float32 specular = calculate_specularity(light, half_vector, lambertian);

    PROF_EXIT(FunctionProfle::SAMPLE_FIRST_BOUNCE);

    // Hit a sphere
    return Vec3::add(
        Vec3(specular, specular, specular),
        Vec3::scale(
            samplefn(intersection, half_vector),
            SPHERE_ALBEDO
        )
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  void render(std::FILE* out)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SAMPLE_BUFFER_SIZE 8

void render(std::FILE* out) {

    std::FILE* dbg = fopen("aek3b_rays.ppm", "wb");
    if (!dbg) {
        return;
    }
    std::fprintf(out, "P6 %d %d 255 ", IMAGE_SIZE, IMAGE_SIZE);
    std::fprintf(dbg, "P5 %d %d 255 ", IMAGE_SIZE, IMAGE_SIZE);

    PROF_ENTER(FunctionProfle::RENDER);

    // camera direction vectors
    Vec3
        camera_forward = Vec3::normalize( // Unit forwards
            camera_dir
        ),

        camera_up = Vec3::scale( // Unit up - Z is up in this system
            Vec3::normalize(
                Vec3::cross(
                    normal_up,
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
            focal_point,
            probe_delta
        )
    ;



    for (int y = IMAGE_SIZE; y--;) {
        int min_adaptive_ray_count = (SAMPLE_BUFFER_SIZE-1);
        for (int x = IMAGE_SIZE; x--;) {
            // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
            Vec3 pixel(0.0f, 0.0f, 0.0f);

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

            Material material = trace_material_only(probe_origin, probe_direction, 1.10f, -0.01f);

            if (material != M_SKY) {
                Vec3 samples[SAMPLE_BUFFER_SIZE];
                SampleFunction samplefn = (material == M_MIRROR ? sample_first_bounce : sample_no_bounce);
                int ray_count;
                // Cast MAX_RAYS rays per pixel for sampling
                for (ray_count = 0; ray_count < MAX_RAYS; ++ray_count) {

                    // Random delta to be added for depth of field effects
                    Vec3 delta = Vec3::add(
                        Vec3::scale(camera_up,    (frand() - 0.5f) * 99.0f),
                        Vec3::scale(camera_right, (frand() - 0.5f) * 99.0f)
                    );

                    // Buffer the most recent 4 samoles
                    Vec3& sample = samples[ray_count & (SAMPLE_BUFFER_SIZE-1)];

                    sample = samplefn(
                        Vec3::add(
                            focal_point,
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

                    // After a minimum of 16 samples, every 4 samples, check to see if the samples vary from the current
                    // average pixel colour by more than some amount.
                    //
                    // TODO - decide on what is a good solution for this.
                    //
                    // We first convert the last four samples into their difference from the average, then compute the
                    // dot product of that difference with itself to get some notion of the samples distance from the
                    // average. We then sum those up and just check it's lower than some arbitrary threshold.

                    if (
                        ray_count > min_adaptive_ray_count &&
                        (ray_count & (SAMPLE_BUFFER_SIZE-1)) == (SAMPLE_BUFFER_SIZE-1)
                    ) {

                        Vec3 average = Vec3::scale(
                            pixel,
                            1.0f/(ray_count + 1)
                        );

                        Vec3 last = samples[0];
                        for (int s = 1; s < SAMPLE_BUFFER_SIZE; ++s) {
                            last = Vec3::add(last, samples[s]);
                        }
                        last = Vec3::sub(
                            Vec3::scale(last, 1.0f/SAMPLE_BUFFER_SIZE),
                            average
                        );
                        float32 dot_sum = Vec3::dot(last, last);
                        if (dot_sum < RGB_SIMILARITY_LIMIT) {
                            pixel = Vec3::scale(
                                pixel,
                                (float32)MAX_RAYS / (float32)(ray_count + 1)
                            );


                            min_adaptive_ray_count = ray_count;

                            break;
                        }
                    }
                }

                min_adaptive_ray_count *= 0.75f;
                if (min_adaptive_ray_count < (SAMPLE_BUFFER_SIZE-1)) {
                    min_adaptive_ray_count = (SAMPLE_BUFFER_SIZE-1);
                } else if (min_adaptive_ray_count > MAX_RAYS>>1) {
                    min_adaptive_ray_count = MAX_RAYS>>1;
                }

                pixel = Vec3::scale(pixel, SAMPLE_SCALE);
                if (ray_count >= MAX_RAYS) {
                    ray_count = MAX_RAYS-1;
                }
                std::fprintf(dbg, "%c", ray_count);

            } else {
                pixel = Vec3::scale(material_sky_rgb(probe_direction), MAX_RAYS * SAMPLE_SCALE);
                std::fprintf(dbg, "%c", 0);
            }
            pixel = Vec3::add(pixel, ambient_rgb);

            // Convert to integers and push out to ppm output stream
            std::fprintf(out, "%c%c%c", (int)pixel.x, (int)pixel.y, (int)pixel.z);
        }
    }

    PROF_EXIT(FunctionProfle::RENDER);

    std::fclose(dbg);
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
        init_spheres();
        render(out);
        std::fclose(out);
        PROF_DUMP();
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}
