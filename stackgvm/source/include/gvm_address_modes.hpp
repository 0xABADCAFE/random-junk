// This file automatically generated. Do not edit.

EA(L_L_I1) {
    // local, local, i1[const uint8]
    gvmDebugAddress(
        "(%d), (%d), (i1+%u)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = L(0);
    op2 = L(0 + LSIZE);
    op3 = I1(0 + LSIZE + LSIZE);
    return OSIZE + LSIZE + LSIZE + ISIZE;
}

EA(L_L_I0X) {
    // local, local, i0[local int32]
    gvmDebugAddress(
        "(%d), (%d), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = L(0 + LSIZE);
    op3 = I0X(0 + LSIZE + LSIZE);
    return OSIZE + LSIZE + LSIZE + ISIZE;
}

EA(L_L_I1X) {
    // local, local, i1[local int32]
    gvmDebugAddress(
        "(%d), (%d), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = L(0 + LSIZE);
    op3 = I1X(0 + LSIZE + LSIZE);
    return OSIZE + LSIZE + LSIZE + ISIZE;
}

EA(L_L_R) {
    // local, local, local[const uint8]
    gvmDebugAddress(
        "(%d), (%d), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = L(0 + LSIZE);
    op3 = R(0 + LSIZE + LSIZE);
    return OSIZE + LSIZE + LSIZE + RSIZE;
}

EA(L_I0_I0) {
    // local, i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(%d), (i0+%u), (i0+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = L(0);
    op2 = I0(0 + LSIZE);
    op3 = I0(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0_I0X) {
    // local, i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "(%d), (i0+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0(0 + LSIZE);
    op3 = I0X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0_I1X) {
    // local, i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "(%d), (i0+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0(0 + LSIZE);
    op3 = I1X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0_R) {
    // local, i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "(%d), (i0+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0(0 + LSIZE);
    op3 = R(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + RSIZE;
}

EA(L_I1_L) {
    // local, i1[const uint8], local
    gvmDebugAddress(
        "(%d), (i1+%u), (%d)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = L(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + LSIZE;
}

EA(L_I1_I0) {
    // local, i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(%d), (i1+%u), (i0+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = I0(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1_I1) {
    // local, i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(%d), (i1+%u), (i1+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = I1(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1_I0X) {
    // local, i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "(%d), (i1+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = I0X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1_I1X) {
    // local, i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "(%d), (i1+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = I1X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1_R) {
    // local, i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "(%d), (i1+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1(0 + LSIZE);
    op3 = R(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + RSIZE;
}

EA(L_I0X_L) {
    // local, i0[local int32], local
    gvmDebugAddress(
        "(%d), (i0+(%d)), (%d)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = L(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + LSIZE;
}

EA(L_I0X_I0) {
    // local, i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "(%d), (i0+(%d)), (i0+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = I0(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0X_I1) {
    // local, i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "(%d), (i0+(%d)), (i1+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = I1(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0X_I0X) {
    // local, i0[local int32], i0[local int32]
    gvmDebugAddress(
        "(%d), (i0+(%d)), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = I0X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0X_I1X) {
    // local, i0[local int32], i1[local int32]
    gvmDebugAddress(
        "(%d), (i0+(%d)), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = I1X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I0X_R) {
    // local, i0[local int32], local[const uint8]
    gvmDebugAddress(
        "(%d), (i0+(%d)), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I0X(0 + LSIZE);
    op3 = R(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + RSIZE;
}

EA(L_I1X_L) {
    // local, i1[local int32], local
    gvmDebugAddress(
        "(%d), (i1+(%d)), (%d)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = L(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + LSIZE;
}

EA(L_I1X_I0) {
    // local, i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "(%d), (i1+(%d)), (i0+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = I0(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1X_I1) {
    // local, i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "(%d), (i1+(%d)), (i1+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = I1(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1X_I0X) {
    // local, i1[local int32], i0[local int32]
    gvmDebugAddress(
        "(%d), (i1+(%d)), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = I0X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1X_I1X) {
    // local, i1[local int32], i1[local int32]
    gvmDebugAddress(
        "(%d), (i1+(%d)), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = I1X(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + ISIZE;
}

EA(L_I1X_R) {
    // local, i1[local int32], local[const uint8]
    gvmDebugAddress(
        "(%d), (i1+(%d)), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = I1X(0 + LSIZE);
    op3 = R(0 + LSIZE + ISIZE);
    return OSIZE + LSIZE + ISIZE + RSIZE;
}

EA(L_R_L) {
    // local, local[const uint8], local
    gvmDebugAddress(
        "(%d), ((%d)+%u), (%d)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = L(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + LSIZE;
}

EA(L_R_I0) {
    // local, local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(%d), ((%d)+%u), (i0+%u)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = I0(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + ISIZE;
}

EA(L_R_I1) {
    // local, local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(%d), ((%d)+%u), (i1+%u)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = I1(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + ISIZE;
}

EA(L_R_I0X) {
    // local, local[const uint8], i0[local int32]
    gvmDebugAddress(
        "(%d), ((%d)+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = I0X(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + ISIZE;
}

EA(L_R_I1X) {
    // local, local[const uint8], i1[local int32]
    gvmDebugAddress(
        "(%d), ((%d)+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = I1X(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + ISIZE;
}

EA(L_R_R) {
    // local, local[const uint8], local[const uint8]
    gvmDebugAddress(
        "(%d), ((%d)+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = L(0);
    op2 = R(0 + LSIZE);
    op3 = R(0 + LSIZE + RSIZE);
    return OSIZE + LSIZE + RSIZE + RSIZE;
}

EA(I0_L_I0) {
    // i0[const uint8], local, i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), (%d), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = L(0 + ISIZE);
    op3 = I0(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0_L_I0X) {
    // i0[const uint8], local, i0[local int32]
    gvmDebugAddress(
        "(i0+%u), (%d), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = L(0 + ISIZE);
    op3 = I0X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0_L_I1X) {
    // i0[const uint8], local, i1[local int32]
    gvmDebugAddress(
        "(i0+%u), (%d), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = L(0 + ISIZE);
    op3 = I1X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0_L_R) {
    // i0[const uint8], local, local[const uint8]
    gvmDebugAddress(
        "(i0+%u), (%d), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = L(0 + ISIZE);
    op3 = R(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + RSIZE;
}

EA(I0_I0_L) {
    // i0[const uint8], i0[const uint8], local
    gvmDebugAddress(
        "(i0+%u), (i0+%u), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0_I0_I0) {
    // i0[const uint8], i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0_I1) {
    // i0[const uint8], i0[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0_I0X) {
    // i0[const uint8], i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+%u), (i0+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0_I1X) {
    // i0[const uint8], i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+%u), (i0+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0_R) {
    // i0[const uint8], i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0_I1_I0) {
    // i0[const uint8], i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1_I1) {
    // i0[const uint8], i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1_I0X) {
    // i0[const uint8], i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+%u), (i1+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1_I1X) {
    // i0[const uint8], i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+%u), (i1+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1_R) {
    // i0[const uint8], i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0_I0X_L) {
    // i0[const uint8], i0[local int32], local
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0_I0X_I0) {
    // i0[const uint8], i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0X_I1) {
    // i0[const uint8], i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0X_I0X) {
    // i0[const uint8], i0[local int32], i0[local int32]
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0X_I1X) {
    // i0[const uint8], i0[local int32], i1[local int32]
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I0X_R) {
    // i0[const uint8], i0[local int32], local[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i0+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I0X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0_I1X_L) {
    // i0[const uint8], i1[local int32], local
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0_I1X_I0) {
    // i0[const uint8], i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1X_I1) {
    // i0[const uint8], i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1X_I0X) {
    // i0[const uint8], i1[local int32], i0[local int32]
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1X_I1X) {
    // i0[const uint8], i1[local int32], i1[local int32]
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0_I1X_R) {
    // i0[const uint8], i1[local int32], local[const uint8]
    gvmDebugAddress(
        "(i0+%u), (i1+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = I1X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0_R_L) {
    // i0[const uint8], local[const uint8], local
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), (%d)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = L(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + LSIZE;
}

EA(I0_R_I0) {
    // i0[const uint8], local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = I0(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0_R_I1) {
    // i0[const uint8], local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = I1(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0_R_I0X) {
    // i0[const uint8], local[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = I0X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0_R_I1X) {
    // i0[const uint8], local[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = I1X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0_R_R) {
    // i0[const uint8], local[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+%u), ((%d)+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0(0);
    op2 = R(0 + ISIZE);
    op3 = R(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + RSIZE;
}

EA(I1_L_L) {
    // i1[const uint8], local, local
    gvmDebugAddress(
        "(i1+%u), (%d), (%d)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = L(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + LSIZE;
}

EA(I1_L_I0) {
    // i1[const uint8], local, i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), (%d), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = I0(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1_L_I1) {
    // i1[const uint8], local, i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), (%d), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = I1(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1_L_I0X) {
    // i1[const uint8], local, i0[local int32]
    gvmDebugAddress(
        "(i1+%u), (%d), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = I0X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1_L_I1X) {
    // i1[const uint8], local, i1[local int32]
    gvmDebugAddress(
        "(i1+%u), (%d), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = I1X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1_L_R) {
    // i1[const uint8], local, local[const uint8]
    gvmDebugAddress(
        "(i1+%u), (%d), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = L(0 + ISIZE);
    op3 = R(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + RSIZE;
}

EA(I1_I0_L) {
    // i1[const uint8], i0[const uint8], local
    gvmDebugAddress(
        "(i1+%u), (i0+%u), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1_I0_I0) {
    // i1[const uint8], i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0_I1) {
    // i1[const uint8], i0[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0_I0X) {
    // i1[const uint8], i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+%u), (i0+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0_I1X) {
    // i1[const uint8], i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+%u), (i0+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0_R) {
    // i1[const uint8], i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1_I1_L) {
    // i1[const uint8], i1[const uint8], local
    gvmDebugAddress(
        "(i1+%u), (i1+%u), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1_I1_I0) {
    // i1[const uint8], i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1_I1) {
    // i1[const uint8], i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1_I0X) {
    // i1[const uint8], i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+%u), (i1+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1_I1X) {
    // i1[const uint8], i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+%u), (i1+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1_R) {
    // i1[const uint8], i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1_I0X_L) {
    // i1[const uint8], i0[local int32], local
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1_I0X_I0) {
    // i1[const uint8], i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0X_I1) {
    // i1[const uint8], i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0X_I0X) {
    // i1[const uint8], i0[local int32], i0[local int32]
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0X_I1X) {
    // i1[const uint8], i0[local int32], i1[local int32]
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I0X_R) {
    // i1[const uint8], i0[local int32], local[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i0+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I0X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1_I1X_L) {
    // i1[const uint8], i1[local int32], local
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), (%d)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1_I1X_I0) {
    // i1[const uint8], i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1X_I1) {
    // i1[const uint8], i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1X_I0X) {
    // i1[const uint8], i1[local int32], i0[local int32]
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1X_I1X) {
    // i1[const uint8], i1[local int32], i1[local int32]
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1_I1X_R) {
    // i1[const uint8], i1[local int32], local[const uint8]
    gvmDebugAddress(
        "(i1+%u), (i1+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (uint8)pc[1 + OSIZE], (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = I1X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1_R_L) {
    // i1[const uint8], local[const uint8], local
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), (%d)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = L(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + LSIZE;
}

EA(I1_R_I0) {
    // i1[const uint8], local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = I0(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1_R_I1) {
    // i1[const uint8], local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = I1(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1_R_I0X) {
    // i1[const uint8], local[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = I0X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1_R_I1X) {
    // i1[const uint8], local[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = I1X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1_R_R) {
    // i1[const uint8], local[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+%u), ((%d)+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE],
        (int8)pc[1 + OSIZE], (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1(0);
    op2 = R(0 + ISIZE);
    op3 = R(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + RSIZE;
}

EA(I0X_L_L) {
    // i0[local int32], local, local
    gvmDebugAddress(
        "(i0+(%d)), (%d), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = L(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + LSIZE;
}

EA(I0X_L_I0) {
    // i0[local int32], local, i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (%d), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = I0(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0X_L_I1) {
    // i0[local int32], local, i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (%d), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = I1(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0X_L_I0X) {
    // i0[local int32], local, i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (%d), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = I0X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0X_L_I1X) {
    // i0[local int32], local, i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (%d), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = I1X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I0X_L_R) {
    // i0[local int32], local, local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (%d), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = L(0 + ISIZE);
    op3 = R(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + RSIZE;
}

EA(I0X_I0_L) {
    // i0[local int32], i0[const uint8], local
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0X_I0_I0) {
    // i0[local int32], i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0_I1) {
    // i0[local int32], i0[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0_I0X) {
    // i0[local int32], i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0_I1X) {
    // i0[local int32], i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0_R) {
    // i0[local int32], i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0X_I1_L) {
    // i0[local int32], i1[const uint8], local
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0X_I1_I0) {
    // i0[local int32], i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1_I1) {
    // i0[local int32], i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1_I0X) {
    // i0[local int32], i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1_I1X) {
    // i0[local int32], i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1_R) {
    // i0[local int32], i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0X_I0X_L) {
    // i0[local int32], i0[local int32], local
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0X_I0X_I0) {
    // i0[local int32], i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0X_I1) {
    // i0[local int32], i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0X_I0X) {
    // i0[local int32], i0[local int32], i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0X_I1X) {
    // i0[local int32], i0[local int32], i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I0X_R) {
    // i0[local int32], i0[local int32], local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i0+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I0X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0X_I1X_L) {
    // i0[local int32], i1[local int32], local
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I0X_I1X_I0) {
    // i0[local int32], i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1X_I1) {
    // i0[local int32], i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1X_I0X) {
    // i0[local int32], i1[local int32], i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1X_I1X) {
    // i0[local int32], i1[local int32], i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I0X_I1X_R) {
    // i0[local int32], i1[local int32], local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), (i1+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = I1X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I0X_R_L) {
    // i0[local int32], local[const uint8], local
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = L(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + LSIZE;
}

EA(I0X_R_I0) {
    // i0[local int32], local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = I0(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0X_R_I1) {
    // i0[local int32], local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = I1(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0X_R_I0X) {
    // i0[local int32], local[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = I0X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0X_R_I1X) {
    // i0[local int32], local[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = I1X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I0X_R_R) {
    // i0[local int32], local[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i0+(%d)), ((%d)+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I0X(0);
    op2 = R(0 + ISIZE);
    op3 = R(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + RSIZE;
}

EA(I1X_L_L) {
    // i1[local int32], local, local
    gvmDebugAddress(
        "(i1+(%d)), (%d), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = L(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + LSIZE;
}

EA(I1X_L_I0) {
    // i1[local int32], local, i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (%d), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = I0(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1X_L_I1) {
    // i1[local int32], local, i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (%d), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = I1(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1X_L_I0X) {
    // i1[local int32], local, i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (%d), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = I0X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1X_L_I1X) {
    // i1[local int32], local, i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (%d), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = I1X(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + ISIZE;
}

EA(I1X_L_R) {
    // i1[local int32], local, local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (%d), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = L(0 + ISIZE);
    op3 = R(0 + ISIZE + LSIZE);
    return OSIZE + ISIZE + LSIZE + RSIZE;
}

EA(I1X_I0_L) {
    // i1[local int32], i0[const uint8], local
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1X_I0_I0) {
    // i1[local int32], i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0_I1) {
    // i1[local int32], i0[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0_I0X) {
    // i1[local int32], i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0_I1X) {
    // i1[local int32], i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0_R) {
    // i1[local int32], i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1X_I1_L) {
    // i1[local int32], i1[const uint8], local
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1X_I1_I0) {
    // i1[local int32], i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1_I1) {
    // i1[local int32], i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1_I0X) {
    // i1[local int32], i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1_I1X) {
    // i1[local int32], i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1_R) {
    // i1[local int32], i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1X_I0X_L) {
    // i1[local int32], i0[local int32], local
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1X_I0X_I0) {
    // i1[local int32], i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0X_I1) {
    // i1[local int32], i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0X_I0X) {
    // i1[local int32], i0[local int32], i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0X_I1X) {
    // i1[local int32], i0[local int32], i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I0X_R) {
    // i1[local int32], i0[local int32], local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i0+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I0X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1X_I1X_L) {
    // i1[local int32], i1[local int32], local
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = L(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + LSIZE;
}

EA(I1X_I1X_I0) {
    // i1[local int32], i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1X_I1) {
    // i1[local int32], i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1X_I0X) {
    // i1[local int32], i1[local int32], i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I0X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1X_I1X) {
    // i1[local int32], i1[local int32], i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = I1X(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + ISIZE;
}

EA(I1X_I1X_R) {
    // i1[local int32], i1[local int32], local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), (i1+(%d)), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = I1X(0 + ISIZE);
    op3 = R(0 + ISIZE + ISIZE);
    return OSIZE + ISIZE + ISIZE + RSIZE;
}

EA(I1X_R_L) {
    // i1[local int32], local[const uint8], local
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), (%d)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = L(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + LSIZE;
}

EA(I1X_R_I0) {
    // i1[local int32], local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), (i0+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = I0(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1X_R_I1) {
    // i1[local int32], local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), (i1+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = I1(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1X_R_I0X) {
    // i1[local int32], local[const uint8], i0[local int32]
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), (i0+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = I0X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1X_R_I1X) {
    // i1[local int32], local[const uint8], i1[local int32]
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), (i1+(%d))",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = I1X(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + ISIZE;
}

EA(I1X_R_R) {
    // i1[local int32], local[const uint8], local[const uint8]
    gvmDebugAddress(
        "(i1+(%d)), ((%d)+%u), ((%d)+%u)",
        (uint8)pc[0 + OSIZE], (int8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = I1X(0);
    op2 = R(0 + ISIZE);
    op3 = R(0 + ISIZE + RSIZE);
    return OSIZE + ISIZE + RSIZE + RSIZE;
}

EA(R_L_L) {
    // local[const uint8], local, local
    gvmDebugAddress(
        "((%d)+%u), (%d), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = L(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + LSIZE;
}

EA(R_L_I0) {
    // local[const uint8], local, i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (%d), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = I0(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + ISIZE;
}

EA(R_L_I1) {
    // local[const uint8], local, i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (%d), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = I1(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + ISIZE;
}

EA(R_L_I0X) {
    // local[const uint8], local, i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), (%d), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = I0X(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + ISIZE;
}

EA(R_L_I1X) {
    // local[const uint8], local, i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), (%d), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = I1X(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + ISIZE;
}

EA(R_L_R) {
    // local[const uint8], local, local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (%d), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = L(0 + RSIZE);
    op3 = R(0 + RSIZE + LSIZE);
    return OSIZE + RSIZE + LSIZE + RSIZE;
}

EA(R_I0_L) {
    // local[const uint8], i0[const uint8], local
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = L(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + LSIZE;
}

EA(R_I0_I0) {
    // local[const uint8], i0[const uint8], i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = I0(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0_I1) {
    // local[const uint8], i0[const uint8], i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = I1(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0_I0X) {
    // local[const uint8], i0[const uint8], i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = I0X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0_I1X) {
    // local[const uint8], i0[const uint8], i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = I1X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0_R) {
    // local[const uint8], i0[const uint8], local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0(0 + RSIZE);
    op3 = R(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + RSIZE;
}

EA(R_I1_L) {
    // local[const uint8], i1[const uint8], local
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = L(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + LSIZE;
}

EA(R_I1_I0) {
    // local[const uint8], i1[const uint8], i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = I0(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1_I1) {
    // local[const uint8], i1[const uint8], i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = I1(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1_I0X) {
    // local[const uint8], i1[const uint8], i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = I0X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1_I1X) {
    // local[const uint8], i1[const uint8], i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (uint8)pc[3 + OSIZE], (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = I1X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1_R) {
    // local[const uint8], i1[const uint8], local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE],
        (int8)pc[3 + OSIZE], (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1(0 + RSIZE);
    op3 = R(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + RSIZE;
}

EA(R_I0X_L) {
    // local[const uint8], i0[local int32], local
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = L(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + LSIZE;
}

EA(R_I0X_I0) {
    // local[const uint8], i0[local int32], i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = I0(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0X_I1) {
    // local[const uint8], i0[local int32], i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = I1(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0X_I0X) {
    // local[const uint8], i0[local int32], i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = I0X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0X_I1X) {
    // local[const uint8], i0[local int32], i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = I1X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I0X_R) {
    // local[const uint8], i0[local int32], local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i0+(%d)), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I0X(0 + RSIZE);
    op3 = R(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + RSIZE;
}

EA(R_I1X_L) {
    // local[const uint8], i1[local int32], local
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = L(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + LSIZE;
}

EA(R_I1X_I0) {
    // local[const uint8], i1[local int32], i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = I0(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1X_I1) {
    // local[const uint8], i1[local int32], i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = I1(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1X_I0X) {
    // local[const uint8], i1[local int32], i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = I0X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1X_I1X) {
    // local[const uint8], i1[local int32], i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = I1X(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + ISIZE;
}

EA(R_I1X_R) {
    // local[const uint8], i1[local int32], local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), (i1+(%d)), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (uint8)pc[2 + OSIZE], (int8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = I1X(0 + RSIZE);
    op3 = R(0 + RSIZE + ISIZE);
    return OSIZE + RSIZE + ISIZE + RSIZE;
}

EA(R_R_L) {
    // local[const uint8], local[const uint8], local
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), (%d)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = L(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + LSIZE;
}

EA(R_R_I0) {
    // local[const uint8], local[const uint8], i0[const uint8]
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), (i0+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = I0(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + ISIZE;
}

EA(R_R_I1) {
    // local[const uint8], local[const uint8], i1[const uint8]
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), (i1+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = I1(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + ISIZE;
}

EA(R_R_I0X) {
    // local[const uint8], local[const uint8], i0[local int32]
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), (i0+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = I0X(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + ISIZE;
}

EA(R_R_I1X) {
    // local[const uint8], local[const uint8], i1[local int32]
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), (i1+(%d))",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (uint8)pc[4 + OSIZE], (int8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = I1X(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + ISIZE;
}

EA(R_R_R) {
    // local[const uint8], local[const uint8], local[const uint8]
    gvmDebugAddress(
        "((%d)+%u), ((%d)+%u), ((%d)+%u)",
        (int8)pc[0 + OSIZE], (uint8)pc[1 + OSIZE],
        (int8)pc[2 + OSIZE], (uint8)pc[3 + OSIZE],
        (int8)pc[4 + OSIZE], (uint8)pc[5 + OSIZE]
    );
    op1 = R(0);
    op2 = R(0 + RSIZE);
    op3 = R(0 + RSIZE + RSIZE);
    return OSIZE + RSIZE + RSIZE + RSIZE;
}

