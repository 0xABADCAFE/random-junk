
// Literal bit set in Local
BCC(X_BS_SL) {
    gvmDebugOpcode(
        "bcc set #%u, {%d}, %d : 0x%08X => ",
        (unsigned)U8(1),
        (int)OPS(2),
        (int)JBRA(3),
        (unsigned)LOC(2).u
    );
    if ((1<<U8(1)) & LOC(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit set in Indirect[0]
BCC(X_BS_SI0) {
    gvmDebugOpcode(
        "bcc set #%u, i0[%u], %d : 0x%08X => ",
        (unsigned)U8(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX0(2).u
    );
    if ((1<<U8(1)) & IX0(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Literal bit set in Indirect[1]
BCC(X_BS_SI1) {
    gvmDebugOpcode(
        "bcc set #%u, i1[%u], %d : 0x%08X => ",
        (unsigned)U8(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX1(2).u
    );
    if ((1<<U8(1)) & IX1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit set in Local
BCC(X_BS_LL) {
    gvmDebugOpcode(
        "bcc set {%d}, {%d}, %d : 0x%08X => ",
        (int)OPS(1),
        (int)OPS(2),
        (int)JBRA(3),
        (unsigned)LOC(2).u
    );
    if ((1<<LOC(1).u) & LOC(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit set in Indirect[0]
BCC(X_BS_LI0) {
    gvmDebugOpcode(
        "bcc set {%d}, i0[%u], %d : 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX0(2).u
    );
    if ((1<<LOC(1).u) & IX0(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

// Local bit set in Indirect[1]
BCC(X_BS_LI1) {
    gvmDebugOpcode(
        "bcc set {%d}, i1[%u], %d : 0x%08X => ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)JBRA(3),
        (unsigned)IX1(2).u
    );
    if ((1<<LOC(1).u) & IX1(2).u) {
        BOC_TAKEN
    }
    BOC_SKIPPED
}

