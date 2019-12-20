
// Local < Small Integer Literal
BCC(I_LT_LS) {
    gvmDebugOpcode(
        "blt.i " OPF_L ", " OPF_S ", %d : %d < %d => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_LOCAL(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_LOCAL(1).i < OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] < Small Integer Literal
BCC(I_LT_I0S) {
    gvmDebugOpcode(
        "blt.i " OPF_I0 ", " OPF_S ", %d : %d < %d => ",
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_INDIRECT_0(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_INDIRECT_0(1).i < OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[1] < Small Integer Literal
BCC(I_LT_I1S) {
    gvmDebugOpcode(
        "blt.i " OPF_I1 ", " OPF_S ", %d : %d < %d => ",
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_INDIRECT_1(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_INDIRECT_1(1).i < OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Local
BCC(I_LT_LL) {
    gvmDebugOpcode(
        "blt.i " OPF_L ", " OPF_L ", %d : %d < %d => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_LOCAL(1).i,
        (int)OP_LOCAL(2).i
    );
    if (OP_LOCAL(1).i < OP_LOCAL(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[0]
BCC(I_LT_LI0) {
    gvmDebugOpcode(
        "blt.i " OPF_L ", " OPF_I0 ", %d : %d < %d => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_LOCAL(1).i,
        (int)OP_INDIRECT_0(2).i
    );
    if (OP_LOCAL(1).i < OP_INDIRECT_0(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[1]
BCC(I_LT_LI1) {
    gvmDebugOpcode(
        "blt.i " OPF_L ", " OPF_I1 ", %d : %d < %d => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_LOCAL(1).i,
        (int)OP_INDIRECT_1(2).i
    );
    if (OP_LOCAL(1).i < OP_INDIRECT_1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] < Indirect[1]
BCC(I_LT_II) {
    gvmDebugOpcode(
        "blt.i " OPF_I0 ", " OPF_I1 ", %d : %d < %d => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_INDIRECT_0(1).i,
        (int)OP_INDIRECT_1(2).i
    );
    if (OP_INDIRECT_0(1).i < OP_INDIRECT_1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
