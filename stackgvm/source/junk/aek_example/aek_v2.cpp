#include "aek.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    const char* S_PPMNAME = "aek_v2.ppm";
    std::FILE* r_out = std::fopen(S_PPMNAME, "wb");
    if (r_out) {
        std::printf("Rendering to %s...\n", S_PPMNAME);
        Scene::init();
        Scene::render(r_out);
        Scene::done();
        std::fclose(r_out);
    } else {
        std::printf("Unable to open output file\n");
    }
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    // Dynamically allocated set of spheres
    Vec3* av_spheres    = 0;
    int   i_num_spheres = 0;

    /**
     * Scene initialisation now unpacks the awkward bitmap representation of the scene objects into an array that can
     * be directly traversed within intersection test code. Given how many times the intersection test happens, this
     * represents a large time saving over v1.
     */
    void init() {
        // Calclulate how many spheres we have, allocate space and unpack the bitmap
        av_spheres    = 0;
        i_num_spheres = 0;
        int i_column  = 0;
        for (int i = 0; i < I_BITMAP_ROWS; ++i) {
            i_num_spheres += __builtin_popcount(AI_BITMAP[i]);  // builtin, returns number of bits set in an int.
            i_column |= AI_BITMAP[i];
        }

        i_column = 8 * sizeof(int32) - __builtin_clz(i_column); // builtin, returns number of leading zeros in an int.

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
     * Vanilla trace behaviour. Traces a ray into the Scene in order to determine what is hit, at what distance and
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

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    /**
     * Vanilla sample behaviour. Traces a ray into the Scene and depending on which Material was hit, calculates an
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
     *
     */
    Vec3 sample(const Vec3& v_origin, const Vec3& v_direction) {
        float32 f_distance;
        Vec3    v_normal;

        // Find where the ray intersects the world
        Material::Kind i_material = Ray::trace(v_origin, v_direction, f_distance, v_normal);

        // Hit nothing? Sky shade
        if (Material::I_SKY == i_material) {
            return Material::shadeSky(v_direction);
        }

        Vec3
            v_intersection = v_origin + v_direction * f_distance,

            // Calculate the lighting vector
            v_light = ~(
                Vec3(
                    // lighting direction, plus a bit of randomness to generate soft shadows.
                    Scene::V_LIGHT_ORIGIN.x + frand(),
                    Scene::V_LIGHT_ORIGIN.y + frand(),
                    Scene::V_LIGHT_ORIGIN.z
                ) - v_intersection
            )
        ;

        // Calculate the lambertian illumuination factor
        float32 f_lambertian = v_light ^ v_normal;
        if (f_lambertian < 0.0f || Ray::trace(v_intersection, v_light, f_distance, v_normal)) {
            f_lambertian = 0.0f; // in shadow
        }

        // Hit the floor plane
        if (Material::I_FLOOR == i_material) {
            return Material::shadeFloor(v_intersection, f_lambertian);
        }

        Vec3 v_half_vector = v_half_vector = v_direction | v_normal;

        // Compute the specular highlight intensity
        float32 f_specular = Material::specularity(v_light, v_half_vector, f_lambertian);

        // Hit a sphere
        return Vec3(f_specular) + sample(v_intersection, v_half_vector) * Material::F_MIRROR_ALBEDO;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    /**
     * Vanilla renderPixel() behaviour. Slightly tweaked over the v1 version so that scaling of the samples happens
     * once after summation.
     */
    Vec3 renderPixel(const int x, const int y) {
        // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
        Vec3 v_pixel;

        // Cast 64 rays per pixel for sampling
        for (int ray_count = I_MAX_RAYS; ray_count--;) {

            // Random delta to be added for depth of field effects
            Vec3 v_delta =
                V_CAMERA_UP    * frand(-49.5f, 49.5f) +
                V_CAMERA_RIGHT * frand(-49.5f, 49.5f);

            // Accumulate the sample result into the current pixel
            v_pixel += Sample::sample(
                V_FOCAL_POINT + v_delta,
                ~(
                    (
                        V_CAMERA_UP    * (frand() + x) +
                        V_CAMERA_RIGHT * (frand() + y) +
                        V_EYE_OFFSET
                    ) * 16.0f - v_delta
                )
            );
        }

        // Scale the sample and add on the ambient term
        v_pixel *= F_SAMPLE_SCALE;
        v_pixel += V_AMBIENT_RGB;
        return v_pixel;
    }

    /**
     * Main render() function. Essentially this just renders the image one pixel at a time and converts the Vec3 output
     * to an integer RGB value for writing to disk.
     */
    void render(std::FILE* r_out) {
        std::fprintf(r_out, "P6 %d %d 255 ", I_IMAGE_SIZE, I_IMAGE_SIZE);

        Profiling::Nanotime u_start = Profiling::mark();

        for (int y = I_IMAGE_SIZE; y--;) {
            for (int x = I_IMAGE_SIZE; x--;) {
                Vec3 v_pixel = renderPixel(x, y);
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

        Profiling::Nanotime u_end = Profiling::mark();

        std::printf(
            "Total render() time %0.6f seconds\n",
            (float64)(u_end - u_start) / 1e9
        );
    }

}



