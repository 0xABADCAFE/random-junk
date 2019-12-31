
// Integer specific instructions ///////////////////////////////////////////////////////////////////////////////////////


// Decrement Integer And Branch If Not Zero ////////////////////////////////////////////////////////////////////////////

IS(DBNZ_L) {
    gvmDebugOpcode(
        "dbnz.i " OPF_L ", %d : --%d != 0 => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_JUMP_S16(1),
        (int)OP_LOCAL(0).i
    );
    // Decrement local and branch if not zero
    if (--OP_LOCAL(0).i) {
        gvmDebugJump(1);
        STEP(OP_JUMP_S16(1));
        NEXT;
    }
    gvmDebugOpcode("%d ", (int)OP_LOCAL(0).i);
    STEP(4);
    NEXT;
}

// Decrement Integer And Branch If Not Negative ////////////////////////////////////////////////////////////////////////

IS(DBNN_L) {
    gvmDebugOpcode(
        "dbnn.i " OPF_L ", %d : --%d >= 0 => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_JUMP_S16(1),
        (int)OP_LOCAL(0).i
    );
    // Decrement local and branch if not negative
    if (--OP_LOCAL(0).i >= 0) {
        gvmDebugJump(1);
        STEP(OP_JUMP_S16(1));
        NEXT;
    }
    gvmDebugOpcode("%d ", (int)OP_LOCAL(0).i);
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Load Small Integer Literal //////////////////////////////////////////////////////////////////////////////////////////

IS(LOAD_SL) {
    OP_LOCAL(1).i = OP_LITERAL_S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_L " : %d",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LOCAL(1).i
    );
    STEP(3);
    NEXT;
}

IS(LOAD_SI0) {
    OP_INDIRECT_0(1).i = OP_LITERAL_S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_I0 " : %d",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_INDIRECT_0(1).i
    );
    STEP(3);
    NEXT;
}

IS(LOAD_SI1) {
    OP_INDIRECT_1(1).i = OP_LITERAL_S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_I1 " : %d",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_INDIRECT_1(1).i
    );
    STEP(3);
    NEXT;
}

// Set Single Bit //////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BSET_SL) {
    // Set bit in local
    OP_LOCAL(1).u |= 1 << OP_LITERAL_U8(0);
    gvmDebugOpcode(
        "bset %u, " OPF_L " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LOCAL(1).u
    );
    STEP(3);
    NEXT;
}

IS(BSET_SI) {
    // Set bit in indirect
    OP_INDIRECT_0(1).u |= 1 << OP_LITERAL_U8(0);
    gvmDebugOpcode(
        "bset %u, " OPF_I0 " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_INDIRECT_0(1).u
    );
    STEP(3);
    NEXT;
}

// Clear Single Bit ////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCLR_SL) {
    // Clear bit in local
    OP_LOCAL(1).u &= ~(1 << OP_LITERAL_U8(0));
    gvmDebugOpcode(
        "bclr %u, " OPF_L " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LOCAL(1).u
    );
    STEP(3);
    NEXT;
}

IS(BCLR_SI) {
    // Clear bit in indirect
    OP_INDIRECT_0(1).u &= ~(1 << OP_LITERAL_U8(0));
    gvmDebugOpcode(
        "bclr %u, " OPF_I0 " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_INDIRECT_0(1).u
    );
    STEP(3);
    NEXT;
}

// Two Operand Logical Inverse /////////////////////////////////////////////////////////////////////////////////////////

IS(NOT_LL) {
    OP_LOCAL(1).u = ~OP_LOCAL(0).u;
    gvmDebugOpcode(
        "not " OPF_L ", " OPF_L " : 0x%08X",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LOCAL(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_IL) {
    OP_LOCAL(1).u = ~OP_INDIRECT_0(0).u;
    gvmDebugOpcode(
        "not " OPF_I0 ", " OPF_L " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LOCAL(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_LI) {
    OP_INDIRECT_0(1).u = ~OP_LOCAL(0).u;
    gvmDebugOpcode(
        "not " OPF_L ", " OPF_I0 " : 0x%08X",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_INDIRECT_0(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_II) {
    OP_INDIRECT_1(1).u = ~OP_INDIRECT_0(0).u;
    gvmDebugOpcode(
        "not " OPF_I0 ", " OPF_I1 " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_INDIRECT_1(1).u
    );
    STEP(3);
    NEXT;
}

// Two Operand Integer Negate //////////////////////////////////////////////////////////////////////////////////////////

IS(NEG_LL) {
    OP_LOCAL(1).i = -OP_LOCAL(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_L ", " OPF_L " : %d",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LOCAL(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_IL) {
    OP_LOCAL(1).i = -OP_INDIRECT_0(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_I0 ", " OPF_L " : %d",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LOCAL(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_LI) {
    OP_INDIRECT_0(1).i = -OP_LOCAL(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_L ", " OPF_I0 " : %d",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_INDIRECT_0(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_II) {
    OP_INDIRECT_1(1).i = -OP_INDIRECT_0(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_I0 ", " OPF_I1 " : %d",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_INDIRECT_1(1).i
    );
    STEP(3);
    NEXT;
}

// Three Operand Integer Addition (Commutative, 4 unique variants) /////////////////////////////////////////////////////

IS(ADD_LLL) {
    // Local + Local -> Local
    gvmDebugOpcode(
        "add.i " OPF_L ", " OPF_L ", " OPF_L " : %d + %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_LOCAL(0).i + OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_ILL) {
    // Indirect + Local -> Local
    gvmDebugOpcode(
        "add.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d + %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i + OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_LLI) {
    // Local + Local -> Indirect
    gvmDebugOpcode(
        "add.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d + %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_0(2).i = OP_LOCAL(0).i + OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_ILI) {
    // Indirect + Local -> Indirect
    gvmDebugOpcode(
        "add.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d + %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_1(2).i = OP_INDIRECT_0(0).i + OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("add.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d + %d => ",
            (int)op1->i,
            (int)op2->i
        );
        op3->i = op1->i + op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three operand Integer Subtraction (Noncommutative, 7 unique variants) ///////////////////////////////////////////////

IS(SUB_LLL) {
    // Local - Local -> Local
    gvmDebugOpcode(
        "sub.i " OPF_L ", " OPF_L ", " OPF_L " : %d - %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_LOCAL(0).i - OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_ILL) {
    // Indirect - Local -> Local
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d - %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i - OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LLI) {
    // Local - Local -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d - %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_0(2).i = OP_LOCAL(0).i - OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_ILI) {
    // Indirect - Local -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d - %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_1(2).i = OP_INDIRECT_0(0).i - OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LIL) {
    // Local - Indirect -> Local
    gvmDebugOpcode(
        "sub.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d - %d => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_INDIRECT_0(1).i
    );
    OP_LOCAL(2).i = OP_LOCAL(0).i - OP_INDIRECT_0(0).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_IIL) {
    // Indirect - Indirect -> Local
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d - %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_INDIRECT_1(1).i
    );
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i - OP_INDIRECT_1(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LII) {
    // Local - Indirect -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d - %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_INDIRECT_1(1).i
    );
    OP_INDIRECT_1(2).i = OP_LOCAL(0).i - OP_INDIRECT_0(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("sub.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d - %d => ",
            (int)op1->i,
            (int)op2->i
        );
        op3->i = op1->i - op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Integer Multiplication (Commutative, 4 unique variants) ///////////////////////////////////////////////

IS(MUL_LLL) {
    // Local * Local -> Local
    gvmDebugOpcode(
        "mul.i " OPF_L ", " OPF_L ", " OPF_L " : %d * %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_LOCAL(0).i * OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_ILL) {
    // Indirect * Local -> Local
    gvmDebugOpcode(
        "mul.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d * %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i * OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_LLI) {
    // Local * Local -> Indirect
    gvmDebugOpcode(
        "mul.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d * %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_0(2).i = OP_LOCAL(0).i * OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_ILI) {
    // Indirect * Local -> Indirect
    gvmDebugOpcode(
        "mul.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d * %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)OP_LOCAL(1).i
    );
    OP_INDIRECT_1(2).i = OP_INDIRECT_0(0).i * OP_LOCAL(1).i;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mul.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d * %d => ",
            (int)op1->i,
            (int)op2->i
        );
        op3->i = op1->i * op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Integer Division (Noncommutative, 7 unique variants) //////////////////////////////////////////////////

IS(DIV_LLL) {
    // Local / Local -> Local
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_L ", " OPF_L " : %d / %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_LOCAL(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_ILL) {
    // Indirect / Local -> Local
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d / %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)denominator
    );
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LLI) {
    // Local / Local -> Indirect
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d / %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_0(2).i = OP_LOCAL(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_ILI) {
    // Indirect / Local -> Indirect
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d / %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_1(2).i = OP_INDIRECT_0(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LIL) {
    // Local / Indirect -> Local
    int32 denominator = OP_INDIRECT_0(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d / %d => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_LOCAL(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_IIL) {
    // Indirect / Indirect -> Local
    int32 denominator = OP_INDIRECT_1(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d / %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LII) {
    // Local / Indirect -> Indirect
    int32 denominator = OP_INDIRECT_0(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_I0 ", " OPF_I1 " : %d / %d => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_1(2).i = OP_LOCAL(0).i / denominator;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("div.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d / %d => ",
            (int)op1->i,
            (int)op2->i
        );
        if (0 == op2->i) {
            gvmDebugOpcode("Abort with Zero Divide");
            EXIT(EXEC_DIVISION_BY_ZERO);
        }
        op3->i = op1->i / op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Integer Modulo (Noncommutative, 7 unique variants) ////////////////////////////////////////////////////

IS(MOD_LLL) {
    // Local % Local -> Local
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_L ", " OPF_L " : %d %% %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_LOCAL(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILL) {
    // Indirect % Local -> Local
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d %% %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LLI) {
    // Local % Local -> Indirect
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d %% %d => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_0(2).i = OP_LOCAL(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILI) {
    // Indirect % Local -> Indirect
    int32 denominator = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d %% %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_1(2).i = OP_INDIRECT_0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LIL) {
    // Local % Indirect -> Local
    int32 denominator = OP_INDIRECT_0(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d %% %d => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_LOCAL(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_IIL) {
    // Indirect % Indirect -> Local
    int32 denominator = OP_INDIRECT_1(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d %% %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        (int)OP_INDIRECT_0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_LOCAL(2).i = OP_INDIRECT_0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LII) {
    // Local % Indirect -> Indirect
    int32 denominator = OP_INDIRECT_0(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_I0 ", " OPF_I1 " : %d %% %d => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)OP_LOCAL(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    OP_INDIRECT_1(2).i = OP_LOCAL(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mod.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d %% %d => ",
            (int)op1->i,
            (int)op2->i
        );
        if (0 == op2->i) {
            gvmDebugOpcode("Abort with Zero Divide");
            EXIT(EXEC_DIVISION_BY_ZERO);
        }
        op3->i = op1->i % op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Logical AND (Commutative, 4 unique variants) //////////////////////////////////////////////////////////

IS(AND_LLL) {
    // Local & Local -> Local
    gvmDebugOpcode(
        "and " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X & 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_LOCAL(0).u & OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(AND_ILL) {
    // Indirect & Local -> Local
    gvmDebugOpcode(
        "and " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X & 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_INDIRECT_0(0).u & OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(AND_LLI) {
    // Local & Local -> Indirect
    gvmDebugOpcode(
        "and " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X & 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_0(2).u = OP_LOCAL(0).u & OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_0(2).u);
    STEP(4);
    NEXT;
}

IS(AND_ILI) {
    // Indirect & Local -> Indirect
    gvmDebugOpcode(
        "and " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X & 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_1(2).u = OP_INDIRECT_0(0).u & OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_1(2).u);
    STEP(4);
    NEXT;
}

IS(AND_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("and ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : 0x%08X & 0x%08X => ",
            (unsigned)op1->u,
            (unsigned)op2->u
        );
        op3->u = op1->u & op2->u;
        gvmDebugOpcode("0x%08X", (unsigned)op3->u);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Logical OR (Commutative, 4 unique variants) ///////////////////////////////////////////////////////////

IS(OR_LLL) {
    // Local | Local -> Local
    gvmDebugOpcode(
        "or " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X | 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_LOCAL(0).u | OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(OR_ILL) {
    // Indirect | Local -> Local
    gvmDebugOpcode(
        "or " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X | 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_INDIRECT_0(0).u | OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(OR_LLI) {
    // Local | Local -> Indirect
    gvmDebugOpcode(
        "or " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X | 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_0(2).u = OP_LOCAL(0).u | OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_0(2).u);
    STEP(4);
    NEXT;
}

IS(OR_ILI) {
    // Indirect | Local -> Indirect
    gvmDebugOpcode(
        "or " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X | 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_1(2).u = OP_INDIRECT_0(0).u | OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_1(2).u);
    STEP(4);
    NEXT;
}

IS(OR_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("or ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : 0x%08X  0x%08X => ",
            (unsigned)op1->u,
            (unsigned)op2->u
        );
        op3->u = op1->u | op2->u;
        gvmDebugOpcode("0x%08X", (unsigned)op3->u);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Logical XOR (Commutative, 4 unique variants) //////////////////////////////////////////////////////////

IS(XOR_LLL) {
    // Local ^ Local -> Local
    gvmDebugOpcode(
        "xor " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X ^ 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_LOCAL(0).u ^ OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_ILL) {
    // Indirect ^ Local -> Local
    gvmDebugOpcode(
        "xor " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X ^ 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_INDIRECT_0(0).u ^ OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_LLI) {
    // Local ^ Local -> Indirect
    gvmDebugOpcode(
        "xor " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X ^ 0x%08X => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_0(2).u = OP_LOCAL(0).u ^ OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_0(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_ILI) {
    // Indirect ^ Local -> Indirect
    gvmDebugOpcode(
        "xor " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X ^ 0x%08X => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_1(2).u = OP_INDIRECT_0(0).u ^ OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_1(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("xor ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : 0x%08X ^ 0x%08X => ",
            (unsigned)op1->u,
            (unsigned)op2->u
        );
        op3->u = op1->u ^ op2->u;
        gvmDebugOpcode("0x%08X", (unsigned)op3->u);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Logical Shift Left (Noncommutative, 4 supported variants) /////////////////////////////////////////////

IS(LSL_LLL) {
    // Local << Local -> Local
    gvmDebugOpcode(
        "lsl " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X << %u => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_LOCAL(0).u << OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_ILL) {
    // Indirect << Local -> Local
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X << %u => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_INDIRECT_0(0).u << OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_LLI) {
    // Local << Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X << %u => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_0(2).u = OP_LOCAL(0).u << OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_0(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_ILI) {
    // Indirect << Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X << %u => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_1(2).u = OP_INDIRECT_0(0).u << OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_1(2).u);
    STEP(4);
    NEXT;
}

// Three Operand Logical Shift Right (Noncommutative, 4 supported variants) ////////////////////////////////////////////

IS(LSR_LLL) {
    // Local >> Local -> Local
    gvmDebugOpcode(
        "lsr " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X << %u => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_LOCAL(0).u >> OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_ILL) {
    // Indirect >> Local -> Local
    gvmDebugOpcode(
        "lsr " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X >> %u => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_LOCAL(2).u = OP_INDIRECT_0(0).u >> OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_LOCAL(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_LLI) {
    // Local >> Local -> Indirect
    gvmDebugOpcode(
        "lsr " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X >> %u => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_LOCAL(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_0(2).u = OP_LOCAL(0).u >> OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_0(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_ILI) {
    // Indirect >> Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X >> %u => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (unsigned)OP_INDIRECT_0(0).u,
        (unsigned)OP_LOCAL(1).u
    );
    OP_INDIRECT_1(2).u = OP_INDIRECT_0(0).u >> OP_LOCAL(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)OP_INDIRECT_1(2).u);
    STEP(4);
    NEXT;
}

// Three Operand Integer Maximum (Commutative, 4 unique variants) //////////////////////////////////////////////////////

IS(MAX_LLL) {
    // max(Local, Local) -> Local
    int32 i1 = OP_LOCAL(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "max.i " OPF_L ", " OPF_L ", " OPF_L " : max(%d, %d) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)i1,
        (int)i2
    );
    OP_LOCAL(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_ILL) {
    // max(Indirect, Local) -> Local
    int32 i1 = OP_INDIRECT_0(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "max.i " OPF_I0 ", " OPF_L ", " OPF_L " : max(%d, %d) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)i1,
        (int)i2
    );
    OP_LOCAL(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_LLI) {
    // max(Local, Local) -> Indirect
    int32 i1 = OP_LOCAL(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "max.i " OPF_L ", " OPF_L ", " OPF_I0 " : max(%d, %d) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)i1,
        (int)i2
    );
    OP_INDIRECT_0(0).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_ILI) {
    // max(Indirect, Local) -> Indirect
    int32 i1 = OP_INDIRECT_0(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "max.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : max(%d, %d) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)i1,
        (int)i2
    );
    OP_INDIRECT_1(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("max.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : max(%d, %d) => ",
            (int)op1->i,
            (int)op2->i
        );
        op3->i = op1->i > op2->i ? op1->i : op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}


// Three Operand Integer Minumum (Commutative, 4 unique variants) //////////////////////////////////////////////////////

IS(MIN_LLL) {
    // min(Local, Local) -> Local
    int32 i1 = OP_LOCAL(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "min.i " OPF_L ", " OPF_L ", " OPF_L " : min(%d, %d) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)i1,
        (int)i2
    );
    OP_LOCAL(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_ILL) {
    // min(Indirect, Local) -> Local
    int32 i1 = OP_INDIRECT_0(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "min.i " OPF_I0 ", " OPF_L ", " OPF_L " : min(%d, %d) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (int)i1,
        (int)i2
    );
    OP_LOCAL(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_LOCAL(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_LLI) {
    // min(Local, Local) -> Indirect
    int32 i1 = OP_LOCAL(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "min.i " OPF_L ", " OPF_L ", " OPF_I0 " : min(%d, %d) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)i1,
        (int)i2
    );
    OP_INDIRECT_0(0).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_0(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_ILI) {
    // min(Indirect, Local) -> Indirect
    int32 i1 = OP_INDIRECT_0(0).i;
    int32 i2 = OP_LOCAL(1).i;
    gvmDebugOpcode(
        "min.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : min(%d, %d) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        (int)i1,
        (int)i2
    );
    OP_INDIRECT_1(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)OP_INDIRECT_1(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("min.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : min(%d, %d) => ",
            (int)op1->i,
            (int)op2->i
        );
        op3->i = op1->i < op2->i ? op1->i : op2->i;
        gvmDebugOpcode("%d", (int)op3->i);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}
