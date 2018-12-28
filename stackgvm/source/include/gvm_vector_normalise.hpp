/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

    sf = 1.0f / std::sqrt(
        (vs1[0] * vs1[0]) +
        (vs1[1] * vs1[1]) +
        (vs1[2] * vs1[2])
    );
    gvmDebugOpcode(
        "{%e, %e, %e} * %.6f => ",
        vs1[0], vs1[1], vs1[2],
        sf
    );
    vd[0] = sf * vs1[0];
    vd[1] = sf * vs1[1];
    vd[2] = sf * vs1[2];
    gvmDebugOpcode(
        "{%e, %e, %e}\n",
        vd[0], vd[1], vd[2]
    );
    STEP(3);
    NEXT;

