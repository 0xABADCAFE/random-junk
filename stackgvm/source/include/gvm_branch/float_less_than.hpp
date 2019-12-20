
// Local < Local
BCC(F_LT_LL) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_L ", %d : %e < %e => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_LOCAL(2).f
    );
    if (OP_LOCAL(1).f < OP_LOCAL(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[0]
BCC(F_LT_LI0) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_I0 ", %d : %e < %e => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_INDIRECT_0(2).f
    );
    if (OP_LOCAL(1).f < OP_INDIRECT_0(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[1]
BCC(F_LT_LI1) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_I1 ", %d : %e < %e => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_LOCAL(1).f,
        OP_INDIRECT_1(2).f
    );
    if (OP_LOCAL(1).f < OP_INDIRECT_1(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] < Indirect[1]
BCC(F_LT_II) {
    gvmDebugOpcode(
        "blt.f " OPF_I0 ", " OPF_I1 ", %d : %e < %e => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        OP_INDIRECT_0(1).f,
        OP_INDIRECT_1(2).f
    );
    if (OP_INDIRECT_0(1).f < OP_INDIRECT_1(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
