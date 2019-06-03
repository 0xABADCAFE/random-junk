#include <host.i>
#include "include/defines.i"

/**
 * main()
 *
 * Main entry point
 */
@main:
    // Get the globals into i0 index for dereferencing
    addr    $aek_globals, i0

    // Image header
    copy    (i0 + gi_image_size),  i_main_image_size
    copy    i_main_image_size,     m_next_func_param_space
    host    #host_print_header

    // Camera vectprs
    norm.v  (i0 + gv_camera_dir),  v_main_camera_forward
    cross.v (i0 + gv_normal_up),   v_main_camera_forward,  v_main_camera_up
    norm.v  v_main_camera_up,      v_main_camera_up
    mulf.v  v_main_camera_up,      (i0 + gf_camera_scale), v_main_camera_up
    cross.v v_main_camera_forward, v_main_camera_up,       v_main_camera_right
    norm.v  v_main_camera_right,   v_main_camera_right
    mulf.v  v_main_camera_right,   (i0 + gf_camera_scale), v_main_camera_right
    load    #1,                    m_main_temp_1
    lsr     i_main_image_size,     m_main_temp_1,          m_main_temp_0
    neg.i   m_main_temp_0,         m_main_temp_0
    itof    m_main_temp_0,         m_main_temp_0
    add.v   v_main_camera_up,      v_main_camera_right,    v_main_eye_offset
    mulf.v  v_main_eye_offset,     m_main_temp_0,          v_main_eye_offset
    add.v   v_main_eye_offset,     v_main_camera_forward,  v_main_eye_offset
    sub.i   i_main_image_size,     m_main_temp_1,          i_main_image_size


    // Scanline loop
    copy    i_main_image_size,     i_main_pixel_y_pos

.scanline:
    copy    i_main_image_size,     i_main_pixel_x_pos

.pixel:
    copy.v  (i0 + gv_const_ambient_rgb),  v_pixel_accumulator

    // Ray loop
    copy    (i0 + gi_max_rays), i_main_ray_count

.ray:
    rnd.f   m_main_temp_0
    sub.f   m_main_temp_0,         (i0 + gf_dof_bias),    m_main_temp_0
    mul.f   (i0 + gf_dof_scale),   m_main_temp_0,         m_main_temp_0
    mulf.v  v_main_camera_up,      m_main_temp_0,         v_main_temp_0
    rnd.f   m_main_temp_0
    sub.f   m_main_temp_0,         (i0 + gf_dof_bias),    m_main_temp_0
    mul.f   (i0 + gf_dof_scale),   m_main_temp_0,         m_main_temp_0
    mulf.v  v_main_camera_right,   m_main_temp_0,         v_main_temp_1
    add.v   v_main_temp_0,         v_main_temp_1,         v_main_delta
    add.v   (i0 + gv_focal_point), v_main_delta,          v_main_origin
    itof    i_main_pixel_y_pos,    m_main_temp_0
    rnd.f   m_main_temp_1
    add.f   m_main_temp_0,         m_main_temp_1,         m_main_temp_0
    mulf.v  v_main_camera_right,   m_main_temp_0,         v_main_temp_0
    add.v   v_main_temp_0,         v_main_eye_offset,     v_main_temp_0
    itof    i_main_pixel_x_pos,    m_main_temp_0
    rnd.f   m_main_temp_1
    add.f   m_main_temp_0,         m_main_temp_1,         m_main_temp_0
    mulf.v  v_main_camera_up,      m_main_temp_0,         v_main_temp_1
    add.v   v_main_temp_0,         v_main_temp_1,         v_main_temp_0
    mulf.v  v_main_temp_0,         (i0 + gf_accum_scale), v_main_temp_0
    sub.v   v_main_temp_0,         v_main_delta,          v_main_temp_0
    norm.v  v_main_temp_0,         v_main_direction

    call    @sample

    mulf.v  m_main_sample_return,  (i0 + gf_rgb_scale),   v_main_temp_0
    add.v   v_pixel_accumulator,   v_main_temp_0,         v_pixel_accumulator
    dbnz.i  i_main_ray_count,      .ray

    copy.v  v_pixel_accumulator,   m_next_func_param_space
    host    #host_print_rgb

    dbnn.i  i_main_pixel_x_pos,    .pixel
    dbnn.i  i_main_pixel_y_pos,    .scanline
    ret

/**
 * vec3 sample(vec3 origin, vec3 direction)
 *
 * Calculates the colour value associated with a traced ray
 */
@sample: // vec3 sample(cvr3 origin, cvr3 direction)

    addr    $aek_globals, i0

    // Find where the ray intersects the world
    copy.v  v_sample_in_origin,    v_sample_origin
    copy.v  v_sample_in_direction, v_sample_direction
    call    @trace

    //   // Hit nothing? Sky shade
    bnz     i_sample_material, .notsky
        load    #1, f_sample_gradient
        itof    f_sample_gradient, f_sample_gradient
        sub.f   f_sample_gradient, vec3_z(v_sample_in_direction), f_sample_gradient
        mul.f   f_sample_gradient, f_sample_gradient, f_sample_gradient
        mul.f   f_sample_gradient, f_sample_gradient, f_sample_gradient
        mulf.v  (i0 + gv_sky_rgb), f_sample_gradient, v_sample_rgb
        ret

.notsky:
    mulf.v   v_sample_in_direction, f_sample_distnace,     v_sample_intersection
    add.v    v_sample_in_origin,    v_sample_intersection, v_sample_intersection

    // Calculate the lighting vector, adding a little randomness to x and y components
    rnd.f   f_sample_rand
    add.f   (i0 + vec3_x(gv_const_light_pos)), f_sample_rand, vec3_x(v_sample_light)
    rnd.f   f_sample_rand
    add.f   (i0 + vec3_y(gv_const_light_pos)), f_sample_rand, vec3_y(v_sample_light)
    copy    (i0 + vec3_z(gv_const_light_pos)), vec3_z(v_sample_light)
    sub.v   v_sample_light, v_sample_intersection, v_sample_light
    norm.v  v_sample_light, v_sample_light
    copy.v  v_sample_light, v_sample_temp_1

    // Calculate the lambertian illumuination factor
    dot.v   v_sample_light, v_sample_normal, f_sample_lambertian
    copy    i_sample_material, m_sample_temp_1
    load    #0, m_sample_temp_0
    clt.f   f_sample_lambertian, m_sample_temp_0, .tracetolight
        bra     .shadowed

.tracetolight:
    call    @trace
    bez     i_sample_material, .illuminated

.shadowed:
    load    #0, f_sample_lambertian

.illumuinated:

    // Hit floor or sphere?
    bbc     #0, m_sample_temp_1, .sphere
.floor:
        mul.f    (i0 + gf_point_2), f_sample_lambertian, f_sample_lambertian
        add.f    (i0 + gf_point_1), f_sample_lambertian, f_sample_lambertian
        mulf.v   v_sample_intersection, (i0 + gf_point_2), v_sample_intersection
        ceil.f   vec3_x(v_sample_intersection), m_sample_temp_0
        ceil.f   vec3_y(v_sample_intersection), m_sample_temp_1
        add.f    m_sample_temp_0, m_sample_temp_1, m_sample_temp_1
        ftoi     m_sample_temp_1, m_sample_temp_0

        bbs      #0, m_sample_temp_0, .redtile

.whitetile:
        mulf.v   (i0 + gv_floor_white_rgb), f_sample_lambertian, v_sample_rgb
        ret

.redtile:
        mulf.v   (i0 + gv_floor_red_rgb),   f_sample_lambertian, v_sample_rgb
        ret

.sphere:
    copy.v  v_sample_intersection, v_sample_temp_0
    dot.v   v_sample_normal,       v_sample_in_direction, f_sample_dot_temp
    mul.f   (i0 + gf_minus_2),     f_sample_dot_temp,     f_sample_dot_temp
    mulf.v  v_sample_normal,       f_sample_dot_temp,     v_sample_half_vector
    add.v   v_sample_in_direction, v_sample_half_vector,  v_sample_half_vector

    // Compute the specular highlight power
.specular:
    copy.v  v_sample_temp_0, v_sample_next_origin
    call    @sample
    mulf.v  v_sample_next_rgb, (i0 + gf_reflection_scale), v_sample_rgb
    load    #0, m_sample_temp_0
    cgt.f   f_sample_lambertian, m_sample_temp_0, .done
        dot.v   v_sample_temp_1,   v_sample_half_vector, f_sample_specular
        copy    (i0 + gf_specular_power), m_sample_temp_0
        pow.f   f_sample_specular, m_sample_temp_0,      f_sample_specular
        add.f   f_sample_specular, vec3_x(v_sample_rgb), vec3_x(v_sample_rgb)
        add.f   f_sample_specular, vec3_y(v_sample_rgb), vec3_y(v_sample_rgb)
        add.f   f_sample_specular, vec3_z(v_sample_rgb), vec3_z(v_sample_rgb)
.done:
    ret

/**
 * int trace(vec3 origin, vec3 direction, float& distance, vec3& normal)
 *
 * Traces a ray, returning the material kind and setting the distance to intersection and normal
 */
@trace: // int32 trace(cvr3 origin, cvr3 direction, float32& distance, vec3& normal)

    addr    $aek_globals, i0

    // Assume trace hits nothing
    copy    (i0 + gf_distance_max), f_trace_distance
    load    #0,                     i_trace_material
    div.f   vec3_z(v_trace_origin), vec3_z(v_trace_direction),  f_trace_p
    neg.f   f_trace_p, f_trace_p

    // Check if trace maybe hits floor
.checkfloor:
    clt.f   (i0 + gf_distance_min),     f_trace_p,              .checksphere
        copy    f_trace_p,              f_trace_distance
        copy.v  (i0 + gv_normal_up),    v_trace_normal
        load    #127,                   i_trace_material

    // Check if trace maybe hits a sphere
.checksphere:
    load    #1, m_trace_temp_0
    load    #0, f_trace_zero
    load    #4, m_trace_temp_3
    load    #8, f_trace_j

.nextj:
    cpix    (i0 + gi_bitmap), f_trace_j, i_trace_bitmap_row
    load    #18, f_trace_k

.nextk:
    cbs     f_trace_k, i_trace_bitmap_row, .nextsphere
        load    #0,             vec3_y(v_trace_sphere)
        itof    f_trace_k,      vec3_x(v_trace_sphere)
        add.i   f_trace_j,      m_trace_temp_3,         m_trace_temp_2
        itof    m_trace_temp_2, vec3_z(v_trace_sphere)
        sub.v   v_trace_origin, v_trace_sphere,         v_trace_p
        dot.v   v_trace_p,      v_trace_direction,      f_trace_b
        itof    m_trace_temp_0, m_trace_temp_1
        dot.v   v_trace_p,      v_trace_p,              m_trace_temp_2
        sub.v   m_trace_temp_2, m_trace_temp_1,         f_trace_eye_offset
        mul.f   f_trace_b,      f_trace_b,              m_trace_temp_2
        sub.f   m_trace_temp_2, f_trace_eye_offset,     f_trace_q

        cgt.f   f_trace_q,      f_trace_zero,           .nextsphere
            sqrt.f  f_trace_q,               f_trace_q
            add.f   f_trace_b, f_trace_q,    f_trace_sphere_distance
            neg.f   f_trace_sphere_distance, f_trace_sphere_distance

            clt.f   f_trace_sphere_distance, f_trace_distance, .nextsphere
                cgt.f   f_trace_sphere_distance,    (i0 + gf_distance_min), .nextsphere
                    copy    f_trace_sphere_distance,    f_trace_distance
                    mulf.v  v_trace_direction,          f_trace_distance,   v_trace_temp
                    add.v   v_trace_temp,               v_trace_p,          v_trace_temp
                    norm.v  v_trace_temp,               v_trace_normal
                    load    #64, i_trace_material
.nextsphere:
    dbnn.i      f_trace_k, .nextk
    dbnn.i      f_trace_j, .nextj
    ret

$aek_globals:
/*
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
*/
