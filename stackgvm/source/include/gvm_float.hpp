
// Floating point specific instructions ////////////////////////////////////////////////////////////////////////////////

// Single Operand Normalised Random Number /////////////////////////////////////////////////////////////////////////////

IS(FRND_L) {
    LOC(0).f = 0.5f;//invRMax * std::rand();
    STEP(2);
    NEXT;
}

// Two Operand Branch If Float Greater Or Equal ////////////////////////////////////////////////////////////////////////

IS(FBGE_LL) {
    gvmDebugOpcode(
        "fbge %d(sf), %d(sf), %d : %e >= %e => ",
        OPS(0),
        OPS(1),
        (int)J16(2),
        LOC(0).f,
        LOC(1).f
    );
    if (LOC(0).f >= LOC(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGE_IL) {
    gvmDebugOpcode(
        "fbge %u(i0), %d(sf), %d : %e >= %e => ",
        OPU(0),
        OPS(1),
        (int)J16(2),
        IX0(0).f,
        LOC(1).f
    );
    if (IX0(0).f >= LOC(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGE_LI) {
    gvmDebugOpcode(
        "fbge %d(sf), %u(i0), %d : %e >= %e => ",
        OPS(0),
        OPU(1),
        (int)J16(2),
        LOC(0).f,
        IX0(1).f
    );
    if (LOC(0).f >= IX0(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGE_II) {
    gvmDebugOpcode(
        "fbge %u(i0), %u(i1), %d : %e >= %e => ",
        OPU(0),
        OPU(1),
        (int)J16(2),
        IX0(0).f,
        IX1(1).f
    );
    if (IX0(0).f >= IX1(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

// Two Operand Branch If Float Greater Than ////////////////////////////////////////////////////////////////////////////

IS(FBGT_LL) {
    gvmDebugOpcode(
        "fbgt %d(sf), %d(sf), %d : %e > %e => ",
        OPS(0),
        OPS(1),
        (int)J16(2),
        LOC(0).f,
        LOC(1).f
    );
    if (LOC(0).f > LOC(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGT_IL) {
    gvmDebugOpcode(
        "fbgt %u(i0), %d(sf), %d : %e > %e => ",
        OPU(0),
        OPS(1),
        (int)J16(2),
        IX0(0).f,
        LOC(1).f
    );
    if (IX0(0).f > LOC(1).f) {
        gvmDebugJump(2);
        STEP(J16(2));
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGT_LI) {
    gvmDebugOpcode(
        "fbgt %d(sf), %u(i0), %d : %e > %e => ",
        OPS(0),
        OPU(1),
        (int)J16(2),
        LOC(0).f,
        IX0(1).f
    );
    if (LOC(0).f > IX0(1).f) {
        STEP(J16(2));
        gvmDebugJump(2);
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

IS(FBGT_II) {
    gvmDebugOpcode(
        "fbgt %u(i0), %u(i1), %d : %e > %e => ",
        OPU(0),
        OPU(1),
        (int)J16(2),
        IX0(0).f,
        IX1(1).f
    );
    if (IX0(0).f > IX1(1).f) {
        STEP(J16(2));
        gvmDebugJump(2);
        NEXT;
    }
    gvmDebugSkip();
    STEP(5);
    NEXT;
}

// Two Operand Float Math Functions (Local to Local) ///////////////////////////////////////////////////////////////////

IS(FINV_LL) {
    // Reciprocal
    gvmDebugOpcode(
        "finv %d(sf), %d(sf) : 1/%e => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).f = 1.0f / LOC(0).f;
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FSQRT_LL) {
    // Square root
    gvmDebugOpcode(
        "fsqrt %d(sf), %d(sf) : sqrt(%e) => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::sqrt(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(INVSQ_LL) {
    // Inverse square
    gvmDebugOpcode(
        "finvsq %d(sf), %d(sf) : 1/(%e^2) => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    float32 sqr = LOC(0).f;
    sqr *= sqr;
    LOC(1).f = 1.0f / sqr;
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FSIN_LL) {
    // Sine
    gvmDebugOpcode(
        "fsin %d(sf), %d(sf) : sin(%e) => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::sin(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FCOS_LL) {
    // Cosine
    gvmDebugOpcode(
        "fcos %d(sf), %d(sf) : cos(%e) => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::cos(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FACOS_LL) {
    // Arccosine
    gvmDebugOpcode(
        "facos %d(sf), %d(sf) : acos(%e) => ",
        OPS(0),
        OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::acos(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

// Two Operand Float Negate ////////////////////////////////////////////////////////////////////////////////////////////

IS(FNEG_LL) {
    LOC(1).f = -LOC(0).f;
    gvmDebugOpcode(
        "fneg %d(sf), %d(sf) : %g",
        OPS(0),
        OPS(1),
        LOC(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_IL) {
    LOC(1).f = -IX0(0).f;
    gvmDebugOpcode(
        "fneg %d(sf), %d(sf) : %g",
        OPS(0),
        OPS(1),
        LOC(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_LI) {
    IX0(1).f = -LOC(0).f;
    gvmDebugOpcode(
        "fneg %d(sf), %d(sf) : %g",
        OPS(0),
        OPS(1),
        IX0(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_II) {
    IX1(1).f = -IX0(0).f;
    gvmDebugOpcode(
        "fneg %d(sf), %d(sf) : %g",
        OPS(0),
        OPS(1),
        IX1(1).f
    );
    STEP(3);
    NEXT;
}

// Three Operand Float Addition (Commutative, 4 unique variants) ///////////////////////////////////////////////////////

IS(FADD_LLL) {
    // Local + Local -> Local
    gvmDebugOpcode(
        "fadd %d(sf), %d(sf), %d(sf) : %g + %g => ",
        OPS(0),
        OPS(1),
        OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f = LOC(0).f + LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_ILL) {
    // Indirect + Local -> Local
    gvmDebugOpcode(
        "fadd %u(i0), %d(sf), %d(sf) : %g + %g => ",
        OPU(0),
        OPS(1),
        OPS(2),
        IX0(0).f,
        LOC(1).f
    );
    LOC(2).f = IX0(0).f + LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_LLI) {
    // Local + Local -> Indirect
    gvmDebugOpcode(
        "fadd %d(sf), %d(sf), %u(i0) : %g + %g => ",
        OPS(0),
        OPS(1),
        OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX0(2).f = LOC(0).f + LOC(1).f;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FADD_ILI) {
    // Indirect + Local -> Indirect
    gvmDebugOpcode(
        "fadd %u(i0), %d(sf), %u(i1) : %g + %g => ",
        OPU(0),
        OPS(1),
        OPU(2),
        IX0(0).f,
        LOC(1).f
    );
    IX1(2).f = IX0(0).f + LOC(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Subtraction (Noncommutative, 7 unique variants) /////////////////////////////////////////////////

IS(FSUB_LLL) {
    // Local - Local -> Local
    LOC(2).f = LOC(0).f - LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_ILL) {
    // Indirect - Local -> Local
    LOC(2).f = IX0(0).f - LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_LLI) {
    // Local - Local -> Indirect
    IX0(2).f = LOC(0).f - LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_ILI) {
    // Indirect - Local -> Indirect
    IX1(2).f = IX0(0).f - LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_LIL) {
    // Local - Indirect -> Local
    LOC(2).f = LOC(0).f - IX0(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_IIL) {
    // Indirect - Indirect -> Local
    LOC(2).f = IX0(0).f - IX1(1).f;
    STEP(4);
    NEXT;
}

IS(FSUB_LII) {
    // Local - Indirect -> Indirect
    IX1(2).f = LOC(0).f - IX0(1).f;
    STEP(4);
    NEXT;
}

// Three Operand Float Multiplication (Commutative, 4 unique variants) /////////////////////////////////////////////////

IS(FMUL_LLL) {
    // Local * Local -> Local
    LOC(2).f = LOC(0).f * LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FMUL_ILL) {
    // Indirect * Local -> Local
    LOC(2).f = IX0(0).f * LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FMUL_LLI) {
    // Local * Local -> Indirect
    IX0(2).f = LOC(0).f * LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FMUL_ILI) {
    // Indirect * Local -> Indirect
    IX1(2).f = IX0(0).f * LOC(1).f;
    STEP(4);
    NEXT;
}

// Three Operand Float Division (Noncommutative, 7 unique variants) ////////////////////////////////////////////////////

IS(FDIV_LLL) {
    LOC(2).f = LOC(0).f / LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_ILL) {
    // Indirect / Local -> Local
    LOC(2).f = IX0(0).f / LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_LLI) {
    // Local / Local -> Indirect
    IX0(2).f = LOC(0).f / LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_ILI) {
    // Indirect / Local -> Indirect
    IX1(2).f = IX0(0).f / LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_LIL) {
    // Local / Indirect -> Local
    LOC(2).f = IX0(0).f / LOC(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_IIL) {
    // Indirect / Indirect -> Local
    LOC(2).f = IX0(0).f / IX1(1).f;
    STEP(4);
    NEXT;
}

IS(FDIV_LII) {
    // Local / Indirect -> Indirect
    IX1(2).f = LOC(0).f / IX0(1).f;
    STEP(4);
    NEXT;
}

// Three Operand Float Modulo (Noncommutative, 7 unique variants) //////////////////////////////////////////////////////

IS(FMOD_LLL) {
    LOC(2).f = std::fmod(LOC(0).f, LOC(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILL) {
    // Indirect % Local -> Local
    LOC(2).f = std::fmod(IX0(0).f, LOC(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LLI) {
    // Local % Local -> Indirect
    IX0(2).f = std::fmod(LOC(0).f, LOC(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILI) {
    // Indirect % Local -> Indirect
    IX1(2).f = std::fmod(IX0(0).f, LOC(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LIL) {
    // Local % Indirect -> Local
    LOC(2).f = std::fmod(IX0(0).f, LOC(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_IIL) {
    // Indirect % Indirect -> Local
    LOC(2).f = std::fmod(IX0(0).f, IX1(1).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LII) {
    // Local % Indirect -> Indirect
    IX1(2).f = std::fmod(LOC(0).f, IX0(1).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Maximum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMAX_LLL) {
    // max(Local, Local) -> Local
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    LOC(2).f  = f1 > f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMAX_ILL) {
    // max(Indirect, Local) -> Local
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    LOC(2).f  = f1 > f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMAX_LLI) {
    // max(Local, Local) -> Indirect
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    IX0(0).f  = f1 > f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMAX_ILI) {
    // max(Indirect, Local) -> Indirect
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    IX1(2).f  = f1 > f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

// Three Operand Flaot Minumum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMIN_LLL) {
    // max(Local, Local) -> Local
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    LOC(2).f  = f1 < f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMIN_ILL) {
    // min(Indirect, Local) -> Local
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    LOC(2).f  = f1 < f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMIN_LLI) {
    // min(Local, Local) -> Indirect
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    IX0(0).f  = f1 < f2 ? f1 : f2;
    STEP(4);
    NEXT;
}

IS(FMIN_ILI) {
    // min(Indirect, Local) -> Indirect
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    IX1(2).f  = f1 < f2 ? f1 : f2;
    STEP(4);
    NEXT;
}
