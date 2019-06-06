
// Local !== Small Integer Literal
BCC(X_NE_LS) {
    gvmDebugOpcode(
        "bcc ne.i (%d), #%d, %d : %d != %d => ",
        OPS(1),
        S8(2),
        (int)J16(3),
        LOC(1).i,
        S8(2)
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (LOC(1).i != S8(2)) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] !== Small Integer Literal
BCC(X_NE_I0S) {
    gvmDebugOpcode(
        "bcc.i ne.i (i0 + %u), #%d, %d : %d != %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX0(1).i,
        S8(2)
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (IX0(1).i != S8(2)) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[1] !== Small Integer Literal
BCC(X_NE_I1S) {
    gvmDebugOpcode(
        "bcc ne.i (i1 + %u), #%d, %d : %d != %d => ",
        OPU(1),
        S8(2),
        (int)J16(3),
        IX1(1).i,
        S8(2)
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (IX1(1).i != S8(2)) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local !== Local
BCC(X_NE_LL) {
    gvmDebugOpcode(
        "bcc ne (%d), (%d), %d : 0x%08X != 0x%08X => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).u,
        LOC(2).u
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (LOC(1).u != LOC(2).u) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local !== Indirect[0]
BCC(X_NE_LI0) {
    gvmDebugOpcode(
        "bcc ne (%d), (i0 + %u), %d : 0x%08X != 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).u,
        IX0(2).u
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (LOC(1).u != IX0(2).u) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local !== Indirect[1]
BCC(X_NE_LI1) {
    gvmDebugOpcode(
        "bcc ne (%d), (i1 + %u), %d : 0x%08X != 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).u,
        IX1(2).u
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (LOC(1).u != IX1(2).u) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] !== Indirect[1]
BCC(X_NE_II) {
    gvmDebugOpcode(
        "bcc ne (i0 + %u), (i1 + %u), %d : 0x%08X != 0x%08X => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).u,
        IX1(2).u
    );
    // Branch to a signed 16-bit offset if two local values are not equal
    if (IX0(1).u != IX1(2).u) {
        gvmDebugJump(2);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
