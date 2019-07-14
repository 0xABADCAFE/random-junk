#ifndef _AEK_HPP_
    #define _AEK_HPP

    #include <cstdlib>
    #include <cstdio>
    #include <cmath>

    #include "aek_types.hpp"
    #include "aek_vec3.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Image Configuration settings
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int     I_IMAGE_SIZE    = 1024;
const int     I_MAX_RAYS      = 256;

// Derived settings
const float32 F_IMAGE_SCALE   = 1.024f / I_IMAGE_SIZE;
const float32 F_RGB_SCALE     = 3.5f;
const float32 F_SAMPLE_SCALE  = F_RGB_SCALE * (64.0f / I_MAX_RAYS);

const float32 F_INV_RAND_MAX = 1.0f / RAND_MAX;

// Get a random number in the range 0.0 - 1.0
inline float32 frand() {
    return F_INV_RAND_MAX * rand();
}

inline float32 frand(const float32 f_min, const float32 f_max) {
    return frand() * (f_max - f_min) + f_min;
}

inline Vec3 calculateHalfVector(const Vec3& v_direction, const Vec3& v_normal) {
    return v_direction + v_normal * (v_normal ^ v_direction) * -2.0f;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    // Basic Data
    const Vec3
        V_CAMERA_DIR   (-6.0f, -16.0f,  0.0f),
        V_FOCAL_POINT  (17.0f,  16.0f,  8.0f),
        V_NORMAL_UP    ( 0.0f,   0.0f,  1.0f),
        V_AMBIENT_RGB  (13.0f,  13.0f, 13.0f),
        V_LIGHT_ORIGIN ( 9.0f,   9.0f, 16.0f)
    ;

    const float32 F_SPHERE_RADIUS = 1.0f;

    /**
     * Sphere Position map. The array of integer values defines a planar bitmap. Every bit represents a coordinate on
     * a 2D plane, each bit set to 1 will have a sphere at that coordinate.
     */
    const int32 AI_BITMAP[] = {
        247570, // 0111100011100010010
        280596, // 1000100100000010100
        280600, // 1000100100000011000
        249748, // 0111100111110010100
        18578,  // 0000100100010010010
        18577,  // 0000100100010010001
        231184, // 0111000011100010000
        16,     // 0000000000000010000
        16      // 0000000000000010000
    };

    const int32 I_BITMAP_ROWS = sizeof(AI_BITMAP)/sizeof(int32);

    // Derived constants
    const Vec3
        // Camera vectors
        V_CAMERA_FORWARD = ~V_CAMERA_DIR,
        V_CAMERA_UP      = ~(V_NORMAL_UP * V_CAMERA_FORWARD) * F_IMAGE_SCALE,
        V_CAMERA_RIGHT   = ~(V_CAMERA_FORWARD * V_CAMERA_UP) * F_IMAGE_SCALE,

        // Offset from eye to coner of focal plane
        V_EYE_OFFSET     = V_CAMERA_FORWARD + (V_CAMERA_UP + V_CAMERA_RIGHT) * -(I_IMAGE_SIZE >> 1)
    ;

    // Scene initialisation
    void init();

    // Render the Scene to a file output
    void render(std::FILE* r_out, int i_image_size);

    // Scene completion
    void done();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Material {

    // Material Kind
    typedef enum {
        I_SKY    = 0,
        I_FLOOR  = 1,
        I_MIRROR = 2
    } Kind;

    // Material properties
    const float32
        F_MIRROR_ALBEDO  = 0.75f,
        F_SPECULAR_POWER = 99.0f
    ;

    // Material Colours
    const Vec3
        V_SKY_RGB        (0.7f, 0.6f, 1.0f),
        V_TILE_RED_RGB   (3.0f, 1.0f, 1.0f),
        V_TILE_WHITE_RGB (3.0f, 3.0f, 3.0f);


    // Shading function for Sky Material
    inline Vec3 shadeSky(const Vec3& v_direction) {
        float32 f_gradient = 1.0f - v_direction.z;
        f_gradient *= f_gradient;
        f_gradient *= f_gradient;
        return V_SKY_RGB * f_gradient;
    }


    // Shading function for Floor Material
    inline Vec3 shadeFloor(Vec3& v_intersection, float32 f_lambertian) {
        v_intersection *= 0.2f;
        return (
            // Compute check colour based on the position
            (int) (std::ceil(v_intersection.x) + std::ceil(v_intersection.y)) & 1 ?
                V_TILE_RED_RGB :
                V_TILE_WHITE_RGB
        ) * (f_lambertian * 0.2f + 0.1f);
    }


    // Shading function for Specular intensity
    inline float32 specularity(const Vec3& v_light, const Vec3& v_half_vector, float32 f_lambertian) {
        return (f_lambertian > 0.0f) ?
            std::pow((v_light ^ v_half_vector), F_SPECULAR_POWER) :
            0.0f;
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Ray
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Ray {

    // Trace a ray into the scene to determine what kind of material it hits, at what distance and what is the
    // normal (if any) to use
    Material::Kind trace(const Vec3& v_origin, const Vec3& v_direction, float32& f_distance, Vec3& v_normal);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    // Obtain a sample RGB value for a given origin and direction
    Vec3 sample(const Vec3& v_origin, const Vec3& v_direction);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Profiling
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <time.h>

namespace Profiling {

    typedef uint64 Nanotime;

    // Obtain a nanosecond precision wall time
    Nanotime mark() {
        timespec r_current;
        clock_gettime(CLOCK_MONOTONIC, &r_current);
        Nanotime u_mark = 1000000000ULL * r_current.tv_sec ;
        return   u_mark + r_current.tv_nsec;
    }
};

#endif
