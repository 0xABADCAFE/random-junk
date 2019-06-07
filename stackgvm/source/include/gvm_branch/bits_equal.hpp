
// Local === Small Integer Literal
BCC(X_EQ_LS) {
    gvmDebugOpcode(
        "bcc eq.i (%d), #%d, %d : %d == %d => ",
        OPS(1),
        S8(2),
        (int)J16(3),
        LOC(1).i,
        S8(2)
    );
    if (LOC(1).i == S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] === Small Integer Literal
BCC(X_EQ_I0S) {
    gvmDebugOpcode(
        "bcc eq.i (i0 + %u), #%d, %d : %d == %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX0(1).i,
        S8(2)
    );
    if (IX0(1).i == S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[1] === Small Integer Literal
BCC(X_EQ_I1S) {
    gvmDebugOpcode(
        "bcc eq.i (i1 + %u), #%d, %d : %d == %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX1(1).i,
        S8(2)
    );
    if (IX1(1).i == S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Local
BCC(X_EQ_LL) {
    gvmDebugOpcode(
        "bcc eq (%d), (%d), %d : 0x%08X == 0x%08X => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).u,
        LOC(2).u
    );
    if (LOC(1).u == LOC(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[0]
BCC(X_EQ_LI0) {
    gvmDebugOpcode(
        "bcc eq (%d), (i0 + %u), %d : 0x%08X == 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).u,
        IX0(2).u
    );
    if (LOC(1).u == IX0(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[1]
BCC(X_EQ_LI1) {
    gvmDebugOpcode(
        "bcc eq (%d), (i1 + %u), %d : 0x%08X == 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).u,
        IX1(2).u
    );
    if (LOC(1).u == IX1(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] == Indirect[1]
BCC(X_EQ_II) {
    gvmDebugOpcode(
        "bcc eq (i0 + %u), (i1 + %u), %d : 0x%08X == 0x%08X => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).u,
        IX1(2).u
    );
    if (IX0(1).u == IX1(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
