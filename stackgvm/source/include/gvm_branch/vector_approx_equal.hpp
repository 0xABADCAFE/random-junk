
// Local == Local
BCC(V_AE_LL) {
    vs1 = OP_LOCAL_VEC_3F(1);
    vs2 = OP_LOCAL_VEC_3F(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_L ", %d : ",
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_JUMP_OFFSET(3)
    );

    SCALAR_F
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[0]
BCC(V_AE_LI0) {
    vs1 = OP_LOCAL_VEC_3F(1);
    vs2 = OP_INDIRECT_0_VEC_3F(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_I0 ", %d : ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    SCALAR_F
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[1]
BCC(V_AE_LI1) {
    vs1 = OP_LOCAL_VEC_3F(1);
    vs2 = OP_INDIRECT_1_VEC_3F(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_I1 ", %d : ",
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    SCALAR_F
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] == Indirect[1]
BCC(V_AE_II) {
    vs1 = OP_INDIRECT_0_VEC_3F(1);
    vs2 = OP_INDIRECT_1_VEC_3F(2);
    gvmDebugOpcode(
        "bae.v " OPF_I0 ", " OPF_I1 ", %d : ",
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_JUMP_OFFSET(3)
    );
    SCALAR_F
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
