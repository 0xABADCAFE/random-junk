
// Vector specific Instructions ////////////////////////////////////////////////////////////////////////////////////////

// Single Operand Random Vector ////////////////////////////////////////////////////////////////////////////////////////

IS(VRND_L) {
    vd = OP_LOCAL_VEC_3F(0);
    SCALAR_F x = (invRMax * std::rand()) - 1.0f;
    SCALAR_F y = (invRMax * std::rand()) - 1.0f;
    SCALAR_F z = (invRMax * std::rand()) - 1.0f;
    sf = 1.0f / std::sqrt((x * x) + (y * y) + (z * z));
    vd[0] = x*sf;
    vd[1] = y*sf;
    vd[2] = z*sf;
    gvmDebugOpcode(
        "rnd.v " OPF_L " : { %g, %g, %g }",
        (int)OP_LITERAL_S8(0),
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
        "copy.v " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1)
    );
    us = OP_LOCAL_VEC_3(0);
    ud = OP_LOCAL_VEC_3(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_IL) {
    gvmDebugOpcode(
        "copy.v " OPF_I0 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1)
    );
    us = OP_INDIRECT_0_VEC_3(0);
    ud = OP_LOCAL_VEC_3(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_LI) {
    gvmDebugOpcode(
        "copy.v " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    us = OP_LOCAL_VEC_3(0);
    ud = OP_INDIRECT_0_VEC_3(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_copy;
#else
    #include "gvm_vector_copy.hpp"
#endif
}

IS(VCOPY_II) {
    gvmDebugOpcode(
        "copy.v " OPF_I0 ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    us = OP_INDIRECT_0_VEC_3(0);
    ud = OP_INDIRECT_1_VEC_3(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_copy:
#endif
#include "gvm_vector_copy.hpp"
}

// Two Operand Vector Negate ///////////////////////////////////////////////////////////////////////////////////////////

IS(VNEG_LL) {
    gvmDebugOpcode(
        "neg.v " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vd  = OP_LOCAL_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_IL) {
    gvmDebugOpcode(
        "neg.v " OPF_I0 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vd  = OP_LOCAL_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_LI) {
    gvmDebugOpcode(
        "neg.v " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vd  = OP_INDIRECT_0_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_negate;
#else
    #include "gvm_vector_negate.hpp"
#endif
}

IS(VNEG_II) {
    gvmDebugOpcode(
        "neg.v " OPF_I0 ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vd  = OP_INDIRECT_1_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_negate:
#endif
#include "gvm_vector_negate.hpp"
}

// Two Operand Vector Normalisation ////////////////////////////////////////////////////////////////////////////////////

IS(VNORM_LL) {
    gvmDebugOpcode(
        "vnrm.v " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vd  = OP_LOCAL_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_IL) {
    gvmDebugOpcode(
        "vnrm.v " OPF_I0 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vd  = OP_LOCAL_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_LI) {
    gvmDebugOpcode(
        "vnrm.v " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vd  = OP_INDIRECT_0_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_normalise;
#else
    #include "gvm_vector_normalise.hpp"
#endif
}

IS(VNORM_II) {
    gvmDebugOpcode(
        "vnrm.v " OPF_I0 ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vd  = OP_INDIRECT_1_VEC_3F(1);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_normalise:
#endif
#include "gvm_vector_normalise.hpp"
}

// Two Operand Vector Magnitude (Float Result) /////////////////////////////////////////////////////////////////////////

IS(VMAG_LL) {
    SCALAR_F* v = OP_LOCAL_VEC_3F(0);
    gvmDebugOpcode(
        "vmag.f " OPF_L ", " OPF_L " : |{ %g, %g, %g }| => ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        v[0], v[1], v[2]
    );
    OP_LOCAL(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_IL) {
    SCALAR_F* v = OP_INDIRECT_0_VEC_3F(0);
    gvmDebugOpcode(
        "vmag.f " OPF_I0 ", " OPF_L " : |{ %g, %g, %g }| => ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        v[0], v[1], v[2]
    );
    OP_LOCAL(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", OP_LOCAL(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_LI) {
    SCALAR_F* v = OP_LOCAL_VEC_3F(0);
    gvmDebugOpcode(
        "vmag.f " OPF_L ", " OPF_I0 " : |{ %g, %g, %g }| => ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        v[0], v[1], v[2]
    );
    OP_INDIRECT_0(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", OP_INDIRECT_0(1).f);
    STEP(3);
    NEXT;
}

IS(VMAG_II) {
    SCALAR_F* v = OP_INDIRECT_0_VEC_3F(0);
    gvmDebugOpcode(
        "vmag.f " OPF_I0 ", " OPF_I1 " : |{ %g, %g, %g }| => ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        v[0], v[1], v[2]
    );
    OP_INDIRECT_1(1).f = std::sqrt(
        (v[0] * v[0]) +
        (v[1] * v[1]) +
        (v[2] * v[2])
    );
    gvmDebugOpcode("%g", OP_INDIRECT_1(1).f);
    STEP(3);
    NEXT;
}

// Three Operand Vector Instructions ///////////////////////////////////////////////////////////////////////////////////

// Three Operand Vector Addition (Commutative, 4 unique variants) //////////////////////////////////////////////////////
IS(VADD_LLL) {
    gvmDebugOpcode(
        "add.v " OPF_L ", " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_ILL) {
    gvmDebugOpcode(
        "add.v " OPF_I0 ", " OPF_L ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_LLI) {
    gvmDebugOpcode(
        "add.v " OPF_L ", " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_0_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_add;
#else
    #include "gvm_vector_add.hpp"
#endif
}

IS(VADD_ILI) {
    gvmDebugOpcode(
        "add.v " OPF_I0 ", " OPF_L ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_1_VEC_3F(2);
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
        "sub.v " OPF_L ", " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_ILL) {
    gvmDebugOpcode(
        "sub.v " OPF_I0 ", " OPF_L ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
    vs1 = OP_INDIRECT_0_VEC_3F(0);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LLI) {
    gvmDebugOpcode(
        "sub.v " OPF_L ", " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_0_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_ILI) {
    gvmDebugOpcode(
        "sub.v " OPF_I0 ", " OPF_L ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_1_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LIL) {
    gvmDebugOpcode(
        "sub.v " OPF_L ", " OPF_I0 ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs2 = OP_INDIRECT_0_VEC_3F(1);
    vs1 = OP_LOCAL_VEC_3F(0);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_IIL) {
    gvmDebugOpcode(
        "sub.v " OPF_I0 ", " OPF_I1 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_INDIRECT_1_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_subtract;
#else
    #include "gvm_vector_subtract.hpp"
#endif
}

IS(VSUB_LII) {
    gvmDebugOpcode(
        "sub.v " OPF_L ", " OPF_I0 ", " OPF_I1 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_INDIRECT_0_VEC_3F(1);
    vd  = OP_INDIRECT_1_VEC_3F(2);

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
        "vdot.f " OPF_L ", " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    OP_LOCAL(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        OP_LOCAL(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILL) {
    gvmDebugOpcode(
        "vdot.f %u(sf), " OPF_L ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    OP_LOCAL(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        OP_LOCAL(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_LLI) {
    gvmDebugOpcode(
        "vdot.f " OPF_L ", " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    OP_INDIRECT_0(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        OP_INDIRECT_0(2).f
    );
    STEP(4);
    NEXT;
}

IS(VDOT_ILI) {
    gvmDebugOpcode(
        "vdot.f " OPF_I0 ", " OPF_L ", " OPF_I1 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    OP_INDIRECT_1(2).f = vs1[0] * vs2[0] + vs1[1] * vs2[1] + vs1[2] * vs2[2];
    gvmDebugOpcode(
        "{ %g, %g, %g } . { %g, %g, %g } => %g",
        vs1[0], vs1[1], vs1[2],
        vs2[0], vs2[1], vs2[2],
        OP_INDIRECT_1(2).f
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
        "mul.v " OPF_L ", " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_ILL) {
    gvmDebugOpcode(
        "mul.v " OPF_I0 ", " OPF_L ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LLI) {
    gvmDebugOpcode(
        "mul.v " OPF_L ", " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_0_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_ILI) {
    gvmDebugOpcode(
        "mul.v " OPF_I0 ", " OPF_L ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_LOCAL_VEC_3F(1);
    vd  = OP_INDIRECT_1_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LIL) {
    gvmDebugOpcode(
        "mul.v " OPF_I0 ", " OPF_I0 ", " OPF_I1 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_INDIRECT_0_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_IIL) {
    gvmDebugOpcode(
        "mul.v " OPF_I0 ", " OPF_I1 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    vs2 = OP_INDIRECT_1_VEC_3F(1);
    vd  = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_cross_product;
#else
    #include "gvm_vector_cross_product.hpp"
#endif
}

IS(VCROSS_LII) {
    gvmDebugOpcode(
        "mul.v " OPF_L ", " OPF_I0 ", " OPF_I1 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    vs2 = OP_INDIRECT_0_VEC_3F(1);
    vd  = OP_INDIRECT_1_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    vector_cross_product:
#endif
#include "gvm_vector_cross_product.hpp"
}


// TODO VCROSS_X

// Three Operand Vector Scale (Commutative, mixed args, 7 unique variants) /////////////////////////////////////////////
IS(VFMUL_LLL) {
    gvmDebugOpcode(
        "mulf.v " OPF_L ", " OPF_L ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    sf = OP_LOCAL(1).f;
    vd = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_ILL) {
    gvmDebugOpcode(
        "mulf.v " OPF_I0 ", " OPF_L ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    sf = OP_LOCAL(1).f;
    vd = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LLI) {
    gvmDebugOpcode(
        "mulf.v " OPF_L ", " OPF_L ", " OPF_I0 " : ",
        (int)OP_LITERAL_S8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    sf = OP_LOCAL(1).f;
    vd = OP_INDIRECT_0_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_ILI) {
    gvmDebugOpcode(
        "mulf.v " OPF_I0 ", " OPF_L ", " OPF_I1 " : ",
        (unsigned)OP_LITERAL_U8(0),
        (int)OP_LITERAL_S8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    sf = OP_LOCAL(1).f;
    vd = OP_INDIRECT_1_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LIL) {
    gvmDebugOpcode(
        "mulf.v " OPF_L ", " OPF_I0 ", " OPF_L " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    sf = OP_INDIRECT_0(1).f;
    vd = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_IIL) {
    gvmDebugOpcode(
        "mulf.v " OPF_I0 ", " OPF_I1 ", " OPF_L " : ",
        (unsigned)OP_LITERAL_U8(0),
        (unsigned)OP_LITERAL_U8(1),
        (int)OP_LITERAL_S8(2)
    );
    vs1 = OP_INDIRECT_0_VEC_3F(0);
    sf = OP_INDIRECT_1(1).f;
    vd = OP_LOCAL_VEC_3F(2);
#ifdef _GVM_OPT_ALLOW_GOTO_
    goto vector_scale_by_float;
#else
    #include "gvm_vector_scale_by_float.hpp"
#endif
}

IS(VFMUL_LII) {
    gvmDebugOpcode(
        "mulf.v " OPF_L ", " OPF_I0 ", " OPF_I1 " : ",
        (int)OP_LITERAL_S8(0),
        (unsigned)OP_LITERAL_U8(1),
        (unsigned)OP_LITERAL_U8(2)
    );
    vs1 = OP_LOCAL_VEC_3F(0);
    sf = OP_INDIRECT_0(1).f;
    vd = OP_INDIRECT_1_VEC_3F(2);

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

