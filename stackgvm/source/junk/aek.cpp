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

#ifdef __LP64__
    #define PPMNAME "aek_64.ppm"
#else
    #define PPMNAME "aek_32.ppm"
#endif

Material trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal) {
    distance = 1e9f;

    // Assume trace hits nothing
    Material material = M_SKY;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up,
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int k = 19; k--;) {
        for (int j = 9; j--;) {
            if (data[j] & 1 << k) {
                Vec3 p = Vec3::sub(
                    origin,
                    Vec3(k, 0.0f, j + 4.0f) // Sphere coordinate
                );

                float32
                    b = Vec3::dot(p, direction),
                    eye_offset = Vec3::dot(p, p) - 1.0f,
                    q = b * b - eye_offset
                ;
                if (q > 0.0f) {
                    float32 sphere_distance = -b - sqrt(q);
                        if (sphere_distance < distance && sphere_distance > 0.01f) {
                            distance = sphere_distance,
                            normal   = Vec3::normalize(
                            Vec3::add(p, Vec3::scale(direction, distance))
                        ),
                        material = M_MIRROR; // Returning here is fast, but we'd get z fighting
                    }
                }
            }
        }
    }
    return material;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Vec3 sample(cvr3 origin, cvr3 direction)
//
//  Generic sampling method that uses the most expensive trace() and recursively samples when hitting a reflective
//  surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vec3 sample(cvr3 origin, cvr3 direction) {
    float32 distance;
    Vec3 normal;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        float32 gradient = 1.0f - direction.z;
        gradient *= gradient;
        gradient *= gradient;
        return Vec3::scale(
            sky_rgb, // Blueish sky colour
            gradient
        );
    }

    Vec3
        intersection = Vec3::add(origin, Vec3::scale(direction, distance)),

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
        ),

        half_vector = Vec3::add(
            direction,
            Vec3::scale(
                normal,
                Vec3::dot(normal, direction) * -2.0f
            )
        )
    ;

    // Calculate the lambertian illumuination factor
    float32 lambertian = Vec3::dot(light, normal);
    if (lambertian < 0.0f || trace(intersection, light, distance, normal)) {
        lambertian = 0.0f; // in shadow
    }

    // Hit the floor plane
    if (material == M_FLOOR) {
        intersection = Vec3::scale(intersection, 0.2f);
        return Vec3::scale(
            (
                // Compute check colour based on the position
                (int32) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
                    floor_red_rgb : // red
                    floor_white_rgb   // white
            ),
            (lambertian * 0.2f + 0.1f)
        );
    }

    // Compute the specular highlight power
    float32 specular = pow(Vec3::dot(light, half_vector) * (lambertian > 0.0f), 99.0f);

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
//  void render(std::FILE* out)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void render(std::FILE* out) {
    std::fprintf(out, "P6 %d %d 255 ", IMAGE_SIZE, IMAGE_SIZE);

    NanoTime::Value start = NanoTime::mark();

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
        )
    ;

    for (int y = IMAGE_SIZE; y--;) {
        for (int x = IMAGE_SIZE; x--;) {

            // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
            Vec3 pixel = ambient_rgb;

            // Cast 64 rays per pixel for sampling
            for (int ray_count = MAX_RAYS; ray_count--;) {

                // Random delta to be added for depth of field effects
                Vec3 delta = Vec3::add(
                    Vec3::scale(camera_up,    (frand() - 0.5f) * 99.0f),
                    Vec3::scale(camera_right, (frand() - 0.5f) * 99.0f)
                );

                // Accumulate the sample result into the current pixel
                pixel  = Vec3::add(
                    Vec3::scale(
                        sample(
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
                                        16.0
                                    ),
                                    delta
                                )
                            )
                        ),
                        SAMPLE_SCALE
                    ),
                    pixel
                );
            }

            // Convert to integers and push out to ppm outpu stream
            std::fprintf(out, "%c%c%c", (int)pixel.x, (int)pixel.y, (int)pixel.z);
        }
    }

    NanoTime::Value end = NanoTime::mark();

    std::printf(
        "Total render() time %0.6f seconds\n",
        (float64)(end - start) / 1e9
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
        render(out);
        std::fclose(out);
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}
