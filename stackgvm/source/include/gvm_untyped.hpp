
// Untyped Instructions ////////////////////////////////////////////////////////////////////////////////////////////////

IS(HCF) {
    gvmDebugOpcode(
        "hcf : Abort"
    );
    // Halt and catch fire
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Unconditional Branch (GOTO) /////////////////////////////////////////////////////////////////////////////////////////

IS(BRA) {
    // Branch to a signed 16-bit offset
    gvmDebugOpcode(
        "bra %d : jump to %p",
        (int)OP_JUMP_S16(0),
        PRGC + OP_JUMP_S16(0)
    );
    STEP(OP_JUMP_S16(0));
    NEXT;
}

// Function Call ///////////////////////////////////////////////////////////////////////////////////////////////////////

IS(BCALL) {
    gvmDebugOpcode(
        "bcall %d",
        (int)OP_JUMP_S16(1)
    );
    // Call an anonymous local function
    result = enterClosure(RETURN_ADDRESS(4), OP_JUMP_S16(1), OP_LITERAL_U8(0));
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(CALL) {
    gvmDebugOpcode(
        "call @%04X : ",
        (unsigned)OP_SYMBOL_ID(0)
    );
    // Call a named function by ID
    result = enterFunction(RETURN_ADDRESS(3), OP_SYMBOL_ID(0));
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(ICALL_L) {
    // Call a named function by ID stored in local refrence. Must be tagged with TAG_CODE_REFERENCE
    tag = OP_LOCAL(0).u;
    if ((tag & TAG_MASK_REFERENCE) != (uint32)TAG_CODE_REFERENCE) {
        EXIT(EXEC_ILLEGAL_CALL_ID);
    }
    result = enterFunction(RETURN_ADDRESS(2), tag & 0xFFFF);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto gvm_untyped_handle_exit;
#else
    #include "gvm_untyped_handle_exit.hpp"
#endif
}

IS(ICALL_I) {
    // Call a named function by ID stored in an indirect reference. Must be tagged with TAG_CODE_REFERENCE
    tag = OP_INDIRECT(0, 1).u;
    if ((tag & TAG_MASK_REFERENCE) != (uint32)TAG_CODE_REFERENCE) {
        EXIT(EXEC_ILLEGAL_CALL_ID);
    }
    result = enterFunction(RETURN_ADDRESS(3), tag & 0xFFFF);
#ifdef _GVM_OPT_ALLOW_GOTO_
    gvm_untyped_handle_exit:
#endif
#include "gvm_untyped_handle_exit.hpp"
}

IS(HCALL) {
    gvmDebugOpcode(
        "host #%04X : ",
        (int)OP_SYMBOL_ID(0)
    );
    // Call a host function by ID
    result = invokeHostFunction(OP_SYMBOL_ID(0));
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
        std::fprintf(stderr, "\nExecuted: %" FU64 " instructions total.\n", numExecuted);
        DUMP_OPCODE_COUNTS;
        EXIT(result);
    }
    UPDATE_PTRS;
    NEXT;
}

// Linked List Traversal ///////////////////////////////////////////////////////////////////////////////////////////////

IS(LI0BNN) {
    gvmDebugOpcode(
        "libnn " OPF_I0 ", %d : %p != null => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_JUMP_S16(1),
        OP_INDIRECT_0(0).a
    );
    // Load indirect[0] to indirection register[0] and branch if not null
    if (!(IR(0) = OP_INDIRECT_0(0).a)) {
        gvmDebugJump(1);
        STEP(OP_JUMP_S16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

IS(LI1BNN) {
    gvmDebugOpcode(
        "libnn " OPF_I1 ", %d : %p != null => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_JUMP_S16(1),
        OP_INDIRECT_1(0).a
    );
    // Load indirect[1] to indirection register[1] and branch if not null
    if (!(IR(1) = OP_INDIRECT_1(0).a)) {
        gvmDebugJump(1);
        STEP(OP_JUMP_S16(1));
        NEXT;
    }
    gvmDebugSkip();
    STEP(4);
    NEXT;
}

// Scalar Instructions (Float Or Integer) //////////////////////////////////////////////////////////////////////////////

// Addressing Operations //////////////////////////////////////////////////////////////////////////////////////////////

IS(ADDR_LL) {
    // Get address of local variable into local variable
    OP_LOCAL(1).a = &OP_LOCAL(0);
    gvmDebugOpcode(
        "addr " OPF_L ", " OPF_L " : %p",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_I0L) {
    // Get address of indirect [0] variable into local variable
    OP_LOCAL(1).a = &OP_INDIRECT_0(0);
    gvmDebugOpcode(
        "addr " OPF_I0 ", " OPF_L " : %p",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_I1L) {
    // Get address of indirect [1] variable into local variable
    OP_LOCAL(1).a = &OP_INDIRECT_1(0);
    gvmDebugOpcode(
        "addr " OPF_I1 ", " OPF_L " : %p",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(1).a
    );
    STEP(3);
    NEXT;
}

IS(ADDR_DL) {
    // Load the address of a global data symbol to a local variable
    uint32 symbolId = OP_SYMBOL_ID(0);
    gvmDebugOpcode(
        "addr $%04X, " OPF_L " : ",
        (unsigned)symbolId,
        (int)OP_LITERAL_S8(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    OP_LOCAL(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI0) {
    // Load the address of a global data symbol to an indirect [0] variable
    uint32 symbolId = OP_SYMBOL_ID(0);
    gvmDebugOpcode(
        "addr $%04X, " OPF_I0 " : ",
        (unsigned)symbolId,
        (unsigned)OP_LITERAL_U8(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    OP_INDIRECT_0(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_DI1) {
    // Load the address of a global data symbol to an indirect [1] variable
    uint32 symbolId = OP_SYMBOL_ID(0);
    gvmDebugOpcode(
        "addr $%04X, " OPF_I1 " : ",
        (unsigned)symbolId,
        (unsigned)OP_LITERAL_U8(2)
    );
    if (!symbolId) {
        gvmDebugOpcode("Abort on illegal symbol id");
        EXIT(EXEC_ILLEGAL_DATA_ID);
    }
    gvmDebugOpcode("%p", (void*)dataTable[symbolId]);
    OP_INDIRECT_1(2).a = dataTable[symbolId];
    STEP(4);
    NEXT;
}

IS(ADDR_D0) {
    // Load the address of a global data symbol directly into an index register
    uint32 symbolId = OP_SYMBOL_ID(0);
    gvmDebugOpcode(
        "addr $%04X, i0 : ",
        (unsigned)symbolId
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
    uint32 symbolId = OP_SYMBOL_ID(0);
    gvmDebugOpcode(
        "addr $%04X, i1 : ",
        (unsigned)symbolId
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
    OP_LOCAL(2).u = OP_SYMBOL_ID(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

IS(ADDR_CI0) {
    // Load code symbol to indirect variable
    OP_INDIRECT_0(2).u = OP_SYMBOL_ID(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

IS(ADDR_CI1) {
    // Load code symbol to indirect variable
    OP_INDIRECT_1(2).u = OP_SYMBOL_ID(0) | TAG_CODE_REFERENCE;
    STEP(4);
    NEXT;
}

IS(ADDA_SI0) {
    // Add small integer offset to indirect[0]
    IR(0) += OP_LITERAL_S8(0);
    SAVE_IR(0);
    STEP(2);
    NEXT;
}

IS(ADDA_SI1) {
    // Add small integer offset to indirect[1]
    IR(1) += OP_LITERAL_S8(0);
    SAVE_IR(1);
    STEP(2);
    NEXT;
}

// Data Movement Operations ////////////////////////////////////////////////////////////////////////////////////////////

IS(SWPIDX) {
    Scalar* p = IR(0);
    IR(0) = IR(1);
    IR(1) = p;
    SAVE_IR(0);
    SAVE_IR(1);
}

IS(LOAD_L0) {
    // Load local reference to index register
    IR(0) = &OP_LOCAL(0);
    SAVE_IR(0);
    STEP(2);
    NEXT;
}

IS(LOAD_L1) {
    // Load local reference to index register
    IR(1) = &OP_LOCAL(0);
    SAVE_IR(1);
    STEP(2);
    NEXT;
}

IS(SAVE_0L) {
    // Save indirection index to local
    OP_LOCAL(0).a = IR(0);
    STEP(2);
    NEXT;
}

IS(SAVE_1L) {
    // Save indirection index to local
    OP_LOCAL(0).a = IR(1);
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
        "copy " OPF_L ", " OPF_L " : 0x%08X",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LOCAL(0).u
    );

    OP_LOCAL(1).u = OP_LOCAL(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I0L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "copy " OPF_I0 ", " OPF_L " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_INDIRECT_0(0).u
    );

    OP_LOCAL(1).u = OP_INDIRECT_0(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_I1L) {
    // Copy an indirect scalar to a local
    gvmDebugOpcode(
        "copy " OPF_I1 " " OPF_L " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_INDIRECT_1(0).u
    );
    OP_LOCAL(1).u = OP_INDIRECT_1(0).u;
    STEP(3);
    NEXT;
}

IS(CPIX_I0L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "copy " OPF_I0 "[" OPF_L "], " OPF_L " : [%u] => 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(1).u,
        (unsigned)OP_INDIRECT_0_VEC_3(0)[OP_LOCAL(1).u]
    );
    OP_LOCAL(2).u = OP_INDIRECT_0_VEC_3(0)[OP_LOCAL(1).u];
    STEP(4);
    NEXT;
}

IS(CPIX_I1L) {
    // Copy indirect indexed by local to local
    gvmDebugOpcode(
        "copy " OPF_I1 "[" OPF_L "], " OPF_L " : [%u] => 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        (unsigned)OP_LOCAL(1).u,
        (unsigned)OP_INDIRECT_1_VEC_3(0)[OP_LOCAL(1).u]
    );
    OP_LOCAL(2).u = OP_INDIRECT_1_VEC_3(0)[OP_LOCAL(1).u];
    STEP(4);
    NEXT;
}

IS(COPY_LI0) {
    gvmDebugOpcode(
        "copy " OPF_L ", " OPF_I0 " : 0x%08X",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LOCAL(0).u
    );
    // Copy a local scalar to an indirect
    OP_INDIRECT_0(1).u = OP_LOCAL(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_LI1) {
    gvmDebugOpcode(
        "copy " OPF_L ", " OPF_I0 " : 0x%08X",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LOCAL(0).u
    );
    // Copy a local scalar to an indirect
    OP_INDIRECT_1(1).u = OP_LOCAL(0).u;
    STEP(3);
    NEXT;
}

IS(COPY_II) {
    gvmDebugOpcode(
        "copy " OPF_I0 ", " OPF_I1 " : 0x%08X",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_INDIRECT_0(0).u
    );
    // Copy an indirect scalar to another indirect
    OP_INDIRECT_1(1).u = OP_INDIRECT_0(0).u;
    STEP(3);
    NEXT;
}

// Type Conversion Operations //////////////////////////////////////////////////////////////////////////////////////////

IS(ITOF_LL) {
    // Cast integer to float
    gvmDebugOpcode(
        "ito.f " OPF_L ", " OPF_L " : %d => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LOCAL(0).i
    );
    OP_LOCAL(1).f = (float32)OP_LOCAL(0).i;
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FTOI_LL) {
    // Cast float to integer
    gvmDebugOpcode(
        "fto.i " OPF_L ", " OPF_L " : %e => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).i = (int32)OP_LOCAL(0).f;
    gvmDebugOpcode("%d", (int)OP_LOCAL(1).i);
    STEP(3);
    NEXT;
}
