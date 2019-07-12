// De-golfed version of the Business Card Raytracer by Andrew Kensler

#include "aek.hpp"

#ifdef __LP64__
    #define PPMNAME "aek_v1_64.ppm"
#else
    #define PPMNAME "aek_v1_32.ppm"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    // Maximum column to consider
    int32 i_max_bitmap_column = 0;

    // Initialise the scene.
    void init() {
        int i_mask = 0;
        for (int i = 0; i < I_BITMAP_ROWS; ++i) {
            i_mask |= AI_BITMAP[i];
        }
        i_max_bitmap_column = 8 * sizeof(int32) - __builtin_clz(i_mask);
    }

    void done() {

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
    Material::Kind trace(cvr3 v_origin, cvr3 v_direction, float32& f_distance, Vec3& v_normal) {
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
        for (int k = Scene::i_max_bitmap_column; k--;) {
            for (int j = Scene::I_BITMAP_ROWS; j--;) {
                if (Scene::AI_BITMAP[j] & 1 << k) {
                    Vec3 v_p = Vec3::sub(
                        v_origin,
                        Vec3(k, 0.0f, j + 4.0f) // Sphere coordinate
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
                                    Vec3::add(v_p, Vec3::scale(v_direction, f_distance)
                                )
                            ),
                            i_material = Material::I_MIRROR;
                        }
                    }
                }
            }
        }
        return i_material;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    Vec3 sample(cvr3 v_origin, cvr3 v_direction) {
        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (i_material == Material::I_SKY) {
            return Material::shadeSky(v_direction);
        }

        Vec3
            v_intersection = Vec3::add(v_origin, Vec3::scale(v_direction, f_distance)),

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
            ),

            v_half_vector = calculateHalfVector(v_direction, v_normal)
        ;

        // Calculate the lambertian illumuination factor
        float32 f_lambertian = Vec3::dot(v_light, v_normal);
        if (f_lambertian < 0.0f || Ray::trace(v_intersection, v_light, f_distance, v_normal)) {
            f_lambertian = 0.0f; // in shadow
        }

        // Hit the floor plane
        if (i_material == Material::I_FLOOR) {
            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        // Compute the specular highlight power
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        // Hit a sphere
        return Vec3::add(
            Vec3(f_specular),
            Vec3::scale(
                sample(v_intersection, v_half_vector),
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

    void render(std::FILE* r_out) {
        std::fprintf(r_out, "P6 %d %d 255 ", I_IMAGE_SIZE, I_IMAGE_SIZE);

        Profiling::Nanotime u_start = Profiling::mark();

        // camera direction vectors
        Vec3
            v_camera_forward = Vec3::normalize( // Unit forwards
                V_CAMERA_DIR
            ),

            v_camera_up = Vec3::scale( // Unit up - Z is up in this system
                Vec3::normalize(
                    Vec3::cross(
                        V_NORMAL_UP,
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
            )
        ;

        for (int y = I_IMAGE_SIZE; y--;) {
            for (int x = I_IMAGE_SIZE; x--;) {

                // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
                Vec3 v_pixel = V_AMBIENT_RGB;

                // Cast 64 rays per pixel for sampling
                for (int ray_count = I_MAX_RAYS; ray_count--;) {

                    // Random delta to be added for depth of field effects
                    Vec3 v_delta = Vec3::add(
                        Vec3::scale(v_camera_up,    (frand() - 0.5f) * 99.0f),
                        Vec3::scale(v_camera_right, (frand() - 0.5f) * 99.0f)
                    );

                    // Accumulate the sample result into the current pixel
                    v_pixel  = Vec3::add(
                        Vec3::scale(
                            Sample::sample(
                                Vec3::add(
                                    V_FOCAL_POINT,
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
                            ),
                            F_SAMPLE_SCALE
                        ),
                        v_pixel
                    );
                }

                // Convert to integers and push out to ppm outpu stream
                std::fprintf(r_out, "%c%c%c", (int)v_pixel.x, (int)v_pixel.y, (int)v_pixel.z);
            }
        }

        Profiling::Nanotime u_end = Profiling::mark();

        std::printf(
            "Total render() time %0.6f seconds\n",
            (float64)(u_end - u_start) / 1e9
        );
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::FILE* r_out = std::fopen(PPMNAME, "wb");
    if (r_out) {
        std::printf("Rendering to " PPMNAME "...\n");
        Scene::init();
        Scene::render(r_out);
        Scene::done();
        std::fclose(r_out);
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}

