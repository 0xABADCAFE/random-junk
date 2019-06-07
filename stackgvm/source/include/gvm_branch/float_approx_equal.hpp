
// Local <= Local
BCC(F_AE_LL) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (%d), %d : %e ~= %e => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(1).f,
        LOC(2).f
    );
    float32 diff = (LOC(1).f - LOC(2).f);
    if (diff > -FLT_EPSILON && diff < FLT_EPSILON) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local <= Indirect[0]
BCC(F_AE_LI0) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (i0 + %u), %d : %e ~= %e => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).f,
        IX0(2).f
    );
    float32 diff = (LOC(1).f - IX0(2).f);
    if (diff > -FLT_EPSILON && diff < FLT_EPSILON) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local <= Indirect[1]
BCC(F_AE_LI1) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (i1 + %u), %d : %e ~= %e => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        LOC(1).f,
        IX1(2).f
    );
    float32 diff = (LOC(1).f - IX1(2).f);
    if (diff > -FLT_EPSILON && diff < FLT_EPSILON) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] <= Indirect[1]
BCC(F_AE_II) {
    gvmDebugOpcode(
        "bcc ae.f (i0 + %u), (i1 + %u), %d : %e ~= %e => ",
        OPU(1),
        OPU(2),
        (int)J16(3),
        IX0(1).f,
        IX1(2).f
    );
    float32 diff = (IX0(1).f - IX1(2).f);
    if (diff > -FLT_EPSILON && diff < FLT_EPSILON) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
