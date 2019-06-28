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

///////////////////////////////////////////////////////////////////////////////
//
// Vector 3 type
//
///////////////////////////////////////////////////////////////////////////////

typedef float32 vec4f __attribute__ ((vector_size (16)));

#ifdef PASS_BY_REF
    typedef const vec4f& cvr;
#else
    typedef const vec4f cvr;
#endif

// Sum two vec4f
inline vec4f vec_add(cvr v1, cvr v2) {
    return v1 + v2;
}

// Subtract two vec4f
inline vec4f vec_sub(cvr v1, cvr v2) {
    return v1 - v2;
}

// Scale a vec4f by a float
inline vec4f vec_scale(cvr v, float32 s) {
    return s * v;
}

// Get a normalised vec4f
inline vec4f vec_normalize(cvr v) {
    vec4f t = v*v;
    return vec_scale(v, (1.0 / sqrt(
        t[0] + t[1] + t[2]
    )));
}

// Get the dot product of two vec4f
inline float32 dot(cvr v1, cvr v2) {
    vec4f t = v1*v2;
    return t[0]+t[1]+t[2];
}

// Get the cross product for two vec4f
inline vec4f vec_cross(cvr v1, cvr v2) {
    vec4f t = {
        v1[1] * v2[2] - v1[2] * v2[1],
        v1[2] * v2[0] - v1[0] * v2[2],
        v1[0] * v2[1] - v1[1] * v2[0],
        0.0f
    };
    return t;
}

static const float32 invRM = 1.0 / RAND_MAX;

// Get a random number in the range 0.0 - 1.0
inline float32 frand() {
    return invRM * rand();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Global Data
//
///////////////////////////////////////////////////////////////////////////////

const vec4f camera_dir = {
    -6.0, -16.0, 0.0, 0
};

const vec4f focal_point = {
    17.0, 16.0, 8.0, 0
};

const vec4f normal_up = {
    0.0, 0.0, 1.0, 0
};

const vec4f sky_rgb = {
    0.7, 0.6, 1.0, 0
};

const vec4f floor_red_rgb = {
    3.0, 1.0, 1.0, 0
};

const vec4f floor_white_rgb = {
    3.0, 3.0, 3.0, 0
};

const vec4f ambient_rgb = {
    13.0f, 13.0f, 13.0f, 0.0f
};

int32 data[] = {
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

typedef enum {
    M_SKY    = 0,
    M_FLOOR  = 1,
    M_MIRROR = 2
} Material;

vec4f spheres[18*8];
int32 num_spheres = 0;

void init_spheres() {
    // Check if trace maybe hits a sphere
    for (int32 k = 19; k--;) {
        for (int32 j = 9; j--;) {
            if (data[j] & 1 << k) {
                spheres[num_spheres][0] = k;
                spheres[num_spheres][1] = 0;
                spheres[num_spheres][2] = j + 4;
                num_spheres++;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace(cvr origin, cvr direction, float32& distance, vec4f& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Since sphere volumes overlap, this version exhaustively tests every sphere to determine the
//  exact point of intersection.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace(cvr origin, cvr direction, float32& distance, vec4f& normal) {
    distance = 1e9f;

    // Assume trace hits nothing
    Material   material = M_SKY;
    float32 p = -origin[2] / direction[2];

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up,
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i<num_spheres; i++) {
        vec4f p = vec_sub(
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
                normal   = vec_normalize(
                    vec_add(p, vec_scale(direction, distance))
                ),
                material = M_MIRROR; // Returning here is fast, but we'd get z fighting
            }
        }
    }
    return material;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Material trace_nobounce(cvr origin, cvr direction, float32& distance, vec4f& normal)
//
//  General purpose trace routine that calculates the material, distance to point of intersection and the normal at the
//  point of intersection. Completely ignores sphere intersection tests. We use this routine when we know that a ray
//  cannot intersect any of the spheres in the scene,
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace_nobounce(cvr origin, cvr direction, float32& distance, vec4f& normal) {
    distance  = 1e9f;
    float32 p = -origin[2] / direction[2];

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
//  Material trace_material_only(cvr origin, cvr direction)
//
//  Shortcut version of the trace routine that only tests what material is intersected first by the ray. As the distance
//  and nprmal are not required here. if the ray hits a sphere we early exit;
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material trace_material_only(cvr origin, cvr direction, const float32 sphere_size_mod = 1.0f, const float32 floor_mod = 0.0f) {

    // Assume trace hits sky
    Material material = M_SKY;
    float32 p = -origin[2] / (direction[2] + floor_mod);

    // Check if trace maybe hits floor
    if (0.01f < p) {
        material = M_FLOOR;
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i<num_spheres; i++) {
        vec4f p = vec_sub(
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

inline vec4f sample_sky(cvr direction) {
    float32 gradient = 1.0f - direction[2];
    gradient *= gradient;
    gradient *= gradient;
    return vec_scale(
        sky_rgb, // Blueish sky colour
        gradient
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec4f sample(cvr origin, cvr direction)
//
//  Generic sampling method that uses the most expensive trace() and recursively samples when hitting a reflective
//  surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vec4f sample(cvr origin, cvr direction) {
    float32 distance;
    vec4f normal;

    // Find where the ray intersects the world
    Material material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        return sample_sky(direction);
    }

    vec4f
        intersection = vec_add(origin, vec_scale(direction, distance)),

        // Calculate the lighting vector
        light = vec_normalize(
            vec_sub(
                (vec4f){ // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f,
                    0.0f
                },
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
        intersection = vec_scale(intersection, 0.2f);
        return vec_scale(
            (
                // Compute check colour based on the position
                (int32) (ceil(intersection[0]) + ceil(intersection[1])) & 1 ?
                    floor_red_rgb : // red
                    floor_white_rgb   // white
            ),
            (lambertian * 0.2f + 0.1f)
        );
    }

    vec4f half_vector = vec_add(
        direction,
        vec_scale(
            normal,
            dot(normal, direction) * -2.0f
        )
    );

    // Compute the specular highlight power
    float32 specular = pow(dot(light, half_vector) * (lambertian > 0.0), 99.0f);

    // Hit a sphere
    return vec_add(
        (vec4f){ specular, specular, specular, 0.0f},
        vec_scale(
            sample(intersection, half_vector),
            0.75f
        )
    );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  vec4f sample_nobounce(cvr origin, cvr direction)
//
//  Tuned sample method for rays that we know will not hit a reflective surface.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vec4f sample_nobounce(cvr origin, cvr direction) {

    float32 distance;
    vec4f normal;

    // Find where the ray intersects the world
    Material material = trace_nobounce(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (material == M_SKY) {
        return sample_sky(direction);
    }

    vec4f
        intersection = vec_add(origin, vec_scale(direction, distance)),

        // Calculate the lighting vector
        light = vec_normalize(
            vec_sub(
                (vec4f){ // lighting direction, plus a bit of randomness to generate soft shadows.
                    9.0f + frand(),
                    9.0f + frand(),
                    16.0f,
                    0.0f
                },
                intersection
            )
        )
    ;

    // Calculate the lambertian illumuination factor
    float32 lambertian = dot(light, normal);
    if (lambertian < 0.0f || trace_material_only(intersection, light)) {
        lambertian = 0.0f; // in shadow
    }


    intersection = vec_scale(intersection, 0.2f);
    return vec_scale(
        (
            // Compute check colour based on the position
            (int32) (ceil(intersection[0]) + ceil(intersection[1])) & 1 ?
                floor_red_rgb : // red
                floor_white_rgb   // white
        ),
        (lambertian * 0.2f + 0.1f)
    );

}

typedef vec4f (*sampler)(cvr origin, cvr direction);

///////////////////////////////////////////////////////////////////////////////


// Main
int main() {
    int image_size = 512;
    printf("P6 %d %d 255 ", image_size, image_size);

    // camera direction vectors
    vec4f
        camera_forward = vec_normalize( // Unit forwards
            camera_dir
        ),

        camera_up = vec_scale( // Unit up - Z is up in this system
            vec_normalize(
                vec_cross(
                normal_up,
                camera_forward
                )
            ),
            0.002f
        ),

        camera_right = vec_scale( // Unit right
            vec_normalize(
                vec_cross(camera_forward, camera_up)
            ),
            0.002f
        ),

        eye_offset = vec_add( // Offset frm eye to coner of focal plane
            vec_scale(
                vec_add(camera_up, camera_right),
                -(image_size >> 1)
            ),
            camera_forward
        ),

        probe_delta = vec_add(
            camera_up,
            camera_right
        ),

        probe_origin = vec_add(
            focal_point,
            probe_delta
        )
    ;

    init_spheres();

    for (int32 y = image_size; y--;) {
        for (int32 x = image_size; x--;) {
            // Use a vector for the pixel. The values here are in the range 0.0 - 255.0 rather than the 0.0 - 1.0
            vec4f pixel = {0.0f, 0.0f, 0.0f, 0.0f};

            // Perform a material probe first. If we don't hit a sphere we can use an optimised sample function
            vec4f probe_direction = vec_normalize(
                vec_sub(
                    vec_scale(
                        vec_add(
                            vec_scale(camera_up, 0.5 + x),
                            vec_add(
                                vec_scale(camera_right, 0.5 + y),
                                eye_offset
                            )
                        ),
                        16.0f
                    ),
                    probe_delta
                )
            );

            Material material = trace_material_only(probe_origin, probe_direction, 1.15f, -0.01f);

            if (material != M_SKY) {

                sampler samplefn = (material == M_MIRROR ? sample : sample_nobounce);

                // Cast 64 rays per pixel for sampling
                for (int32 ray_count = 64; ray_count--;) {

                    // Random delta to be added for depth of field effects
                    vec4f delta = vec_add(
                        vec_scale(camera_up,    (frand() - 0.5f) * 99.0f),
                        vec_scale(camera_right, (frand() - 0.5f) * 99.0f)
                    );

                    // Accumulate the sample result into the current pixel
                    pixel  = vec_add(
                        samplefn(
                            vec_add(
                                focal_point,
                                delta
                            ),
                            vec_normalize(
                                vec_sub(
                                    vec_scale(
                                        vec_add(
                                            vec_scale(camera_up, frand() + x),
                                            vec_add(
                                                vec_scale(camera_right, frand() + y),
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

                pixel = vec_scale(pixel, 3.5f);
            } else {
                pixel = vec_scale(sample_sky(probe_direction), 64 * 3.5);
            }
            pixel = vec_add(pixel, ambient_rgb);

            // Convert to integers and push out to ppm outpu stream
            std::printf("%c%c%c", (int)pixel[0], (int)pixel[1], (int)pixel[2]);
        }
    }

  return 0;
}

