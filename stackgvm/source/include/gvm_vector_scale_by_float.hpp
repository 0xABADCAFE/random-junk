/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */
    gvmDebugOpcode(
        "{%e, %e, %e} * %e => ",
        vs1[0], vs1[1], vs1[2],
        sf
    );

    vd[0] = vs1[0] * sf;
    vd[1] = vs1[1] * sf;
    vd[2] = vs1[2] * sf;

    gvmDebugOpcode(
        "{%e, %e, %e}\n",
        vd[0], vd[1], vd[2]
    );
    STEP(4);
    NEXT;
