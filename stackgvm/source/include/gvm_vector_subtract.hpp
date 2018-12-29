/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */
    gvmDebugOpcode(
        "{%g, %g, %g} - {%g, %g, %g} => ",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2]
    );

    vd[0] = vs1[0] - vs2[0];
    vd[1] = vs1[1] - vs2[1];
    vd[2] = vs1[2] - vs2[2];
    gvmDebugOpcode(
        "{%g, %g, %g}",
        vd[0], vd[1], vd[2]
    );

    STEP(4);
    NEXT;
