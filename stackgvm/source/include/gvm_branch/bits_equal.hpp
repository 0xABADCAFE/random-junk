
// Local === Small Integer Literal
BCC(X_EQ_LS) {
    gvmDebugOpcode(
        "beq.i " OPF_L ", #%d, %d : %d == %d => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_LOCAL(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_LOCAL(1).i == OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] === Small Integer Literal
BCC(X_EQ_I0S) {
    gvmDebugOpcode(
        "beq.i i0 [%u], #%d, %d : %d == %d => ",
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_INDIRECT_0(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_INDIRECT_0(1).i == OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[1] === Small Integer Literal
BCC(X_EQ_I1S) {
    gvmDebugOpcode(
        "beq.i " OPF_I1 ", #%d, %d : %d == %d => ",
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (int)OP_INDIRECT_1(1).i,
        (int)OP_LITERAL_S8(2)
    );
    if (OP_INDIRECT_1(1).i == OP_LITERAL_S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Local
BCC(X_EQ_LL) {
    gvmDebugOpcode(
        "beq " OPF_L ", " OPF_L ", %d : 0x%08X == 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_LOCAL(1).u,
        (unsigned)OP_LOCAL(2).u
    );
    if (OP_LOCAL(1).u == OP_LOCAL(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[0]
BCC(X_EQ_LI0) {
    gvmDebugOpcode(
        "beq " OPF_L ", " OPF_I0 ", %d : 0x%08X == 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_LOCAL(1).u,
        (unsigned)OP_INDIRECT_0(2).u
    );
    if (OP_LOCAL(1).u == OP_INDIRECT_0(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[1]
BCC(X_EQ_LI1) {
    gvmDebugOpcode(
        "beq " OPF_L ", " OPF_I1 ", %d : 0x%08X == 0x%08X => ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_LOCAL(1).u,
        (unsigned)OP_INDIRECT_1(2).u
    );
    if (OP_LOCAL(1).u == OP_INDIRECT_1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] == Indirect[1]
BCC(X_EQ_II) {
    gvmDebugOpcode(
        "beq " OPF_I0 ", " OPF_I1 ", %d : 0x%08X == 0x%08X => ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3),
        (unsigned)OP_INDIRECT_0(1).u,
        (unsigned)OP_INDIRECT_1(2).u
    );
    if (OP_INDIRECT_0(1).u == OP_INDIRECT_1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

