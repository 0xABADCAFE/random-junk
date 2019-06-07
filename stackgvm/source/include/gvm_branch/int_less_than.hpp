
// Local < Small Integer Literal
BCC(I_LT_LS) {
    gvmDebugOpcode(
        "bcc lt.i (%d), #%d, %d : %d < %d => ",
        OPS(1),
        S8(2),
        (int)J16(3),
        LOC(1).i,
        S8(2)
    );
    if (LOC(1).i < S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] < Small Integer Literal
BCC(I_LT_I0S) {
    gvmDebugOpcode(
        "bcc lt.i (i0 + %u), #%d, %d : %d < %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX0(1).i,
        S8(2)
    );
    if (IX0(1).i < S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[1] < Small Integer Literal
BCC(I_LT_I1S) {
    gvmDebugOpcode(
        "bcc lt.i (i1 + %u), #%d, %d : %d < %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX1(1).i,
        S8(2)
    );
    if (IX1(1).i < S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local < Local
BCC(I_LT_LL) {
    gvmDebugOpcode(
        "bcc lt.i (%d), (%d), %d : %d < %d => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).i,
        LOC(2).i
    );
    if (LOC(1).i < LOC(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local < Indirect[0]
BCC(I_LT_LI0) {
    gvmDebugOpcode(
        "bcc lt.i (%d), (i0 + %u), %d : %d < %d => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).i,
        IX0(2).i
    );
    if (LOC(1).i < IX0(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local < Indirect[1]
BCC(I_LT_LI1) {
    gvmDebugOpcode(
        "bcc lt.i (%d), (i1 + %u), %d : %d < %d => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).i,
        IX1(2).i
    );
    if (LOC(1).i < IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] < Indirect[1]
BCC(I_LT_II) {
    gvmDebugOpcode(
        "bcc lt.i (i0 + %u), (i1 + %u), %d : %d < %d => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).i,
        IX1(2).i
    );
    if (IX0(1).i < IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
