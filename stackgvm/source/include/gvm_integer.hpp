
// Integer specific instructions ///////////////////////////////////////////////////////////////////////////////////////

// Two Operand Branch If Integer Greater Or Equal //////////////////////////////////////////////////////////////////////

IS(BGE_LL) {
    if (LOC(0).i >= LOC(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGE_IL) {
    if (IX0(0).i >= LOC(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGE_LI) {
    if (LOC(0).i >= IX0(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGE_II) {
    if (IX0(0).i >= IX1(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

// Two Operand Branch If Integer Greater Than //////////////////////////////////////////////////////////////////////////

IS(BGT_LL) {
    if (LOC(0).i > LOC(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGT_IL) {
    if (IX0(0).i > LOC(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGT_LI) {
    if (LOC(0).i > IX0(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BGT_II) {
    if (IX0(0).i > IX1(1).i) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

// Decrement Integer And Branch If Not Zero ////////////////////////////////////////////////////////////////////////////

IS(DBNZ_L) {
    gvmDebugOpcode(
        "\tdbnz %d(sf), %d : {%d} => ",
        OPS(0),
        (int)J16(1),
        LOC(0).i
    );
    // Decrement local and branch if not zero
    if (--LOC(0).i) {
        gvmDebugOpcode("{%d} ", (int)LOC(0).i);
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("{%d} ", (int)LOC(0).i);
    STEP(4);
    NEXT;
}

// Decrement Integer And Branch If Not Negative ////////////////////////////////////////////////////////////////////////

IS(DBNN_L) {
    gvmDebugOpcode(
        "\tdbnn %d(sf), %d : {%d} => ",
        OPS(0),
        (int)J16(1),
        LOC(0).i
    );
    // Decrement local and branch if not negative
    if (--LOC(0).i >= 0) {
        gvmDebugOpcode("{%d} ", (int)LOC(0).i);
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("{%d} ", (int)LOC(0).i);
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Load Small Integer Literal //////////////////////////////////////////////////////////////////////////////////////////

IS(LOAD_SL) {
    LOC(1).i = S8(0);
    STEP(3);
    NEXT;
}

IS(LOAD_SI0) {
    IX0(1).i = S8(0);
    STEP(3);
    NEXT;
}

IS(LOAD_SI1) {
    IX1(1).i = S8(0);
    STEP(3);
    NEXT;
}

// Set Single Bit //////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BSET_SL) {
    // Set bit in local
    LOC(1).u |= 1 << U8(0);
    STEP(3);
    NEXT;
}

IS(BSET_SI) {
    // Set bit in indirect
    IX0(1).u |= 1 << U8(0);
    STEP(3);
    NEXT;
}

// Clear Single Bit ////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCLR_SL) {
    // Clear bit in local
    LOC(1).u &= ~(1 << U8(0));
    STEP(3);
    NEXT;
}

IS(BCLR_SI) {
    // Clear bit in indirect
    IX0(1).u &= ~(1 << U8(0));
    STEP(3);
    NEXT;
}

// Branch If Bit Set ///////////////////////////////////////////////////////////////////////////////////////////////////

IS(BBS_SL) {
    // Branch if bit is set (local)
    if ( LOC(1).u & (1 << U8(0)) ) {
        STEP(J16(2));
        NEXT;
    }
    STEP(3);
    NEXT;
}

IS(BBS_SI) {
    // Branch if bit is set (indirect)
    if ( IX0(1).u & (1 << U8(0)) ) {
        STEP(J16(2));
        NEXT;
    }
    STEP(3);
    NEXT;
}

// Branch If Bit Clear /////////////////////////////////////////////////////////////////////////////////////////////////

IS(BBC_SL) {
    // Branch if bit is clear (local)
    if (!(LOC(1).u & (1 << U8(0)))) {
        STEP(J16(2));
        NEXT;
    }
    STEP(3);
    NEXT;
}

IS(BBC_SI) {
    // Branch if bit is clear (indirect)
    if (!(IX0(1).u & (1 << U8(0)))) {
        STEP(J16(2));
        NEXT;
    }
    STEP(3);
    NEXT;
}

// Two Operand Logical Inverse /////////////////////////////////////////////////////////////////////////////////////////

IS(NOT_LL) {
    LOC(1).u = ~LOC(0).u;
    STEP(3);
    NEXT;
}

IS(NOT_IL) {
    LOC(1).u = ~IX0(0).u;
    STEP(3);
    NEXT;
}

IS(NOT_LI) {
    IX0(1).u = ~LOC(0).u;
    STEP(3);
    NEXT;
}

IS(NOT_II) {
    IX1(1).u = ~IX0(0).u;
    STEP(3);
    NEXT;
}

// Two Operand Integer Negate //////////////////////////////////////////////////////////////////////////////////////////

IS(NEG_LL) {
    LOC(1).u = -LOC(0).u;
    STEP(3);
    NEXT;
}

IS(NEG_IL) {
    LOC(1).u = -IX0(0).u;
    STEP(3);
    NEXT;
}

IS(NEG_LI) {
    IX0(1).u = -LOC(0).u;
    STEP(3);
    NEXT;
}

IS(NEG_II) {
    IX1(1).u = -IX0(0).u;
    STEP(3);
    NEXT;
}

// Three Operand Integer Addition (Commutative, 4 unique variants) /////////////////////////////////////////////////////

IS(ADD_LLL) {
    // Local + Local -> Local
    LOC(2).i = LOC(0).i + LOC(1).i;
    STEP(4);
    NEXT;
}

IS(ADD_ILL) {
    // Indirect + Local -> Local
    LOC(2).i = IX0(0).i + LOC(1).i;
    STEP(4);
    NEXT;
}

IS(ADD_LLI) {
    // Local + Local -> Indirect
    IX0(2).i = LOC(0).i + LOC(1).i;
    STEP(4);
    NEXT;
}

IS(ADD_ILI) {
    // Indirect + Local -> Indirect
    IX1(2).i = IX0(0).i + LOC(1).i;
    STEP(4);
    NEXT;
}

// Three operand Integer Subtraction (Noncommutative, 7 unique variants) ///////////////////////////////////////////////

IS(SUB_LLL) {
    // Local - Local -> Local
    LOC(2).i = LOC(0).i - LOC(1).i;
    STEP(4);
    NEXT;
}

IS(SUB_ILL) {
    // Indirect - Local -> Local
    LOC(2).i = IX0(0).i - LOC(1).i;
    STEP(4);
    NEXT;
}

IS(SUB_LLI) {
    // Local - Local -> Indirect
    IX0(2).i = LOC(0).i - LOC(1).i;
    STEP(4);
    NEXT;
}

IS(SUB_ILI) {
    // Indirect - Local -> Indirect
    IX1(2).i = IX0(0).i - LOC(1).i;
    STEP(4);
    NEXT;
}

IS(SUB_LIL) {
    // Local - Indirect -> Local
    LOC(2).i = LOC(0).i - IX0(0).i;
    STEP(4);
    NEXT;
}

IS(SUB_IIL) {
    // Indirect - Indirect -> Local
    LOC(2).i = IX0(0).i - IX1(1).i;
    STEP(4);
    NEXT;
}

IS(SUB_LII) {
    // Local - Indirect -> Indirect
    IX1(2).i = LOC(0).i - IX0(1).i;
    STEP(4);
    NEXT;
}

// Three Operand Integer Multiplication (Commutative, 4 unique variants) ///////////////////////////////////////////////

IS(MUL_LLL) {
    // Local * Local -> Local
    LOC(2).i = LOC(0).i * LOC(1).i;
    STEP(4);
    NEXT;
}

IS(MUL_ILL) {
    // Indirect * Local -> Local
    LOC(2).i = IX0(0).i * LOC(1).i;
    STEP(4);
    NEXT;
}

IS(MUL_LLI) {
    // Local * Local -> Indirect
    IX0(2).i = LOC(0).i * LOC(1).i;
    STEP(4);
    NEXT;
}

IS(MUL_ILI) {
    // Indirect * Local -> Indirect
    IX1(2).i = IX0(0).i * LOC(1).i;
    STEP(4);
    NEXT;
}

// Three Operand Integer Division (Noncommutative, 7 unique variants) //////////////////////////////////////////////////

IS(DIV_LLL) {
    // Local / Local -> Local

    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_ILL) {
    // Indirect / Local -> Local
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_LLI) {
    // Local / Local -> Indirect
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX0(2).i = LOC(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_ILI) {
    // Indirect / Local -> Indirect
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = IX0(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_LIL) {
    // Local / Indirect -> Local
    int32 denominator = IX0(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_IIL) {
    // Indirect / Indirect -> Local
    int32 denominator = IX1(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i / denominator;
    STEP(4);
    NEXT;
}

IS(DIV_LII) {
    // Local / Indirect -> Indirect
    int32 denominator = IX0(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = LOC(0).i / denominator;
    STEP(4);
    NEXT;
}

// Three Operand Integer Modulo (Noncommutative, 7 unique variants) ////////////////////////////////////////////////////

IS(MOD_LLL) {
    // Local % Local -> Local
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILL) {
    // Indirect % Local -> Local
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LLI) {
    // Local % Local -> Indirect
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX0(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_ILI) {
    // Indirect % Local -> Indirect
    int32 denominator = LOC(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LIL) {
    // Local % Indirect -> Local
    int32 denominator = IX0(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_IIL) {
    // Indirect % Indirect -> Local
    int32 denominator = IX1(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    LOC(2).i = IX0(0).i % denominator;
    STEP(4);
    NEXT;
}

IS(MOD_LII) {
    // Local % Indirect -> Indirect
    int32 denominator = IX0(1).i;
    if (!denominator) {
        EXIT(EXEC_DIVISION_BY_ZERO);
    }
    IX1(2).i = LOC(0).i % denominator;
    STEP(4);
    NEXT;
}

// Three Operand Logical AND (Commutative, 4 unique variants) //////////////////////////////////////////////////////////

IS(AND_LLL) {
    // Local & Local -> Local
    LOC(2).u = LOC(0).u & LOC(1).u;
    STEP(4);
    NEXT;
}

IS(AND_ILL) {
    // Indirect & Local -> Local
    LOC(2).u = IX0(0).u & LOC(1).u;
    STEP(4);
    NEXT;
}

IS(AND_LLI) {
    // Local & Local -> Indirect
    IX0(2).u = LOC(0).u & LOC(1).u;
    STEP(4);
    NEXT;
}

IS(AND_ILI) {
    // Indirect & Local -> Indirect
    IX1(2).u = IX0(0).u & LOC(1).u;
    STEP(4);
    NEXT;
}

// Three Operand Logical OR (Commutative, 4 unique variants) ///////////////////////////////////////////////////////////

IS(OR_LLL) {
    // Local | Local -> Local
    LOC(2).u = LOC(0).u | LOC(1).u;
    STEP(4);
    NEXT;
}

IS(OR_ILL) {
    // Indirect | Local -> Local
    LOC(2).u = IX0(0).u | LOC(1).u;
    STEP(4);
    NEXT;
}

IS(OR_LLI) {
    // Local | Local -> Indirect
    IX0(2).u = LOC(0).u | LOC(1).u;
    STEP(4);
    NEXT;
}

IS(OR_ILI) {
    // Indirect | Local -> Indirect
    IX1(2).u = IX0(0).u | LOC(1).u;
    STEP(4);
    NEXT;
}

// Three Operand Logical XOR (Commutative, 4 unique variants) //////////////////////////////////////////////////////////

IS(XOR_LLL) {
    // Local ^ Local -> Local
    LOC(2).u = LOC(0).u ^ LOC(1).u;
    STEP(4);
    NEXT;
}

IS(XOR_ILL) {
    // Indirect ^ Local -> Local
    LOC(2).u = IX0(0).u ^ LOC(1).u;
    STEP(4);
    NEXT;
}

IS(XOR_LLI) {
    // Local ^ Local -> Indirect
    IX0(2).u = LOC(0).u ^ LOC(1).u;
    STEP(4);
    NEXT;
}

IS(XOR_ILI) {
    // Indirect ^ Local -> Indirect
    IX1(2).u = IX0(0).u ^ LOC(1).u;
    STEP(4);
    NEXT;
}

// Three Operand Logical Shift Left (Noncommutative, 4 supported variants) /////////////////////////////////////////////

IS(LSL_LLL) {
    // Local << Local -> Local
    LOC(2).u = LOC(0).u << LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSL_ILL) {
    // Indirect << Local -> Local
    LOC(2).u = IX0(0).u << LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSL_LLI) {
    // Local << Local -> Indirect
    IX0(2).u = LOC(0).u << LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSL_ILI) {
    // Indirect << Local -> Indirect
    IX1(2).u = IX0(0).u << LOC(1).u;
    STEP(4);
    NEXT;
}

// Three Operand Logical Shift Right (Noncommutative, 4 supported variants) ////////////////////////////////////////////

IS(LSR_LLL) {
    // Local >> Local -> Local
    LOC(2).u = LOC(0).u >> LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSR_ILL) {
    // Indirect >> Local -> Local
    LOC(2).u = IX0(0).u >> LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSR_LLI) {
    // Local >> Local -> Indirect
    IX0(2).u = LOC(0).u >> LOC(1).u;
    STEP(4);
    NEXT;
}

IS(LSR_ILI) {
    // Indirect >> Local -> Indirect
    IX1(2).u = IX0(0).u >> LOC(1).u;
    STEP(4);
    NEXT;
}

// Three Operand Integer Maximum (Commutative, 4 unique variants) //////////////////////////////////////////////////////

IS(MAX_LLL) {
    // max(Local, Local) -> Local
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    LOC(2).i  = i1 > i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MAX_ILL) {
    // max(Indirect, Local) -> Local
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    LOC(2).i  = i1 > i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MAX_LLI) {
    // max(Local, Local) -> Indirect
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    IX0(0).i  = i1 > i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MAX_ILI) {
    // max(Indirect, Local) -> Indirect
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    IX1(2).i  = i1 > i2 ? i1 : i2;
    STEP(4);
    NEXT;
}


// Three Operand Integer Minumum (Commutative, 4 unique variants) //////////////////////////////////////////////////////

IS(MIN_LLL) {
    // min(Local, Local) -> Local
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    LOC(2).i  = i1 < i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MIN_ILL) {
    // min(Indirect, Local) -> Local
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    LOC(2).i  = i1 < i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MIN_LLI) {
    // min(Local, Local) -> Indirect
    int32 i1 = LOC(0).i;
    int32 i2 = LOC(1).i;
    IX0(0).i  = i1 < i2 ? i1 : i2;
    STEP(4);
    NEXT;
}

IS(MIN_ILI) {
    // min(Indirect, Local) -> Indirect
    int32 i1 = IX0(0).i;
    int32 i2 = LOC(1).i;
    IX1(2).i  = i1 < i2 ? i1 : i2;
    STEP(4);
    NEXT;
}
