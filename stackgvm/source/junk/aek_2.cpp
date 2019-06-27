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

#include "aek.hpp"

///////////////////////////////////////////////////////////////////////////////

vec3 spheres[18*8];
int32 num_spheres = 0;

void init_spheres() {
    // Check if trace maybe hits a sphere
    for (int32 k = 19; k--;) {
        for (int32 j = 9; j--;) {
            if (data[j] & 1 << k) {
                spheres[num_spheres].x = k;
                spheres[num_spheres].y = 0;
                spheres[num_spheres].z = j + 4;
                num_spheres++;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

// Trace
int32 trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {
    distance         = 1e9f;

    // Assume trace hits nothing
    int32   material = 0;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up,
        material = 1;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i<num_spheres; i++) {
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
                material = 2; // Returning here is fast, but we'd get z fighting
            }
        }
    }
    return material;
}

///////////////////////////////////////////////////////////////////////////////

// Sampling
vec3 sample(cvr3 origin, cvr3 direction) {
    float32 distance;
    vec3 normal;

    // Find where the ray intersects the world
    int32 material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (!material) {
        float32 gradient = 1.0f - direction.z;
        gradient *= gradient;
        gradient *= gradient;
        return vec3_scale(
            sky_rgb, // Blueish sky colour
            gradient
        );
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
    if (lambertian < 0.0f || trace(intersection, light, distance, normal)) {
        lambertian = 0.0f; // in shadow
    }

    // Hit the floor plane
    if (material == 1) {
        intersection = vec3_scale(intersection, 0.2f);
        return vec3_scale(
            (
                // Compute check colour based on the position
                (int32) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
                    floor_red_rgb : // red
                    floor_white_rgb   // white
            ),
            (lambertian * 0.2f + 0.1f)
        );
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
            0.5f
        )
    );
}



///////////////////////////////////////////////////////////////////////////////

// Main
int main() {
    int image_size = 512;
    printf("P6 %d %d 255 ", image_size, image_size);

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
        )
    ;

    init_spheres();

    for (int32 y = image_size; y--;) {
        for (int32 x = image_size; x--;) {

            // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
            vec3 pixel(0.0f, 0.0f, 0.0f);

            // Cast 64 rays per pixel for sampling
            for (int32 ray_count = 64; ray_count--;) {

                // Random delta to be added for depth of field effects
                vec3 delta = vec3_add(
                    vec3_scale(camera_up,    (frand() - 0.5f) * 99.0f),
                    vec3_scale(camera_right, (frand() - 0.5f) * 99.0f)
                );

                // Accumulate the sample result into the current pixel
                pixel  = vec3_add(
                    sample(
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
            pixel = vec3_add(pixel, vec3(13.0f, 13.0f, 13.0f));

            // Convert to integers and push out to ppm outpu stream
            std::printf("%c%c%c", (int)pixel.x, (int)pixel.y, (int)pixel.z);
        }
    }

  return 0;
}

