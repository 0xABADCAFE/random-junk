
// Local < Local
BCC(F_LT_LL) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_L ", %d : %e < %e => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3),
        LOC(1).f,
        LOC(2).f
    );
    if (LOC(1).f < LOC(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[0]
BCC(F_LT_LI0) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_I0 ", %d : %e < %e => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        LOC(1).f,
        IX0(2).f
    );
    if (LOC(1).f < IX0(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local < Indirect[1]
BCC(F_LT_LI1) {
    gvmDebugOpcode(
        "blt.f " OPF_L ", " OPF_I1 ", %d : %e < %e => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        LOC(1).f,
        IX1(2).f
    );
    if (LOC(1).f < IX1(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] < Indirect[1]
BCC(F_LT_II) {
    gvmDebugOpcode(
        "blt.f " OPF_I0 ", " OPF_I1 ", %d : %e < %e => ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        IX0(1).f,
        IX1(2).f
    );
    if (IX0(1).f < IX1(2).f) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
