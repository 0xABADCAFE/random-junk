#ifndef _AEK_HPP_
    #define _AEK_HPP

    #include <cstdlib>
    #include <cstdio>
    #include <cmath>

    #ifdef __LP64__
        // 64-bit typedefs
        typedef signed char int8;
        typedef signed short int int16;
        typedef signed int int32;
        typedef signed long int int64;
        typedef unsigned char uint8;
        typedef unsigned short int uint16;
        typedef unsigned int uint32;
        typedef unsigned long int uint64;
        typedef float float32;
        typedef double float64;

    // Formatting Templates
        #define FS16 "hd"
        #define FU16 "hu"
        #define FS32 "d"
        #define FU32 "u"
        #define FS64 "ld"
        #define FU64 "lu"
    #else
        // 32-bit typedefs
        typedef signed char int8;
        typedef signed short int int16;
        typedef signed long int int32;
        typedef signed long long int int64;
        typedef unsigned char uint8;
        typedef unsigned short int uint16;
        typedef unsigned long int uint32;
        typedef unsigned long long int uint64;
        typedef float float32;
        typedef double float64;

        // Formatting Templates
        #define FS16 "hd"
        #define FU16 "hu"
        #define FS32 "ld"
        #define FU32 "lu"
        #define FS64 "lld"
        #define FU64 "llu"
    #endif

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Vec3 type
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Vec3 {
    public:
    float32 x, y, z;

    // Constructors
    Vec3() { }
    Vec3(const float32 v) : x(v), y(v), z(v) { }
    Vec3(const float32 a, const float32 b, const float32 c) : x(a), y(b), z(c) { }

    // Sum two Vec3
    static Vec3 add(const Vec3& v1, const Vec3& v2) {
        return Vec3(
            v1.x + v2.x,
            v1.y + v2.y,
            v1.z + v2.z
        );
    }

    // Subtract two Vec3
    static Vec3 sub(const Vec3& v1, const Vec3& v2) {
        return Vec3(
            v1.x - v2.x,
            v1.y - v2.y,
            v1.z - v2.z
        );
    }

    // Scale a Vec3 by a float
    static Vec3 scale(const Vec3& v, float32 s) {
        return Vec3(
            v.x * s,
            v.y * s,
            v.z * s
        );
    }

    // Get a normalised Vec3
    static Vec3 normalize(const Vec3& v) {
        return scale(v, (1.0f / sqrt(
            (v.x * v.x) +
            (v.y * v.y) +
            (v.z * v.z)
        )));
    }

    // Get the dot product of two Vec3
    static float32 dot(const Vec3& v1, const Vec3& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    // Get the cross product for two Vec3
    static Vec3 cross(const Vec3& v1, const Vec3& v2) {
        return Vec3(
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x
        );
    }
} __attribute__((aligned(16)));

// Get a random number in the range 0.0 - 1.0
inline float32 frand() {
    static const float32 F_INV_RAND_MAX = 1.0f / RAND_MAX;
    return F_INV_RAND_MAX * rand();
}

inline Vec3 calculateHalfVector(const Vec3& v_direction, const Vec3& v_normal) {
    return Vec3::add(
        v_direction,
        Vec3::scale(
            v_normal,
            Vec3::dot(v_normal, v_direction) * -2.0f
        )
    );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    // Basic Data
    const Vec3 V_CAMERA_DIR  (-6.0f, -16.0f,  0.0f);
    const Vec3 V_FOCAL_POINT (17.0f,  16.0f,  8.0f);
    const Vec3 V_NORMAL_UP   (0.0f,    0.0f,  1.0f);
    const Vec3 V_AMBIENT_RGB (13.0f,  13.0f, 13.0f);

    // Bitmap
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
    const float32 F_MIRROR_ALBEDO = 0.75f;

    // Material Colours
    const Vec3    V_SKY_RGB        (0.7f, 0.6f, 1.0f);
    const Vec3    V_TILE_RED_RGB   (3.0f, 1.0f, 1.0f);
    const Vec3    V_TILE_WHITE_RGB (3.0f, 3.0f, 3.0f);

    // Shading function for Sky Material
    inline Vec3 shadeSky(const Vec3& v_direction) {
        float32 f_gradient = 1.0f - v_direction.z;
        f_gradient *= f_gradient;
        f_gradient *= f_gradient;
        return Vec3::scale(
            V_SKY_RGB, // Blueish sky colour
            f_gradient
        );
    }

    // Shading function for Floor Material
    inline Vec3 shadeFloor(Vec3& v_intersection, float32 f_lambertian) {
        v_intersection = Vec3::scale(v_intersection, 0.2f);
        return Vec3::scale(
            (
                // Compute check colour based on the position
                (int) (std::ceil(v_intersection.x) + std::ceil(v_intersection.y)) & 1 ?
                    V_TILE_RED_RGB :
                    V_TILE_WHITE_RGB
            ),
            (f_lambertian * 0.2f + 0.1f)
        );
    }

    // Shading function for Specular intensity
    inline float32 specularity(const Vec3& v_light, const Vec3& v_half_vector, float32 f_lambertian) {
        return (f_lambertian > 0.0f) ?
            std::pow(Vec3::dot(v_light, v_half_vector), 99.0f) :
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
