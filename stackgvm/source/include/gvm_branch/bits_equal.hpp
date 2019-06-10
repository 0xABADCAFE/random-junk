
// Local === Small Integer Literal
BCC(X_EQ_LS) {
    gvmDebugOpcode(
        "bcc eq.i (%d), #%d, %d : %d == %d => ",
        (int)OPS(1),
        (int)S8(2),
        (int)J16(3),
        (int)LOC(1).i,
        (int)S8(2)
    );
    if (LOC(1).i == S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] === Small Integer Literal
BCC(X_EQ_I0S) {
    gvmDebugOpcode(
        "bcc eq.i (i0 + %u), #%d, %d : %d == %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX0(1).i,
        (int)S8(2)
    );
    if (IX0(1).i == S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[1] === Small Integer Literal
BCC(X_EQ_I1S) {
    gvmDebugOpcode(
        "bcc eq.i (i1 + %u), #%d, %d : %d == %d => ",
        (unsigned)OPU(1),
        (int)S8(2),
        (int)J16(3),
        (int)IX1(1).i,
        (int)S8(2)
    );
    if (IX1(1).i == S8(2)) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Local
BCC(X_EQ_LL) {
    gvmDebugOpcode(
        "bcc eq (%d), (%d), %d : 0x%08X == 0x%08X => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)J16(3),
        (unsigned)LOC(1).u,
        (unsigned)LOC(2).u
    );
    if (LOC(1).u == LOC(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[0]
BCC(X_EQ_LI0) {
    gvmDebugOpcode(
        "bcc eq (%d), (i0 + %u), %d : 0x%08X == 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (unsigned)LOC(1).u,
        (unsigned)IX0(2).u
    );
    if (LOC(1).u == IX0(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local == Indirect[1]
BCC(X_EQ_LI1) {
    gvmDebugOpcode(
        "bcc eq (%d), (i1 + %u), %d : 0x%08X == 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (unsigned)LOC(1).u,
        (unsigned)IX1(2).u
    );
    if (LOC(1).u == IX1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Indirect[0] == Indirect[1]
BCC(X_EQ_II) {
    gvmDebugOpcode(
        "bcc eq (i0 + %u), (i1 + %u), %d : 0x%08X == 0x%08X => ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)J16(3),
        (unsigned)IX0(1).u,
        (unsigned)IX1(2).u
    );
    if (IX0(1).u == IX1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}
