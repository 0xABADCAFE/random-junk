

// Branch on Condition ///////// ///////////////////////////////////////////////////////////////////////////////////////

#ifdef _GVM_OPT_BCC_16_BIT_
    #define OP_JUMP_OFFSET(n) OP_JUMP_S16(n)
    #define JSKIP 6
#else
    #define OP_JUMP_OFFSET(n) OP_JUMP_S8(n)
    #define JSKIP 5
#endif

#ifdef _GVM_OPT_ALLOW_GOTO_

    #define BOC_TAKEN   goto boc_branch_taken;
    #define BOC_SKIPPED goto boc_branch_skipped;
    #define HANDLE_BOC_TAKEN \
    gvmDebugJump(3); \
    STEP(OP_JUMP_OFFSET(3)); \
    NEXT;

    #define HANDLE_BOC_SKIPPED \
    gvmDebugSkip(); \
    STEP(JSKIP); \
    NEXT;

#else

    #define BOC_TAKEN \
    gvmDebugJump(3); \
    STEP(OP_JUMP_OFFSET(3)); \
    NEXT;

    #define BOC_SKIPPED \
    gvmDebugSkip(); \
    STEP(JSKIP); \
    NEXT;

    #define HANDLE_BOC_TAKEN
    #define HANDLE_BOC_SKIPPED

#endif

IS(BOC) {

    /**
     * Branch On Condition
     * Instruction layout:
     * [Opcode] [Condition] [Operand 1] [Operand 2] [Jump MSB] [Jump LSB]
     *
     */
    FETCHC {
        #include "gvm_branch/bits_equal.hpp"
        #include "gvm_branch/bits_not_equal.hpp"
        #include "gvm_branch/int_less_than.hpp"
        #include "gvm_branch/int_less_or_equal.hpp"
        #include "gvm_branch/int_greater_or_equal.hpp"
        #include "gvm_branch/int_greater_than.hpp"
        #include "gvm_branch/bit_set.hpp"
        #include "gvm_branch/bit_not_set.hpp"
        #include "gvm_branch/float_less_than.hpp"
        #include "gvm_branch/float_less_or_equal.hpp"
        #include "gvm_branch/float_greater_or_equal.hpp"
        #include "gvm_branch/float_greater_than.hpp"
        #include "gvm_branch/float_approx_equal.hpp"
        #include "gvm_branch/vector_equal.hpp"
        #include "gvm_branch/vector_approx_equal.hpp"
        #include "gvm_branch/vector_not_equal.hpp"
    }

    #pragma GCC diagnostic ignored "-Wunused-label"
    boc_branch_taken:
        HANDLE_BOC_TAKEN;
    boc_branch_skipped:
        HANDLE_BOC_SKIPPED;
}
