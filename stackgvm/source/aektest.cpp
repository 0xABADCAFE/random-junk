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
    gv_const_light_pos     = 21,

    gi_bitmap              = 24,
    gi_image_size          = 33,
    gi_max_rays            = 34,
    gf_dof_scale           = 35,
    gf_dof_bias            = 36,
    gf_accum_scale         = 37,
    gf_rgb_scale           = 38,
    gf_camera_scale        = 39,
    gf_distance_max        = 40,
    gf_distance_min        = 41,

    gf_minus_2             = 42,
    gf_point_2             = 43,
    gf_point_1             = 44,

    gf_reflection_scale    = 36,
    gf_specular_power      = 35,

    gv_temp_floor_rgb      = 45,

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
    vec3(9.0f, 9.0f, 16.0f),   // gv_const_light_pos

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
    512,       // gi_image_size
    1,       // gi_max_rays
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

    -2.0f,
    0.2f,
    0.1f,
    vec3(0.5f, 0.1f, 0.1f),
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Host Functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    print_header = 1,
    print_rgb,
} HostFunctionEnum;

Result hostPrintHeader(Scalar* frame) {
#ifdef _GVM_DEBUGGING_
    std::printf("OUTPUT PPM HEADER {P6 %d %d 255}\n", (int)frame[0].i, (int)frame[0].i);
#else
    std::printf("P6 %d %d 255 ", (int)frame[0].i, (int)frame[0].i);
#endif
    return SUCCESS;
}

Result hostPrintRGB(Scalar* frame) {
#ifdef _GVM_DEBUGGING_
    std::printf("OUTPUT PPM PIXEL {%d, %d, %d}\n", (int)frame[0].f, (int)frame[1].f, (int)frame[2].f);
#else
    std::printf("%c%c%c", (int)frame[0].f, (int)frame[1].f, (int)frame[2].f);
#endif
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
    lsr_lll     (i_render_image_size,   m_render_temp_1,            m_render_temp_0)                // 4 [1, 1, 1, 1]
    neg_ll      (m_render_temp_0,       m_render_temp_0)                                            // 3 [1, 1, 1]
    itof_ll     (m_render_temp_0,       m_render_temp_0)                                            // 3 [1, 1, 1]

    vadd_lll    (v_render_camera_up,    v_render_camera_right,      v_render_eye_offset)            // 4 [1, 1, 1, 1]
    vfmul_lll   (v_render_eye_offset,   m_render_temp_0,            v_render_eye_offset)            // 4 [1, 1, 1, 1]
    vadd_lll    (v_render_eye_offset,   v_render_camera_forward,    v_render_eye_offset)            // 4 [1, 1, 1, 1]
    sub_lll     (i_render_image_size,   m_render_temp_1,            i_render_image_size)            // 4 [1, 1, 1, 1]


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
    call(sample)                                                                                    // 3 [1, 2]

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
    v_trace_temp            = 15, // Shared with v_trace_sphere
    v_trace_p               = 18,
    f_trace_b               = 21,
    f_trace_eye_offset      = 22,
    f_trace_q               = 23,
    f_trace_sphere_distance = 23, // Shared with f_trace_q
    f_trace_zero            = 24,
    m_trace_temp_0          = 25,
    m_trace_temp_1          = 26,
    m_trace_temp_2          = 27,
    m_trace_temp_3          = 28,
} TraceLocalsEnum;


GFUNC(trace) {
// int32 trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal) {

    addr_d      (g_globals, 0)                                                              // 3 [1, 1, 1]

//   distance         = 1e9;
//   // Assume trace hits nothing
//   int32   material = 0;
//   float32 p = -origin.z / direction.z;
                                                                                            // Total: 14
    copy_il     (0, gf_distance_max, f_trace_distance)                                      // 4 [1, 1, 1, 1]
    load_sl     (0, i_trace_material)                                                       // 3 [1, 1, 1]
    fdiv_lll    (vec3_z(v_trace_origin ), vec3_z(v_trace_direction), f_trace_p)             // 4 [1, 1, 1, 1]
    fneg_ll     (f_trace_p, f_trace_p)                                                      // 3 [1, 1, 1]

//   // Check if trace maybe hits floor
//   if (0.01 < p) {
//     distance = p,
//     normal   = normal_up,
//     material = 1;
//   }
                                                                                            // Total: 9 + BOC_SIZE
    fclt_il     (0, gf_distance_min, f_trace_p, 9 + BOC_SIZE)                               // BOC_SIZE
        copy_ll     (f_trace_p, f_trace_distance)                                           // 3 [1, 1, 1]
        vcopy_il    (gv_normal_up, v_trace_normal)                                          // 3 [1, 1, 1]
        load_sl     (1, i_trace_material)                                                   // 3 [1, 1, 1]

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

// Check if trace maybe hits a sphere                                                       // Total: 12
    load_sl     (1, m_trace_temp_0)                                                         // 3 [1, 1, 1]
    load_sl     (0, f_trace_zero)                                                           // 3 [1, 1, 1]
    load_sl     (4, m_trace_temp_3)                                                         // 3 [1, 1, 1]
    load_sl     (8, f_trace_j)                                                              // 3 [1, 1, 1]

// Loop target for j                                                                        // Total: 7
    cpix_il     (0, gi_bitmap, f_trace_j, i_trace_bitmap_row)                               // 4 [1, 1, 1, 1]
    load_sl     (18, f_trace_k)                                                             // 3 [1, 1, 1]

// Loop target for k                                                                        // Total:40 + BOC_SIZE
    cbs_ll      (f_trace_k, i_trace_bitmap_row, (40 + BOC_SIZE) + (27 + 3*BOC_SIZE))        // BOC_SIZE

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
        load_sl     (0, vec3_y(v_trace_sphere))                                                 // 3 [1, 1, 1]
        itof_ll     (f_trace_k, vec3_x(v_trace_sphere))                                         // 3 [1, 1, 1]
        add_lll     (f_trace_j, m_trace_temp_3, m_trace_temp_2)                                 // 4 [1, 1, 1, 1]
        itof_ll     (m_trace_temp_2, vec3_z(v_trace_sphere))                                    // 3 [1, 1, 1]
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
                                                                                            // Total: 27 + 3*BOC_SIZE
        fcgt_ll     (f_trace_q, f_trace_zero, 27 + 3*BOC_SIZE)                              // BOC_SIZE
            fsqrt_ll    (f_trace_q, f_trace_q)                                              // 3 [1, 1, 1]
            fadd_lll    (f_trace_b, f_trace_q, f_trace_sphere_distance)                     // 4 [1, 1, 1, 1]
            fneg_ll     (f_trace_sphere_distance, f_trace_sphere_distance)                  // 3 [1, 1, 1]

            fclt_ll     (f_trace_sphere_distance, f_trace_distance, 17 + 2*BOC_SIZE)        // BOC_SIZE
                fcgt_li     (f_trace_sphere_distance, 0, gf_distance_min, 17 + BOC_SIZE)    // BOC_SIZE
                    copy_ll     (f_trace_sphere_distance, f_trace_distance)                 // 3 [1, 1, 1]
                    vfmul_lll   (v_trace_direction, f_trace_distance, v_trace_temp)         // 4 [1, 1, 1, 1]
                    vadd_lll    (v_trace_temp, v_trace_p, v_trace_temp)                     // 4 [1, 1, 1, 1]
                    vnorm_ll    (v_trace_temp, v_trace_normal)                              // 3 [1, 1, 1]
                    load_sl     (2, i_trace_material)                                       // 3 [1, 1, 1]
// k--
    dbnn_l      (f_trace_k, -(27 + 3*BOC_SIZE) - (40 + BOC_SIZE))                           // 4 [1, 1, 2]
// j--
    dbnn_l      (f_trace_j, -4 - (27 + 3*BOC_SIZE) - (40 + BOC_SIZE) - 7)                   // 4 [1, 1, 2]
    ret
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    //
    v_sample_rgb          = 0,
    v_sample_in_origin    = 3,
    v_sample_in_direction = 6,
    f_sample_gradient     = 9,
    f_sample_rand         = 9,
    f_sample_dot_temp     = 9,
    m_sample_temp_0       = 9,
    m_sample_temp_1       = 10,
    f_sample_lambertian   = 11,
    f_sample_specular     = 12,
    v_sample_temp_0       = 13,
    v_sample_temp_1       = 16,
    m_sample_next_func_p  = 32,

    i_sample_material     = m_sample_next_func_p + i_trace_material,
    v_sample_origin       = m_sample_next_func_p + v_trace_origin,
    v_sample_intersection = m_sample_next_func_p + v_trace_origin,
    v_sample_direction    = m_sample_next_func_p + v_trace_direction,
    v_sample_light        = m_sample_next_func_p + v_trace_direction,
    f_sample_distnace     = m_sample_next_func_p + f_trace_distance,
    v_sample_normal       = m_sample_next_func_p + v_trace_normal,

    v_sample_next_rgb       = m_sample_next_func_p,
    v_sample_next_origin    = m_sample_next_func_p + v_sample_in_origin,
    v_sample_next_direction = m_sample_next_func_p + v_sample_in_direction,
    v_sample_half_vector    = m_sample_next_func_p + v_sample_in_direction,
} SampleLocalsEnum;

GFUNC(sample) {
// vec3 sample(cvr3 origin, cvr3 direction) {

    addr_d      (g_globals, 0)                                                     // 3 [1, 1, 1]

//   float32 distance;
//   vec3 normal;
//
//   // Find where the ray intersects the world
//   int32 material = trace(origin, direction, distance, normal);

    vcopy_ll    (v_sample_in_origin,    v_sample_origin)                           // 3 [1, 1, 1]
    vcopy_ll    (v_sample_in_direction, v_sample_direction)                        // 3 [1, 1, 1]
    call(trace)                                                                    // 3 [1, 2]

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
    bne_ls  (i_sample_material, 0, 23 + BOC_SIZE)                                      // BOC_SIZE
        load_sl     (1, f_sample_gradient)                                             // 3 [1, 1, 1]
        itof_ll     (f_sample_gradient, f_sample_gradient)                             // 3
        fsub_lll    (f_sample_gradient, vec3_z(v_sample_in_direction), f_sample_gradient)    // 4
        fmul_lll    (f_sample_gradient, f_sample_gradient, f_sample_gradient)          // 4
        fmul_lll    (f_sample_gradient, f_sample_gradient, f_sample_gradient)          // 4
        vfmul_ill   (gv_sky_rgb,        f_sample_gradient, v_sample_rgb)               // 4
        ret                                                                            // 1

//   vec3
//     intersection = vec3_add(origin, vec3_scale(direction, distance)),

    vfmul_lll   (v_sample_in_direction, f_sample_distnace, v_sample_intersection)      // 4 [1, 1, 1, 1]
    vadd_lll    (v_sample_in_origin, v_sample_intersection, v_sample_intersection)     // 4 [1, 1, 1, 1]

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

    frnd_l      (f_sample_rand)                                                        // 2
    fadd_ill    (vec3_x(gv_const_light_pos), f_sample_rand, vec3_x(v_sample_light))    // 3
    frnd_l      (f_sample_rand)                                                        // 2
    fadd_ill    (vec3_y(gv_const_light_pos), f_sample_rand, vec3_y(v_sample_light))    // 3
    copy_il     (0, vec3_z(gv_const_light_pos), vec3_z(v_sample_light))                // 3
    vsub_lll    (v_sample_light, v_sample_intersection, v_sample_light)                // 4
    vnorm_ll    (v_sample_light, v_sample_light)                                       // 3
    vcopy_ll    (v_sample_light, v_sample_temp_1)

//   // Calculate the lambertian illumuination factor
//   float32 lambertian = dot(light, normal);

    vdot_lll    (v_sample_light, v_sample_normal, f_sample_lambertian)

//   if (lambertian < 0 || trace(intersection, light, distance, normal)) {
//     lambertian = 0; // in shadow
//   }

    copy_ll     (i_sample_material, m_sample_temp_1)
    load_sl     (0, m_sample_temp_0)

    //fclt_ll     (f_sample_lambertian, m_sample_temp_0, 8)  // 5
    fclt_ll     (f_sample_lambertian, m_sample_temp_0, 3 + BOC_SIZE)  // BOC_SIZE
        bra         (3 + 3 + BOC_SIZE)                                // 3

    call(trace)                                                       // 3

    beq_ls      (i_sample_material, 0, 3 + BOC_SIZE)                  // BOC_SIZE
        load_sl     (0, f_sample_lambertian)                          // 3

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
    bne_ls      (m_sample_temp_1, 1, 35 + 2*BOC_SIZE)                           // BOC_SIZE
        fmul_ill    (gf_point_2, f_sample_lambertian, f_sample_lambertian)      // 4 [1, 1, 1, 1]
        fadd_ill    (gf_point_1, f_sample_lambertian, f_sample_lambertian)      // 4 [1, 1, 1, 1]
        vfmul_lil   (v_sample_intersection, gf_point_2, v_sample_intersection)  // 4 [1, 1, 1, 1]
        fceil_ll    (vec3_x(v_sample_intersection), m_sample_temp_0)            // 3 [1, 1, 1]
        fceil_ll    (vec3_y(v_sample_intersection), m_sample_temp_1)            // 3 [1, 1, 1]
        fadd_lll    (m_sample_temp_0, m_sample_temp_1, m_sample_temp_1)         // 4 [1, 1, 1, 1]
        ftoi_ll     (m_sample_temp_1, m_sample_temp_0)                          // 3 [1, 1, 1]
        bbs_sl      (0, m_sample_temp_0, 5 + BOC_SIZE)                          // BOC_SIZE
            vfmul_ill   (gv_floor_white_rgb, f_sample_lambertian, v_sample_rgb) // 4 [1, 1, 1, 1]
            ret                                                                 // 1
        vfmul_ill   (gv_floor_red_rgb, f_sample_lambertian, v_sample_rgb)       // 4 [1, 1, 1, 1]
        ret                                                                     // 1

//     half_vector = vec3_add(
//       direction,
//       vec3_scale(
//         normal,
//         dot(normal, direction) * -2.0
//       )
//     )
//   ;

    vcopy_ll    (v_sample_intersection, v_sample_temp_0)                              // 3
    vdot_lll    (v_sample_normal, v_sample_in_direction, f_sample_dot_temp)           // 4
    fmul_ill    (gf_minus_2, f_sample_dot_temp, f_sample_dot_temp)                    // 4
    vfmul_lll   (v_sample_normal, f_sample_dot_temp, v_sample_half_vector)            // 4
    vadd_lll    (v_sample_in_direction, v_sample_half_vector, v_sample_half_vector)   // 4

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

    vcopy_ll    (v_sample_temp_0, v_sample_next_origin)                               // 4
    call        (sample)
    vfmul_lil   (v_sample_next_rgb, gf_reflection_scale, v_sample_rgb)

    load_sl     (0, m_sample_temp_0)                                                  // 3
    fcgt_ll     (f_sample_lambertian, m_sample_temp_0, 23 + BOC_SIZE)                 // BOC_SIZE
        vdot_lll    (v_sample_temp_1,   v_sample_half_vector, f_sample_specular)      // 4
        copy_il     (0, gf_specular_power, m_sample_temp_0)                           // 3
        fpow_lll    (f_sample_specular, m_sample_temp_0,    f_sample_specular)        // 4
        fadd_lll    (f_sample_specular, vec3_x(v_sample_rgb), vec3_x(v_sample_rgb))   // 4
        fadd_lll    (f_sample_specular, vec3_y(v_sample_rgb), vec3_y(v_sample_rgb))   // 4
        fadd_lll    (f_sample_specular, vec3_z(v_sample_rgb), vec3_z(v_sample_rgb))   // 4

    ret
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BEGIN_GDATA_TABLE(globalData)
    globals
END_GDATA_TABLE

BEGIN_GHOST_TABLE(hostFunctionTable)
    hostPrintHeader,
    hostPrintRGB
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
    { _gvm_sample, 32,  3,  6, 23 }
END_GFUNC_TABLE

int main() {
    std::fprintf(
        stderr,
        "Implementation Limits\n\tOpcode::_MAX %d\n\tCondition::_MAX %d\n\tExtendedAddress::_MAX %d\n",
        Opcode::_MAX,
        Condition::_MAX,
        ExtendedAddress::_MAX
    );
    FloatClock t;
    Interpreter::init(128, 0, functionTable, hostFunctionTable, globalData);
    t.set();

#ifdef _GVM_DEBUGGING_
    Scalar* tmp =  Interpreter::stack();
    tmp[0].f = 0;
    tmp[1].f = 0;
    tmp[2].f = 0;
    tmp[3].u = 0x41880000; // origin.x = 17;
    tmp[4].u = 0x41800000; // origin.y = 16;
    tmp[5].u = 0x41000000; // origin.z = 8;
    tmp[6].u = 0xBEB0712E; // direction.x = -0.344613;
    tmp[7].u = 0xBF6A8ADF; // direction.y = -0.916182;
    tmp[8].u = 0x3E517D4A; // direction.z = 0.20458;
    Result result = Interpreter::invoke(sample);
#else
    Result result = Interpreter::invoke(render);
#endif
    float32 elapsed = t.elapsed();
    Interpreter::done();
    std::fprintf(stderr, "Took %.6f seconds [%d]\n", elapsed, (int)result);
    return 0;
}
