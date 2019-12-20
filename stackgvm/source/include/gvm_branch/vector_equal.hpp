
// Local == Local
BCC(V_EQ_LL) {
    us = OP_LOCAL_VEC_3(1);
    ud = OP_LOCAL_VEC_3(2);
    gvmDebugOpcode(
        "beq.v " OPF_L ", " OPF_L ", %d : ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3)
    );

    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[0]
BCC(V_EQ_LI0) {
    us = OP_LOCAL_VEC_3(1);
    ud = OP_INDIRECT_0_VEC_3(2);
    gvmDebugOpcode(
        "beq.v " OPF_L ", " OPF_I0 ", %d : ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[1]
BCC(V_EQ_LI1) {
    us = OP_LOCAL_VEC_3(1);
    ud = OP_INDIRECT_1_VEC_3(2);
    gvmDebugOpcode(
        "beq.v " OPF_L ", " OPF_I1 ", %d : ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] == Indirect[1]
BCC(V_EQ_II) {
    us = OP_INDIRECT_0_VEC_3(1);
    ud = OP_INDIRECT_1_VEC_3(2);
    gvmDebugOpcode(
        "beq.v " OPF_I0 ", " OPF_I1 ", %d : ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    if (
        ud[0] == us[0] &&
        ud[1] == us[1] &&
        ud[2] == us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
