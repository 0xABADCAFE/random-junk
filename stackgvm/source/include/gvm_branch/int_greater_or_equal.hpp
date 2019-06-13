
// Local >= Small Integer Literal
BCC(I_GE_LS) {
    gvmDebugOpcode(
        "bcc ge.i (%d), #%d, %d : %d >= %d => ",
        (int)OPS(1),
        (int)S8(2),
        (int)JBRA(3),
        (int)LOC(1).i,
        (int)S8(2)
    );
    if (LOC(1).i >= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] >= Small Integer Literal
BCC(I_GE_I0S) {
    gvmDebugOpcode(
        "bcc ge.i (i0 + %u), #%d, %d : %d >= %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)JBRA(3),
        (int)IX0(1).i,
        (int)S8(2)
    );
    if (IX0(1).i >= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[1] >= Small Integer Literal
BCC(I_GE_I1S) {
    gvmDebugOpcode(
        "bcc ge.i (i1 + %u), #%d, %d : %d >= %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)JBRA(3),
        (int)IX1(1).i,
        (int)S8(2)
    );
    if (IX1(1).i >= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local >= Local
BCC(I_GE_LL) {
    gvmDebugOpcode(
        "bcc ge.i (%d), (%d), %d : %d >= %d => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3),
        (int)LOC(1).i,
        (int)LOC(2).i
    );
    if (LOC(1).i >= LOC(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local >= Indirect[0]
BCC(I_GE_LI0) {
    gvmDebugOpcode(
        "bcc ge.i (%d), (i0 + %u), %d : %d >= %d => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (int)LOC(1).i,
        (int)IX0(2).i
    );
    if (LOC(1).i >= IX0(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local >= Indirect[1]
BCC(I_GE_LI1) {
    gvmDebugOpcode(
        "bcc ge.i (%d), (i1 + %u), %d : %d >= %d => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (int)LOC(1).i,
        (int)IX1(2).i
    );
    if (LOC(1).i >= IX1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] >= Indirect[1]
BCC(I_GE_II) {
    gvmDebugOpcode(
        "bcc ge.i (i0 + %u), (i1 + %u), %d : %d >= %d => ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (int)IX0(1).i,
        (int)IX1(2).i
    );
    if (IX0(1).i >= IX1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
