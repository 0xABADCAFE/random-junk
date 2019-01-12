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
    16,//247570, // 0111100011100010010 gv_bitmap[0]
    32,//280596, // 1000100100000010100
    64,//280600, // 1000100100000011000
    128,//249748, // 0111100111110010100
    256,//18578,  // 0000100100010010010
    512,//18577,  // 0000100100010010001
    1024,//231184, // 0111000011100010000
    0,//16,     // 0000000000000010000
    0,//16     // 0000000000000010000

    // Other Scalars
#ifdef _GVM_DEBUGGING_
    512,       // gi_image_size
    1,       // gi_max_rays
#else
    512,     // gi_image_size
    //64,      // gi_max_rays
    1,
#endif
    99.0f,   // gf_dof_scale
    0.5f,    // gf_dof_bias
    16.0f,   // gf_accum_scale
    //3.5f,    // gf_rgb_scale
    64.f*3.5f,
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
                                                                                            // Total: 14
    copy_il     (0, gf_distance_max, f_trace_distance)                                      // 4 [1, 1, 1, 1]
    load_sl     (0, i_trace_material)                                                       // 3 [1, 1, 1]
    fdiv_lll    (v_trace_origin + 2, v_trace_direction + 2, f_trace_p)                      // 4 [1, 1, 1, 1]
    fneg_ll     (f_trace_p, f_trace_p)                                                      // 3 [1, 1, 1]

//   // Check if trace maybe hits floor
//   if (0.01 < p) {
//     distance = p,
//     normal   = normal_up,
//     material = 1;
//   }
                                                                                            // Total: 14
    fclt_il     (gf_distance_min, f_trace_p, 14)                                            // 5 [1, 1, 1, 2]
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

// Check if trace maybe hits a sphere                                                   // Total: 12
    load_sl     (1, m_trace_temp_0)                                                         // 3 [1, 1, 1]
    load_sl     (0, f_trace_zero)                                                           // 3 [1, 1, 1]
    load_sl     (4, m_trace_temp_3)                                                         // 3 [1, 1, 1]
    load_sl     (8, f_trace_j)                                                              // 3 [1, 1, 1]

// Loop target for j                                                                        // Total: 7
    cpix_il     (0, gi_bitmap, f_trace_j, i_trace_bitmap_row)                               // 4 [1, 1, 1, 1]
    load_sl     (18, f_trace_k)                                                             // 3 [1, 1, 1]

// Loop target for k                                                                        // Total:42
    cbs_ll      (f_trace_k, i_trace_bitmap_row, 42+42)                                      // 5 [1, 1, 1, 2]

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
                                                                                            // Total: 42
        fcgt_ll     (f_trace_q, f_trace_zero, 42)                                               // 5 [1, 1, 1, 2]
            fsqrt_ll    (f_trace_q, f_trace_q)                                                  // 3 [1, 1, 1]
            fadd_lll    (f_trace_b, f_trace_q, f_trace_sphere_distance)                         // 4 [1, 1, 1, 1]
            fneg_ll     (f_trace_sphere_distance, f_trace_sphere_distance)                      // 3 [1, 1, 1]

            fclt_ll     (f_trace_sphere_distance, f_trace_distance, 27)                         // 5 [1, 1, 1, 2]
                fcgt_li     (f_trace_sphere_distance, gf_distance_min, 22)                      // 5 [1, 1, 1, 2]

                    copy_ll     (f_trace_sphere_distance, f_trace_distance)                     // 3 [1, 1, 1]
                    vfmul_lll   (v_trace_direction, f_trace_distance, v_trace_temp)             // 4 [1, 1, 1, 1]
                    vadd_lll    (v_trace_temp, v_trace_p, v_trace_temp)                         // 4 [1, 1, 1, 1]
                    vnorm_ll    (v_trace_temp, v_trace_normal)                                  // 3 [1, 1, 1]
                    load_sl     (2, i_trace_material)                                           // 3 [1, 1, 1]
// k--
    dbnn_l      (f_trace_k, -42-42)                                                         // 4 [1, 1, 2]
// j--
    dbnn_l      (f_trace_j, -4 -42-42 -7)                                                   // 4 [1, 1, 2]

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
    v_sample_temp_0       = 12,
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

    addr_d      (g_globals, 0)                                                              // 3 [1, 1, 1]

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
    bnz_l   (i_sample_material, 27)                                                    // 4 [1, 1, 2]
        load_sl     (1, f_sample_gradient)                                             // 3 [1, 1, 1]
        itof_ll     (f_sample_gradient, f_sample_gradient)                             // 3
        fsub_lll    (f_sample_gradient, v_sample_in_direction+2, f_sample_gradient)    // 4
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

//   // Calculate the lambertian illumuination factor
//   float32 lambertian = dot(light, normal);

    vdot_lll    (v_sample_light, v_sample_normal, f_sample_lambertian)

//   if (lambertian < 0 || trace(intersection, light, distance, normal)) {
//     lambertian = 0; // in shadow
//   }

    copy_ll     (i_sample_material, m_sample_temp_1)
    load_sl     (0, m_sample_temp_0)

    fclt_ll     (f_sample_lambertian, m_sample_temp_0, 7)  // 5
        bras        (2+3+4)                                // 2

    call(trace)                                            // 3

    bez_l       (i_sample_material, 7)                     // 4
        load_sl     (0, f_sample_lambertian)               // 3



// TODO - if material & 1
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
    bbc_sl      (0, m_sample_temp_1, 45)                                    // 5
    fmul_ill    (gf_point_2, f_sample_lambertian, f_sample_lambertian)      // 4
    fadd_ill    (gf_point_1, f_sample_lambertian, f_sample_lambertian)      // 4
    vfmul_lil   (v_sample_intersection, gf_point_2, v_sample_intersection)  // 4
    fceil_ll    (vec3_x(v_sample_intersection), m_sample_temp_0)            // 3
    fceil_ll    (vec3_y(v_sample_intersection), m_sample_temp_1)            // 3
    fadd_lll    (m_sample_temp_0, m_sample_temp_1, m_sample_temp_1)         // 4
    ftoi_ll     (m_sample_temp_1, m_sample_temp_0)                          // 3
    bbs_sl      (0, m_sample_temp_0, 10)                                    // 5
        vfmul_ill   (gv_floor_white_rgb, f_sample_lambertian, v_sample_rgb) // 4
        ret                                                                 // 1
    vfmul_ill   (gv_floor_red_rgb, f_sample_lambertian, v_sample_rgb)       // 4
    ret                                                                     // 1


//
//     half_vector = vec3_add(
//       direction,
//       vec3_scale(
//         normal,
//         dot(normal, direction) * -2.0
//       )
//     )
//   ;

    vcopy_ll    (v_sample_intersection, v_sample_temp_0)
    vdot_lll    (v_sample_normal, v_sample_in_direction, f_sample_dot_temp)           // 4
    fmul_ill    (gf_minus_2, f_sample_dot_temp, f_sample_dot_temp)                    // 4
    vfmul_lll   (v_sample_normal, f_sample_dot_temp, v_sample_half_vector)            // 4
    vadd_lll    (v_sample_in_direction, v_sample_half_vector, v_sample_half_vector)   // 4
    vcopy_ll    (v_sample_temp_0, v_sample_next_origin)                               // 4

    call        (sample)
    vfmul_lil   (v_sample_next_rgb, gf_reflection_scale, v_sample_rgb)

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

#ifdef _GVM_DEBUGGING_

#include <cmath>

struct Vec3 {
    float32 x, y, z;

    // default constructor
    Vec3() { }

    // constructor
    Vec3(float32 a, float32 b, float32 c, int df=0) {
        x = a;
        y = b;
        z = c;

        if (df) {
            debug(df);
        }
    }

    void debug(int df) const {
        std::fprintf(stderr, "{ %g, %g, %g }%s", x, y, z, (df & 2 ? "\n" : ""));
    }
};

typedef const Vec3& cvr3;

// Sum two Vec3
static inline Vec3 vec3_add(cvr3 v1, cvr3 v2) {
    std::fprintf(stderr, "\tvec3_add(");
    v1.debug(1);
    std::fprintf(stderr, ", ");
    v2.debug(1);
    std::fprintf(stderr, ") -> ");
    return Vec3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z,
        2
    );
}

// Subtract two vec3
static inline Vec3 vec3_sub(cvr3 v1, cvr3 v2) {
    std::fprintf(stderr, "\tvec3_sub(");
    v1.debug(1);
    std::fprintf(stderr, ", ");
    v2.debug(1);
    std::fprintf(stderr, ") -> ");
    return Vec3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z,
        2
    );
}

// Scale a vec3 by a float
static inline Vec3 vec3_scale(cvr3 v, float32 s) {
    std::fprintf(stderr, "\tvec3_scale(");
    v.debug(1);
    std::fprintf(stderr, ", %g) -> ", s);
    return Vec3(
        v.x * s,
        v.y * s,
        v.z * s,
        2
    );
}

// Get a normalised Vec3
static inline Vec3 vec3_normalize(cvr3 v) {
    std::fprintf(stderr, "\tvec3_normalize() => ");
    return vec3_scale(v, (1.0 / std::sqrt(
        (v.x * v.x) +
        (v.y * v.y) +
        (v.z * v.z)
    )));
}

// Get the dot product of two Vec3
static inline float32 dot(cvr3 v1, cvr3 v2) {
    std::fprintf(stderr, "\tvec3_dot(");
    v1.debug(1);
    std::fprintf(stderr, ", ");
    v2.debug(1);
    float32 res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    std::fprintf(stderr, ") -> %g\n", res);
    return res;
}

// Get the cross product for two Vec3
static inline Vec3 vec3_cross(cvr3 v1, cvr3 v2) {
    std::fprintf(stderr, "\tvec3_cross(");
    v1.debug(1);
    std::fprintf(stderr, ", ");
    v2.debug(1);
    std::fprintf(stderr, ") -> ");
    return Vec3(
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

const Vec3 camera_dir(
    -6.0, -16.0, 0.0
);

const Vec3 focal_point(
    17.0, 16.0, 8.0
);


const Vec3 normal_up(
    0.0, 0.0, 1.0
);


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

Vec3 invokeSample(cvr3 origin, cvr3 direction) {

    std::fprintf(stderr,
        "\nsample(origin:{ %g, %g, %g }, direction:{ %g, %g, %g })\n",
        origin.x,    origin.y,    origin.z,
        direction.x, direction.y, direction.z
    );

    Scalar* tmp =  Interpreter::stack();
    tmp[0].f = 0;
    tmp[1].f = 0;
    tmp[2].f = 0;
    tmp[3].f = origin.x;
    tmp[4].f = origin.y;
    tmp[5].f = origin.z;
    tmp[6].f = direction.x;
    tmp[7].f = direction.y;
    tmp[8].f = direction.z;
    Interpreter::invoke(sample);
    return Vec3(tmp[0].f, tmp[1].f, tmp[2].f);
}

void singlePixelRenderTest() {
    int image_size = 512;

    std::fprintf(stderr, "Individual Pixel Trace Debugging\n");

    // camera direction vectors
    Vec3
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

        eye_offset = vec3_add( // Offset from eye to coner of focal plane
            vec3_scale(
                vec3_add(camera_up, camera_right),
                -(image_size >> 1)
            ),
            camera_forward
        )
    ;

    std::fprintf(stderr, "main(): camera_forward = "); camera_forward.debug(2);
    std::fprintf(stderr, "main(): camera_up      = "); camera_up.debug(2);
    std::fprintf(stderr, "main(): camera_right   = "); camera_right.debug(2);
    std::fprintf(stderr, "main(): eye_offset     = "); eye_offset.debug(2);
    std::fprintf(stderr, "main(): Scene configuration completed.\n");

    for (int n = 0; n < sizeof(pixel_coordinates)/sizeof(int); n+=2) {

        int x = image_size - pixel_coordinates[n];
        int y = image_size - pixel_coordinates[n+1];

        std::fprintf(stderr,
            "\n//////////////////////////////////////////////////////////////////////////////////////////////////////\n"
            "main(): Tracing Pixel at (%d, %d), sampling \"%s\"\n",
            pixel_coordinates[n], pixel_coordinates[n+1], pixel_descriptions[n>>1]
        );

        // Random delta to be added for depth of field effects
        Vec3 delta = vec3_add(
            vec3_scale(camera_up,    (frand() - 0.5f) * 99.0f),
            vec3_scale(camera_right, (frand() - 0.5f) * 99.0f)
        );

        // Accumulate the sample result into the current pixel
        Vec3 pixel  = vec3_scale(
            invokeSample(
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

        pixel = vec3_add(pixel, Vec3(13.0f, 13.0f, 13.0f));

        // Convert to integers and push out to ppm outpu stream
        std::fprintf(stderr,
            "\nmain(): Pixel (%d, %d) \"%s\" final RGB => ",
            pixel_coordinates[n],
            pixel_coordinates[n+1],
            pixel_descriptions[n>>1]
        );
        pixel.debug(1);
        std::fprintf(stderr, ": #%02X%02X%02X\n", (unsigned)pixel.x, (unsigned)pixel.y, (unsigned)pixel.z);
    }
}

#endif

int main() {
    std::fprintf(stderr, "Max Opcode %d\n", Opcode::_MAX);
    FloatClock t;
    Interpreter::init(128, 0, functionTable, hostFunctionTable, globalData);
    t.set();
    Result result =

#ifdef _GVM_DEBUGGING_
    GVM::EXEC_RETURN_TO_HOST;
    singlePixelRenderTest();
#else
    Interpreter::invoke(render);
#endif
    float32 elapsed = t.elapsed();
    Interpreter::done();
    std::fprintf(stderr, "Took %.6f seconds [%d]\n", elapsed, (int)result);
    return 0;
}
