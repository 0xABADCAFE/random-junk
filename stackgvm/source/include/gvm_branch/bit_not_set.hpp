
// Literal bit clear in Local
BCC(X_BC_SL) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_L ", %d : 0x%08X => ",
        (unsigned)U8(1),
        (int)OPS(2),
        (int)JBRA(3),
        (unsigned)LOC(2).u
    );
    if (!((1<<U8(1)) & LOC(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit clear in Indirect[0]
BCC(X_BC_SI0) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_I0 ", %d : 0x%08X => ",
        (unsigned)U8(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX0(2).u
    );
    if (!((1<<U8(1)) & IX0(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit clear in Indirect[1]
BCC(X_BC_SI1) {
    gvmDebugOpcode(
        "bbc " OPF_SU ", " OPF_I1 ", %d : 0x%08X => ",
        (unsigned)U8(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX1(2).u
    );
    if (!((1<<U8(1)) & IX1(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Local
BCC(X_BC_LL) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_L ", %d : 0x%08X => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3),
        (unsigned)LOC(2).u
    );
    if (!((1<<LOC(1).u) & LOC(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Indirect[0]
BCC(X_BC_LI0) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_I0 ", %d : 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX0(2).u
    );
    if (!((1<<LOC(1).u) & IX0(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit clear in Indirect[1]
BCC(X_BC_LI1) {
    gvmDebugOpcode(
        "bbc " OPF_L ", " OPF_I1 ", %d : 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX1(2).u
    );
    if (!((1<<LOC(1).u) & IX1(2).u)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

