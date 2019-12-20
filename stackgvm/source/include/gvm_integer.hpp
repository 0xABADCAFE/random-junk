
// Integer specific instructions ///////////////////////////////////////////////////////////////////////////////////////


// Decrement Integer And Branch If Not Zero ////////////////////////////////////////////////////////////////////////////

IS(DBNZ_L) {
    gvmDebugOpcode(
        "dbnz.i " OPF_L ", %d : --%d != 0 => ",
        (int)OPS(0),
        (int)J16(1),
        (int)LOC(0).i
    );
    // Decrement local and branch if not zero
    if (--LOC(0).i) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("%d ", (int)LOC(0).i);
    STEP(4);
    NEXT;
}

// Decrement Integer And Branch If Not Negative ////////////////////////////////////////////////////////////////////////

IS(DBNN_L) {
    gvmDebugOpcode(
        "dbnn.i " OPF_L ", %d : --%d >= 0 => ",
        (int)OPS(0),
        (int)J16(1),
        (int)LOC(0).i
    );
    // Decrement local and branch if not negative
    if (--LOC(0).i >= 0) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("%d ", (int)LOC(0).i);
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Load Small Integer Literal //////////////////////////////////////////////////////////////////////////////////////////

IS(LOAD_SL) {
    LOC(1).i = S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_L " : %d",
        (int)OPS(0),
        (int)OPS(1),
        (int)LOC(1).i
    );
    STEP(3);
    NEXT;
}

IS(LOAD_SI0) {
    IX0(1).i = S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_I0 " : %d",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)IX0(1).i
    );
    STEP(3);
    NEXT;
}

IS(LOAD_SI1) {
    IX1(1).i = S8(0);
    gvmDebugOpcode(
        "copy " OPF_S ", " OPF_I1 " : %d",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)IX1(1).i
    );
    STEP(3);
    NEXT;
}

// Set Single Bit //////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BSET_SL) {
    // Set bit in local
    LOC(1).u |= 1 << U8(0);
    gvmDebugOpcode(
        "bset %u, " OPF_L " : 0x%08X",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)LOC(1).u
    );
    STEP(3);
    NEXT;
}

IS(BSET_SI) {
    // Set bit in indirect
    IX0(1).u |= 1 << U8(0);
    gvmDebugOpcode(
        "bset %u, " OPF_I0 " : 0x%08X",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (unsigned)IX0(1).u
    );
    STEP(3);
    NEXT;
}

// Clear Single Bit ////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCLR_SL) {
    // Clear bit in local
    LOC(1).u &= ~(1 << U8(0));
    gvmDebugOpcode(
        "bclr %u, " OPF_L " : 0x%08X",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)LOC(1).u
    );
    STEP(3);
    NEXT;
}

IS(BCLR_SI) {
    // Clear bit in indirect
    IX0(1).u &= ~(1 << U8(0));
    gvmDebugOpcode(
        "bclr %u, " OPF_I0 " : 0x%08X",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (unsigned)IX0(1).u
    );
    STEP(3);
    NEXT;
}

// Two Operand Logical Inverse /////////////////////////////////////////////////////////////////////////////////////////

IS(NOT_LL) {
    LOC(1).u = ~LOC(0).u;
    gvmDebugOpcode(
        "not " OPF_L ", " OPF_L " : 0x%08X",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)LOC(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_IL) {
    LOC(1).u = ~IX0(0).u;
    gvmDebugOpcode(
        "not " OPF_I0 ", " OPF_L " : 0x%08X",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)LOC(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_LI) {
    IX0(1).u = ~LOC(0).u;
    gvmDebugOpcode(
        "not " OPF_L ", " OPF_I0 " : 0x%08X",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)IX0(1).u
    );
    STEP(3);
    NEXT;
}

IS(NOT_II) {
    IX1(1).u = ~IX0(0).u;
    gvmDebugOpcode(
        "not " OPF_I0 ", " OPF_I1 " : 0x%08X",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (unsigned)IX1(1).u
    );
    STEP(3);
    NEXT;
}

// Two Operand Integer Negate //////////////////////////////////////////////////////////////////////////////////////////

IS(NEG_LL) {
    LOC(1).i = -LOC(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_L ", " OPF_L " : %d",
        (int)OPS(0),
        (int)OPS(1),
        (int)LOC(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_IL) {
    LOC(1).i = -IX0(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_I0 ", " OPF_L " : %d",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)LOC(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_LI) {
    IX0(1).i = -LOC(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_L ", " OPF_I0 " : %d",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)IX0(1).i
    );
    STEP(3);
    NEXT;
}

IS(NEG_II) {
    IX1(1).i = -IX0(0).i;
    gvmDebugOpcode(
        "neg.i " OPF_I0 ", " OPF_I1 " : %d",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)IX1(1).i
    );
    STEP(3);
    NEXT;
}

// Three Operand Integer Addition (Commutative, 4 unique variants) /////////////////////////////////////////////////////

IS(ADD_LLL) {
    // Local + Local -> Local
    gvmDebugOpcode(
        "add.i " OPF_L ", " OPF_L ", " OPF_L " : %d + %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = LOC(0).i + LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_ILL) {
    // Indirect + Local -> Local
    gvmDebugOpcode(
        "add.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d + %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = IX0(0).i + LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_LLI) {
    // Local + Local -> Indirect
    gvmDebugOpcode(
        "add.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d + %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    IX0(2).i = LOC(0).i + LOC(1).i;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(ADD_ILI) {
    // Indirect + Local -> Indirect
    gvmDebugOpcode(
        "add.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d + %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)IX0(0).i,
        (int)LOC(1).i
    );
    IX1(2).i = IX0(0).i + LOC(1).i;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = LOC(0).i - LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_ILL) {
    // Indirect - Local -> Local
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d - %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = IX0(0).i - LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LLI) {
    // Local - Local -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d - %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    IX0(2).i = LOC(0).i - LOC(1).i;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_ILI) {
    // Indirect - Local -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d - %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)IX0(0).i,
        (int)LOC(1).i
    );
    IX1(2).i = IX0(0).i - LOC(1).i;
    gvmDebugOpcode("%d", (int)IX1(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LIL) {
    // Local - Indirect -> Local
    gvmDebugOpcode(
        "sub.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d - %d => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)IX0(1).i
    );
    LOC(2).i = LOC(0).i - IX0(0).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_IIL) {
    // Indirect - Indirect -> Local
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d - %d => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)IX1(1).i
    );
    LOC(2).i = IX0(0).i - IX1(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(SUB_LII) {
    // Local - Indirect -> Indirect
    gvmDebugOpcode(
        "sub.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d - %d => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)IX1(1).i
    );
    IX1(2).i = LOC(0).i - IX0(1).i;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = LOC(0).i * LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_ILL) {
    // Indirect * Local -> Local
    gvmDebugOpcode(
        "mul.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d * %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)LOC(1).i
    );
    LOC(2).i = IX0(0).i * LOC(1).i;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_LLI) {
    // Local * Local -> Indirect
    gvmDebugOpcode(
        "mul.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d * %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    IX0(2).i = LOC(0).i * LOC(1).i;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(MUL_ILI) {
    // Indirect * Local -> Indirect
    gvmDebugOpcode(
        "mul.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d * %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)LOC(1).i
    );
    IX1(2).i = IX0(0).i * LOC(1).i;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_L ", " OPF_L " : %d / %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i / denominator;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_ILL) {
    // Indirect / Local -> Local
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d / %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)denominator
    );
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i / denominator;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LLI) {
    // Local / Local -> Indirect
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d / %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX0(2).i = LOC(0).i / denominator;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_ILI) {
    // Indirect / Local -> Indirect
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d / %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = IX0(0).i / denominator;
    gvmDebugOpcode("%d", (int)IX1(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LIL) {
    // Local / Indirect -> Local
    int32 denominator = IX0(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d / %d => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i / denominator;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_IIL) {
    // Indirect / Indirect -> Local
    int32 denominator = IX1(1).i;
    gvmDebugOpcode(
        "div.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d / %d => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i / denominator;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(DIV_LII) {
    // Local / Indirect -> Indirect
    int32 denominator = IX0(1).i;
    gvmDebugOpcode(
        "div.i " OPF_L ", " OPF_I0 ", " OPF_I1 " : %d / %d => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = LOC(0).i / denominator;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_L ", " OPF_L " : %d / %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILL) {
    // Indirect % Local -> Local
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_L ", " OPF_L " : %d / %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LLI) {
    // Local % Local -> Indirect
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_L ", " OPF_I0 " : %d / %d => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX0(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILI) {
    // Indirect % Local -> Indirect
    int32 denominator = LOC(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : %d / %d => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LIL) {
    // Local % Indirect -> Local
    int32 denominator = IX0(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_I0 ", " OPF_L " : %d / %d => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_IIL) {
    // Indirect % Indirect -> Local
    int32 denominator = IX1(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_I0 ", " OPF_I1 ", " OPF_L " : %d / %d => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        (int)IX0(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LII) {
    // Local % Indirect -> Indirect
    int32 denominator = IX0(1).i;
    gvmDebugOpcode(
        "mod.i " OPF_L ", " OPF_I0 ", " OPF_I1 " : %d / %d => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        (int)LOC(0).i,
        (int)denominator
    );
    if (!denominator) {
        gvmDebugOpcode("Abort with Zero Divide");
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mod.i ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        gvmDebugOpcode(
            " : %d % %d => ",
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = LOC(0).u & LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(AND_ILL) {
    // Indirect & Local -> Local
    gvmDebugOpcode(
        "and " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X & 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = IX0(0).u & LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(AND_LLI) {
    // Local & Local -> Indirect
    gvmDebugOpcode(
        "and " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X & 0x%08X => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    IX0(2).u = LOC(0).u & LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX0(2).u);
    STEP(4);
    NEXT;
}

IS(AND_ILI) {
    // Indirect & Local -> Indirect
    gvmDebugOpcode(
        "and " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X & 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    IX1(2).u = IX0(0).u & LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX1(2).u);
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = LOC(0).u | LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(OR_ILL) {
    // Indirect | Local -> Local
    gvmDebugOpcode(
        "or " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X | 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = IX0(0).u | LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(OR_LLI) {
    // Local | Local -> Indirect
    gvmDebugOpcode(
        "or " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X | 0x%08X => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    IX0(2).u = LOC(0).u | LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX0(2).u);
    STEP(4);
    NEXT;
}

IS(OR_ILI) {
    // Indirect | Local -> Indirect
    gvmDebugOpcode(
        "or " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X | 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    IX1(2).u = IX0(0).u | LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX1(2).u);
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = LOC(0).u ^ LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_ILL) {
    // Indirect ^ Local -> Local
    gvmDebugOpcode(
        "xor " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X ^ 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = IX0(0).u ^ LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_LLI) {
    // Local ^ Local -> Indirect
    gvmDebugOpcode(
        "xor " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X ^ 0x%08X => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    IX0(2).u = LOC(0).u ^ LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX0(2).u);
    STEP(4);
    NEXT;
}

IS(XOR_ILI) {
    // Indirect ^ Local -> Indirect
    gvmDebugOpcode(
        "xor " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X ^ 0x%08X => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    IX1(2).u = IX0(0).u ^ LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX1(2).u);
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
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = LOC(0).u << LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_ILL) {
    // Indirect << Local -> Local
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X << %u => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = IX0(0).u << LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_LLI) {
    // Local << Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X << %u => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    IX0(2).u = LOC(0).u << LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX0(2).u);
    STEP(4);
    NEXT;
}

IS(LSL_ILI) {
    // Indirect << Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X << %u => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    IX1(2).u = IX0(0).u << LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX1(2).u);
    STEP(4);
    NEXT;
}

// Three Operand Logical Shift Right (Noncommutative, 4 supported variants) ////////////////////////////////////////////

IS(LSR_LLL) {
    // Local >> Local -> Local
    gvmDebugOpcode(
        "lsr " OPF_L ", " OPF_L ", " OPF_L " : 0x%08X << %u => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = LOC(0).u >> LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_ILL) {
    // Indirect >> Local -> Local
    gvmDebugOpcode(
        "lsr " OPF_I0 ", " OPF_L ", " OPF_L " : 0x%08X >> %u => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    LOC(2).u = IX0(0).u >> LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)LOC(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_LLI) {
    // Local >> Local -> Indirect
    gvmDebugOpcode(
        "lsr " OPF_L ", " OPF_L ", " OPF_I0 " : 0x%08X >> %u => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)LOC(0).u,
        (unsigned)LOC(1).u
    );
    IX0(2).u = LOC(0).u >> LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX0(2).u);
    STEP(4);
    NEXT;
}

IS(LSR_ILI) {
    // Indirect >> Local -> Indirect
    gvmDebugOpcode(
        "lsl " OPF_I0 ", " OPF_L ", " OPF_I1 " : 0x%08X >> %u => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (unsigned)IX0(0).u,
        (unsigned)LOC(1).u
    );
    IX1(2).u = IX0(0).u >> LOC(1).u;
    gvmDebugOpcode("0x%08X", (unsigned)IX1(2).u);
    STEP(4);
    NEXT;
}

// Three Operand Integer Maximum (Commutative, 4 unique variants) //////////////////////////////////////////////////////

IS(MAX_LLL) {
    // max(Local, Local) -> Local
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "max.i " OPF_L ", " OPF_L ", " OPF_L " : max(%d, %d) => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)i1,
        (int)i2
    );
    LOC(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_ILL) {
    // max(Indirect, Local) -> Local
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "max.i " OPF_I0 ", " OPF_L ", " OPF_L " : max(%d, %d) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)i1,
        (int)i2
    );
    LOC(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_LLI) {
    // max(Local, Local) -> Indirect
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "max.i " OPF_L ", " OPF_L ", " OPF_I0 " : max(%d, %d) => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)i1,
        (int)i2
    );
    IX0(0).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(MAX_ILI) {
    // max(Indirect, Local) -> Indirect
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "max.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : max(%d, %d) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)i1,
        (int)i2
    );
    IX1(2).i  = i1 > i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "min.i " OPF_L ", " OPF_L ", " OPF_L " : min(%d, %d) => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)i1,
        (int)i2
    );
    LOC(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_ILL) {
    // min(Indirect, Local) -> Local
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "min.i " OPF_I0 ", " OPF_L ", " OPF_L " : min(%d, %d) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        (int)i1,
        (int)i2
    );
    LOC(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)LOC(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_LLI) {
    // min(Local, Local) -> Indirect
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "min.i " OPF_L ", " OPF_L ", " OPF_I0 " : min(%d, %d) => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)i1,
        (int)i2
    );
    IX0(0).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)IX0(2).i);
    STEP(4);
    NEXT;
}

IS(MIN_ILI) {
    // min(Indirect, Local) -> Indirect
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    gvmDebugOpcode(
        "min.i " OPF_I0 ", " OPF_L ", " OPF_I1 " : min(%d, %d) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        (int)i1,
        (int)i2
    );
    IX1(2).i  = i1 < i2 ? i1 : i2;
    gvmDebugOpcode("%d", (int)IX1(2).i);
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
