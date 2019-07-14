// De-golfed version of the Business Card Raytracer by Andrew Kensler

#include "aek.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __LP64__
    #define PPMNAME "aek_v3_64.ppm"
#else
    #define PPMNAME "aek_v3_32.ppm"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    // Dynamically allocated set of spheres
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
     * Vanilla trace() behaviour. Traces a ray into the Scene in order to determine what is hit, at what distance and
     * what the surface normal (if any) is at that location. Returns the material type of the entity that was hit and
     * where relevant, updates f_distance and v_normal.
     *
     * The ray is traced from v_origin along v_direction. Due to the simplicity of our Scene, only three outcomes are
     * possible:
     *
     * 1) The ray misses all objects and heads towards the sky.
     * 2) The ray misses all objects and heads towards the floor. The distance from v_origin to the point of
     *    intersection is set in f_distance and the unit normal UP is set in v_normal.
     * 3) The ray hits an object. The distance from v_origin to the point of intersection is set in f_distance and the
     *    surface normal at the point of intersection is set in v_normal.
     *
     * Since a ray may intersect multiple objects and the objects are in no particular order, every object is tested
     * to find the one closest to v_origin.
     */
    Material::Kind trace(const Vec3& v_origin, const Vec3& v_direction, float32& f_distance, Vec3& v_normal) {

        f_distance = 1e9f;

        // Assume trace hits the sky
        Material::Kind i_material = Material::I_SKY;
        float32        f_p        = -v_origin.z / v_direction.z;

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            f_distance = f_p;
            v_normal   = Scene::V_NORMAL_UP;
            i_material = Material::I_FLOOR;
        }

        // Check if trace maybe hits a sphere. Here we compute the position in the Scene of each sphere referenced in
        // the bitmap and check if the ray intersects it. Even if it intersects, we cannot guarantee we have found the
        // nearest point of intersection as the order in which the spheres are tested is fixed. We have to test each
        // one and keep track of the nearest.

        for (int i = 0; i < Scene::i_num_spheres; ++i) {
            Vec3 v_position = v_origin - Scene::av_spheres[i]; // Sphere coordinate

            float32
                f_b          = v_position ^ v_direction,
                f_eye_offset = (v_position ^ v_position) - Scene::F_SPHERE_RADIUS,
                f_q          = f_b * f_b - f_eye_offset
            ;

            if (f_q > 0.0f) {
                // We have an intersection. Need confirm that it's nearer than any calculated so far and also
                // not at point blank range.
                float32 f_sphere_distance = -f_b - std::sqrt(f_q);
                if (f_sphere_distance < f_distance && f_sphere_distance > 0.01f) {
                    f_distance = f_sphere_distance;
                    v_normal   = ~(v_position + v_direction * f_distance);
                    i_material = Material::I_MIRROR;
                }
            }
        }
        return i_material;
    }


    /**
     * Variant trace() behaviour, tests for floor and sky intersection only, completely omitting any object intersection
     * tests. We use this version when we have reason to believe that no intersection is possible.
     */
    Material::Kind traceNoBounce(const Vec3& v_origin, const Vec3& v_direction, float32& f_distance, Vec3& v_normal) {

        f_distance  = 1e9f;
        float32 f_p = -v_origin.z / v_direction.z;

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            f_distance = f_p,
            v_normal   = Scene::V_NORMAL_UP;
            return Material::I_FLOOR;
        }
        return Material::I_SKY;
    }

    /**
     * Variant trace() behaviour, tests only which material was hit. Accepts tuning parameters that adjust the apparent
     * radius of objects and the pitch of the horizon. This is to allow us to provide an estimation of what material
     * was hit so that we can use the correct version later for stochastic sampling.
     */
    Material::Kind traceMaterialOnly(
        const Vec3&   v_origin,
        const Vec3&   v_direction,
        const float32 f_sphere_size_mod = Scene::F_SPHERE_RADIUS,
        const float32 f_floor_mod = 0.0f
    ) {

        // Assume trace hits sky
        Material::Kind i_material = Material::I_SKY;
        float32        f_p        = -v_origin.z / (v_direction.z + f_floor_mod);

        // Check if trace maybe hits floor
        if (0.01f < f_p) {
            i_material = Material::I_FLOOR;
        }

        // Check if trace maybe hits a sphere
        for (int i = 0; i < Scene::i_num_spheres; i++) {
            Vec3 v_position = v_origin - Scene::av_spheres[i]; // Sphere coordinate

            float32
                f_b          = v_position ^ v_direction,
                f_eye_offset = (v_position ^ v_position) - f_sphere_size_mod,
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

    /**
     * Defines how similar two Vec3 RGB values should be (based on the square of the component distances) such that they
     * are considered equivalent.
     */
    const float32 F_RGB_SIMILARITY_LIMIT    = 1e-4f;

    /**
     * Defines the maximum y component value used to switch between recursive and non recursive sample() variants.
     */
    const float32 F_THRESHOLD_SAMPLE_SELECT = 0.15f;

    /**
     * Callable type for sample() variants.
     */
    typedef Vec3 (*Function)(const Vec3& v_origin, const Vec3& v_direction);


    /**
     * Helper function to calculate the lambertian value for lighting, as well as generating a perturbed lighting
     * vector.
     */
    inline float32 calculateLambertian(const Vec3& v_intersection, const Vec3& v_normal, Vec3& v_light) {
        // Calculate the lighting vector
        v_light = ~(
            Vec3(
                // lighting direction, plus a bit of randomness to generate soft shadows.
                Scene::V_LIGHT_ORIGIN.x + frand(),
                Scene::V_LIGHT_ORIGIN.y + frand(),
                Scene::V_LIGHT_ORIGIN.z
            ) - v_intersection
        );

        // Calculate the lambertian illumuination factor
        float32 f_lambertian = v_light ^ v_normal;
        if (f_lambertian < 0.0f || Ray::traceMaterialOnly(v_intersection, v_light)) {
            f_lambertian = 0.0f; // in shadow
        }
        return f_lambertian;
    }


    /**
     * Vanilla sample() behaviour. Traces a ray into the Scene and depending on which Material was hit, calculates an
     * RGB value, taking into consideration the material and lighting conditions.
     *
     * 1) Where the trace heads into the sky, we use the sky shading Material behaviour to calculate the RGB value.
     *
     * 2) Where the trace hits the floor, we calculate the lambertian illumination factor and trace a second ray towards
     *    the light source, to determine whether or not the point of intersection was in shadow or not. We then use the
     *    floor shading Material behaviour, providing our lambertian, to calculate the RGB value.
     *    A small amount of randomness is used in this second trace so that the edge of the shadow region is imprecise
     *    and over many samples, a smooth penumbra will evolve.
     *
     * 3) Where the trace hit a sphere, we first compute a specular brightness sample and then recursively sample another
     *    ray from the point of intersection into the scene to see what was reflected. The RGB value returned from that
     *    recursion is attenuated by the mirror albedo and summed with the specular brightness sample to derive a final
     *    RGB value.
     */
    Vec3 sample(const Vec3& v_origin, const Vec3& v_direction) {

        Vec3    v_normal;
        float32 f_distance;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (Material::I_SKY == i_material) {
            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = v_origin + v_direction * f_distance
        ;

        float32 f_lambertian   = calculateLambertian(v_intersection, v_normal, v_light);

        // Hit the floor plane
        if (Material::I_FLOOR == i_material) {
            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        Vec3 v_half_vector = v_direction | v_normal;

        // Compute the specular highlight intensity
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        // Hit a sphere
        return Vec3(f_specular) + sample(v_intersection, v_half_vector) * Material::F_MIRROR_ALBEDO;
    }

    /**
     * Variant sample() behaviour that uses the variant trace behaviour that excludes object intersection tests. We use
     * this when sampling for a direction we do not believe will intersect anything other than the floor or sky,
     */
    Vec3 sampleNoBounce(const Vec3& v_origin, const Vec3& v_direction) {

        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::traceNoBounce(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (Material::I_SKY == i_material) {
            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = v_origin + v_direction * f_distance
        ;

        float32 f_lambertian = calculateLambertian(v_intersection, v_normal, v_light);

        return Material::shadeFloor(v_intersection, f_lambertian);
    }

    /**
     * Variant sample() behaviour that we use for the first intersected reflection only. This version will either use a
     * recursive or non-recursive variant of the sample function depending on whether or not it seems the reflected
     * ray is heading away from the plane containing the objects.
     */
    Vec3 sampleFirstBounce(const Vec3& v_origin, const Vec3& v_direction) {

        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (i_material == Material::I_SKY) {
            return Material::shadeSky(v_direction);
        }

        Vec3
            v_light,
            v_intersection = v_origin + v_direction * f_distance
        ;

        float32 f_lambertian = calculateLambertian(v_intersection, v_normal, v_light);

        // Hit the floor plane
        if (i_material == Material::I_FLOOR) {
            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        Vec3 v_half_vector = v_direction | v_normal;

        Function samplefn = (v_half_vector.y > 0.15f) ? sampleNoBounce : sample;

        // Compute the specular highlight intensity
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        // Hit a sphere
        return Vec3(f_specular) + samplefn(v_intersection, v_half_vector) * Material::F_MIRROR_ALBEDO;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    const float32
        F_SPHERE_PROBE_RADIUS = F_SPHERE_RADIUS * 1.1f,
        F_FLOOR_PROBE_OFFSET  = -0.01f
    ;

    const Vec3
        V_PROBE_DELTA    = V_CAMERA_UP   + V_CAMERA_RIGHT,
        V_PROBE_ORIGIN   = V_FOCAL_POINT + V_PROBE_DELTA
    ;

    void render(std::FILE* r_out) {

        std::fprintf(r_out, "P6 %d %d 255 ", I_IMAGE_SIZE, I_IMAGE_SIZE);

        for (int y = I_IMAGE_SIZE; y--;) {
            int i_min_adaptive_ray_count = Sample::I_ADAPTIVE_BUFFER_SIZE;
            for (int x = I_IMAGE_SIZE; x--;) {
                // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
                Vec3 v_pixel(0.0f);

                // Perform a material probe first. If we don't hit a sphere we can use an optimised sample function
                Vec3 v_probe_direction = ~(
                    (
                        V_CAMERA_UP    * (0.5f + x) +
                        V_CAMERA_RIGHT * (0.5f + y) +
                        V_EYE_OFFSET

                    ) * 16.0f - V_PROBE_DELTA
                );

                Material::Kind i_material = Ray::traceMaterialOnly(
                    V_PROBE_ORIGIN,
                    v_probe_direction,
                    F_SPHERE_PROBE_RADIUS,
                    F_FLOOR_PROBE_OFFSET
                );

                if (i_material != Material::I_SKY) {
                    Vec3 av_samples[Sample::I_ADAPTIVE_BUFFER_SIZE];
                    Sample::Function samplefn = (Material::I_MIRROR == i_material) ?
                        Sample::sampleFirstBounce :
                        Sample::sampleNoBounce
                    ;

                    int i_ray_count = 0;

                    // Cast up to MAX_RAYS rays per pixel for sampling
                    for (; i_ray_count < I_MAX_RAYS; ++i_ray_count) {

                        // Random delta to be added for depth of field effects
                        Vec3 v_delta =
                            V_CAMERA_UP    * frand(-49.5f, 49.5f) +
                            V_CAMERA_RIGHT * frand(-49.5f, 49.5f);

                        // Buffer the most recent sample
                        Vec3& v_sample = av_samples[i_ray_count & (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)];

                        // Accumulate the sample result into the current pixel
                        v_sample = samplefn(
                            V_FOCAL_POINT + v_delta,
                            ~(
                                (
                                    V_CAMERA_UP    * (frand() + x) +
                                    V_CAMERA_RIGHT * (frand() + y) +
                                    V_EYE_OFFSET
                                ) * 16.0f - v_delta
                            )
                        );



                        // Accumulate the sample result into the current pixel
                        v_pixel += v_sample;

                        // Check if the short duration average is close enough to the all time average that we believe
                        // the pixel value to be stable.
                        if (
                            i_ray_count >= i_min_adaptive_ray_count &&
                            (i_ray_count & (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)) == (Sample::I_ADAPTIVE_BUFFER_SIZE - 1)
                        ) {
                            Vec3 v_average = v_pixel * (1.0f/(i_ray_count + 1));

                            Vec3 v_last    = av_samples[0];
                            for (int s = 1; s < Sample::I_ADAPTIVE_BUFFER_SIZE; ++s) {
                                v_last += av_samples[s];
                            }

                            v_last = v_last * (1.0f/Sample::I_ADAPTIVE_BUFFER_SIZE) - v_average;

                            float32 f_dot_sum = v_last ^ v_last;

                            if (f_dot_sum < Sample::F_RGB_SIMILARITY_LIMIT) {
                                v_pixel *= (float32)I_MAX_RAYS / (float32)(i_ray_count + 1);
                                break;
                            }
                        }
                    }

                    i_min_adaptive_ray_count = i_ray_count >> 1;
                    if (i_min_adaptive_ray_count < Sample::I_ADAPTIVE_BUFFER_SIZE) {
                        i_min_adaptive_ray_count = Sample::I_ADAPTIVE_BUFFER_SIZE;
                    }
                    v_pixel *= F_SAMPLE_SCALE;

                } else {
                    v_pixel = Material::shadeSky(v_probe_direction) * (I_MAX_RAYS * F_SAMPLE_SCALE);
                }

                v_pixel += Scene::V_AMBIENT_RGB;

                // Convert to integers and push out to ppm output stream
                std::fprintf(
                    r_out,
                    "%c%c%c",
                    (int)v_pixel.x,
                    (int)v_pixel.y,
                    (int)v_pixel.z
                );
            }
        }


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
