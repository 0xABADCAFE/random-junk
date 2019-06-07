
// Local <= Small Integer Literal
BCC(I_LE_LS) {
    gvmDebugOpcode(
        "bcc le.i (%d), #%d, %d : %d <= %d => ",
        OPS(1),
        S8(2),
        (int)J16(3),
        LOC(1).i,
        S8(2)
    );
    if (LOC(1).i <= S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] <= Small Integer Literal
BCC(I_LE_I0S) {
    gvmDebugOpcode(
        "bcc le.i (i0 + %u), #%d, %d : %d <= %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX0(1).i,
        S8(2)
    );
    if (IX0(1).i <= S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[1] <= Small Integer Literal
BCC(I_LE_I1S) {
    gvmDebugOpcode(
        "bcc le.i (i1 + %u), #%d, %d : %d <= %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX1(1).i,
        S8(2)
    );
    if (IX1(1).i <= S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local <= Local
BCC(I_LE_LL) {
    gvmDebugOpcode(
        "bcc le.i (%d), (%d), %d : %d <= %d => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).i,
        LOC(2).i
    );
    if (LOC(1).i <= LOC(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local <= Indirect[0]
BCC(I_LE_LI0) {
    gvmDebugOpcode(
        "bcc le.i (%d), (i0 + %u), %d : %d <= %d => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).i,
        IX0(2).i
    );
    if (LOC(1).i <= IX0(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local <= Indirect[1]
BCC(I_LE_LI1) {
    gvmDebugOpcode(
        "bcc le.i (%d), (i1 + %u), %d : %d <= %d => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).i,
        IX1(2).i
    );
    if (LOC(1).i <= IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] <= Indirect[1]
BCC(I_LE_II) {
    gvmDebugOpcode(
        "bcc le.i (i0 + %u), (i1 + %u), %d : %d <= %d => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).i,
        IX1(2).i
    );
    if (IX0(1).i <= IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
