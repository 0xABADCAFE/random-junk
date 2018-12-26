
// Vector specific Instructions ////////////////////////////////////////////////////////////////////////////////////////

// Single Operand Random Vector ////////////////////////////////////////////////////////////////////////////////////////

IS(VRND_L) {
    vd = VLOC(0);
    float32 x = (invRMax * std::rand()) - 1.0f;
    float32 y = (invRMax * std::rand()) - 1.0f;
    float32 z = (invRMax * std::rand()) - 1.0f;
    sf = 1.0f / std::sqrt((x * x) + (y * y) + (z * z));
    vd[0] = x*sf;
    vd[1] = y*sf;
    vd[2] = z*sf;
    STEP(2);
    NEXT;
}

// Two Operand Branch If Vector Equal //////////////////////////////////////////////////////////////////////////////////

IS(VBEQ_LL) {
    us = ULOC(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_branch_equal;
#else
    #include "gvm_vector_branch_equal.hpp"
#endif
}

IS(VBEQ_IL) {
    us = UIX0(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_branch_equal;
#else
    #include "gvm_vector_branch_equal.hpp"
#endif
}

IS(VBEQ_II) {
    us = UIX0(0);
    ud = UIX1(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_branch_equal:
#endif
#include "gvm_vector_branch_equal.hpp"
}

// Two Operand Branch if Vector Not Equal //////////////////////////////////////////////////////////////////////////////

IS(VBNE_LL) {
    us = ULOC(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_branch_not_equal;
#else
    #include "gvm_vector_branch_not_equal.hpp"
#endif
}

IS(VBNE_IL) {
    us = UIX0(0);
    ud = ULOC(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_branch_not_equal;
#else
    #include "gvm_vector_branch_not_equal.hpp"
#endif
}

IS(VBNE_II) {
    us = UIX0(0);
    ud = UIX1(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_branch_not_equal:
#endif
#include "gvm_vector_branch_not_equal.hpp"
}

// Two Operand Vector Copy /////////////////////////////////////////////////////////////////////////////////////////////

IS(VCOPY_LL) {
    gvmDebugOpcode(
        "\tvcopy %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1)
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
        "\tvcopy %u(i0), %d(sf) : ",
        OPU(0),
        OPS(1)
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
        "\tvcopy %d(sf), %u(i0) : ",
        OPS(0),
        OPU(1)
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
        "\tvcopy %u(i0), %u(i1) : ",
        OPU(0),
        OPU(1)
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
        "\tvneg %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1)
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
        "\tvneg %u(i0), %d(sf) : ",
        OPU(0),
        OPS(1)
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
        "\tvneg %d(sf), %u(i0) : ",
        OPS(0),
        OPU(1)
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
        "\tvneg %u(i0), %u(i1) : ",
        OPU(0),
        OPU(1)
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
        "\tvnorm %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1)
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
        "\tvnorm %u(i0), %d(sf) : ",
        OPU(0),
        OPS(1)
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
        "\tvnorm %d(sf), %u(i0) : ",
        OPS(0),
        OPU(1)
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
        "\tvnorm %u(i0), %u(i1) : ",
        OPU(0),
        OPU(1)
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
    float32* v = VLOC(0);
    LOC(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    STEP(3);
    NEXT;
}

IS(VMAG_IL) {
    float32* v = VIX0(0);
    LOC(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    STEP(3);
    NEXT;
}

IS(VMAG_LI) {
    float32* v = VLOC(0);
    IX0(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    STEP(3);
    NEXT;
}

IS(VMAG_II) {
    float32* v = VIX0(0);
    IX1(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    STEP(3);
    NEXT;
}

// Three Operand Vector Instructions ///////////////////////////////////////////////////////////////////////////////////

// Three Operand Vector Addition (Commutative, 4 unique variants) //////////////////////////////////////////////////////
IS(VADD_LLL) {
    gvmDebugOpcode(
        "\tvadd %d(sf), %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1),
        OPS(2)
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
        "\tvadd %u(i0), %d(sf), %d(sf) : ",
        OPU(0),
        OPS(1),
        OPS(2)
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
        "\tvadd %d(sf), %d(sf), %u(i0) : ",
        OPS(0),
        OPS(1),
        OPU(2)
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
        "\tvadd %u(i0), %d(sf), %u(i1) : ",
        OPU(0),
        OPS(1),
        OPU(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_add:
#endif
#include "gvm_vector_add.hpp"
}

// Three Operand Vector Subtraction (Noncommutative, 7 unique variants) ////////////////////////////////////////////////

IS(VSUB_LLL) {
    gvmDebugOpcode(
        "\tvsub %d(sf), %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1),
        OPS(2)
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
        "\tvsub %u(i0), %d(sf), %d(sf) : ",
        OPU(0),
        OPS(1),
        OPS(2)
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
        "\tvsub %d(sf), %d(sf), %u(i0) : ",
        OPS(0),
        OPS(1),
        OPU(2)
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
        "\tvsub %u(i0), %d(sf), %u(i1) : ",
        OPU(0),
        OPS(1),
        OPU(2)
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
        "\tvsub %d(sf), %u(i0), %d(sf) : ",
        OPS(0),
        OPU(1),
        OPS(2)
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
        "\tvsub %u(i0), %u(i1), %d(sf) : ",
        OPU(0),
        OPU(1),
        OPS(2)
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
        "\tvsub %d(sf), %u(i0), %u(i1) : ",
        OPS(0),
        OPU(1),
        OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VIX0(1);
    vd  = VIX1(2);

#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_subtract:
#endif
#include "gvm_vector_subtract.hpp"
}


// Three Operand Dot Product (Scalar Float Result) /////////////////////////////////////////////////////////////////////

IS(VDOT_LLL) {
    gvmDebugOpcode(
        "\tvdot %d(sf), %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1),
        OPS(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    LOC(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{%0.6f, %0.6f, %0.6f} . {%0.6f, %0.6f, %0.6f} => %.6f\n",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        LOC(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILL) {
    gvmDebugOpcode(
        "\tvdot %u(sf), %d(sf), %d(sf) : ",
        OPU(0),
        OPS(1),
        OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    LOC(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{%0.6f, %0.6f, %0.6f} . {%0.6f, %0.6f, %0.6f} => %.6f\n",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        LOC(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_LLI) {
    gvmDebugOpcode(
        "\tvdot %d(sf), %d(sf), %u(i0) : ",
        OPS(0),
        OPS(1),
        OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VLOC(1);
    IX0(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{%0.6f, %0.6f, %0.6f} . {%0.6f, %0.6f, %0.6f} => %.6f\n",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        IX0(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILI) {
    gvmDebugOpcode(
        "\tvdot %u(i0), %d(sf), %u(i1) : ",
        OPS(0),
        OPS(1),
        OPS(2)
    );
    vs1 = VIX0(0);
    vs2 = VLOC(1);
    IX1(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{%0.6f, %0.6f, %0.6f} . {%0.6f, %0.6f, %0.6f} => %.6f\n",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        IX1(2).f
    );
    STEP(4);
    NEXT;
}


// Three Operand Cross Product (Noncommutative, 7 unique variants) /////////////////////////////////////////////////////
IS(VCROSS_LLL) {
    gvmDebugOpcode(
        "\tvcross %d(sf), %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1),
        OPS(2)
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
        "\tvcross %u(i0), %d(sf), %d(sf) : ",
        OPU(0),
        OPS(1),
        OPS(2)
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
        "\tvcross %d(sf), %d(sf), %u(i0) : ",
        OPS(0),
        OPS(1),
        OPU(2)
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
        "\tvcross %u(i0), %d(sf), %u(i1) : ",
        OPU(0),
        OPS(1),
        OPU(2)
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
        "\tvcross %u(i0), %u(i0), %u(i1) : ",
        OPS(0),
        OPU(1),
        OPS(2)
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
        "\tvcross %u(i0), %u(i1), %d(sf) : ",
        OPU(0),
        OPU(1),
        OPS(2)
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
        "\tvcross %d(sf), %u(i0), %u(i1) : ",
        OPS(0),
        OPU(1),
        OPU(2)
    );
    vs1 = VLOC(0);
    vs2 = VIX0(1);
    vd  = VIX1(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_cross_product:
#endif
#include "gvm_vector_cross_product.hpp"
}


// Three Operand Vector Scale (Commutative, mixed args, 7 unique variants) /////////////////////////////////////////////
IS(VFMUL_LLL) {
    gvmDebugOpcode(
        "\tvfmul %d(sf), %d(sf), %d(sf) : ",
        OPS(0),
        OPS(1),
        OPS(2)
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
        "\tvfmul %u(i0), %d(sf), %d(sf) : ",
        OPU(0),
        OPS(1),
        OPS(2)
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
        "\tvfmul %d(sf), %d(sf), %u(i0) : ",
        OPS(0),
        OPS(1),
        OPU(2)
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
        "\tvfmul %u(i0), %d(sf), %u(i1) : ",
        OPU(0),
        OPS(1),
        OPU(2)
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
        "\tvfmul %d(sf), %u(i0), %d(sf) : ",
        OPS(0),
        OPU(1),
        OPS(2)
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
        "\tvfmul %u(i0), %u(i1), %d(sf) : ",
        OPU(0),
        OPU(1),
        OPS(2)
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
        "\tvfmul %d(sf), %u(i0), %u(i1) : ",
        OPS(0),
        OPU(1),
        OPU(2)
    );
    vs1 = VLOC(0);
    sf = IX0(1).f;
    vd = VIX1(2);

#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_scale_by_float:
#endif
#include "gvm_vector_scale_by_float.hpp"

}
