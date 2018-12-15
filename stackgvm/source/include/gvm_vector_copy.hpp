/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */
    gvmDebugOpcode(
        "\tvcopy {%0.6f, %0.6f, %0.6f}\n",
        ((float32*)us)[0], ((float32*)us)[1], ((float32*)us)[2]
    );
    ud[0] = us[0];
    ud[1] = us[1];
    ud[2] = us[2];
    STEP(3);
    NEXT;

