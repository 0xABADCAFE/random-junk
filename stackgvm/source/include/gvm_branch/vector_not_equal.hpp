
// Local == Local
BCC(V_NE_LL) {
    us = ULOC(1);
    ud = ULOC(2);
    gvmDebugOpcode(
        "bne.v " OPF_L ", " OPF_L ", %d : ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3)
    );
    if (
        ud[0] != us[0] ||
        ud[1] != us[1] ||
        ud[2] != us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[0]
BCC(V_NE_LI0) {
    us = ULOC(1);
    ud = UIX0(2);
    gvmDebugOpcode(
        "bne.v " OPF_L ", " OPF_I0 ", %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
    );
    if (
        ud[0] != us[0] ||
        ud[1] != us[1] ||
        ud[2] != us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[1]
BCC(V_NE_LI1) {
    us = ULOC(1);
    ud = UIX1(2);
    gvmDebugOpcode(
        "bne.v " OPF_L ", " OPF_I1 ", %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
    );
    if (
        ud[0] != us[0] ||
        ud[1] != us[1] ||
        ud[2] != us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] == Indirect[1]
BCC(V_NE_II) {
    us = UIX0(1);
    ud = UIX1(2);
    gvmDebugOpcode(
        "bne.v " OPF_I0 ", " OPF_I1 ", %d : ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)JBRA(3)
    );
    if (
        ud[0] != us[0] ||
        ud[1] != us[1] ||
        ud[2] != us[2]
    ) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
