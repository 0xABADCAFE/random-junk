
// Floating point specific instructions ////////////////////////////////////////////////////////////////////////////////

// Single Operand Normalised Random Number /////////////////////////////////////////////////////////////////////////////

IS(FRND_L) {
#ifdef _GVM_DEBUG_OPCODES_
    LOC(0).f = 0.5f;
#else
    LOC(0).f = invRMax * std::rand();
    //LOC(0).f = 0.5f;
#endif
    gvmDebugOpcode(
        "rnd.f (%d) : %g",
        (int)OPS(0),
        LOC(0).f
    );
    STEP(2);
    NEXT;
}

// Two Operand Branch If Float Greater Or Equal ////////////////////////////////////////////////////////////////////////

IS(FBGE_LL) {
    gvmDebugOpcode(
        "bge.f (%d), (%d), %d : %e >= %e => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "bge.f (i0+%u), (%d), %d : %e >= %e => ",
        (unsigned)OPU(0),
        (int)OPS(1),
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
        "bge.f (%d), (i0+%u), %d : %e >= %e => ",
        (int)OPS(0),
        (unsigned)OPU(1),
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
        "bge.f (i0+%u), (i1+%u), %d : %e >= %e => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
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

IS(FBLE_II) {
    gvmDebugOpcode(
        "ble.f (i0+%u), (i1+%u), %d : %e <= %e => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)J16(2),
        IX0(0).f,
        IX1(1).f
    );
    if (IX0(0).f <= IX1(1).f) {
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
        "bgt.f (%d), (%d), %d : %e > %e => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "bgt.f (i0+%u), (%d), %d : %e > %e => ",
        (unsigned)OPU(0),
        (int)OPS(1),
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
        "bgt.f (%d), (i0+%u), %d : %e > %e => ",
        (int)OPS(0),
        (unsigned)OPU(1),
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
        "bgt.f (i0+%u), (i1+%u), %d : %e > %e => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
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

IS(FBLT_II) {
    gvmDebugOpcode(
        "blt.f (i0+%u), (i1+%u), %d : %e < %e => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)J16(2),
        IX0(0).f,
        IX1(1).f
    );
    if (IX0(0).f < IX1(1).f) {
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
        "inv.f (%d), (%d) : 1/%e => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "sqrt.f (%d), (%d) : sqrt(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "invsq.f (%d), (%d) : 1/(%e^2) => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "sin.f (%d), (%d) : sin(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "cos.f (%d), (%d) : cos(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
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
        "acos.f (%d), (%d) : acos(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::acos(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FCEIL_LL) {
    // Ceil
    gvmDebugOpcode(
        "ceil.f (%d), (%d) : ceil(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::ceil(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(FFLOOR_LL) {
    // Floor
    gvmDebugOpcode(
        "floor.f (%d), (%d) : floor(%e) => ",
        (int)OPS(0),
        (int)OPS(1),
        LOC(0).f
    );
    LOC(1).f = std::floor(LOC(0).f);
    gvmDebugOpcode("%e", LOC(1).f);
    STEP(3);
    NEXT;
}


// Two Operand Float Negate ////////////////////////////////////////////////////////////////////////////////////////////

IS(FNEG_LL) {
    LOC(1).f = -LOC(0).f;
    gvmDebugOpcode(
        "neg.f (%d), (%d) : %g",
        (int)OPS(0),
        (int)OPS(1),
        LOC(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_IL) {
    LOC(1).f = -IX0(0).f;
    gvmDebugOpcode(
        "neg.f (i0 + %u), (%d) : %g",
        (unsigned)OPU(0),
        (int)OPS(1),
        LOC(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_LI) {
    IX0(1).f = -LOC(0).f;
    gvmDebugOpcode(
        "neg.f (%d), (i0 + %u) : %g",
        (int)OPS(0),
        (unsigned)OPU(1),
        IX0(1).f
    );
    STEP(3);
    NEXT;
}

IS(FNEG_II) {
    IX1(1).f = -IX0(0).f;
    gvmDebugOpcode(
        "neg.f (i0 + %u), (i1 + %u) : %g",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        IX1(1).f
    );
    STEP(3);
    NEXT;
}

// Three Operand Float Addition (Commutative, 4 unique variants) ///////////////////////////////////////////////////////

IS(FADD_LLL) {
    // Local + Local -> Local
    gvmDebugOpcode(
        "add.f (%d), (%d), (%d) : %g + %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
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
        "add.f (i0+%u), (%d), (%d) : %g + %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
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
        "add.f (%d), (%d), (i0+%u) : %g + %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
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
        "add.f (i0+%u), (%d), (i1+%u) : %g + %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
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
    gvmDebugOpcode(
        "sub.f (%d), (%d), (%d) : %g - %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f = LOC(0).f - LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_ILL) {
    // Indirect - Local -> Local
    gvmDebugOpcode(
        "sub.f (i0+%u), (%d), (%d) : %g - %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        IX0(0).f,
        LOC(1).f
    );
    LOC(2).f = IX0(0).f - LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LLI) {
    // Local - Local -> Indirect
    gvmDebugOpcode(
        "sub.f (%d), (%d), (i0+%u) : %g - %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX0(2).f = LOC(0).f - LOC(1).f;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_ILI) {
    // Indirect - Local -> Indirect
    gvmDebugOpcode(
        "sub.f (i0+%u), (%d), (i1+%u) : %g - %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        IX0(0).f,
        LOC(1).f
    );
    IX1(2).f = IX0(0).f - LOC(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LIL) {
    // Local - Indirect -> Local
    gvmDebugOpcode(
        "sub.f (%d), (i0+%u), (%d) : %g - %g => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        LOC(0).f,
        IX0(1).f
    );
    LOC(2).f = LOC(0).f - IX0(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_IIL) {
    // Indirect - Indirect -> Local
    gvmDebugOpcode(
        "sub.f (i0+%u), (i1+%u), (%d) : %g - %g => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        IX0(0).f,
        IX1(1).f
    );
    LOC(2).f = IX0(0).f - IX1(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FSUB_LII) {
    // Local - Indirect -> Indirect
    gvmDebugOpcode(
        "sub.f (%d), (%d), (%d) : %g - %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    IX1(2).f = LOC(0).f - IX0(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Multiplication (Commutative, 4 unique variants) /////////////////////////////////////////////////

IS(FMUL_LLL) {
    // Local * Local -> Local
    gvmDebugOpcode(
        "mul.f (%d), (%d), (%d) : %g * %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f = LOC(0).f * LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_ILL) {
    // Indirect * Local -> Local
    gvmDebugOpcode(
        "mul.f (i0+%u), (%d), (%d) : %g * %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        IX0(0).f,
        LOC(1).f
    );
    LOC(2).f = IX0(0).f * LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_LLI) {
    // Local * Local -> Indirect
    gvmDebugOpcode(
        "mul.f (%d), (%d), (i0+%u) : %g * %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX0(2).f = LOC(0).f * LOC(1).f;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FMUL_ILI) {
    // Indirect * Local -> Indirect
    gvmDebugOpcode(
        "mul.f (i0+%u), (%d), (i1+%u) : %g * %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX1(2).f = IX0(0).f * LOC(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Division (Noncommutative, 7 unique variants) ////////////////////////////////////////////////////

IS(FDIV_LLL) {
    gvmDebugOpcode(
        "div.f (%d), (%d), (%d) : %g / %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f = LOC(0).f / LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_ILL) {
    gvmDebugOpcode(
        "div.f (i0+%u), (%d), (%d) : %g / %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        IX0(0).f,
        LOC(1).f
    );
    // Indirect / Local -> Local
    LOC(2).f = IX0(0).f / LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LLI) {
    // Local / Local -> Indirect
    gvmDebugOpcode(
        "div.f (%d), (%d), (i0+%u) : %g / %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX0(2).f = LOC(0).f / LOC(1).f;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_ILI) {
    // Indirect / Local -> Indirect
    gvmDebugOpcode(
        "div.f (i0+%u), (%d), (i1+%u) : %g / %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        IX0(0).f,
        LOC(1).f
    );
    IX1(2).f = IX0(0).f / LOC(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LIL) {
    // Local / Indirect -> Local
    gvmDebugOpcode(
        "div.f (%d), (i0+%u), (%d) : %g / %g => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        LOC(0).f,
        IX0(1).f
    );
    LOC(2).f = IX0(0).f / LOC(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_IIL) {
    // Indirect / Indirect -> Local
    gvmDebugOpcode(
        "div.f (i0+%u), (i1+%u), (%d) : %g / %g => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        IX0(0).f,
        IX1(1).f
    );
    LOC(2).f = IX0(0).f / IX1(1).f;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FDIV_LII) {
    // Local / Indirect -> Indirect
    gvmDebugOpcode(
        "div.f (%d), (i0+%u), (i1+%u) : %g / %g => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        LOC(0).f,
        IX0(1).f
    );
    IX1(2).f = LOC(0).f / IX0(1).f;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Modulo (Noncommutative, 7 unique variants) //////////////////////////////////////////////////////

IS(FMOD_LLL) {
    gvmDebugOpcode(
        "mod.f (%d), (%d), (%d) : %g %% %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f = std::fmod(LOC(0).f, LOC(1).f);
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILL) {
    // Indirect % Local -> Local
    gvmDebugOpcode(
        "mod.f (i0+%u), (%d), (%d) : %g %% %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        IX0(0).f,
        LOC(1).f
    );
    LOC(2).f = std::fmod(IX0(0).f, LOC(1).f);
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LLI) {
    // Local % Local -> Indirect
    gvmDebugOpcode(
        "mod.f (%d), (%d), (i0+%u) : %g %% %g => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        LOC(0).f,
        LOC(1).f
    );
    IX0(2).f = std::fmod(LOC(0).f, LOC(1).f);
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_ILI) {
    // Indirect % Local -> Indirect
    gvmDebugOpcode(
        "mod.f (i0+%u), (%d), (i1+%u) : %g %% %g => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        IX0(0).f,
        LOC(1).f
    );
    IX1(2).f = std::fmod(IX0(0).f, LOC(1).f);
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LIL) {
    // Local % Indirect -> Local
    gvmDebugOpcode(
        "mod.f (%d), (%d), (i0+%u) : %g %% %g => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        LOC(0).f,
        IX0(1).f
    );
    LOC(2).f = std::fmod(IX0(0).f, LOC(1).f);
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_IIL) {
    // Indirect % Indirect -> Local
    gvmDebugOpcode(
        "mod.f (i0+%u), (i1+%u), (%d) : %g %% %g => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2),
        IX0(0).f,
        IX1(1).f
    );
    LOC(2).f = std::fmod(IX0(0).f, IX1(1).f);
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMOD_LII) {
    // Local % Indirect -> Indirect
    gvmDebugOpcode(
        "mod.f (%d), (i0+%u), (i1+%u) : %g %% %g => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2),
        LOC(0).f,
        IX0(1).f
    );
    IX1(2).f = std::fmod(LOC(0).f, IX0(1).f);
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Float Maximum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMAX_LLL) {
    // max(Local, Local) -> Local
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "max.f (%d), (%d), (%d) : max(%g, %g) => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        f1,
        f2
    );
    LOC(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_ILL) {
    // max(Indirect, Local) -> Local
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "max.f (i0+%u), (%d), (%d) : max(%g, %g) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        f1,
        f2
    );
    LOC(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_LLI) {
    // max(Local, Local) -> Indirect
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "max.f (%d), (%d), (i0+%u) : max(%g, %g) => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        f1,
        f2
    );
    IX0(0).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FMAX_ILI) {
    // max(Indirect, Local) -> Indirect
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "max.f (i0+%u), (%d), (i1+%u) : max(%g, %g) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        f1,
        f2
    );
    IX1(2).f  = f1 > f2 ? f1 : f2;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

// Three Operand Flaot Minumum (Commutative, 4 unique variants) ////////////////////////////////////////////////////////

IS(FMIN_LLL) {
    // min(Local, Local) -> Local
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "min.f (%d), (%d), (%d) : max(%g, %g) => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        f1,
        f2
    );
    LOC(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_ILL) {
    // min(Indirect, Local) -> Local
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "min.f (i0+%u), (%d), (%d) : max(%g, %g) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2),
        f1,
        f2
    );
    LOC(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_LLI) {
    // min(Local, Local) -> Indirect
    float32 f1 = LOC(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "min.f (%d), (%d), (i0+%u) : max(%g, %g) => ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        f1,
        f2
    );
    IX0(0).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", IX0(2).f);
    STEP(4);
    NEXT;
}

IS(FMIN_ILI) {
    // min(Indirect, Local) -> Indirect
    float32 f1 = IX0(0).f;
    float32 f2 = LOC(1).f;
    gvmDebugOpcode(
        "min.f (i0+%u), (%d), (i1+%u) : max(%g, %g) => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2),
        f1,
        f2
    );
    IX1(2).f  = f1 < f2 ? f1 : f2;
    gvmDebugOpcode("%g", IX1(2).f);
    STEP(4);
    NEXT;
}

IS(FPOW_LLL) {
    // Power
    gvmDebugOpcode(
        "pow.f (%d), (%d), (%d) : pow(%g, %g) => ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2),
        LOC(0).f,
        LOC(1).f
    );
    LOC(2).f  = std::pow(LOC(0).f, LOC(1).f);
    gvmDebugOpcode("%g", LOC(2).f);
    STEP(4);
    NEXT;
}
