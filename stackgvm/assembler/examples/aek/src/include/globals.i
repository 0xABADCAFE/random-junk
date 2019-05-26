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
#endif
