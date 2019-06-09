
// Local == Local
BCC(V_EQ_LL) {
    us = ULOC(1);
    ud = ULOC(2);
    gvmDebugOpcode(
        "bcc eq.v (%d), (%d), %d : ",
        (int)OPS(1),
        (int)OPS(2),
        (int)J16(3)
    );

    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[0]
BCC(V_EQ_LI0) {
    us = ULOC(1);
    ud = UIX0(2);
    gvmDebugOpcode(
        "bcc eq.v (%d), (i0 + %u), %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[1]
BCC(V_EQ_LI1) {
    us = ULOC(1);
    ud = UIX1(2);
    gvmDebugOpcode(
        "bcc eq.v (%d), (i1 + %u), %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] == Indirect[1]
BCC(V_EQ_II) {
    us = UIX0(1);
    ud = UIX1(2);
    gvmDebugOpcode(
        "bcc eq.v (i0 + %u), (i1 + %u), %d : ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
