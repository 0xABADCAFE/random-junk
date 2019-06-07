
// Local > Local
BCC(F_GT_LL) {
    gvmDebugOpcode(
        "bcc gt.f (%d), (%d), %d : %e > %e => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).f,
        LOC(2).f
    );
    if (LOC(1).f > LOC(2).f) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local > Indirect[0]
BCC(F_GT_LI0) {
    gvmDebugOpcode(
        "bcc gt.f (%d), (i0 + %u), %d : %e > %e => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).f,
        IX0(2).f
    );
    if (LOC(1).f > IX0(2).f) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local > Indirect[1]
BCC(F_GT_LI1) {
    gvmDebugOpcode(
        "bcc gt.f (%d), (i1 + %u), %d : %e > %e => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).f,
        IX1(2).f
    );
    if (LOC(1).f > IX1(2).f) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] > Indirect[1]
BCC(F_GT_II) {
    gvmDebugOpcode(
        "bcc gt.f (i0 + %u), (i1 + %u), %d : %e > %e => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).f,
        IX1(2).f
    );
    if (IX0(1).f > IX1(2).f) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
