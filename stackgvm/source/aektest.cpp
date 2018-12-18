/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include <cstdio>
#include "include/gvm_core.hpp"
#include "include/gvm_codemacros.hpp"

using namespace GVM;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Data
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    g_globals              = 1, // Defines the actual symbol, the following are offsets into this set

    gv_camera_dir          = 0,
    gv_focal_point         = 3,
    gv_normal_up           = 6,
    gv_sky_rgb             = 9,
    gv_floor_red_rgb       = 12,
    gv_floor_white_rgb     = 15,
    gv_const_ambient_rgb   = 18,
    gi_bitmap              = 21,
    gi_image_size          = 30,
    gi_max_rays            = 31,
    gf_dof_scale           = 32,
    gf_dof_bias            = 33,
    gf_accum_scale         = 34,
    gf_rgb_scale           = 35,
    gf_camera_scale        = 36,
    gf_distance_max        = 37,
    gf_distance_min        = 38,
} GlobalEnum;


Scalar globals[] = {

    // Vectors
    vec3(-6.0f, -16.0f, 0.0f), // gv_camera_dir
    vec3(17.0f, 16.0f, 8.0f),  // gv_focal_point
    vec3(0.0f, 0.0f, 1.0f),    // gv_normal_up
    vec3(0.7f, 0.6f, 1.0f),    // gv_sky_rgb
    vec3(3.0f, 1.0f, 1.0f),    // gv_floor_red_rgb,
    vec3(3.0f, 3.0f, 3.0f),    // gv_floor_white_rgb
    vec3(13.0f, 13.0f, 13.0f), // gv_const_ambient_rgb

    // Bitmap
    247570, // 0111100011100010010 gv_bitmap[0]
    280596, // 1000100100000010100
    280600, // 1000100100000011000
    249748, // 0111100111110010100
    18578,  // 0000100100010010010
    18577,  // 0000100100010010001
    231184, // 0111000011100010000
    16,     // 0000000000000010000
    16,     // 0000000000000010000

    // Other Scalars
#ifdef _GVM_DEBUGGING_
    4,       // gi_image_size
    4,       // gi_max_rays
#else
    512,     // gi_image_size
    64,      // gi_max_rays
#endif
    99.0f,   // gf_dof_scale
    0.5f,    // gf_dof_bias
    16.0f,   // gf_accum_scale
    3.5f,    // gf_rgb_scale
    0.002f,  // gf_camera_scale
    1e9f,    // gf_distamce_max
    0.01f,   // gf_distance_min
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Host Functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    print_header = 1,
    print_rgb,
    shim_sample
} HostFunctionEnum;

Result hostPrintHeader(Scalar* frame) {
#ifdef _GVM_DEBUGGING_
    std::printf("OUTPUT PPM HEADER {P6 %d %d 255}\n", (int)frame[0].i, (int)frame[0].i);
#else
    //std::printf("P6 %d %d 255 ", (int)frame[0].i, (int)frame[0].i);
#endif
    return SUCCESS;
}

Result hostPrintRGB(Scalar* frame) {
#ifdef _GVM_DEBUGGING_
    std::printf("OUTPUT PPM PIXEL {%d, %d, %d}\n", (int)frame[0].f, (int)frame[1].f, (int)frame[2].f);
#else
    //std::printf("%c%c%c", (int)frame[0].f, (int)frame[1].f, (int)frame[2].f);
#endif
    return SUCCESS;
}

// This function serves as a proxy for the virtual code sample function for now
Result hostShimSample(Scalar* frame) {
    frame[0].f = 1;
    frame[1].f = 1;
    frame[2].f = 1;
    std::fprintf(
        stderr,
        "\nsample(origin:{%.6f, %.6f, %.6f}, direction:{%.6f, %.6f, %.6f}) => {%.6f, %.6f, %.6f}\n\n",
        frame[3].f, frame[4].f, frame[5].f,
        frame[6].f, frame[7].f, frame[8].f,
        frame[0].f, frame[1].f, frame[2].f
    );

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    render = 1,
    trace,
    sample
} FunctionEnum;

typedef enum {
    //
    i_render_image_size        = 0,
    f_render_camera_scale      = 1,
    v_render_camera_forward    = 2,
    v_render_camera_right      = 5,
    v_render_camera_up         = 8,
    v_render_eye_offset        = 11,
    i_render_pixel_y_pos       = 14,
    i_render_pixel_x_pos       = 15,
    i_render_ray_count         = 16,
    m_render_temp_0            = 17,
    m_render_temp_1            = 18,

    v_render_temp_0            = 19,
    v_render_temp_1            = 22,
    v_render_delta             = 25,
    v_pixel_accumulator        = 28,

    m_next_func_param_space    = 32,
    m_render_sample_return     = 32,
    v_render_origin            = 35,
    v_render_direction         = 38
} RenderLocalsEnum;

GFUNC(render) {
//  Instruction (Arguments... )                                                                     Size [breakdown]

    addr_d      (g_globals, 0)                                                                      // 3 [1, 2]


//  int image_size = 512;
//  printf("P6 %d %d 255 ", image_size, image_size);

    copy_il     (0, gi_image_size,    i_render_image_size)                                          // 3 [1, 1, 1]
    copy_ll     (i_render_image_size, m_next_func_param_space)                                      // 3 [1, 1, 1]
    hcall       (print_header)                                                                      // 3 [1, 2]


//  vec3 camera_forward = vec3_normalize( // Unit forwards
//      camera_dir
//  ),

    vnorm_il    (gv_camera_dir, v_render_camera_forward)                                            // 3 [1, 1, 1]


//  vec3 camera_up = vec3_scale( // Unit up - Z is up in this system
//      vec3_normalize(
//          vec3_cross(
//              normal_up,
//              camera_forward
//          )
//      ),
//      0.002
//  ),

    vcross_ill  (gv_normal_up,          v_render_camera_forward,    v_render_camera_up)             // 4 [1, 1, 1, 1]
    vnorm_ll    (v_render_camera_up,    v_render_camera_up)                                         // 3 [1, 1, 1]
    vfmul_lil   (v_render_camera_up,    gf_camera_scale,            v_render_camera_up)             // 4 [1, 1, 1, 1]

//  vec3 camera_right = vec3_scale( // Unit right
//      vec3_normalize(
//          vec3_cross(
//              camera_forward,
//              camera_up
//          )
//      ),
//      0.002
//  ),

    vcross_lll  (v_render_camera_forward,   v_render_camera_up,     v_render_camera_right)          // 4 [1, 1, 1, 1]
    vnorm_ll    (v_render_camera_right,     v_render_camera_right)                                  // 3 [1, 1, 1]
    vfmul_lil   (v_render_camera_right,     gf_camera_scale,        v_render_camera_right)          // 4 [1, 1, 1, 1]


//  vec3 eye_offset = vec3_add( // Offset from eye to coner of focal plane
//      vec3_scale(
//          vec3_add(
//              camera_up,
//              camera_right
//          ),
//          -(image_size >> 1)
//      ),
//      camera_forward
//  )

    // (float) -(image_size >> 1)
    load_sl     (1, m_render_temp_1)                                                                // 3 [1, 1, 1]
    lsl_lll     (i_render_image_size,   m_render_temp_1,            m_render_temp_0)                // 4 [1, 1, 1, 1]
    neg_ll      (m_render_temp_0,       m_render_temp_0)                                            // 3 [1, 1, 1]
    itof_ll     (m_render_temp_0,       m_render_temp_0)                                            // 3 [1, 1, 1]

    vadd_lll    (v_render_camera_up,    v_render_camera_right,      v_render_eye_offset)            // 4 [1, 1, 1, 1]
    vfmul_lil   (v_render_eye_offset,   m_render_temp_0,            v_render_eye_offset)            // 4 [1, 1, 1, 1]
    vadd_lll    (v_render_eye_offset,   v_render_camera_forward,    v_render_eye_offset)            // 4 [1, 1, 1, 1]
    vsub_lll    (i_render_image_size,   m_render_temp_1,            i_render_image_size)            // 4 [1, 1, 1, 1]


//  for (int32 y = image_size; y--;) {

    copy_ll     (i_render_image_size,   i_render_pixel_y_pos)                                       // 3 [1, 1, 1]

// Y LOOP TARGET

//      for (int32 x = image_size; x--;) {

    copy_ll     (i_render_image_size,   i_render_pixel_x_pos)                                       // 3 [1, 1, 1]


// X LOOP TARGET

//          vec3 pixel(13.0, 13.0, 13.0);

    vcopy_il    (gv_const_ambient_rgb,  v_pixel_accumulator)                                        // 3 [1, 1, 1]

//          for (int32 ray_count = 64; ray_count--;) {
    copy_il     (0, gi_max_rays, i_render_ray_count)                                                // 3 [1, 1, 1]

//  RAY COUNT LOOP TARGET

//          // Random delta to be added for depth of field effects
//              vec3 delta = vec3_add(
//                  vec3_scale(camera_up,    (frand() - 0.5) * 99.0),
//                  vec3_scale(camera_right, (frand() - 0.5) * 99.0)
//              );

    //                                                                                              // 32
    // v0 = vec3_scale(camera_up,    (frand() - 0.5) * 99.0)                                        // 14
    frnd_l      (m_render_temp_0)                                                                   // 2 [1, 1]
    fsub_lil    (m_render_temp_0,       gf_dof_bias,                m_render_temp_0)                // 4 [1, 1, 1, 1]
    fmul_ill    (gf_dof_scale,          m_render_temp_0,            m_render_temp_0)                // 4 [1, 1, 1, 1]
    vfmul_lll   (v_render_camera_up,    m_render_temp_0,            v_render_temp_0)                // 4 [1, 1, 1, 1]

    // delta = vec3_add(v0, vec3_scale(camera_right, (frand() - 0.5) * 99.0))                       // 18
    frnd_l      (m_render_temp_0)                                                                   // 2 [1, 1]
    fsub_lil    (m_render_temp_0,       gf_dof_bias,                m_render_temp_0)                // 4 [1, 1, 1, 1]
    fmul_ill    (gf_dof_scale,          m_render_temp_0,            m_render_temp_0)                // 4 [1, 1, 1, 1]
    vfmul_lll   (v_render_camera_right, m_render_temp_0,            v_render_temp_1)                // 4 [1, 1, 1, 1]
    vadd_lll    (v_render_temp_0,       v_render_temp_1,            v_render_delta)                 // 4 [1, 1, 1, 1]

//         // Accumulate the sample result into the current pixel
//         pixel  = vec3_add(
//           vec3_scale(
//             sample(
//               vec3_add(
//                 focal_point,
//                 delta
//               ),
//               vec3_normalize(
//                 vec3_sub(
//                   vec3_scale(
//                     vec3_add(
//                       vec3_scale(camera_up, frand() + x),
//                       vec3_add(
//                         vec3_scale(camera_right, frand() + y),
//                         eye_offset
//                       )
//                     ),
//                     16.0
//                   ),
//                   delta
//                 )
//               )
//             ),
//             3.5
//           ),
//           pixel
//         );
//       }

    //                                                                                              // 49
    // origin = vec3_add(focal_point, delta)
    vadd_ill    (gv_focal_point, v_render_delta, v_render_origin)                                   // 4 [1, 1, 1, 1]

    // v0 = vec3_add(vec3_scale(camera_right, frand() + y), eye_offset)                             // 17
    itof_ll     (i_render_pixel_y_pos,  m_render_temp_0)                                            // 3 [1, 1, 1]
    frnd_l      (m_render_temp_1)                                                                   // 2 [1, 1]
    fadd_lll    (m_render_temp_0, m_render_temp_1, m_render_temp_0)                                 // 4
    vfmul_lll   (v_render_camera_right, m_render_temp_0, v_render_temp_0)                           // 4
    vadd_lll    (v_render_temp_0, v_render_eye_offset, v_render_temp_0)                             // 4

    // v1 = vec3_scale(camera_up, frand() + x),                                                     // 13
    itof_ll     (i_render_pixel_x_pos,  m_render_temp_0)                                            // 3 [1, 1, 1]
    frnd_l      (m_render_temp_1)                                                                   // 2 [1, 1]
    fadd_lll    (m_render_temp_0, m_render_temp_1, m_render_temp_0)                                 // 4 [1, 1, 1, 1]
    vfmul_lll   (v_render_camera_up, m_render_temp_0, v_render_temp_1)                              // 4 [1, 1, 1, 1]

    // v0 = vec3_scale(vec3_add(v0, v1), 16)                                                        // 8
    vadd_lll    (v_render_temp_0, v_render_temp_1, v_render_temp_0)                                 // 4 [1, 1, 1, 1]
    vfmul_lil   (v_render_temp_0, gf_accum_scale, v_render_temp_0)                                  // 4 [1, 1, 1, 1]

    // v0 = vec3_sub(v0, delta)                                                                     // 7
    vsub_lll    (v_render_temp_0, v_render_delta, v_render_temp_0)                                  // 4 [1, 1, 1, 1]
    vnorm_ll    (v_render_temp_0, v_render_direction)                                               // 3 [1, 1, 1]

    // pixel = vec3_add(vec3_scale(sample(orign, direction)), 3.5)                                  // 11
#ifdef _GVM_DEBUGGING_
    hcall(shim_sample)                                                                              // 3 [1, 2]
#else
    call(sample)                                                                                    // 3 [1, 2]
#endif


    vfmul_lil   (m_render_sample_return, gf_rgb_scale, v_render_temp_0)                             // 4
    vadd_lll    (v_pixel_accumulator, v_render_temp_0, v_pixel_accumulator)                         // 4

//          } // ray loop

    dbnz_l      (i_render_ray_count, -11-49-32)                                                     // 4 [1, 1, 2]

//          printf("%c%c%c", (int32)pixel.x, (int32)pixel.y, (int32)pixel.z);
                                                                                                    // 6
    vcopy_ll    (v_pixel_accumulator, m_next_func_param_space)                                      // 3
    hcall       (print_rgb)                                                                         // 3 [1, 2]

//      } // x loop

    dbnn_l      (i_render_pixel_x_pos, -4-6-11-49-32-3-3)                                           // 4 [1, 1, 2]


//  } // y loop

    dbnn_l      (i_render_pixel_y_pos, -4-4-6-11-49-32-3-3-3)                                       // 4 [1, 1, 2]
    ret                                                                                             // 1
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    //
    i_trace_material        = 0,
    v_trace_origin          = 1,
    v_trace_direction       = 4,
    f_trace_distance        = 7,
    v_trace_normal          = 8,
    f_trace_p               = 11,
    f_trace_k               = 12,
    f_trace_j               = 13,
    i_trace_bitmap_row      = 14,
    v_trace_sphere          = 15,
    f_trace_zero            = 16, // Shared with v_trace_sphere[1]
    v_trace_p               = 18,
    f_trace_b               = 21,
    f_trace_eye_offset      = 22,
    f_trace_q               = 23,
    f_trace_sphere_distance = 23, // Shared with f_trace_q
    m_trace_temp_0          = 24,
    m_trace_temp_1          = 25,
    m_trace_temp_2          = 26,
    m_trace_temp_3          = 27,
} TraceLocalsEnum;

GFUNC(trace) {
// int32 trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {

    addr_d      (g_globals, 0)                                                              // 3 [1, 1, 1]

//   distance         = 1e9;
//   // Assume trace hits nothing
//   int32   material = 0;
//   float32 p = -origin.z / direction.z;
                                                                                            // Total: 11
    copy_il     (0, gf_distance_max, f_trace_distance)                                      // 4 [1, 1, 1, 1]
    load_sl     (0, i_trace_material)                                                       // 3 [1, 1, 1]
    fdiv_lll    (v_trace_origin + 2, v_trace_direction + 2, f_trace_p)                      // 4 [1, 1, 1, 1]

//   // Check if trace maybe hits floor
//   if (0.01 < p) {
//     distance = p,
//     normal   = normal_up,
//     material = 1;
//   }
                                                                                            // Total: 16
    fbge_li     (f_trace_p, gf_distance_min, 13)                                            // 4 [1, 1, 2]
    copy_ll     (f_trace_p, f_trace_distance)                                               // 3 [1, 1, 1]
    vcopy_il    (gv_normal_up, v_trace_normal)                                              // 3 [1, 1, 1]
    load_sl     (1, i_trace_material)                                                       // 3 [1, 1, 1]
    load_sl     (1, m_trace_temp_0)                                                         // 3 [1, 1, 1]

  // Check if trace maybe hits a sphere
//     for (int32 j = 9; j--;) {
//         for (int32 k = 19; k--;) {
//             if (data[j] & 1 << k) {
//                 vec3 p = vec3_sub(
//                     origin,
//                     vec3(k, 0.0, j + 4.0) // Sphere coordinate
//                 );
//
//                 float32
//                     b = dot(p, direction),
//                     eye_offset = dot(p, p) - 1.0,
//                     q = b * b - eye_offset
//                 ;
//                 if (q > 0) {
//                     float32 sphere_distance = -b - sqrt(q);
//                     if (sphere_distance < distance && sphere_distance > 0.01) {
//                         distance = sphere_distance,
//                         normal   = vec3_normalize(
//                             vec3_add(p, vec3_scale(direction, distance))
//                         ),
//                         material = 2; // Returning here is fast, but we'd get z fighting
//                     }
//                 }
//             }
//         }
//     }

    // Check if trace maybe hits a sphere                                                   // Total: 9
    load_sl     (0, f_trace_zero)                                                           // 3 [1, 1, 1]
    load_sl     (4, m_trace_temp_3)                                                         // 3 [1, 1, 1]
    load_sl     (8, f_trace_j)                                                              // 3 [1, 1, 1]

// Loop target for j                                                                        // Total: 7
    cpix_il     (0, gi_bitmap, f_trace_j, i_trace_bitmap_row)                               // 4 [1, 1, 1, 1]
    load_sl     (18, f_trace_k)                                                             // 3 [1, 1, 1]

// Loop target for k                                                                        // Total: 8
    lsl_lll     (m_trace_temp_0, f_trace_k, m_trace_temp_1)                                 // 4 [1, 1, 1, 1]
    and_lll     (m_trace_temp_1, i_trace_bitmap_row, m_trace_temp_2)                        // 4 [1, 1, 1, 1]

                                                                                            // Total: 41
    bez_l       (m_trace_temp_2, 41+15)                                                      // 4 [1, 1, 2]
    itof_ll     (f_trace_k, v_trace_sphere)                                                 // 3 [1, 1, 1]
    add_lll     (f_trace_j, m_trace_temp_3, m_trace_temp_2)                                 // 4 [1, 1, 1, 1]
    itof_ll     (m_trace_temp_2, v_trace_sphere + 2)                                        // 3 [1, 1, 1]
    vsub_lll    (v_trace_origin, v_trace_sphere, v_trace_p)                                 // 4 [1, 1, 1, 1]
    vdot_lll    (v_trace_p, v_trace_direction, f_trace_b)                                   // 4 [1, 1, 1, 1]
    itof_ll     (m_trace_temp_0, m_trace_temp_1)                                            // 3 [1, 1, 1]
    vdot_lll    (v_trace_p, v_trace_p, m_trace_temp_2)                                      // 4 [1, 1, 1, 1]
    fsub_lll    (m_trace_temp_2, m_trace_temp_1, f_trace_eye_offset)                        // 4 [1, 1, 1, 1]
    fmul_lll    (f_trace_b, f_trace_b, m_trace_temp_2)                                      // 4 [1, 1, 1, 1]
    fsub_lll    (m_trace_temp_2, f_trace_eye_offset, f_trace_q)                             // 4 [1, 1, 1, 1]

//                 if (q > 0) {
//                     float32 sphere_distance = -b - sqrt(q);
//                     if (sphere_distance < distance && sphere_distance > 0.01) {
//                         distance = sphere_distance,
//                         normal   = vec3_normalize(
//                             vec3_add(p, vec3_scale(direction, distance))
//                         ),
//                         material = 2; // Returning here is fast, but we'd get z fighting
//                     }
//                 }
                                                                                            // 15
    fbge_ll     (f_trace_zero, f_trace_q, 15)                                               // 5 [1, 1, 1, 2]
    fsqrt_ll    (f_trace_q, f_trace_q)                                                      // 3
    fadd_lll    (f_trace_b, f_trace_q, f_trace_sphere_distance)                             // 4
    fneg_ll     (f_trace_sphere_distance, f_trace_sphere_distance)                          // 3


// k--
    dbnn_l      (f_trace_k, -15-41-8)                                                      // 4 [1, 1, 2]
// j--
    dbnn_l      (f_trace_j, -4 -15-41-8 -7)                                               // 4 [1, 1, 2]

    ret
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    //
    v_sample_rgb          = 0,
    v_sample_origin       = 3,
    v_sample_direction    = 6,
    v_sample_intersection = 9,
    v_sample_light        = 12,
    v_sample_half_vector  = 15,
    i_sample_material     = 18,
    f_sample_lambertian   = 19,
    f_sample_specular     = 20,
} SampleLocalsEnum;

GFUNC(sample) {
// vec3 sample(cvr3 origin, cvr3 direction) {
//   float32 distance;
//   vec3 normal;
//
//   // Find where the ray intersects the world
//   int32 material = trace(origin, direction, distance, normal);
//
//   // Hit nothing? Sky shade
//   if (!material) {
//     float32 gradient = 1.0 - direction.z;
//     gradient *= gradient;
//     gradient *= gradient;
//     return vec3_scale(
//       sky_rgb, // Blueish sky colour
//       gradient
//     );
//   }
//
//   vec3
//     intersection = vec3_add(origin, vec3_scale(direction, distance)),
//
//     // Calculate the lighting vector
//     light = vec3_normalize(
//       vec3_sub(
//         vec3( // lighting direction, plus a bit of randomness to generate soft shadows.
//           9.0 + frand(),
//           9.0 + frand(),
//           16.0
//         ),
//         intersection
//       )
//     ),
//
//     half_vector = vec3_add(
//       direction,
//       vec3_scale(
//         normal,
//         dot(normal, direction) * -2.0
//       )
//     )
//   ;
//
//   // Calculate the lambertian illumuination factor
//   float32 lambertian = dot(light, normal);
//   if (lambertian < 0 || trace(intersection, light, distance, normal)) {
//     lambertian = 0; // in shadow
//   }
//
//   // Hit the floor plane
//   if (material & 1) {
//     intersection = vec3_scale(intersection, 0.2);
//     return vec3_scale(
//       (
//         // Compute check colour based on the position
//         (int32) (ceil(intersection.x) + ceil(intersection.y)) & 1 ?
//         floor_red_rgb : // red
//         floor_white_rgb   // white
//       ),
//       (lambertian * 0.2 + 0.1)
//     );
//   }
//
//   // Compute the specular highlight power
//   float32 specular = pow(dot(light, half_vector) * (lambertian > 0.0), 99.0);
//
//   // Hit a sphere
//   return vec3_add(
//     vec3(specular, specular, specular),
//     vec3_scale(
//       sample(intersection, half_vector),
//       0.5
//     )
//   );
// }
    load_sl (0, 0)
    load_sl (0, 1)
    load_sl (0, 2)
    ret
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BEGIN_GDATA_TABLE(globalData)
    globals
END_GDATA_TABLE

BEGIN_GHOST_TABLE(hostFunctionTable)
    hostPrintHeader,
    hostPrintRGB,
    hostShimSample
END_GHOST_TABLE

/*
    uint8* entryPoint;
    uint8  frameSize;
    uint8  returnSize;
    uint8  paramSize;
    uint8  localSize;
 */
BEGIN_GFUNC_TABLE(functionTable)
    { _gvm_render, 32,  0,  0, 32 },
    { _gvm_trace,  32,  1, 10, 21 },
    { _gvm_sample, 9,   3,  6,  0 }
END_GFUNC_TABLE


int main() {
    std::printf("Max Opcode %d\n", Opcode::_MAX);
    FloatClock t;
    Interpreter::init(100, 0, functionTable, hostFunctionTable, globalData);

    Scalar* tmp = Interpreter::stack();
    for (int i = 0; i<64; i++) {
        tmp[i].u = 0;
    }

    t.set();
    //Result result =
    Interpreter::invoke(trace);
    float32 elapsed = t.elapsed();
    Interpreter::done();
    std::printf("Took %.6f seconds\n", elapsed);
    return 0;
}
