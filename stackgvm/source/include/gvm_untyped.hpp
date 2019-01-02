
// Untyped Instructions ////////////////////////////////////////////////////////////////////////////////////////////////

IS(HCF) {
    gvmDebugOpcode(
        "hcf : Abort"
    );
    // Halt and catch fire
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Unconditional Branch (GOTO) /////////////////////////////////////////////////////////////////////////////////////////

IS(BRAS) {
    // Branch to a signed 8-bit offset
    gvmDebugOpcode(
        "bra %d : jump to %p",
        (int)J16(0),
        PRGC + J8(0)
    );
    STEP(J8(0));
    NEXT;
}

IS(BRA) {
    // Branch to a signed 16-bit offset
    gvmDebugOpcode(
        "bra %d : jump to %p",
        (int)J16(0),
        PRGC + J16(0)
    );
    STEP(J16(0));
    NEXT;
}

// Function Call ///////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCALL) {
    gvmDebugOpcode(
        "bcall %d",
        (int)J16(1)
    );
    // Call an anonymous local function
    result = enterClosure(RTA(4), J16(1), U8(0));
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(CALL) {
    gvmDebugOpcode(
        "call $%04X : ",
        (unsigned)SYM(0)
    );
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
    gvmDebugOpcode(
        "hcall $%04X : ",
        (int)SYM(0)
    );
    // Call a host function by ID
    result = invokeHostFunction(SYM(0));
    if (result != SUCCESS) {
        gvmDebugOpcode("Abort with status %d\n", (int)result);
        EXIT(result);
    }
    STEP(3);
    NEXT;
}

IS(RET) {
    gvmDebugOpcode(
        "ret : "
    );
    // Return from the current function
    result = exitFunction();
    if (result != SUCCESS) {
        std::fprintf(stderr, "\nExecuted: %llu instructions total.\n", numExecuted);
        EXIT(result);
    }
    UPDATE_PTRS;
    NEXT;
}

// Linked List Traversal ///////////////////////////////////////////////////////////////////////////////////////////////

IS(LI0BNN) {
    gvmDebugOpcode(
        "libnn (i0+%u), %d : %p != null => ",
        OPU(0),
        (int)(int)J16(1),
        IX0(0).a
    );
    // Load indirect[0] to indirection register[0] and branch if not null
    if (!(IR(0) = IX0(0).a)) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(LI1BNN) {
    gvmDebugOpcode(
        "libnn (i1+%u), %d : %p != null => ",
        OPU(0),
        (int)(int)J16(1),
        IX1(0).a
    );
    // Load indirect[1] to indirection register[1] and branch if not null
    if (!(IR(1) = IX1(0).a)) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}


// Scalar Instructions (Float Or Integer) //////////////////////////////////////////////////////////////////////////////

// Single Operand Branch If Zero ///////////////////////////////////////////////////////////////////////////////////////

IS(BEZ_L) {
    gvmDebugOpcode(
        "bez (%d), %d : 0x%08X == 0 => ",
        OPS(0),
        (int)J16(1),
        LOC(0).u
    );
    // Branch to a signed 16-bit offset if local is equal to zero
    if (0 == LOC(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(BEZ_I0) {
    gvmDebugOpcode(
        "bez (i0+%u), %d : 0x%08X == 0 => ",
        OPU(0),
        (int)J16(1),
        IX0(0).u
    );
    // Branch to a signed 16-bit offset if indirect is equal to zero
    if (0 == IX0(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(BEZ_I1) {
    gvmDebugOpcode(
        "bez (i1+%u), %d : 0x%08X == 0 => ",
        OPU(0),
        (int)J16(1),
        IX1(0).u
    );
    // Branch to a signed 16-bit offset if indirect is equal to zero
    if (0 == IX1(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Single Operand Branch If Not Zero //////////////////////////////////////////////////////////////////////////////////

IS(BNZ_L) {
    gvmDebugOpcode(
        "bnz (%d), %d : 0x%08X != 0 => ",
        OPS(0),
        (int)J16(1),
        LOC(0).u
    );
    // Branch to a signed 16-bit offset if local is not equal to zero
    if (0 != LOC(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(BNZ_I0) {
    gvmDebugOpcode(
        "bnz (i0+%u), %d : 0x%08X != 0 => ",
        OPU(0),
        (int)J16(1),
        IX0(0).u
    );
    // Branch to a signed 16-bit offset if indirect is not equal to zero
    if (0 != IX0(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(BNZ_I1) {
    gvmDebugOpcode(
        "bnz (i0+%u), %d : 0x%08X != 0 => ",
        OPU(0),
        (int)J16(1),
        IX1(0).u
    );
    // Branch to a signed 16-bit offset if indirect is not equal to zero
    if (0 != IX1(0).u) {
        gvmDebugJump(1);
        STEP(J16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Two Operand Branch If Equal /////////////////////////////////////////////////////////////////////////////////////////

IS(BEQ_LL) {
    gvmDebugOpcode(
        "beq (%d), (%d), %d : 0x%08X == 0x%08X => ",
        OPS(0),
        OPS(1),
        (int)J16(2),
        LOC(0).u,
        LOC(1).u
    );
    // Branch to a signed 16-bit offset if two local values are equal
    if (LOC(1).u == LOC(0).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(BEQ_LI) {
    gvmDebugOpcode(
        "beq (%d), (i0+%u), %d : 0x%08X == 0x%08X => ",
        OPS(0),
        OPU(1),
        (int)J16(2),
        LOC(0).u,
        IX0(1).u
    );
    // Branch to a signed 16-bit offset if local and indirect values are equal
    if (IX0(1).u == LOC(0).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(BEQ_II) {
    gvmDebugOpcode(
        "beq (i0+%u), (i1+%u), %d : 0x%08X == 0x%08X => ",
        OPU(0),
        OPU(1),
        (int)J16(2),
        IX0(0).u,
        IX1(1).u
    );
    // Branch to a signed 16-bit offset if two indirect values are equal
    if (IX0(0).u == IX1(1).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

// Two Operand Branch If Not Equal /////////////////////////////////////////////////////////////////////////////////////

IS(BNE_LL) {
    gvmDebugOpcode(
        "bne (%d), (%d), %d : 0x%08X != 0x%08X => ",
        OPS(0),
        OPS(1),
        (int)J16(2),
        LOC(0).u,
        LOC(1).u
    );
    // Branch to a signed 16-bit offset if two local values are equal
    if (LOC(1).u != LOC(0).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(BNE_LI) {
    gvmDebugOpcode(
        "bne (%d), (i0+%u), %d : 0x%08X != 0x%08X => ",
        OPS(0),
        OPU(1),
        (int)J16(1),
        LOC(0).u,
        IX0(1).u
    );
    // Branch to a signed 16-bit offset if local and indirect values are equal
    if (IX0(1).u != LOC(0).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(BNE_II) {
    gvmDebugOpcode(
        "bne (i0+%u), (i1+%u), %d : 0x%08X != 0x%08X => ",
        OPU(0),
        OPU(1),
        (int)J16(2),
        IX0(0).u,
        IX1(1).u
    );
    // Branch to a signed 16-bit offset if two indirect values are equal
    if (IX0(0).u != IX1(1).u) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

// Addressing Operations //////////////////////////////////////////////////////////////////////////////////////////////

IS(ADDR_LL) {
    // Get address of local variable into local variable
    LOC(1).a = &LOC(0);
    gvmDebugOpcode(
        "addr (%d), (%d) : %p",
        OPS(0),
        OPS(1),
        LOC(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_I0L) {
    // Get address of indirect [0] variable into local variable
    LOC(1).a = &IX0(0);
    gvmDebugOpcode(
        "addr (i0+%u), (%d) : %p",
        OPU(0),
        OPS(1),
        LOC(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_I1L) {
    // Get address of indirect [1] variable into local variable
    LOC(1).a = &IX1(0);
    gvmDebugOpcode(
        "addr (i1+%u), (%d) : %p",
        OPU(0),
        OPS(1),
        LOC(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_DL) {
    // Load the address of a global data symbol to a local variable
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "addr $%04X, (%d) : ",
        symbolId,
        OPS(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    LOC(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI0) {
    // Load the address of a global data symbol to an indirect [0] variable
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "addr $%04X, (i0+%u) : ",
        symbolId,
        OPU(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    IX0(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI1) {
    // Load the address of a global data symbol to an indirect [1] variable
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "addr $%04X, (i1+%u) : ",
        symbolId,
        OPU(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    IX1(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_D0) {
    // Load the address of a global data symbol directly into an index register
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "addr $%04X, i0 : ",
        symbolId
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    IR(0) = dataTable[symbolId];
    SAVE_IR(0);
    STEP(3);
    NEXT;
}

IS(ADDR_D1) {
    // Load the address of a global data symbol directly into an index register
    uint32 symbolId = SYM(0);
    gvmDebugOpcode(
        "addr $%04X, i1 : ",
        symbolId
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
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
        "copy (%d), (%d) : 0x%08X",
        OPS(0),
        OPS(1),
        LOC(0).u
    );

    LOC(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I0L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "copy (i0+%u), (%d) : 0x%08X",
        OPU(0),
        OPS(1),
        IX0(0).u
    );

    LOC(1).u = IX0(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I1L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "copy (i1+%u) (%d) : 0x%08X",
        OPU(0),
        OPS(1),
        IX1(0).u
    );
    LOC(1).u = IX1(0).u;
    STEP(3);
    NEXT;
}

IS(CPIX_I0L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "copy (i0+%u)[(%d)], (%d) : [%u] => 0x%08X",
        OPU(0),
        OPS(1),
        OPS(2),
        LOC(1).u,
        UIX0(0)[LOC(1).u]
    );
    LOC(2).u = UIX0(0)[LOC(1).u];
    STEP(4);
    NEXT;
}

IS(CPIX_I1L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "copy (i1+%u)[(%d)], (%d) : [%u] => 0x%08X",
        OPU(0),
        OPS(1),
        OPS(2),
        LOC(1).u,
        UIX1(0)[LOC(1).u]
    );
    LOC(2).u = UIX1(0)[LOC(1).u];
    STEP(4);
    NEXT;
}

IS(COPY_LI0) {
    gvmDebugOpcode(
        "copy (%d), (i0+%u) : 0x%08X",
        OPS(0),
        OPU(1),
        LOC(0).u
    );
    // Copy a local scalar to an indirect
    IX0(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_LI1) {
    gvmDebugOpcode(
        "copy (%d), (i0+%u) : 0x%08X",
        OPS(0),
        OPU(1),
        LOC(0).u
    );
    // Copy a local scalar to an indirect
    IX1(1).u = LOC(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_II) {
    gvmDebugOpcode(
        "copy (i0+%u), (i1+%u) : 0x%08X",
        OPU(0),
        OPU(1),
        IX0(0).u
    );
    // Copy an indirect scalar to another indirect
    IX1(1).u = IX0(0).u;
    STEP(3);
    NEXT;
}

// Type Conversion Operations //////////////////////////////////////////////////////////////////////////////////////////

IS(ITOF_LL) {
    // Cast integer to float
    gvmDebugOpcode(
        "ito.f (%d), (%d) : %d => ",
        OPU(0),
        OPS(1),
        LOC(0).i
    );
    LOC(1).f = (float32)LOC(0).i;
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FTOI_LL) {
    // Cast float to integer
    gvmDebugOpcode(
        "fto.i (%d), (%d) : %e => ",
        OPU(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).i = (int32)LOC(0).f;
    gvmDebugOpcode("%d", LOC(1).i);
    STEP(3);
    NEXT;
}
