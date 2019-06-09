
// Local == Local
BCC(V_AE_LL) {
    vs1 = VLOC(1);
    vs2 = VLOC(2);
    gvmDebugOpcode(
        "bcc ae.v (%d), (%d), %d : ",
        (int)OPS(1),
        (int)OPS(2),
        (int)J16(3)
    );

    float32
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[0]
BCC(V_AE_LI0) {
    vs1 = VLOC(1);
    vs2 = VIX0(2);
    gvmDebugOpcode(
        "bcc ae.v (%d), (i0 + %u), %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    float32
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Local == Indirect[1]
BCC(V_AE_LI1) {
    vs1 = VLOC(1);
    vs2 = VIX1(2);
    gvmDebugOpcode(
        "bcc ae.v (%d), (i1 + %u), %d : ",
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    float32
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}

// Indirect[0] == Indirect[1]
BCC(V_AE_II) {
    vs1 = VIX0(1);
    vs2 = VIX1(2);
    gvmDebugOpcode(
        "bcc ae.v (i0 + %u), (i1 + %u), %d : ",
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)J16(3)
    );
    float32
    t  = vs1[0] - vs2[0]; sf = t * t;
    t  = vs1[1] - vs2[1]; sf += t * t;
    t  = vs1[2] - vs2[2]; sf += t * t;
    if (sf < (3 * FLT_EPSILON * FLT_EPSILON)) {
        gvmDebugJump(3);
        STEP(J16(3));
        NEXT;
    }
    gvmDebugSkip();
    STEP(6);
    NEXT;
}
