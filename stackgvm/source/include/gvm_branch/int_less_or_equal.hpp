
// Local <= Small Integer Literal
BCC(I_LE_LS) {
    gvmDebugOpcode(
        "bcc le.i (%d), #%d, %d : %d <= %d => ",
        (int)OPS(1),
        (int)S8(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)S8(2)
    );
    if (LOC(1).i <= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] <= Small Integer Literal
BCC(I_LE_I0S) {
    gvmDebugOpcode(
        "bcc le.i (i0 + %u), #%d, %d : %d <= %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX0(1).i,
        (int)S8(2)
    );
    if (IX0(1).i <= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[1] <= Small Integer Literal
BCC(I_LE_I1S) {
    gvmDebugOpcode(
        "bcc le.i (i1 + %u), #%d, %d : %d <= %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX1(1).i,
        (int)S8(2)
    );
    if (IX1(1).i <= S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local <= Local
BCC(I_LE_LL) {
    gvmDebugOpcode(
        "bcc le.i (%d), (%d), %d : %d <= %d => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)LOC(2).i
    );
    if (LOC(1).i <= LOC(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local <= Indirect[0]
BCC(I_LE_LI0) {
    gvmDebugOpcode(
        "bcc le.i (%d), (i0 + %u), %d : %d <= %d => ",
        OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)IX0(2).i
    );
    if (LOC(1).i <= IX0(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local <= Indirect[1]
BCC(I_LE_LI1) {
    gvmDebugOpcode(
        "bcc le.i (%d), (i1 + %u), %d : %d <= %d => ",
        OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)IX1(2).i
    );
    if (LOC(1).i <= IX1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] <= Indirect[1]
BCC(I_LE_II) {
    gvmDebugOpcode(
        "bcc le.i (i0 + %u), (i1 + %u), %d : %d <= %d => ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (int)IX0(1).i,
        (int)IX1(2).i
    );
    if (IX0(1).i <= IX1(2).i) {
        BOC_TAKEN
    }
    BOC_SKIPPED;
}
