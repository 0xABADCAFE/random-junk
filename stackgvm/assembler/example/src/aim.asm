#include <constants_lookup.inc>
#include <actor.inc>

#define r_actor (3)
#define f_time  (4)
#define v_result (0)
#define f_time2 (5)
#define f_half_time2 (6)
#define v_temp (7)

@predictPosition(Actor* actor, float time):vector
    load   r_actor, i0
    mulf.v (i0 + v_actor_velocity), f_time, v_result
    loadc  F_LOOKUP_ONE_HALF, f_half_time2
    mul.f  f_time, f_time, f_time2
    mul.f  f_half_time2, f_time2, f_half_time2
    mulf.v (i0 + v_actor_acceleration), f_half_time2, v_temp
    add.v  v_temp, v_result, v_result
    add.v  (i0 + v_actor_position), v_result, v_result
    ret

