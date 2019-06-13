/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include "include/gvm_core.hpp"
#include "include/gvm_debug.hpp"

using namespace GVM;

#ifdef _GVM_OPT_CACHE_POINTERS_
    #define DECLARE_PTRS \
        Scalar *myFS, *myIR[2]; \
        const uint8* myPC = programCounter;
    #define UPDATE_PTRS \
        myPC = programCounter; \
        myFS = frameStack; \
        myIR[0] = callStack->indirection[0];\
        myIR[1] = callStack->indirection[1];
    #define IR(idx)          myIR[(idx)]
    #define SAVE_IR(idx)     callStack->indirection[(idx)] =  myIR[(idx)]
    #define PRGC             myPC
    #define SAVE_PRGC        programCounter = myPC
    #define LOC(operand)   ( myFS[(int8)myPC[(operand) + 1]] )
#else
    #define DECLARE_PTRS
    #define UPDATE_PTRS
    #define IR(idx)          callStack->indirection[(idx)]
    #define SAVE_IR(idx)
    #define PRGC             programCounter
    #define SAVE_PRGC
    #define LOC(operand)   ( frameStack[(int8)programCounter[(operand) + 1]] )
#endif

#ifdef _GVM_DEBUG_OPCODES_
    #define OPS(o) ((int)PRGC[(o)+1])
    #define OPU(o) ((unsigned)PRGC[(o)+1])
    //#define IS(opcode)          case Opcode::_##opcode: std::fprintf(stderr, "\t%-10s %3d %3d %3d\n", #opcode, (int)PRGC[1], (int)PRGC[2], (int)PRGC[3]);
    #define IS(opcode) case Opcode::_##opcode: gvmDebug("\n%p : ", PRGC);
    #define gvmDebugOpcode(...) std::fprintf(stderr, __VA_ARGS__)
    #define gvmDebugJump(o) gvmDebugOpcode("jump to %p\n", PRGC + (int)J16((o)));
    #define gvmDebugSkip()  gvmDebugOpcode("skip")
#else
    #define OPS(o)
    #define OPU(o)
#ifdef _GVM_ANNOTATE_ASM_
    #define IS(opcode)    case Opcode::_##opcode: asm("; "#opcode);
#else
    #define IS(opcode)    case Opcode::_##opcode:
#endif
    #define gvmDebugOpcode(...)
    #define gvmDebugJump(o)
    #define gvmDebugSkip()
#endif

#define FETCH   switch (*PRGC)
#define FETCHC  switch (PRGC[1])

#ifdef _GVM_ANNOTATE_ASM_
#define BCC(c)  case Condition::_##c: asm("; BOC _"#c);
#else
#define BCC(c)  case Condition::_##c:
#endif

#define NEXT          goto forever
#define STEP(size)    PRGC += (size)
#define EXIT(code)    SAVE_PRGC; return ((code))

// Local Operand, dereferences a Scalar on the stack frame by the signed 8-bit operand.
// Parameter is the operand byte number.

// Vector local operand, returns a float32 pointer to the zeroth element of the vector
#define VLOC(operand)  ( (float32*)&LOC(operand) )

// Vector expressed as triplet of unsigned words - for data transfer operations
#define ULOC(operand)  ( (uint32*)&LOC(operand) )

// Indirect Operand, dereferences one of the index registers by the unsigned 8-bit operand.

#define IX(idx, operand) ( IR(idx)[PRGC[(operand) + 1]] )
#define IX0(operand)     ( IR(0)[PRGC[(operand) + 1]] )
#define IX1(operand)     ( IR(1)[PRGC[(operand) + 1]] )


// Vector Indirect Operand,
#define VIX0(operand)    ((float32*)&IX0(operand))
#define VIX1(operand)    ((float32*)&IX1(operand))

// Vector expressed as triplet of unsigned words - for data transfoer operations
#define UIX0(operand)    ((uint32*)&IX0(operand))
#define UIX1(operand)    ((uint32*)&IX1(operand))

// Jump displaceents
#define J16(operand)  (int16)(((uint16)PRGC[(operand) + 1] << 8) | PRGC[(operand) + 2])
#define J8(operand)   (int8)PRGC[(operand) + 1]

// Literal values
#define S8(operand)   (int8)PRGC[(operand) + 1]
#define U8(operand)   PRGC[(operand) + 1]
#define S16(operand)  (int16)(((uint16)PRGC[(operand) + 1] << 8) | PRGC[(operand) + 2])
#define U16(operand)  (((uint16)PRGC[(operand) + 1] << 8) | PRGC[(operand) + 2])

// Symbol ID
#define SYM(operand)  (((uint16)PRGC[(operand) + 1] << 8) | PRGC[(operand) + 2])

// Return address
#define RTA(size)  (PRGC + (size))


#ifdef _GVM_PROFILE_OPCODE_COUNTS_
#define INIT_OPCODE_COUNTS static uint64 perInstructionCounts[256] = { 0 }
#define UPDATE_OPCODE_COUNTS ++perInstructionCounts[(*PRGC)]
#define DUMP_OPCODE_COUNTS \
    for (uint32 i=0; i<256; i++) { \
        if (perInstructionCounts[i]) { \
            std::fprintf(stderr, "\t%02X : %llu\n", i, perInstructionCounts[i]); \
        } \
    }
#else
#define INIT_OPCODE_COUNTS
#define UPDATE_OPCODE_COUNTS
#define DUMP_OPCODE_COUNTS
#endif

const float32 invRMax = 1.0f / (float32)RAND_MAX;

Result Interpreter::run() {
    DECLARE_PTRS;

    float32 *vs1, *vs2, *vd, sf;
    uint32  *us, *ud, tag;
    Result  result;

    UPDATE_PTRS;

    uint64 numExecuted = -1;
    INIT_OPCODE_COUNTS;

forever:
    UPDATE_OPCODE_COUNTS;
    ++numExecuted;
    FETCH {
        #include "include/gvm_untyped.hpp"
        #include "include/gvm_integer.hpp"
        #include "include/gvm_float.hpp"
        #include "include/gvm_vector.hpp"
        #include "include/gvm_conditional_branch.hpp"
        default:
            return EXEC_HALT_AND_CATCH_FIRE;
    }
    return SUCCESS;
}
