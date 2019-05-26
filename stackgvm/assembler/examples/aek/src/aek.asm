#include "include/globals.i"
#include "include/main.i"

@main:
    // Get the globals into i0 index for dereferencing
    addr    $aekGlobals, i0

    // Image header
    copy    (i0 + gi_image_size),  i_main_image_size
    copy    i_main_image_size,     m_next_func_param_space

    //host   @print_header

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
    //host    @print_rgb

    dbnn.i  i_main_pixel_x_pos,    .pixel
    dbnn.i  i_main_pixel_y_pos,    .scanline
    ret
