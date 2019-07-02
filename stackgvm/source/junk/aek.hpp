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
static const float32 SPHERE_ALBEDO = 0.75f;

// Derived settings
static const float32 IMAGE_SCALE   = 1.024f / IMAGE_SIZE;
static const float32 RGB_SCALE     = 3.5f;
static const float32 SAMPLE_SCALE  = RGB_SCALE * (64.0f / MAX_RAYS);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Vector 3 type
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct vec3 {
    float32 x, y, z;

    // default constructor
    vec3() { }

    // constructor
    vec3(float32 a, float32 b, float32 c) {
        x = a;
        y = b;
        z = c;
    }
};

#ifdef NO_PASS_BY_REF
    typedef const vec3 cvr3;
#else
    typedef const vec3& cvr3;
#endif

typedef enum {
    M_SKY    = 0,
    M_FLOOR  = 1,
    M_MIRROR = 2
} Material;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Global Data
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const vec3 camera_dir(
    -6.0, -16.0, 0.0
);

static const vec3 focal_point(
    17.0, 16.0, 8.0
);

static const vec3 normal_up(
    0.0, 0.0, 1.0
);

static const vec3 sky_rgb(
    0.7, 0.6, 1.0
);

static const vec3 floor_red_rgb(
    3.0, 1.0, 1.0
);

static const vec3 floor_white_rgb(
    3.0, 3.0, 3.0
);

static const vec3 ambient_rgb(
    13.0, 13.0, 13.0
);

static const int32 data[] = {
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

static const float32 invRM = 1.0 / RAND_MAX;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Sum two vec3
inline vec3 vec3_add(cvr3 v1, cvr3 v2) {
    return vec3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    );
}

// Subtract two vec3
inline vec3 vec3_sub(cvr3 v1, cvr3 v2) {
    return vec3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    );
}

// Scale a vec3 by a float
inline vec3 vec3_scale(cvr3 v, float32 s) {
    return vec3(
        v.x * s,
        v.y * s,
        v.z * s
    );
}

// Get a normalised vec3
inline vec3 vec3_normalize(cvr3 v) {
    return vec3_scale(v, (1.0 / sqrt(
        (v.x * v.x) +
        (v.y * v.y) +
        (v.z * v.z)
    )));
}

// Get the dot product of two vec3
inline float32 dot(cvr3 v1, cvr3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Get the cross product for two vec3
inline vec3 vec3_cross(cvr3 v1, cvr3 v2) {
    return vec3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

// Get a random number in the range 0.0 - 1.0
inline float32 frand() {
    return invRM * rand();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal);
vec3     sample(cvr3 origin, cvr3 direction);
void     render(std::FILE* out, int image_size);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Timing
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <time.h>

class NanoTime {
    public:
        typedef uint64 Value;
        static Value mark() {
            timespec current;
            clock_gettime(CLOCK_MONOTONIC, &current);
            Value  mark = 1000000000ULL * current.tv_sec ;
            return mark + current.tv_nsec;
        }
};

#endif
