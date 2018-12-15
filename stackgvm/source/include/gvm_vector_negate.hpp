/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */
    gvmDebugOpcode(
        "\tvneg {%0.6f, %0.6f, %0.6f} => ",
        vs1[0], vs1[1], vs1[2]
    );
    vd[0] = -vs1[0];
    vd[1] = -vs1[1];
    vd[2] = -vs1[2];
    gvmDebugOpcode(
        "{%0.6f, %0.6f, %0.6f}\n",
        vd[0], vd[1], vd[2]
    );
    STEP(3);
    NEXT;

