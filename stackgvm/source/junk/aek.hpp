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

static const int     IMAGE_SIZE    = 1024;
static const int     MAX_RAYS      = 256;

// Derived settings
static const float32 IMAGE_SCALE   = 1.024f / IMAGE_SIZE;
static const float32 RGB_SCALE     = 3.5f;
static const float32 SAMPLE_SCALE  = RGB_SCALE * (64.0f / MAX_RAYS);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Vec3 type
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Vec3;

#ifdef NO_PASS_BY_REF
    typedef const Vec3 cvr3;
#else
    typedef const Vec3& cvr3;
#endif

class Vec3 {
    public:
    float32 x, y, z;

    // Constructors
    Vec3() { }
    Vec3(const float32 v) : x(v), y(v), z(v) { }
    Vec3(const float32 a, const float32 b, const float32 c) : x(a), y(b), z(c) { }

    // Sum two Vec3
    static Vec3 add(cvr3 v1, cvr3 v2) {
        return Vec3(
            v1.x + v2.x,
            v1.y + v2.y,
            v1.z + v2.z
        );
    }

    // Subtract two Vec3
    static Vec3 sub(cvr3 v1, cvr3 v2) {
        return Vec3(
            v1.x - v2.x,
            v1.y - v2.y,
            v1.z - v2.z
        );
    }

    // Scale a Vec3 by a float
    static Vec3 scale(cvr3 v, float32 s) {
        return Vec3(
            v.x * s,
            v.y * s,
            v.z * s
        );
    }

    // Get a normalised Vec3
    static Vec3 normalize(cvr3 v) {
        return scale(v, (1.0f / sqrt(
            (v.x * v.x) +
            (v.y * v.y) +
            (v.z * v.z)
        )));
    }

    // Get the dot product of two Vec3
    static float32 dot(cvr3 v1, cvr3 v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    // Get the cross product for two Vec3
    static Vec3 cross(cvr3 v1, cvr3 v2) {
        return Vec3(
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x
        );
    }
} __attribute__((aligned(16)));


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Scene
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Scene {

    static const Vec3 camera_dir(-6.0f, -16.0f, 0.0f);
    static const Vec3 focal_point(17.0f, 16.0f, 8.0f);
    static const Vec3 normal_up(0.0f, 0.0f, 1.0f);
    static const Vec3 ambient_rgb(13.0f, 13.0f, 13.0f);

    static const int32 bitmap[] = {
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

    // Render the Scene to a file output
    void render(std::FILE* out, int image_size);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Material {

    typedef enum {
        SKY    = 0,
        FLOOR  = 1,
        MIRROR = 2
    } Kind;

    static const float32 MIRROR_ALBEDO = 0.75f;

    static const Vec3 sky_rgb(0.7f, 0.6f, 1.0f);
    static const Vec3 tile_red_rgb(3.0f, 1.0f, 1.0f);
    static const Vec3 tile_white_rgb(3.0f, 3.0f, 3.0f);

    static inline Vec3 shadeSky(cvr3 direction) {
        float32 gradient = 1.0f - direction.z;
        gradient *= gradient;
        gradient *= gradient;
        return Vec3::scale(
            sky_rgb, // Blueish sky colour
            gradient
        );
    }

    static inline Vec3 shadeFloor(Vec3& intersection, float32 lambertian) {
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

    static inline float32 specularity(cvr3 light, cvr3 half_vector, float32 lambertian) {
        return (lambertian > 0.0f) ?
            pow(Vec3::dot(light, half_vector), 99.0f) :
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
    Material::Kind trace(cvr3 origin, cvr3 direction, float32& distance, Vec3& normal);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sample
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Sample {

    // Obtain a sample RGB value for a given origin and direction
    Vec3 sample(cvr3 origin, cvr3 direction);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Misc
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Get a random number in the range 0.0 - 1.0
inline float32 frand() {
    static const float32 invRM = 1.0 / RAND_MAX;
    return invRM * rand();
}

inline Vec3 calculateHalfVector(cvr3 direction, cvr3 normal) {
    return Vec3::add(
        direction,
        Vec3::scale(
            normal,
            Vec3::dot(normal, direction) * -2.0f
        )
    );
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
        timespec current;
        clock_gettime(CLOCK_MONOTONIC, &current);
        Nanotime mark = 1000000000ULL * current.tv_sec ;
        return   mark + current.tv_nsec;
    }
};

#endif
