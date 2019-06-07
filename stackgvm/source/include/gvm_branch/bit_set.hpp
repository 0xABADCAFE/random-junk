
// Literal bit set in Local
BCC(X_BS_SL) {
    gvmDebugOpcode(
        "bcc set #%d, (%d), %d : 0x%08X => ",
        U8(1),
        OPS(2),
        (int)J16(3),
        LOC(2).u
    );
    if ((1<<U8(1)) & LOC(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Literal bit set in Indirect[0]
BCC(X_BS_SI0) {
    gvmDebugOpcode(
        "bcc set #%d, (i0 + %u), %d : 0x%08X => ",
        U8(1),
        OPU(2),
        (int)J16(3),
        IX0(2).u
    );
    if ((1<<U8(1)) & IX0(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Literal bit set in Indirect[1]
BCC(X_BS_SI1) {
    gvmDebugOpcode(
        "bcc set #%d, (i1 + %u), %d : 0x%08X => ",
        U8(1),
        OPU(2),
        (int)J16(3),
        IX1(2).u
    );
    if ((1<<U8(1)) & IX1(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local bit set in Local
BCC(X_BS_LL) {
    gvmDebugOpcode(
        "bcc set (%d), (%d), %d : 0x%08X => ",
        OPS(1),
        OPS(2),
        (int)J16(3),
        LOC(2).u
    );
    if ((1<<LOC(1).u) & LOC(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local bit set in Indirect[0]
BCC(X_BS_LI0) {
    gvmDebugOpcode(
        "bcc set (%d), (i0 + %u), %d : 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        IX0(2).u
    );
    if ((1<<LOC(1).u) & IX0(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local bit set in Indirect[1]
BCC(X_BS_LI1) {
    gvmDebugOpcode(
        "bcc set (%d), (i1 + %u), %d : 0x%08X => ",
        OPS(1),
        OPU(2),
        (int)J16(3),
        IX1(2).u
    );
    if ((1<<LOC(1).u) & IX1(2).u) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

