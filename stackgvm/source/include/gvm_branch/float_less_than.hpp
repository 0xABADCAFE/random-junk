
// Local < Local
BCC(F_LT_LL) {
    gvmDebugOpcode(
        "bcc lt.f (%d), (%d), %d : %e < %e => ",
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
        "bcc lt.f (%d), (i0 + %u), %d : %e < %e => ",
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
        "bcc lt.f (%d), (i1 + %u), %d : %e < %e => ",
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
        "bcc lt.f (i0 + %u), (i1 + %u), %d : %e < %e => ",
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