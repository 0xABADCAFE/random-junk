
// Local ~= Local
BCC(F_AE_LL) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (%d), %d : %e ~= %e => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3),
        LOC(1).f,
        LOC(2).f
    );
    sf = (LOC(1).f - LOC(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local ~= Indirect[0]
BCC(F_AE_LI0) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (i0 + %u), %d : %e ~= %e => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        LOC(1).f,
        IX0(2).f
    );
    sf = (LOC(1).f - IX0(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local ~= Indirect[1]
BCC(F_AE_LI1) {
    gvmDebugOpcode(
        "bcc ae.f (%d), (i1 + %u), %d : %e ~= %e => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        LOC(1).f,
        IX1(2).f
    );
    sf = (LOC(1).f - IX1(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] ~= Indirect[1]
BCC(F_AE_II) {
    gvmDebugOpcode(
        "bcc ae.f (i0 + %u), (i1 + %u), %d : %e ~= %e => ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        IX0(1).f,
        IX1(2).f
    );
    sf = (IX0(1).f - IX1(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
