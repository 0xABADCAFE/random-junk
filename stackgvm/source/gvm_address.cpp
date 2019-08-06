/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include "include/gvm_core.hpp"
#include "include/gvm_debug.hpp"

using namespace GVM;

#ifdef _GVM_ANNOTATE_ASM_
    #define EA(a)  case ExtendedAddress::_##a: asm("; EA EA("#a);
#else
    #define EA(a)  case ExtendedAddress::_##a:
#endif

#define FETCHA switch(pc[1])

// Get the address of a Local variable
#define L(p)   &frameStack[(int8)pc[(p)+2]]

// Get the address of the variable pointed to by i0 + unsigned 8-bit constant offset
#define I0(p)  &callStack->indirection[0][pc[(p)+2]]

// Get the address of the variable pointed to by i1 + unsigned 8-bit constant offset
#define I1(p)  &callStack->indirection[1][pc[(p)+2]]

// Get the address of the variable pointed to by i0 + signed 32-bit offset stored in Local Variable
#define I0X(p) &callStack->indirection[0][frameStack[(int8)pc[(p)+2]].i]

// Get the address of the variable pointed to by i1 + signed 32-bit offset stored in Local Variable
#define I1X(p) &callStack->indirection[1][frameStack[(int8)pc[(p)+2]].i]

// Get the address of the variable pointed to by reference in Local Variable + unsigned 8-bit constant offset
#define R(p)   &frameStack[(int8)pc[(p)+2]].a[pc[(p)+3]]

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Interpreter::evaluateExtendedAddress3(const uint8* pc, Scalar*& op1, Scalar*& op2, Scalar*& op3) {

    FETCHA {

        EA(L_L_I1) {
            op1 = L(0);
            op2 = L(1);
            op3 = I1(2);
            return 4;
        }

        EA(L_L_I0X) {
            op1 = L(0);
            op2 = L(1);
            op3 = I0X(2);
            return 4;
        }

        EA(L_L_I1X) {
            op1 = L(0);
            op2 = L(1);
            op3 = I1X(2);
            return 4;
        }

        EA(L_L_R) {
            op1 = L(0);
            op2 = L(1);
            op3 = R(2);
            return 5;
        }

        EA(L_I0_I0) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I0(2);
            return 4;
        }

        EA(L_I0_I0X) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I0X(2);
            return 4;
        }

        EA(L_I0_I1X) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I1X(2);
            return 4;
        }

        EA(L_I0_R) {
            op1 = L(0);
            op2 = I0(1);
            op3 = R(2);
            return 5;
        }


        EA(L_I1_L)
        EA(L_I1_I0)
        EA(L_I1_I1)
        EA(L_I1_I0X)
        EA(L_I1_I1X)
        EA(L_I1_R)

        EA(L_I0X_L)
        EA(L_I0X_I0)
        EA(L_I0X_I1)
        EA(L_I0X_I0X)
        EA(L_I0X_I1X)
        EA(L_I0X_R)

        EA(L_I1X_L)
        EA(L_I1X_I0)
        EA(L_I1X_I1)
        EA(L_I1X_I0X)
        EA(L_I1X_I1X)
        EA(L_I1X_R)

        EA(L_R_L)
        EA(L_R_I0)
        EA(L_R_I1)
        EA(L_R_I0X)
        EA(L_R_I1X)
        EA(L_R_R)

        EA(I0_L_I0)
        EA(I0_L_I0X)
        EA(I0_L_I1X)
        EA(I0_L_R)

        EA(I0_I0_L)
        EA(I0_I0_I0)
        EA(I0_I0_I1)
        EA(I0_I0_I0X)
        EA(I0_I0_I1X)
        EA(I0_I0_R)

        EA(I0_I1_I0)
        EA(I0_I1_I1)
        EA(I0_I1_I0X)
        EA(I0_I1_I1X)
        EA(I0_I1_R)

        EA(I0_I0X_L)
        EA(I0_I0X_I0)
        EA(I0_I0X_I1)
        EA(I0_I0X_I0X)
        EA(I0_I0X_I1X)
        EA(I0_I0X_R)

        EA(I0_I1X_L)
        EA(I0_I1X_I0)
        EA(I0_I1X_I1)
        EA(I0_I1X_I0X)
        EA(I0_I1X_I1X)
        EA(I0_I1X_R)

        EA(I0_R_L)
        EA(I0_R_I0)
        EA(I0_R_I1)
        EA(I0_R_I0X)
        EA(I0_R_I1X)
        EA(I0_R_R)

        EA(I1_L_L)
        EA(I1_L_I0)
        EA(I1_L_I1)
        EA(I1_L_I0X)
        EA(I1_L_I1X)
        EA(I1_L_R)

        EA(I1_I0_L)
        EA(I1_I0_I0)
        EA(I1_I0_I1)
        EA(I1_I0_I0X)
        EA(I1_I0_I1X)
        EA(I1_I0_R)

        EA(I1_I1_L)
        EA(I1_I1_I0)
        EA(I1_I1_I1)
        EA(I1_I1_I0X)
        EA(I1_I1_I1X)
        EA(I1_I1_R)

        EA(I1_I0X_L)
        EA(I1_I0X_I0)
        EA(I1_I0X_I1)
        EA(I1_I0X_I0X)
        EA(I1_I0X_I1X)
        EA(I1_I0X_R)

        EA(I1_I1X_L)
        EA(I1_I1X_I0)
        EA(I1_I1X_I1)
        EA(I1_I1X_I0X)
        EA(I1_I1X_I1X)
        EA(I1_I1X_R)

        EA(I1_R_L)
        EA(I1_R_I0)
        EA(I1_R_I1)
        EA(I1_R_I0X)
        EA(I1_R_I1X)
        EA(I1_R_R)

        EA(I0X_L_L)
        EA(I0X_L_I0)
        EA(I0X_L_I1)
        EA(I0X_L_I0X)
        EA(I0X_L_I1X)
        EA(I0X_L_R)

        EA(I0X_I0_L)
        EA(I0X_I0_I0)
        EA(I0X_I0_I1)
        EA(I0X_I0_I0X)
        EA(I0X_I0_I1X)
        EA(I0X_I0_R)

        EA(I0X_I1_L)
        EA(I0X_I1_I0)
        EA(I0X_I1_I1)
        EA(I0X_I1_I0X)
        EA(I0X_I1_I1X)
        EA(I0X_I1_R)

        EA(I0X_I0X_L)
        EA(I0X_I0X_I0)
        EA(I0X_I0X_I1)
        EA(I0X_I0X_I0X)
        EA(I0X_I0X_I1X)
        EA(I0X_I0X_R)

        EA(I0X_I1X_L)
        EA(I0X_I1X_I0)
        EA(I0X_I1X_I1)
        EA(I0X_I1X_I0X)
        EA(I0X_I1X_I1X)
        EA(I0X_I1X_R)

        EA(I0X_R_L)
        EA(I0X_R_I0)
        EA(I0X_R_I1)
        EA(I0X_R_I0X)
        EA(I0X_R_I1X)
        EA(I0X_R_R)

        EA(I1X_L_L)
        EA(I1X_L_I0)
        EA(I1X_L_I1)
        EA(I1X_L_I0X)
        EA(I1X_L_I1X)
        EA(I1X_L_R)

        EA(I1X_I0_L)
        EA(I1X_I0_I0)
        EA(I1X_I0_I1)
        EA(I1X_I0_I0X)
        EA(I1X_I0_I1X)
        EA(I1X_I0_R)

        EA(I1X_I1_L)
        EA(I1X_I1_I0)
        EA(I1X_I1_I1)
        EA(I1X_I1_I0X)
        EA(I1X_I1_I1X)
        EA(I1X_I1_R)

        EA(I1X_I0X_L)
        EA(I1X_I0X_I0)
        EA(I1X_I0X_I1)
        EA(I1X_I0X_I0X)
        EA(I1X_I0X_I1X)
        EA(I1X_I0X_R)

        EA(I1X_I1X_L)
        EA(I1X_I1X_I0)
        EA(I1X_I1X_I1)
        EA(I1X_I1X_I0X)
        EA(I1X_I1X_I1X)
        EA(I1X_I1X_R)

        EA(I1X_R_L)
        EA(I1X_R_I0)
        EA(I1X_R_I1)
        EA(I1X_R_I0X)
        EA(I1X_R_I1X)
        EA(I1X_R_R)

        EA(R_L_L)
        EA(R_L_I0)
        EA(R_L_I1)
        EA(R_L_I0X)
        EA(R_L_I1X)
        EA(R_L_R)

        EA(R_I0_L)
        EA(R_I0_I0)
        EA(R_I0_I1)
        EA(R_I0_I0X)
        EA(R_I0_I1X)
        EA(R_I0_R)

        EA(R_I1_L)
        EA(R_I1_I0)
        EA(R_I1_I1)
        EA(R_I1_I0X)
        EA(R_I1_I1X)
        EA(R_I1_R)

        EA(R_I0X_L)
        EA(R_I0X_I0)
        EA(R_I0X_I1)
        EA(R_I0X_I0X)
        EA(R_I0X_I1X)
        EA(R_I0X_R)

        EA(R_I1X_L)
        EA(R_I1X_I0)
        EA(R_I1X_I1)
        EA(R_I1X_I0X)
        EA(R_I1X_I1X)
        EA(R_I1X_R)

        EA(R_R_L)
        EA(R_R_I0)
        EA(R_R_I1)
        EA(R_R_I0X)
        EA(R_R_I1X)
        EA(R_R_R)

        default:
            break;
    }

    return 0;
}
