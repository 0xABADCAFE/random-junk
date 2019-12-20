
// Floating point specific instructions ////////////////////////////////////////////////////////////////////////////////

// Single Operand Normalised Random Number /////////////////////////////////////////////////////////////////////////////

IS(FRND_L) {
#ifdef _GVM_DEBUG_OPCODES_
    OP_LOCAL(0).f = 0.5f;
#else
    OP_LOCAL(0).f = invRMax * std::rand();
    //OP_LOCAL(0).f = 0.5f;
#endif
    gvmDebugOpcode(
        "rnd.f " OPF_L " : %g",
        (int)OP_LITERAL_S8(0),
        OP_LOCAL(0).f
    );
    STEP(2);
    NEXT;
}

// Two Operand Float Math Functions (Local to Local) ///////////////////////////////////////////////////////////////////

IS(FINV_LL) {
    // Reciprocal
    gvmDebugOpcode(
        "inv.f " OPF_L ", " OPF_L " : 1/%e => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = 1.0f / OP_LOCAL(0).f;
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FSQRT_LL) {
    // Square root
    gvmDebugOpcode(
        "sqrt.f " OPF_L ", " OPF_L " : sqrt(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::sqrt(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(INVSQ_LL) {
    // Inverse square
    gvmDebugOpcode(
        "invsq.f " OPF_L ", " OPF_L " : 1/(%e^2) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    float32 sqr = OP_LOCAL(0).f;
    sqr *= sqr;
    OP_LOCAL(1).f = 1.0f / sqr;
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FSIN_LL) {
    // Sine
    gvmDebugOpcode(
        "sin.f " OPF_L ", " OPF_L " : sin(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::sin(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FCOS_LL) {
    // Cosine
    gvmDebugOpcode(
        "cos.f " OPF_L ", " OPF_L " : cos(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::cos(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FACOS_LL) {
    // Arccosine
    gvmDebugOpcode(
        "acos.f " OPF_L ", " OPF_L " : acos(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::acos(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FCEIL_LL) {
    // Ceil
    gvmDebugOpcode(
        "ceil.f " OPF_L ", " OPF_L " : ceil(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::ceil(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(FFLOOR_LL) {
    // Floor
    gvmDebugOpcode(
        "floor.f " OPF_L ", " OPF_L " : floor(%e) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(0).f
    );
    OP_LOCAL(1).f = std::floor(OP_LOCAL(0).f);
    gvmDebugOpcode("%e", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}


// Two Operand Float Negate ////////////////////////////////////////////////////////////////////////////////////////////

IS(FNEG_LL) {
    OP_LOCAL(1).f = -OP_LOCAL(0).f;
    gvmDebugOpcode(
        "neg.f " OPF_L ", " OPF_L " : %g",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_IL) {
    OP_LOCAL(1).f = -OP_INDIRECT_0(0).f;
    gvmDebugOpcode(
        "neg.f " OPF_I0 ", " OPF_L " : %g",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        OP_LOCAL(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_LI) {
    OP_INDIRECT_0(1).f = -OP_LOCAL(0).f;
    gvmDebugOpcode(
        "neg.f " OPF_L ", " OPF_I0 " : %g",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        OP_INDIRECT_0(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_II) {
    OP_INDIRECT_1(1).f = -OP_INDIRECT_0(0).f;
    gvmDebugOpcode(
        "neg.f " OPF_I0 ", " OPF_I1 " : %g",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        OP_INDIRECT_1(1).f
    );
    STEP(3);
    NEXT;
}

// Three Operand Float Addition (Commutative, 4 unique variants) ///////////////////////////////////////////////////////

IS(FADD_LLL) {
    // Local + Local -> Local
    gvmDebugOpcode(
        "add.f " OPF_L ", " OPF_L ", " OPF_L " : %g + %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_LOCAL(0).f + OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_ILL) {
    // Indirect + Local -> Local
    gvmDebugOpcode(
        "add.f " OPF_I0 ", " OPF_L ", " OPF_L " : %g + %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f + OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_LLI) {
    // Local + Local -> Indirect
    gvmDebugOpcode(
        "add.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g + %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_0(2).f = OP_LOCAL(0).f + OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_ILI) {
    // Indirect + Local -> Indirect
    gvmDebugOpcode(
        "add.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : %g + %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = OP_INDIRECT_0(0).f + OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("add.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f + op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Float Subtraction (Noncommutative, 7 unique variants) /////////////////////////////////////////////////

IS(FSUB_LLL) {
    // Local - Local -> Local
    gvmDebugOpcode(
        "sub.f " OPF_L ", " OPF_L ", " OPF_L " : %g - %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_LOCAL(0).f - OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_ILL) {
    // Indirect - Local -> Local
    gvmDebugOpcode(
        "sub.f " OPF_I0 ", " OPF_L ", " OPF_L " : %g - %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f - OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LLI) {
    // Local - Local -> Indirect
    gvmDebugOpcode(
        "sub.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g - %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_0(2).f = OP_LOCAL(0).f - OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_ILI) {
    // Indirect - Local -> Indirect
    gvmDebugOpcode(
        "sub.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : %g - %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = OP_INDIRECT_0(0).f - OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LIL) {
    // Local - Indirect -> Local
    gvmDebugOpcode(
        "sub.f " OPF_L ", " OPF_I0 ", " OPF_L " : %g - %g => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_INDIRECT_0(1).f
    );
    OP_LOCAL(2).f = OP_LOCAL(0).f - OP_INDIRECT_0(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_IIL) {
    // Indirect - Indirect -> Local
    gvmDebugOpcode(
        "sub.f " OPF_I0 ", " OPF_I1 ", " OPF_L " : %g - %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_INDIRECT_1(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f - OP_INDIRECT_1(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LII) {
    // Local - Indirect -> Indirect
    gvmDebugOpcode(
        "sub.f " OPF_L ", " OPF_L ", " OPF_L " : %g - %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = OP_LOCAL(0).f - OP_INDIRECT_0(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("sub.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f - op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Float Multiplication (Commutative, 4 unique variants) /////////////////////////////////////////////////

IS(FMUL_LLL) {
    // Local * Local -> Local
    gvmDebugOpcode(
        "mul.f " OPF_L ", " OPF_L ", " OPF_L " : %g * %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_LOCAL(0).f * OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_ILL) {
    // Indirect * Local -> Local
    gvmDebugOpcode(
        "mul.f " OPF_I0 ", " OPF_L ", " OPF_L " : %g * %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f * OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_LLI) {
    // Local * Local -> Indirect
    gvmDebugOpcode(
        "mul.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g * %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_0(2).f = OP_LOCAL(0).f * OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_ILI) {
    // Indirect * Local -> Indirect
    gvmDebugOpcode(
        "mul.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : %g * %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = OP_INDIRECT_0(0).f * OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mul.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f * op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Float Division (Noncommutative, 7 unique variants) ////////////////////////////////////////////////////

IS(FDIV_LLL) {
    gvmDebugOpcode(
        "div.f " OPF_L ", " OPF_L ", " OPF_L " : %g / %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = OP_LOCAL(0).f / OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_ILL) {
    gvmDebugOpcode(
        "div.f " OPF_I0 ", " OPF_L ", " OPF_L " : %g / %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    // Indirect / Local -> Local
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f / OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LLI) {
    // Local / Local -> Indirect
    gvmDebugOpcode(
        "div.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g / %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_0(2).f = OP_LOCAL(0).f / OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_ILI) {
    // Indirect / Local -> Indirect
    gvmDebugOpcode(
        "div.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : %g / %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = OP_INDIRECT_0(0).f / OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LIL) {
    // Local / Indirect -> Local
    gvmDebugOpcode(
        "div.f " OPF_L ", " OPF_I0 ", " OPF_L " : %g / %g => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_INDIRECT_0(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f / OP_LOCAL(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_IIL) {
    // Indirect / Indirect -> Local
    gvmDebugOpcode(
        "div.f " OPF_I0 ", " OPF_I1 ", " OPF_L " : %g / %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_INDIRECT_1(1).f
    );
    OP_LOCAL(2).f = OP_INDIRECT_0(0).f / OP_INDIRECT_1(1).f;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LII) {
    // Local / Indirect -> Indirect
    gvmDebugOpcode(
        "div.f " OPF_L ", " OPF_I0 ", " OPF_I1 " : %g / %g => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_INDIRECT_0(1).f
    );
    OP_INDIRECT_1(2).f = OP_LOCAL(0).f / OP_INDIRECT_0(1).f;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("div.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f / op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Float Modulo (Noncommutative, 7 unique variants) //////////////////////////////////////////////////////

IS(FMOD_LLL) {
    gvmDebugOpcode(
        "mod.f " OPF_L ", " OPF_L ", " OPF_L " : %g %% %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = std::fmod(OP_LOCAL(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILL) {
    // Indirect % Local -> Local
    gvmDebugOpcode(
        "mod.f " OPF_I0 ", " OPF_L ", " OPF_L " : %g %% %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f = std::fmod(OP_INDIRECT_0(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LLI) {
    // Local % Local -> Indirect
    gvmDebugOpcode(
        "mod.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g %% %g => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_0(2).f = std::fmod(OP_LOCAL(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILI) {
    // Indirect % Local -> Indirect
    gvmDebugOpcode(
        "mod.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : %g %% %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_INDIRECT_0(0).f,
        OP_LOCAL(1).f
    );
    OP_INDIRECT_1(2).f = std::fmod(OP_INDIRECT_0(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LIL) {
    // Local % Indirect -> Local
    gvmDebugOpcode(
        "mod.f " OPF_L ", " OPF_L ", " OPF_I0 " : %g %% %g => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_INDIRECT_0(1).f
    );
    OP_LOCAL(2).f = std::fmod(OP_INDIRECT_0(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_IIL) {
    // Indirect % Indirect -> Local
    gvmDebugOpcode(
        "mod.f " OPF_I0 ", " OPF_I1 ", " OPF_L " : %g %% %g => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2),
        OP_INDIRECT_0(0).f,
        OP_INDIRECT_1(1).f
    );
    OP_LOCAL(2).f = std::fmod(OP_INDIRECT_0(0).f, OP_INDIRECT_1(1).f);
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LII) {
    // Local % Indirect -> Indirect
    gvmDebugOpcode(
        "mod.f " OPF_L ", " OPF_I0 ", " OPF_I1 " : %g %% %g => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2),
        OP_LOCAL(0).f,
        OP_INDIRECT_0(1).f
    );
    OP_INDIRECT_1(2).f = std::fmod(OP_LOCAL(0).f, OP_INDIRECT_0(1).f);
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}


IS(FMOD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mod.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = std::fmod(op1->f, op2->f);
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Float Maximum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMAX_LLL) {
    // max(Local, Local) -> Local
    float32 f1 = OP_LOCAL(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "max.f " OPF_L ", " OPF_L ", " OPF_L " : max(%g, %g) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        f1,
        f2
    );
    OP_LOCAL(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_ILL) {
    // max(Indirect, Local) -> Local
    float32 f1 = OP_INDIRECT_0(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "max.f " OPF_I0 ", " OPF_L ", " OPF_L " : max(%g, %g) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        f1,
        f2
    );
    OP_LOCAL(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_LLI) {
    // max(Local, Local) -> Indirect
    float32 f1 = OP_LOCAL(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "max.f " OPF_L ", " OPF_L ", " OPF_I0 " : max(%g, %g) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        f1,
        f2
    );
    OP_INDIRECT_0(0).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_ILI) {
    // max(Indirect, Local) -> Indirect
    float32 f1 = OP_INDIRECT_0(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "max.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : max(%g, %g) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        f1,
        f2
    );
    OP_INDIRECT_1(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("max.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f > op2->f ? op1->f : op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Flaot Minumum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMIN_LLL) {
    // min(Local, Local) -> Local
    float32 f1 = OP_LOCAL(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "min.f " OPF_L ", " OPF_L ", " OPF_L " : max(%g, %g) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        f1,
        f2
    );
    OP_LOCAL(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_ILL) {
    // min(Indirect, Local) -> Local
    float32 f1 = OP_INDIRECT_0(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "min.f " OPF_I0 ", " OPF_L ", " OPF_L " : max(%g, %g) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        f1,
        f2
    );
    OP_LOCAL(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_LLI) {
    // min(Local, Local) -> Indirect
    float32 f1 = OP_LOCAL(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "min.f " OPF_L ", " OPF_L ", " OPF_I0 " : max(%g, %g) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        f1,
        f2
    );
    OP_INDIRECT_0(0).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_INDIRECT_0(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_ILI) {
    // min(Indirect, Local) -> Indirect
    float32 f1 = OP_INDIRECT_0(0).f;
    float32 f2 = OP_LOCAL(1).f;
    gvmDebugOpcode(
        "min.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : max(%g, %g) => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2),
        f1,
        f2
    );
    OP_INDIRECT_1(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", OP_INDIRECT_1(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("min.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        op3->f = op1->f < op2->f ? op1->f : op2->f;
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

IS(FPOW_LLL) {
    // Power
    gvmDebugOpcode(
        "pow.f " OPF_L ", " OPF_L ", " OPF_L " : pow(%g, %g) => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2),
        OP_LOCAL(0).f,
        OP_LOCAL(1).f
    );
    OP_LOCAL(2).f  = std::pow(OP_LOCAL(0).f, OP_LOCAL(1).f);
    gvmDebugOpcode("%g", OP_LOCAL(2).f);
    STEP(4);
    NEXT;
}
