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

#ifdef __LP64__
    #define PPMNAME "aek3_64.ppm"
#else
    #define PPMNAME "aek3_32.ppm"
#endif

vec3 spheres[18*8];
int  num_spheres = 0;

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
//  Material trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Since sphere volumes overlap, this version exhaustively tests every sphere to determine the
//  exact point of intersection.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {
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
        vec3 p = vec3_sub(
            origin,
            spheres[i] // Sphere coordinate
        );

        float32
            b = dot(p, direction),
            eye_offset = dot(p, p) - 1.0f,
            q = b * b - eye_offset
        ;
        if (q > 0.0f) {
            float32 sphere_distance = -b - std::sqrt(q);
            if (sphere_distance < distance && sphere_distance > 0.01f) {
                distance = sphere_distance,
                normal   = vec3_normalize(
                    vec3_add(p, vec3_scale(direction, distance))
                ),
                material = M_MIRROR; // Returning here is fast, but we'd get z fighting
            }
        }
    }
    return material;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace_nobounce(cvr3 origin, cvr3 direction, float32& distance, vec3& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Completely ignores sphere intersection tests. We use this routine when we know that a ray
//  cannot intersect any of the spheres in the scene,
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace_nobounce(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {
    distance  = 1e9f;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up;
        return M_FLOOR;
    }
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

    // Assume trace hits sky
    Material material = M_SKY;
    float32 p = -origin.z / (direction.z + floor_mod);

    // Check if trace maybe hits floor
    if (0.01f < p) {
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i<num_spheres; i++) {
        vec3 p = vec3_sub(
            origin,
            spheres[i] // Sphere coordinate
        );

        float32
            b = dot(p, direction),
            eye_offset = dot(p, p) - sphere_size_mod,
            q = b * b - eye_offset
        ;
        if (q > 0.0f) {
            float32 sphere_distance = -b - std::sqrt(q);
            if (sphere_distance < 1e9 && sphere_distance > 0.01f) {
                material = M_MIRROR;
                break;
            }
        }
    }
    return material;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec3 material_sky_rgb(cvr3 direction)
//
//  Returns the sky colour for a given direction.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline vec3 material_sky_rgb(cvr3 direction) {
    float32 gradient = 1.0f - direction.z;
    gradient *= gradient;
    gradient *= gradient;
    return vec3_scale(
        sky_rgb, // Blueish sky colour
        gradient
    );
}

inline vec3 material_floor_rgb(vec3& intersection, float32 lambertian) {
    intersection = vec3_scale(intersection, 0.2f);
    return vec3_scale(
        (
            // Compute check colour based on the position
            (int) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
                floor_red_rgb :
                floor_white_rgb
        ),
        (lambertian * 0.2f + 0.1f)
    );
}

typedef vec3 (*sampler)(cvr3 origin, cvr3 direction);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec3 sample(cvr3 origin, cvr3 direction)
//
//  Generic sampling method that uses the most expensive trace() and recursively samples when hitting a reflective
//  surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vec3 sample(cvr3 origin, cvr3 direction) {
    float32 distance;
    vec3 normal;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        return material_sky_rgb(direction);
    }

    vec3
        intersection = vec3_add(origin, vec3_scale(direction, distance)),

        // Calculate the lighting vector
        light = vec3_normalize(
            vec3_sub(
                vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f
                ),
                intersection
            )
        )
    ;

    // Calculate the lambertian illumuination factor
    float32 lambertian = dot(light, normal);
    if (lambertian < 0.0f || trace_material_only(intersection, light)) {
        lambertian = 0.0f; // in shadow
    }

    // Hit the floor plane
    if (material == M_FLOOR) {
        return material_floor_rgb(intersection, lambertian);
    }

    vec3 half_vector = vec3_add(
        direction,
        vec3_scale(
            normal,
            dot(normal, direction) * -2.0f
        )
    );

    // Compute the specular highlight power
    float32 specular = pow(dot(light, half_vector) * (lambertian > 0.0), 99.0f);

    // Hit a sphere
    return vec3_add(
        vec3(specular, specular, specular),
        vec3_scale(
            sample(intersection, half_vector),
            0.75f
        )
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec3 sample_nobounce(cvr3 origin, cvr3 direction)
//
//  Tuned sample method for rays that we know will not hit a reflective surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vec3 sample_nobounce(cvr3 origin, cvr3 direction) {

    float32 distance;
    vec3 normal;

    // Find where the ray intersects the world
    Material material = trace_nobounce(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        return material_sky_rgb(direction);
    }

    vec3
        intersection = vec3_add(origin, vec3_scale(direction, distance)),

        // Calculate the lighting vector
        light = vec3_normalize(
            vec3_sub(
                vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f
                ),
                intersection
            )
        )
    ;

    // Calculate the lambertian illumuination factor
    float32 lambertian = dot(light, normal);
    if (lambertian < 0.0f || trace_material_only(intersection, light)) {
        lambertian = 0.0f; // in shadow
    }

    return material_floor_rgb(intersection, lambertian);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec3 sample_first_bounce(cvr3 origin, cvr3 direction)
//
//  Tuned sample method for primary rays that we expect to bounce only once. This determination is made by checking
//  the calculated half_vector's y component to see if it's heading away from the plane containing the spheres.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vec3 sample_first_bounce(cvr3 origin, cvr3 direction) {
    float32 distance;
    vec3 normal;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        return material_sky_rgb(direction);
    }

    vec3
        intersection = vec3_add(origin, vec3_scale(direction, distance)),

        // Calculate the lighting vector
        light = vec3_normalize(
            vec3_sub(
                vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f
                ),
                intersection
            )
        )
    ;

    // Calculate the lambertian illumuination factor
    float32 lambertian = dot(light, normal);
    if (lambertian < 0.0f || trace_material_only(intersection, light)) {
        lambertian = 0.0f; // in shadow
    }

    // Hit the floor plane
    if (material == M_FLOOR) {
        return material_floor_rgb(intersection, lambertian);
    }

    vec3 half_vector = vec3_add(
        direction,
        vec3_scale(
            normal,
            dot(normal, direction) * -2.0f
        )
    );

    sampler samplefn = (half_vector.y > 0.15f) ? sample_nobounce : sample;

    // Compute the specular highlight power
    float32 specular = pow(dot(light, half_vector) * (lambertian > 0.0), 99.0f);

    // Hit a sphere
    return vec3_add(
        vec3(specular, specular, specular),
        vec3_scale(
            samplefn(intersection, half_vector),
            0.75f
        )
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  void render(std::FILE* out, int image_size)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void render(std::FILE* out, int image_size) {
    std::fprintf(out, "P6 %d %d 255 ", image_size, image_size);

    NanoTime::Value start = NanoTime::mark();

    // camera direction vectors
    vec3
        camera_forward = vec3_normalize( // Unit forwards
            camera_dir
        ),

        camera_up = vec3_scale( // Unit up - Z is up in this system
            vec3_normalize(
                vec3_cross(
                    normal_up,
                    camera_forward
                )
            ),
            0.002f
        ),

        camera_right = vec3_scale( // Unit right
            vec3_normalize(
                vec3_cross(camera_forward, camera_up)
            ),
            0.002f
        ),

        eye_offset = vec3_add( // Offset frm eye to coner of focal plane
            vec3_scale(
                vec3_add(camera_up, camera_right),
                -(image_size >> 1)
            ),
            camera_forward
        ),

        probe_delta = vec3_add(
            camera_up,
            camera_right
        ),

        probe_origin = vec3_add(
            focal_point,
            probe_delta
        )
    ;


    int ray_counts[3] = { 0, 0, 0 };

    for (int y = image_size; y--;) {
        for (int x = image_size; x--;) {
            // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
            vec3 pixel(0.0f, 0.0f, 0.0f);

            // Perform a material probe first. If we don't hit a sphere we can use an optimised sample function
            vec3 probe_direction = vec3_normalize(
                vec3_sub(
                    vec3_scale(
                        vec3_add(
                            vec3_scale(camera_up, 0.5 + x),
                            vec3_add(
                                vec3_scale(camera_right, 0.5 + y),
                                eye_offset
                            )
                        ),
                        16.0f
                    ),
                    probe_delta
                )
            );

            Material material = trace_material_only(probe_origin, probe_direction, 1.10f, -0.01f);

            ray_counts[material]++;

            if (material != M_SKY) {

                sampler samplefn = (material == M_MIRROR ? sample_first_bounce : sample_nobounce);

                // Cast 64 rays per pixel for sampling
                for (int ray_count = 64; ray_count--;) {

                    // Random delta to be added for depth of field effects
                    vec3 delta = vec3_add(
                        vec3_scale(camera_up,    (frand() - 0.5f) * 99.0f),
                        vec3_scale(camera_right, (frand() - 0.5f) * 99.0f)
                    );

                    // Accumulate the sample result into the current pixel
                    pixel  = vec3_add(
                        samplefn(
                            vec3_add(
                                focal_point,
                                delta
                            ),
                            vec3_normalize(
                                vec3_sub(
                                    vec3_scale(
                                        vec3_add(
                                            vec3_scale(camera_up, frand() + x),
                                            vec3_add(
                                                vec3_scale(camera_right, frand() + y),
                                                eye_offset
                                            )
                                        ),
                                        16.0f
                                    ),
                                    delta
                                )
                            )
                        ),
                        pixel
                    );
                }

                pixel = vec3_scale(pixel, 3.5f);
            } else {
                pixel = vec3_scale(material_sky_rgb(probe_direction), 64 * 3.5);
            }
            pixel = vec3_add(pixel, ambient_rgb);

            // Convert to integers and push out to ppm outpu stream
            std::fprintf(out, "%c%c%c", (int)pixel.x, (int)pixel.y, (int)pixel.z);
        }
    }

    NanoTime::Value end = NanoTime::mark();

    std::printf(
        "Total render() time %0.6f seconds\n"
        "Primary material probes:\n"
        "\tM_SKY    : %5d\n"
        "\tM_FLOOR  : %5d\n"
        "\tM_MIRROR : %5d\n",
        (float64)(end - start) / 1e9,
        ray_counts[M_SKY],
        ray_counts[M_FLOOR],
        ray_counts[M_MIRROR]
    );
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
        render(out, 512);
        std::fclose(out);
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}
