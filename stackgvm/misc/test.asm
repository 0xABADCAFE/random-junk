
@aimProjectile(Actor*,Actor*,float):vector
    move   4, i0           ; load target ref into indirection register 0
    move   3, i1           ; load attacker ref into indirection register 1
    vsub   0(i0), 0(i1), 0 ; direction = target pos - attacker pos
    vmag   0, 10           ; distance = _magnitude(direction)
    fdiv   10, 5, 10       ; flightTime = distance / speed
    vscl   9(i0), 10, 0    ; direction = target velocity * flightTime
    vadd   0(i0), 0, 0     ; direction += target position
    vsub   0, 0(i1), 0     ; direction -= attacker position
    vnrm   0, 0            ; result = _normalize(direction)
    ret
