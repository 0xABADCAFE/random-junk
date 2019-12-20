
// Local == Local
BCC(V_AE_LL) {
    vs1 = VLOC(1);
    vs2 = VLOC(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_L ", %d : ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3)
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
    vs1 = VLOC(1);
    vs2 = VIX0(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_I0 ", %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
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
    vs1 = VLOC(1);
    vs2 = VIX1(2);
    gvmDebugOpcode(
        "bae.v " OPF_L ", " OPF_I1 ", %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
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
    vs1 = VIX0(1);
    vs2 = VIX1(2);
    gvmDebugOpcode(
        "bae.v " OPF_I0 ", " OPF_I1 ", %d : ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
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
