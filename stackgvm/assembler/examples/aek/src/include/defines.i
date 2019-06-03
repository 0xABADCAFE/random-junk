#ifndef _GLOBALS_I_
    #define _GLOBALS_I_

    // Offsets into the global data segment
    #define gv_camera_dir        0
    #define gv_focal_point       3
    #define gv_normal_up         6
    #define gv_sky_rgb           9
    #define gv_floor_red_rgb     12
    #define gv_floor_white_rgb   15
    #define gv_const_ambient_rgb 18
    #define gv_const_light_pos   21
    #define gi_bitmap            24
    #define gi_image_size        33
    #define gi_max_rays          34
    #define gf_dof_scale         35
    #define gf_dof_bias          36
    #define gf_accum_scale       37
    #define gf_rgb_scale         38
    #define gf_camera_scale      39
    #define gf_distance_max      40
    #define gf_distance_min      41
    #define gf_minus_2           42
    #define gf_point_2           43
    #define gf_point_1           44
    #define gf_reflection_scale  36
    #define gf_specular_power    35
    #define gv_temp_floor_rgb    45

    // Local stack frame variables in in main()
    #define i_main_image_size       (0)
    #define f_main_camera_scale     (1)
    #define v_main_camera_forward   (2)
    #define v_main_camera_right     (5)
    #define v_main_camera_up        (8)
    #define v_main_eye_offset       (11)
    #define i_main_pixel_y_pos      (14)
    #define i_main_pixel_x_pos      (15)
    #define i_main_ray_count        (16)
    #define m_main_temp_0           (17)
    #define m_main_temp_1           (18)
    #define v_main_temp_0           (19)
    #define v_main_temp_1           (22)
    #define v_main_delta            (25)
    #define v_pixel_accumulator     (28)
    #define m_next_func_param_space (32)
    #define m_main_sample_return    (32)
    #define v_main_origin           (35)
    #define v_main_direction        (38)

    // Local stack frame variables in sample()
    #define i_trace_material        (0)
    #define v_trace_origin          (1)
    #define v_trace_direction       (4)
    #define f_trace_distance        (7)
    #define v_trace_normal          (8)
    #define f_trace_p               (11)
    #define f_trace_k               (12)
    #define f_trace_j               (13)
    #define i_trace_bitmap_row      (14)
    #define v_trace_sphere          (15)
    #define v_trace_temp            (15) // Shared with v_trace_sphere
    #define v_trace_p               (18)
    #define f_trace_b               (21)
    #define f_trace_eye_offset      (22)
    #define f_trace_q               (23)
    #define f_trace_sphere_distance (23) // Shared with f_trace_q
    #define f_trace_zero            (24)
    #define m_trace_temp_0          (25)
    #define m_trace_temp_1          (26)
    #define m_trace_temp_2          (27)
    #define m_trace_temp_3          (28)

    // Local stack frame variables in sample()
    #define v_sample_rgb            (0)
    #define v_sample_in_origin      (3)
    #define v_sample_in_direction   (6)
    #define f_sample_gradient       (9)
    #define f_sample_rand           (9)
    #define f_sample_dot_temp       (9)
    #define m_sample_temp_0         (9)
    #define m_sample_temp_1         (10)
    #define f_sample_lambertian     (11)
    #define f_sample_specular       (12)
    #define v_sample_temp_0         (13)
    #define v_sample_temp_1         (16)
    #define m_sample_next_func_p    (32)

    #define i_sample_material       (m_sample_next_func_p + i_trace_material)
    #define v_sample_origin         (m_sample_next_func_p + v_trace_origin)
    #define v_sample_intersection   (m_sample_next_func_p + v_trace_origin)
    #define v_sample_direction      (m_sample_next_func_p + v_trace_direction)
    #define v_sample_light          (m_sample_next_func_p + v_trace_direction)
    #define f_sample_distnace       (m_sample_next_func_p + f_trace_distance)
    #define v_sample_normal         (m_sample_next_func_p + v_trace_normal)

    #define v_sample_next_rgb       (m_sample_next_func_p)
    #define v_sample_next_origin    (m_sample_next_func_p + v_sample_in_origin)
    #define v_sample_next_direction (m_sample_next_func_p + v_sample_in_direction)
    #define v_sample_half_vector    (m_sample_next_func_p + v_sample_in_direction)

#endif
