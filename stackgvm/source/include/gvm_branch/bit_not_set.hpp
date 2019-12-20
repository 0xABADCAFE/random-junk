
// Literal bit clear in Local
BCC(X_BC_SL) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_L ", %d : 0x%08X => ",
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_LOCAL(2).u
    );
    if (!((1<<OP_LITERAL_U8(1)) & OP_LOCAL(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit clear in Indirect[0]
BCC(X_BC_SI0) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_I0 ", %d : 0x%08X => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_INDIRECT_0(2).u
    );
    if (!((1<<OP_LITERAL_U8(1)) & OP_INDIRECT_0(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit clear in Indirect[1]
BCC(X_BC_SI1) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_I1 ", %d : 0x%08X => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_INDIRECT_1(2).u
    );
    if (!((1<<OP_LITERAL_U8(1)) & OP_INDIRECT_1(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Local
BCC(X_BC_LL) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_L ", %d : 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_LOCAL(2).u
    );
    if (!((1<<OP_LOCAL(1).u) & OP_LOCAL(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Indirect[0]
BCC(X_BC_LI0) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_I0 ", %d : 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_INDIRECT_0(2).u
    );
    if (!((1<<OP_LOCAL(1).u) & OP_INDIRECT_0(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Indirect[1]
BCC(X_BC_LI1) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_I1 ", %d : 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_INDIRECT_1(2).u
    );
    if (!((1<<OP_LOCAL(1).u) & OP_INDIRECT_1(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

