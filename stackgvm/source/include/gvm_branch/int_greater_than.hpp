
// Local > Small Integer Literal
BCC(I_GT_LS) {
    gvmDebugOpcode(
        "bcc gt.i (%d), #%d, %d : %d > %d => ",
        (int)OPS(1),
        (int)S8(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)S8(2)
    );
    if (LOC(1).i > S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] > Small Integer Literal
BCC(I_GT_I0S) {
    gvmDebugOpcode(
        "bcc gt.i (i0 + %u), #%d, %d : %d > %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX0(1).i,
        (int)S8(2)
    );
    if (IX0(1).i > S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[1] > Small Integer Literal
BCC(I_GT_I1S) {
    gvmDebugOpcode(
        "bcc gt.i (i1 + %u), #%d, %d : %d > %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX1(1).i,
        (int)S8(2)
    );
    if (IX1(1).i > S8(2)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local > Local
BCC(I_GT_LL) {
    gvmDebugOpcode(
        "bcc gt.i (%d), (%d), %d : %d > %d => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)LOC(2).i
    );
    if (LOC(1).i > LOC(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local > Indirect[0]
BCC(I_GT_LI0) {
    gvmDebugOpcode(
        "bcc gt.i (%d), (i0 + %u), %d : %d > %d => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)IX0(2).i
    );
    if (LOC(1).i > IX0(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local > Indirect[1]
BCC(I_GT_LI1) {
    gvmDebugOpcode(
        "bcc gt.i (%d), (i1 + %u), %d : %d > %d => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)IX1(2).i
    );
    if (LOC(1).i > IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] > Indirect[1]
BCC(I_GT_II) {
    gvmDebugOpcode(
        "bcc gt.i (i0 + %u), (i1 + %u), %d : %d > %d => ",
        (int)OPU(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)IX0(1).i,
        (int)IX1(2).i
    );
    if (IX0(1).i > IX1(2).i) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
