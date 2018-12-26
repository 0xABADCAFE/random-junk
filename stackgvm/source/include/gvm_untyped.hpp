
// Untyped Instructions ////////////////////////////////////////////////////////////////////////////////////////////////

IS(HCF) {
    // Halt and catch fire
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Unconditional Branch (GOTO) /////////////////////////////////////////////////////////////////////////////////////////

IS(BRAS) {
    // Branch to a signed 8-bit offset
    STEP(J8(0));
    NEXT;
}

IS(BRA) {
    // Branch to a signed 16-bit offset
    STEP(J16(0));
    NEXT;
}

// Function Call ///////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCALL) {
    // Call an anonymous local function
    result = enterClosure(RTA(4), J16(1), U8(0));
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(CALL) {
    // Call a named function by ID
    result = enterFunction(RTA(3), SYM(0));
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(ICALL_L) {
    // Call a named function by ID stored in local refrence. Must be tagged with TAG_CODE_REFERENCE
    tag = LOC(0).u;
    if ((tag & TAG_MASK_REFERENCE) != TAG_CODE_REFERENCE) {
        EXIT(EXEC_ILLEGAL_CALL_ID);
    }
    result = enterFunction(RTA(2), tag & 0xFFFF);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(ICALL_I) {
    // Call a named function by ID stored in an indirect reference. Must be tagged with TAG_CODE_REFERENCE
    tag = IX(0, 1).u;
    if ((tag & TAG_MASK_REFERENCE) != TAG_CODE_REFERENCE) {
        EXIT(EXEC_ILLEGAL_CALL_ID);
    }
    result = enterFunction(RTA(3), tag & 0xFFFF);
#ifdef _GVM_OPT_ALLOW_GOTO_
    gvm_untyped_handle_exit:
#endif
#include "gvm_untyped_handle_exit.hpp"
}

IS(HCALL) {
    // Call a host function by ID
    result = invokeHostFunction(SYM(0));
    if (result != SUCCESS) {
        EXIT(result);
    }
    STEP(3);
    NEXT;
}

IS(RET) {
    // Return from the current function
    result = exitFunction();
    if (result != SUCCESS) {
        std::fprintf(stderr, "\nExecuted: %d instructions total.\n", numExecuted);
        EXIT(result);
    }
    UPDATE_PTRS;
    NEXT;
}

// Linked List Traversal ///////////////////////////////////////////////////////////////////////////////////////////////

IS(LI0BNN) {
    gvmDebugOpcode(
        "\tlibnn %u(i0) : {%p} => ",
        OPU(0),
        IX0(0).a
    );
    // Load indirect[0] to indirection register[0] and branch if not null
    if (!(IR(0) = IX0(0).a)) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

IS(LI1BNN) {
    gvmDebugOpcode(
        "\tlibnn %u(i1) : {%p} => ",
        OPU(0),
        IX1(0).a
    );
    // Load indirect[1] to indirection register[1] and branch if not null
    if (!(IR(1) = IX1(0).a)) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}


// Scalar Instructions (Float Or Integer) //////////////////////////////////////////////////////////////////////////////

// Single Operand Branch If Zero ///////////////////////////////////////////////////////////////////////////////////////

IS(BEZ_L) {
    gvmDebugOpcode(
        "\tbez %d(sf) : {%u} => ",
        OPS(0),
        LOC(0).u
    );
    // Branch to a signed 16-bit offset if local is equal to zero
    if (0 == LOC(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

IS(BEZ_I0) {
    gvmDebugOpcode(
        "\tbez %u(i0) : {%u} => ",
        OPU(0),
        IX0(0).u
    );
    // Branch to a signed 16-bit offset if indirect is equal to zero
    if (0 == IX0(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

IS(BEZ_I1) {
    gvmDebugOpcode(
        "\tbez %u(i1) : {%u} => ",
        OPU(0),
        IX1(0).u
    );
    // Branch to a signed 16-bit offset if indirect is equal to zero
    if (0 == IX1(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

// Single Operand Branch If Not Zero //////////////////////////////////////////////////////////////////////////////////

IS(BNZ_L) {
    gvmDebugOpcode(
        "\tbnz %d(sf) : {%u} => ",
        OPS(0),
        LOC(0).u
    );
    // Branch to a signed 16-bit offset if local is not equal to zero
    if (0 != LOC(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

IS(BNZ_I0) {
    gvmDebugOpcode(
        "\tbnz %u(i0) : {%u} => ",
        OPU(0),
        IX0(0).u
    );
    // Branch to a signed 16-bit offset if indirect is not equal to zero
    if (0 != IX0(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

IS(BNZ_I1) {
    gvmDebugOpcode(
        "\tbnz %u(i0) : {%u} => ",
        OPU(0),
        IX1(0).u
    );
    // Branch to a signed 16-bit offset if indirect is not equal to zero
    if (0 != IX1(0).u) {
        gvmDebugOpcode("taken %d\n", (int)J16(1));
        STEP(J16(1));
        NEXT;
    }
    gvmDebugOpcode("not taken\n");
    STEP(4);
    NEXT;
}

// Two Operand Branch If Equal /////////////////////////////////////////////////////////////////////////////////////////

IS(BEQ_LL) {
    // Branch to a signed 16-bit offset if two local values are equal
    if (LOC(1).u == LOC(0).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BEQ_LI) {
    // Branch to a signed 16-bit offset if local and indirect values are equal
    if (IX0(1).u == LOC(0).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BEQ_II) {
    // Branch to a signed 16-bit offset if two indirect values are equal
    if (IX0(0).u == IX1(1).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

// Two Operand Branch If Not Equal /////////////////////////////////////////////////////////////////////////////////////

IS(BNE_LL) {
    // Branch to a signed 16-bit offset if two local values are equal
    if (LOC(1).u != LOC(0).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BNE_LI) {
    // Branch to a signed 16-bit offset if local and indirect values are equal
    if (IX0(1).u != LOC(0).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

IS(BNE_II) {
    // Branch to a signed 16-bit offset if two indirect values are equal
    if (IX0(0).u != IX1(1).u) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;
}

// Addressing Operations //////////////////////////////////////////////////////////////////////////////////////////////

IS(ADDR_LL) {
    // Get address of local variable into local variable
    LOC(1).a = &LOC(0);
    STEP(3);
    NEXT;
}

IS(ADDR_I0L) {
    // Get address of indirect [0] variable into local variable
    LOC(1).a = &IX0(0);
    STEP(3);
    NEXT;
}

IS(ADDR_I1L) {
    // Get address of indirect [1] variable into local variable
    LOC(1).a = &IX1(0);
    STEP(3);
    NEXT;
}

IS(ADDR_DL) {
    // Load the address of a global data symbol to a local variable
    uint32 symbolId = SYM(0);
    if (!symbolId) {
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    LOC(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI0) {
    // Load the address of a global data symbol to an indirect [0] variable
    uint32 symbolId = SYM(0);
    if (!symbolId) {
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    IX0(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI1) {
    // Load the address of a global data symbol to an indirect [1] variable
    uint32 symbolId = SYM(0);
    if (!symbolId) {
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    IX1(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_D0) {
    // Load the address of a global data symbol directly into an index register
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "\taddr %u(globals) ",
        symbolId
    );
    if (!symbolId) {
        gvmDebugOpcode(", i0 : illegal symbol id\n");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("{%p}, i0\n", (void*)dataTable[symbolId]);
    IR(0) = dataTable[symbolId];
    SAVE_IR(0);
    STEP(3);
    NEXT;
}

IS(ADDR_D1) {
    // Load the address of a global data symbol directly into an index register
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "\taddr %u(globals) ",
        symbolId
    );
    if (!symbolId) {
        gvmDebugOpcode(", i1 : illegal symbol id\n");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("{%p}, i1\n", (void*)dataTable[symbolId]);
    IR(1) = dataTable[symbolId];
    SAVE_IR(1);
    STEP(3);
    NEXT;
}


IS(ADDR_CL) {
    // Load code symbol to local variable
    LOC(2).u = SYM(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

IS(ADDR_CI0) {
    // Load code symbol to indirect variable
    IX0(2).u = SYM(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

IS(ADDR_CI1) {
    // Load code symbol to indirect variable
    IX1(2).u = SYM(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

// Data Movement Operations ////////////////////////////////////////////////////////////////////////////////////////////

IS(LOAD_L0) {
    // Load local reference to index register
    IR(0) = &LOC(0);
    SAVE_IR(0);
    STEP(2);
    NEXT;
}

IS(LOAD_L1) {
    // Load local reference to index register
    IR(1) = &LOC(0);
    SAVE_IR(1);
    STEP(2);
    NEXT;
}

IS(SAVE_0L) {
    // Save indirection index to local
    LOC(0).a = IR(0);
    STEP(2);
    NEXT;
}

IS(SAVE_1L) {
    // Save indirection index to local
    LOC(0).a = IR(1);
    STEP(2);
    NEXT;
}

IS(LOAD_HL) {
    // Load host lookup to local
    STEP(3);
    NEXT;
}

IS(COPY_LL) {
    // Copy a local scalar to a local scalar
    gvmDebugOpcode(
        "\tcopy %d(sf) {%u}, %d(sf)\n",
        OPS(0),
        LOC(0).u,
        OPS(1)
    );

    LOC(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I0L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "\tcopy %u(i0) {%u}, %d(sf)\n",
        OPU(0),
        IX0(0).u,
        OPS(1)
    );

    LOC(1).u = IX0(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I1L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "\tcopy %u(i1) {%u}, %d(sf)\n",
        OPU(0),
        IX1(0).u,
        OPS(1)
    );
    LOC(1).u = IX1(0).u;
    STEP(3);
    NEXT;
}

IS(CPIX_I0L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "\tcopy %u(i0)[%d(sf) {%u}] {%u}, %d(sf)\n",
        OPU(0),
        OPS(1),
        LOC(1).u,
        UIX0(0)[LOC(1).u],
        OPS(2)
    );
    LOC(2).u = UIX0(0)[LOC(1).u];
    STEP(4);
    NEXT;
}

IS(CPIX_I1L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "\tcopy %u(i1)[%d(sf) {%u}] {%u}, %d(sf)\n",
        OPU(0),
        OPS(1),
        LOC(1).u,
        UIX1(0)[LOC(1).u],
        OPS(2)
    );
    LOC(2).u = UIX1(0)[LOC(1).u];
    STEP(4);
    NEXT;
}

IS(COPY_LI0) {
    // Copy a local scalar to an indirect
    IX0(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_LI1) {
    // Copy a local scalar to an indirect
    IX0(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_II) {
    // Copy an indirect scalar to another indirect
    IX1(1).u = IX0(0).u;
    STEP(3);
    NEXT;
}

// Type Conversion Operations //////////////////////////////////////////////////////////////////////////////////////////

IS(ITOF_LL) {
    // Cast integer to float
    gvmDebugOpcode(
        "\titof %d(sf) {%d}, %d(sf) => ",
        OPU(0),
        LOC(0).i,
        OPS(1)
    );
    LOC(1).f = (float32)LOC(0).i;
    gvmDebugOpcode("{%.6f}\n", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FTOI_LL) {
    // Cast float to integer
    gvmDebugOpcode(
        "\titof %d(sf) {%.6f}, %d(sf) => ",
        OPU(0),
        LOC(0).f,
        OPS(1)
    );
    LOC(1).i = (int32)LOC(0).f;
    gvmDebugOpcode("{%d}\n", LOC(1).i);
    STEP(3);
    NEXT;
}


