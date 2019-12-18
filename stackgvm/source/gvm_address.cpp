/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include "include/gvm_core.hpp"
#include "include/gvm_debug.hpp"
#include <cstdio>

using namespace GVM;

#ifdef _GVM_ANNOTATE_ASM_
    #define EA(a)  case ExtendedAddress::_##a: asm("; EA("#a"):");
#else
    #define EA(a)  case ExtendedAddress::_##a:
#endif

#define FETCHA switch(pc[1])

#define OSIZE 2 // Size of operation plus address byte
#define LSIZE 1 // Size of local operand
#define ISIZE 1 // Size of indirection register operand
#define RSIZE 2 // Size of local reference operand

// Get the address of a Local variable
#define L(p)   &frameStack[(int8)pc[(p) + OSIZE]]

// Get the address of the variable pointed to by i0 + unsigned 8-bit constant offset
#define I0(p)  &callStack->indirection[0][pc[(p) + OSIZE]]

// Get the address of the variable pointed to by i1 + unsigned 8-bit constant offset
#define I1(p)  &callStack->indirection[1][pc[(p) + OSIZE]]

// Get the address of the variable pointed to by i0 + signed 32-bit offset stored in Local Variable
#define I0X(p) &callStack->indirection[0][frameStack[(int8)pc[(p) + OSIZE]].i]

// Get the address of the variable pointed to by i1 + signed 32-bit offset stored in Local Variable
#define I1X(p) &callStack->indirection[1][frameStack[(int8)pc[(p) + OSIZE]].i]

// Get the address of the variable pointed to by reference in Local Variable + unsigned 8-bit constant offset
#define R(p)   &(frameStack[(int8)pc[(p) + OSIZE]].a[pc[(p) + OSIZE + LSIZE]])


#ifdef _GVM_DEBUG_OPCODES_
    #define gvmDebugAddress(...) std::fprintf(stderr, __VA_ARGS__)
#else
    #define gvmDebugAddress(...)
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 */
int Interpreter::evaluateExtendedAddress3(const uint8* pc, Scalar*& op1, Scalar*& op2, Scalar*& op3) {

    FETCHA {
        #include "include/gvm_address_modes.hpp"

        default:
            break;
    }

    return 0;
}
