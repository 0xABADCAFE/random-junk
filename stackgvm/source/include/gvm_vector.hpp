
// Vector specific Instructions ////////////////////////////////////////////////////////////////////////////////////////

// Single Operand Random Vector ////////////////////////////////////////////////////////////////////////////////////////

IS(VRND_L) {
    vd = VLOC(0);
    SCALAR_F x = (invRMax * std::rand()) - 1.0f;
    SCALAR_F y = (invRMax * std::rand()) - 1.0f;
    SCALAR_F z = (invRMax * std::rand()) - 1.0f;
    sf = 1.0f / std::sqrt((x * x) + (y * y) + (z * z));
    vd[0] = x*sf;
    vd[1] = y*sf;
    vd[2] = z*sf;
    gvmDebugOpcode(
        "rnd.v {%d} : { %g, %g, %g }",
        (int)OPS(0),
        vd[0],
        vd[1],
        vd[2]
    );
    STEP(2);
    NEXT;
}

// Two Operand Vector Copy /////////////////////////////////////////////////////////////////////////////////////////////

IS(VCOPY_LL) {
    gvmDebugOpcode(
        "copy.v {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1)
    );
    us = ULOC(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_IL) {
    gvmDebugOpcode(
        "copy.v i0[%u], {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1)
    );
    us = UIX0(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_LI) {
    gvmDebugOpcode(
        "copy.v {%d}, i0[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1)
    );
    us = ULOC(0);
    ud = UIX0(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_II) {
    gvmDebugOpcode(
        "copy.v i0[%u], i1[%u] : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1)
    );
    us = UIX0(0);
    ud = UIX1(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_copy:
#endif
#include "gvm_vector_copy.hpp"
}

// Two Operand Vector Negate ///////////////////////////////////////////////////////////////////////////////////////////

IS(VNEG_LL) {
    gvmDebugOpcode(
        "neg.v {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1)
    );
    vs1 = VLOC(0);
    vd  = VLOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_IL) {
    gvmDebugOpcode(
        "neg.v i0[%u], {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1)
    );
    vs1 = VIX0(0);
    vd  = VLOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_LI) {
    gvmDebugOpcode(
        "neg.v {%d}, i0[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1)
    );
    vs1 = VLOC(0);
    vd  = VIX0(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_II) {
    gvmDebugOpcode(
        "neg.v i0[%u], i1[%u] : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1)
    );
    vs1 = VIX0(0);
    vd  = VIX1(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_negate:
#endif
#include "gvm_vector_negate.hpp"
}

// Two Operand Vector Normalisation ////////////////////////////////////////////////////////////////////////////////////

IS(VNORM_LL) {
    gvmDebugOpcode(
        "vnrm.v {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1)
    );
    vs1 = VLOC(0);
    vd  = VLOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_IL) {
    gvmDebugOpcode(
        "vnrm.v i0[%u], {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1)
    );
    vs1 = VIX0(0);
    vd  = VLOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_LI) {
    gvmDebugOpcode(
        "vnrm.v {%d}, i0[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1)
    );
    vs1 = VLOC(0);
    vd  = VIX0(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_II) {
    gvmDebugOpcode(
        "vnrm.v i0[%u], i1[%u] : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1)
    );
    vs1 = VIX0(0);
    vd  = VIX1(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_normalise:
#endif
#include "gvm_vector_normalise.hpp"
}

// Two Operand Vector Magnitude (Float Result) /////////////////////////////////////////////////////////////////////////

IS(VMAG_LL) {
    SCALAR_F* v = VLOC(0);
    gvmDebugOpcode(
        "vmag.f {%d}, {%d} : |{ %g, %g, %g }| => ",
        (int)OPS(0),
        (int)OPS(1),
        v[0], v[1], v[2]
    );
    LOC(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_IL) {
    SCALAR_F* v = VIX0(0);
    gvmDebugOpcode(
        "vmag.f i0[%u], {%d} : |{ %g, %g, %g }| => ",
        (unsigned)OPU(0),
        (int)OPS(1),
        v[0], v[1], v[2]
    );
    LOC(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", LOC(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_LI) {
    SCALAR_F* v = VLOC(0);
    gvmDebugOpcode(
        "vmag.f {%d}, i0[%u] : |{ %g, %g, %g }| => ",
        (int)OPS(0),
        (unsigned)OPU(1),
        v[0], v[1], v[2]
    );
    IX0(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", IX0(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_II) {
    SCALAR_F* v = VIX0(0);
    gvmDebugOpcode(
        "vmag.f i0[%u], i1[%u] : |{ %g, %g, %g }| => ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        v[0], v[1], v[2]
    );
    IX1(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", IX1(1).f);
    STEP(3);
    NEXT;
}

// Three Operand Vector Instructions ///////////////////////////////////////////////////////////////////////////////////

// Three Operand Vector Addition (Commutative, 4 unique variants) //////////////////////////////////////////////////////
IS(VADD_LLL) {
    gvmDebugOpcode(
        "add.v {%d}, {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_ILL) {
    gvmDebugOpcode(
        "add.v i0[%u], {%d}, {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_LLI) {
    gvmDebugOpcode(
        "add.v {%d}, {%d}, i0[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VIX0(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_ILI) {
    gvmDebugOpcode(
        "add.v i0[%u], {%d}, i1[%u] : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_add:
#endif
#include "gvm_vector_add.hpp"
}

IS(VADD_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("add.v ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        vs1 = (float*)op1;
        vs2 = (float*)op2;
        vd  = (float*)op3;
        gvmDebugOpcode(
            "{ %g, %g, %g } + { %g, %g, %g } => ",
            vs1[0], vs1[1], vs1[2],
            vs2[0], vs2[1], vs2[2]
        );
        vd[0] = vs1[0] + vs2[0];
        vd[1] = vs1[1] + vs2[1];
        vd[2] = vs1[2] + vs2[2];
        gvmDebugOpcode(
            "{ %g, %g, %g }",
            vd[0], vd[1], vd[2]
        );
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Vector Subtraction (Noncommutative, 7 unique variants) ////////////////////////////////////////////////

IS(VSUB_LLL) {
    gvmDebugOpcode(
        "sub.v {%d}, {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_ILL) {
    gvmDebugOpcode(
        "sub.v i0[%u], {%d}, {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs2 = VLOC(1);
    vd  = VLOC(2);
    vs1 = VIX0(0);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LLI) {
    gvmDebugOpcode(
        "sub.v {%d}, {%d}, i0[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VIX0(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_ILI) {
    gvmDebugOpcode(
        "sub.v i0[%u], {%d}, i1[%u] : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LIL) {
    gvmDebugOpcode(
        "sub.v {%d}, i0[%u], {%d} : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs2 = VIX0(1);
    vs1 = VLOC(0);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_IIL) {
    gvmDebugOpcode(
        "sub.v i0[%u], i1[%u], {%d} : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VIX1(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LII) {
    gvmDebugOpcode(
        "sub.v {%d}, i0[%u], i1[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VIX0(1);
    vd  = VIX1(2);

#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_subtract:
#endif
#include "gvm_vector_subtract.hpp"
}

IS(VSUB_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("sub.v ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        vs1 = (float*)op1;
        vs2 = (float*)op2;
        vd  = (float*)op3;
        gvmDebugOpcode(
            "{ %g, %g, %g } - { %g, %g, %g } => ",
            vs1[0], vs1[1], vs1[2],
            vs2[0], vs2[1], vs2[2]
        );
        vd[0] = vs1[0] - vs2[0];
        vd[1] = vs1[1] - vs2[1];
        vd[2] = vs1[2] - vs2[2];
        gvmDebugOpcode(
            "{ %g, %g, %g }",
            vd[0], vd[1], vd[2]
        );
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Dot Product (Scalar Float Result) /////////////////////////////////////////////////////////////////////

IS(VDOT_LLL) {
    gvmDebugOpcode(
        "vdot.f {%d}, {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    LOC(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        LOC(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILL) {
    gvmDebugOpcode(
        "vdot.f %u(sf), {%d}, {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    LOC(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        LOC(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_LLI) {
    gvmDebugOpcode(
        "vdot.f {%d}, {%d}, i0[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    IX0(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        IX0(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILI) {
    gvmDebugOpcode(
        "vdot.f i0[%u], {%d}, i1[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    IX1(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        IX1(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("vdot.f ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        vs1 = (float*)op1;
        vs2 = (float*)op2;
        op3->f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
        gvmDebugOpcode(
            "{ %g, %g, %g } . { %g, %g, %g } => %g",
            vs1[0], vs1[1], vs1[2],
            vs2[0], vs2[1], vs2[2],
            op3->f
        );
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

// Three Operand Cross Product (Noncommutative, 7 unique variants) /////////////////////////////////////////////////////
IS(VCROSS_LLL) {
    gvmDebugOpcode(
        "mul.v {%d}, {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_ILL) {
    gvmDebugOpcode(
        "mul.v i0[%u], {%d}, {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LLI) {
    gvmDebugOpcode(
        "mul.v {%d}, {%d}, i0[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    vd  = VIX0(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_ILI) {
    gvmDebugOpcode(
        "mul.v i0[%u], {%d}, i1[%u] : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LIL) {
    gvmDebugOpcode(
        "mul.v i0[%u], i0[%u], i1[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VIX0(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_IIL) {
    gvmDebugOpcode(
        "mul.v i0[%u], i1[%u], {%d} : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VIX1(1);
    vd  = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LII) {
    gvmDebugOpcode(
        "mul.v {%d}, i0[%u], i1[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VIX0(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_cross_product:
#endif
#include "gvm_vector_cross_product.hpp"
}


// TODO VCROSS_X

// Three Operand Vector Scale (Commutative, mixed args, 7 unique variants) /////////////////////////////////////////////
IS(VFMUL_LLL) {
    gvmDebugOpcode(
        "mulf.v {%d}, {%d}, {%d} : ",
        (int)OPS(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    sf = LOC(1).f;
    vd = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_ILL) {
    gvmDebugOpcode(
        "mulf.v i0[%u], {%d}, {%d} : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    sf = LOC(1).f;
    vd = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LLI) {
    gvmDebugOpcode(
        "mulf.v {%d}, {%d}, i0[%u] : ",
        (int)OPS(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    sf = LOC(1).f;
    vd = VIX0(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_ILI) {
    gvmDebugOpcode(
        "mulf.v i0[%u], {%d}, i1[%u] : ",
        (unsigned)OPU(0),
        (int)OPS(1),
        (unsigned)OPU(2)
    );
    vs1 = VIX0(0);
    sf = LOC(1).f;
    vd = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LIL) {
    gvmDebugOpcode(
        "mulf.v {%d}, i0[%u], {%d} : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs1 = VLOC(0);
    sf = IX0(1).f;
    vd = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_IIL) {
    gvmDebugOpcode(
        "mulf.v i0[%u], i1[%u], {%d} : ",
        (unsigned)OPU(0),
        (unsigned)OPU(1),
        (int)OPS(2)
    );
    vs1 = VIX0(0);
    sf = IX1(1).f;
    vd = VLOC(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LII) {
    gvmDebugOpcode(
        "mulf.v {%d}, i0[%u], i1[%u] : ",
        (int)OPS(0),
        (unsigned)OPU(1),
        (unsigned)OPU(2)
    );
    vs1 = VLOC(0);
    sf = IX0(1).f;
    vd = VIX1(2);

#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_scale_by_float:
#endif
#include "gvm_vector_scale_by_float.hpp"

}

IS(VFMUL_X) {
    Scalar *op1, *op2, *op3;
    gvmDebugOpcode("mulf.v ");
    if (int step = evaluateExtendedAddress3(PRGC, op1, op2, op3)) {
        vs1 = (float*)op1;
        sf  = op2->f;
        vd  = (float*)op3;
        gvmDebugOpcode(
            "{ %g, %g, %g } * %g => ",
            vs1[0], vs1[1], vs1[2],
            sf
        );

        vd[0] = vs1[0] * sf;
        vd[1] = vs1[1] * sf;
        vd[2] = vs1[2] * sf;

        gvmDebugOpcode(
            "{ %g, %g, %g }",
            vd[0], vd[1], vd[2]
        );
        STEP(step);
        NEXT;
    }
    EXIT(EXEC_HALT_AND_CATCH_FIRE);
}

