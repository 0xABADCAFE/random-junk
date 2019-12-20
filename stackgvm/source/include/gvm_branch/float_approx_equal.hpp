
// Local ~= Local
BCC(F_AE_LL) {
    gvmDebugOpcode(
        "bae.f " OPF_L ", " OPF_L ", %d : %e ~= %e => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_LOCAL(2).f
    );
    sf = (OP_LOCAL(1).f - OP_LOCAL(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local ~= Indirect[0]
BCC(F_AE_LI0) {
    gvmDebugOpcode(
        "bae.f " OPF_L ", " OPF_I0 ", %d : %e ~= %e => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_INDIRECT_0(2).f
    );
    sf = (OP_LOCAL(1).f - OP_INDIRECT_0(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local ~= Indirect[1]
BCC(F_AE_LI1) {
    gvmDebugOpcode(
        "bae.f " OPF_L ", " OPF_I1 ", %d : %e ~= %e => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_INDIRECT_1(2).f
    );
    sf = (OP_LOCAL(1).f - OP_INDIRECT_1(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] ~= Indirect[1]
BCC(F_AE_II) {
    gvmDebugOpcode(
        "bae.f " OPF_I0 ", " OPF_I1 ", %d : %e ~= %e => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_INDIRECT_0(1).f,
        OP_INDIRECT_1(2).f
    );
    sf = (OP_INDIRECT_0(1).f - OP_INDIRECT_1(2).f);
    sf *= sf;
    if (sf < (FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
