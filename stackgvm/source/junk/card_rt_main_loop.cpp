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

typedef int int32;
typedef float float32;

///////////////////////////////////////////////////////////////////////////////

// Vector class. Replaced operator overloads with
struct vec3 {
    float32 x, y, z;

    // default constructor
    vec3() { }

    // constructor
    vec3(float32 a, float32 b, float32 c, int df=0) {
        x = a;
        y = b;
        z = c;

        if (df) {
            debug(df);
        }
    }

    void debug(int df) const {
        std::printf("{ %g, %g, %g }%s", x, y, z, (df & 2 ? "\n" : ""));
    }
};

const vec3 camera_dir(
    -6.0, -16.0, 0.0
);

const vec3 focal_point(
    17.0, 16.0, 8.0
);

const vec3 normal_up(
    0.0, 0.0, 1.0
);

const vec3 sky_rgb(
    0.7, 0.6, 1.0
);

const vec3 floor_red_rgb(
    3.0, 1.0, 1.0
);

const vec3 floor_white_rgb(
    3.0, 3.0, 3.0
);
///////////////////////////////////////////////////////////////////////////////

#ifdef NO_PASS_BY_REF
typedef const vec3 cvr3;
#else
typedef const vec3& cvr3;
#endif

///////////////////////////////////////////////////////////////////////////////

// Data - bitvector of sphere locations, 1 means a sphere, 0 means empty space
//
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
    std::printf("num_spheres:%d\n", num_spheres);
}

///////////////////////////////////////////////////////////////////////////////

// Sum two vec3
static inline vec3 vec3_add(cvr3 v1, cvr3 v2) {
    std::printf("\tvec3_add(");
    v1.debug(1);
    std::printf(", ");
    v2.debug(1);
    std::printf(") -> ");
    return vec3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z,
        2
    );
}

// Subtract two vec3
static inline vec3 vec3_sub(cvr3 v1, cvr3 v2) {
    std::printf("\tvec3_sub(");
    v1.debug(1);
    std::printf(", ");
    v2.debug(1);
    std::printf(") -> ");
    return vec3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z,
        2
    );
}

// Scale a vec3 by a float
static inline vec3 vec3_scale(cvr3 v, float32 s) {
    std::printf("\tvec3_scale(");
    v.debug(1);
    std::printf(", %g) -> ", s);
    return vec3(
        v.x * s,
        v.y * s,
        v.z * s,
        2
    );
}

// Get a normalised vec3
static inline vec3 vec3_normalize(cvr3 v) {
    std::printf("\tvec3_normalize() => ");
    return vec3_scale(v, (1.0 / sqrt(
        (v.x * v.x) +
        (v.y * v.y) +
        (v.z * v.z)
    )));
}

// Get the dot product of two vec3
static inline float32 dot(cvr3 v1, cvr3 v2) {
    std::printf("\tvec3_dot(");
    v1.debug(1);
    std::printf(", ");
    v2.debug(1);
    float32 res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    std::printf(") -> %g\n", res);
    return res;
}

// Get the cross product for two vec3
static inline vec3 vec3_cross(cvr3 v1, cvr3 v2) {
    std::printf("\tvec3_cross(");
    v1.debug(1);
    std::printf(", ");
    v2.debug(1);
    std::printf(") -> ");
    return vec3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x,
        2
    );
}

static const float32 invRM = 1.0 / RAND_MAX;

// Get a random number in the range 0.0 - 1.0
static inline float32 frand() {
    return 0.5f;//invRM * rand();
}

///////////////////////////////////////////////////////////////////////////////

const char* materials[] = {
    "sky",
    "floor",
    "sphere"
};

// Trace
int32 trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {

    std::printf(
        "\ntrace(origin:{ %g, %g, %g }, direction:{ %g, %g, %g }) : Tracing Ray...\n",
        origin.x,    origin.y,    origin.z,
        direction.x, direction.y, direction.z
    );

    distance         = 1e9f;

    // Assume trace hits nothing
    int32   material = 0;
    float32 p = -origin.z / direction.z;

    // Check if trace maybe hits floor
    if (0.01f < p) {
        distance = p,
        normal   = normal_up,
        material = 1;
        std::printf("trace(): Ray will intersect floor at distance %g if not occluded...\n", p);
    } else {
        std::printf("trace(): Ray will intersect sky at distance %g if not occluded...\n", p);
    }

    // Check if trace maybe hits a sphere
    for (int i = 0; i<num_spheres; i++) {
        std::printf("trace(): Checking sphere %d for occlusion...\n", i);
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
            std::printf("trace(): Intersection test necessary, q = %g. Testing for ray intersection with sphere %d...\n", q, i);
            float32 sphere_distance = -b - std::sqrt(q);
            if (sphere_distance < distance && sphere_distance > 0.01f) {
                distance = sphere_distance,
                normal   = vec3_normalize(
                    vec3_add(p, vec3_scale(direction, distance))
                ),
                material = 2; // Returning here is fast, but we'd get z fighting
                std::printf("trace(): Ray intersected sphere %d\n", i);
            } else {
                std::printf("trace(): Ray did not intersect sphere %d\n", i);
            }
        } else {
            std::printf("trace(): No intesection test necessary, q = %g\n", q);
        }
    }

    std::printf("\ntrace(): Ray trace hit %s at distance %g, normal at point of intersection is ", materials[material], distance);
    normal.debug(2);
    std::printf("trace(): returning\n\n");
    return material;
}

///////////////////////////////////////////////////////////////////////////////

// Sampling
vec3 sample(cvr3 origin, cvr3 direction) {
    float32 distance;
    vec3 normal;

    std::printf(
        "\nsample(origin:{ %g, %g, %g }, direction:{ %g, %g, %g })\n",
        origin.x,    origin.y,    origin.z,
        direction.x, direction.y, direction.z
    );

    // Find where the ray intersects the world
    int32 material = trace(origin, direction, distance, normal);

    // Hit nothing? Sky shade
    if (!material) {
        std::printf("sample(): Calculating sky colour for sample...\n");
        float32 gradient = 1.0f - direction.z;
        gradient *= gradient;
        gradient *= gradient;
        std::printf("sample() : returning\n\n");
        return vec3_scale(
            sky_rgb, // Blueish sky colour
            gradient
        );
    }

    std::printf("sample(): Calculating lighting properties at point of intersection...\n");

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
        std::printf("sample(): Intersection point was in shadow\n");
    } else {
        std::printf("sample(): Intersection point was not in shadow\n");
    }

    // Hit the floor plane
    if (material & 1) {
        intersection = vec3_scale(intersection, 0.2f);

        std::printf("sample() : returning\n\n");

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

    std::printf("sample() : recursing...\n");

    // Hit a sphere
    vec3 result = vec3_add(
        vec3(specular, specular, specular),
        vec3_scale(
            sample(intersection, half_vector),
            0.5f
        )
    );

    std::printf("sample() : returning...\n\n");

    return result;
}

///////////////////////////////////////////////////////////////////////////////

int pixel_coordinates[] = {
    236, 145,   // mid sky
    377, 492,   // red floor tile, lit
    456, 477,   // white floor tile, lit
    256, 417,   // red floor tile, shadow
    202, 429,   // white floor tile, shadow
    425, 137,   // sphere, sky reflection, no specular
    425, 145,   // sphere, sky reflection, strong specular,
    295, 391,   // sphere, reflect red floor tile, lit
    280, 388,   // sphere, reflect white floor tile, lit
    237, 283,   // sphere, reflect adjacent sphere
};

const char* pixel_descriptions[] = {
    "Mid sky",
    "Red floor tile, lit",
    "White floor tile, lit",
    "Red floor tile, in shadow",
    "White floor tile, in shadow",
    "Sphere, reflecting sky, no specular",
    "Sphere, reflecting sky, strong specular",
    "Sphere, refecting red floor tile, lit",
    "Sphere, reflecting white floor tile, lit",
    "Sphere, reflecting adjacent sphere"
};

// Main
int32 main() {
    int image_size = 512;

    std::printf("Individual Pixel Trace Debugging\n");

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

    std::printf("main(): camera_forward = "); camera_forward.debug(2);
    std::printf("main(): camera_up      = "); camera_up.debug(2);
    std::printf("main(): camera_right   = "); camera_right.debug(2);
    std::printf("main(): eye_offset     = "); eye_offset.debug(2);

    init_spheres();

    std::printf("main(): Scene configuration completed.\n");

    for (int n = 0; n < sizeof(pixel_coordinates)/sizeof(int); n+=2) {

        int x = image_size - pixel_coordinates[n];
        int y = image_size - pixel_coordinates[n+1];

        std::printf(
            "\n//////////////////////////////////////////////////////////////////////////////////////////////////////\n"
            "main(): Tracing Pixel at (%d, %d), sampling \"%s\"\n",
            pixel_coordinates[n], pixel_coordinates[n+1], pixel_descriptions[n>>1]
        );

        // Random delta to be added for depth of field effects
        vec3 delta = vec3_add(
            vec3_scale(camera_up,    (frand() - 0.5f) * 99.0f),
            vec3_scale(camera_right, (frand() - 0.5f) * 99.0f)
        );

        // Accumulate the sample result into the current pixel
        vec3 pixel  = vec3_scale(
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
            64*3.5f
        );

        pixel = vec3_add(pixel, vec3(13.0f, 13.0f, 13.0f));

        // Convert to integers and push out to ppm outpu stream
        std::printf(
            "\nmain(): Pixel (%d, %d) \"%s\" final RGB => ",
            pixel_coordinates[n],
            pixel_coordinates[n+1],
            pixel_descriptions[n>>1]
        );
        pixel.debug(1);
        std::printf(": #%02X%02X%02X\n", (unsigned)pixel.x, (unsigned)pixel.y, (unsigned)pixel.z);
    }
    return 0;
}

