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

#define OSIZE 2 // Size of operation plus address byte
#define LSIZE 1 // Size of local operand
#define ISIZE 1 // Size of indirection register operand
#define RSIZE 2 // Size of local reference operand

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *
 */
int Interpreter::evaluateExtendedAddress3(const uint8* pc, Scalar*& op1, Scalar*& op2, Scalar*& op3) {

    FETCHA {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_L_I1) {
            op1 = L(0);
            op2 = L(1);
            op3 = I1(2);
            return OSIZE + LSIZE + LSIZE + ISIZE;
        }

        EA(L_L_I0X) {
            op1 = L(0);
            op2 = L(1);
            op3 = I0X(2);
            return OSIZE + LSIZE + LSIZE + ISIZE;
        }

        EA(L_L_I1X) {
            op1 = L(0);
            op2 = L(1);
            op3 = I1X(2);
            return OSIZE + LSIZE + LSIZE + ISIZE;
        }

        EA(L_L_R) {
            op1 = L(0);
            op2 = L(1);
            op3 = R(2);
            return OSIZE + LSIZE + LSIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_I0_I0) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I0(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0_I0X) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I0X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0_I1X) {
            op1 = L(0);
            op2 = I0(1);
            op3 = I1X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0_R) {
            op1 = L(0);
            op2 = I0(1);
            op3 = R(2);
            return OSIZE + LSIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_I1_L) {
            op1 = L(0);
            op2 = I1(1);
            op3 = L(2);
            return OSIZE + LSIZE + ISIZE + LSIZE;
        }

        EA(L_I1_I0) {
            op1 = L(0);
            op2 = I1(1);
            op3 = I0(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1_I1) {
            op1 = L(0);
            op2 = I1(1);
            op3 = I1(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1_I0X) {
            op1 = L(0);
            op2 = I1(1);
            op3 = I0X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1_I1X) {
            op1 = L(0);
            op2 = I1(1);
            op3 = I1X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1_R) {
            op1 = L(0);
            op2 = I1(1);
            op3 = R(2);
            return OSIZE + LSIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_I0X_L) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = L(2);
            return OSIZE + LSIZE + ISIZE + LSIZE;
        }

        EA(L_I0X_I0) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = I0(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0X_I1) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = I1(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0X_I0X) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = I0X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0X_I1X) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = I1X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I0X_R) {
            op1 = L(0);
            op2 = I0X(1);
            op3 = R(2);
            return OSIZE + LSIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_I1X_L) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = L(2);
            return OSIZE + LSIZE + ISIZE + LSIZE;
        }

        EA(L_I1X_I0) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = I0(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1X_I1) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = I1(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1X_I0X) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = I0X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }


        EA(L_I1X_I1X) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = I1X(2);
            return OSIZE + LSIZE + ISIZE + ISIZE;
        }

        EA(L_I1X_R) {
            op1 = L(0);
            op2 = I1X(1);
            op3 = R(2);
            return OSIZE + LSIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local, local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(L_R_L) {
            op1 = L(0);
            op2 = R(1);
            op3 = L(3);
            return OSIZE + LSIZE + RSIZE + LSIZE;
        }

        EA(L_R_I0) {
            op1 = L(0);
            op2 = R(1);
            op3 = I0(3);
            return OSIZE + LSIZE + RSIZE + ISIZE;
        }

        EA(L_R_I1) {
            op1 = L(0);
            op2 = R(1);
            op3 = I1(3);
            return OSIZE + LSIZE + RSIZE + ISIZE;
        }

        EA(L_R_I0X) {
            op1 = L(0);
            op2 = R(1);
            op3 = I0X(3);
            return OSIZE + LSIZE + RSIZE + ISIZE;
        }

        EA(L_R_I1X) {
            op1 = L(0);
            op2 = R(1);
            op3 = I1X(3);
            return OSIZE + LSIZE + RSIZE + ISIZE;
        }

        EA(L_R_R) {
            op1 = L(0);
            op2 = R(1);
            op3 = R(3);
            return OSIZE + LSIZE + RSIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint8], local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_L_I0) {
            op1 = I0(0);
            op2 = L(1);
            op3 = I0(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I0_L_I0X) {
            op1 = I0(0);
            op2 = L(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I0_L_I1X) {
            op1 = I0(0);
            op2 = L(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I0_L_R) {
            op1 = I0(0);
            op2 = L(1);
            op3 = R(2);
            return OSIZE + ISIZE + LSIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint8], i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_I0_L) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = L(2);
            return OSIZE + ISIZE + ISIZE + LSIZE;
        }

        EA(I0_I0_I0) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = I0(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0_I1) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = I1(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0_I0X) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0_I1X) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0_R) {
            op1 = I0(0);
            op2 = I0(1);
            op3 = R(2);
            return OSIZE + ISIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint8], i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_I1_I0) {
            op1 = I0(0);
            op2 = I1(1);
            op3 = I0(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1_I1) {
            op1 = I0(0);
            op2 = I1(1);
            op3 = I1(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1_I0X) {
            op1 = I0(0);
            op2 = I1(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1_I1X) {
            op1 = I0(0);
            op2 = I1(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1_R) {
            op1 = I0(0);
            op2 = I1(1);
            op3 = R(2);
            return OSIZE + ISIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint8], i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_I0X_L) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = L(2);
            return OSIZE + ISIZE + ISIZE + LSIZE;
        }

        EA(I0_I0X_I0) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = I0(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0X_I1) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = I1(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0X_I0X) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0X_I1X) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I0X_R) {
            op1 = I0(0);
            op2 = I0X(1);
            op3 = R(2);
            return OSIZE + ISIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint], i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_I1X_L) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = L(2);
            return OSIZE + ISIZE + ISIZE + LSIZE;
        }

        EA(I0_I1X_I0) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = I0(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1X_I1) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = I1(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1X_I0X) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1X_I1X) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + ISIZE + ISIZE;
        }

        EA(I0_I1X_R) {
            op1 = I0(0);
            op2 = I1X(1);
            op3 = R(2);
            return OSIZE + ISIZE + ISIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[const uint8], local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0_R_L) {
            op1 = I0(0);
            op2 = R(1);
            op3 = L(3);
            return OSIZE + ISIZE + RSIZE + LSIZE;
        }

        EA(I0_R_I0) {
            op1 = I0(0);
            op2 = R(1);
            op3 = I0(3);
            return OSIZE + ISIZE + RSIZE + ISIZE;
        }

        EA(I0_R_I1) {
            op1 = I0(0);
            op2 = R(1);
            op3 = I1(3);
            return OSIZE + ISIZE + RSIZE + ISIZE;
        }

        EA(I0_R_I0X) {
            op1 = I0(0);
            op2 = R(1);
            op3 = I0X(3);
            return OSIZE + ISIZE + RSIZE + ISIZE;
        }

        EA(I0_R_I1X) {
            op1 = I0(0);
            op2 = R(1);
            op3 = I1X(3);
            return OSIZE + ISIZE + RSIZE + ISIZE;
        }

        EA(I0_R_R) {
            op1 = I0(0);
            op2 = R(1);
            op3 = R(3);
            return OSIZE + ISIZE + RSIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_L_L) {
            op1 = I1(0);
            op2 = L(1);
            op3 = L(2);
            return OSIZE + ISIZE + LSIZE + LSIZE;
        }

        EA(I1_L_I0) {
            op1 = I1(0);
            op2 = L(1);
            op3 = I0(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I1_L_I1) {
            op1 = I1(0);
            op2 = L(1);
            op3 = I1(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I1_L_I0X) {
            op1 = I1(0);
            op2 = L(1);
            op3 = I0X(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I1_L_I1X) {
            op1 = I1(0);
            op2 = L(1);
            op3 = I1X(2);
            return OSIZE + ISIZE + LSIZE + ISIZE;
        }

        EA(I1_L_R) {
            op1 = I1(0);
            op2 = L(1);
            op3 = R(2);
            return OSIZE + ISIZE + LSIZE + RSIZE;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_I0_L)
        EA(I1_I0_I0)
        EA(I1_I0_I1)
        EA(I1_I0_I0X)
        EA(I1_I0_I1X)
        EA(I1_I0_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_I1_L)
        EA(I1_I1_I0)
        EA(I1_I1_I1)
        EA(I1_I1_I0X)
        EA(I1_I1_I1X)
        EA(I1_I1_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_I0X_L)
        EA(I1_I0X_I0)
        EA(I1_I0X_I1)
        EA(I1_I0X_I0X)
        EA(I1_I0X_I1X)
        EA(I1_I0X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_I1X_L)
        EA(I1_I1X_I0)
        EA(I1_I1X_I1)
        EA(I1_I1X_I0X)
        EA(I1_I1X_I1X)
        EA(I1_I1X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[const uint8], local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1_R_L)
        EA(I1_R_I0)
        EA(I1_R_I1)
        EA(I1_R_I0X)
        EA(I1_R_I1X)
        EA(I1_R_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_L_L)
        EA(I0X_L_I0)
        EA(I0X_L_I1)
        EA(I0X_L_I0X)
        EA(I0X_L_I1X)
        EA(I0X_L_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_I0_L)
        EA(I0X_I0_I0)
        EA(I0X_I0_I1)
        EA(I0X_I0_I0X)
        EA(I0X_I0_I1X)
        EA(I0X_I0_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_I1_L)
        EA(I0X_I1_I0)
        EA(I0X_I1_I1)
        EA(I0X_I1_I0X)
        EA(I0X_I1_I1X)
        EA(I0X_I1_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_I0X_L)
        EA(I0X_I0X_I0)
        EA(I0X_I0X_I1)
        EA(I0X_I0X_I0X)
        EA(I0X_I0X_I1X)
        EA(I0X_I0X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_I1X_L)
        EA(I0X_I1X_I0)
        EA(I0X_I1X_I1)
        EA(I0X_I1X_I0X)
        EA(I0X_I1X_I1X)
        EA(I0X_I1X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i0[local], local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I0X_R_L)
        EA(I0X_R_I0)
        EA(I0X_R_I1)
        EA(I0X_R_I0X)
        EA(I0X_R_I1X)
        EA(I0X_R_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_L_L)
        EA(I1X_L_I0)
        EA(I1X_L_I1)
        EA(I1X_L_I0X)
        EA(I1X_L_I1X)
        EA(I1X_L_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_I0_L)
        EA(I1X_I0_I0)
        EA(I1X_I0_I1)
        EA(I1X_I0_I0X)
        EA(I1X_I0_I1X)
        EA(I1X_I0_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_I1_L)
        EA(I1X_I1_I0)
        EA(I1X_I1_I1)
        EA(I1X_I1_I0X)
        EA(I1X_I1_I1X)
        EA(I1X_I1_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_I0X_L)
        EA(I1X_I0X_I0)
        EA(I1X_I0X_I1)
        EA(I1X_I0X_I0X)
        EA(I1X_I0X_I1X)
        EA(I1X_I0X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_I1X_L)
        EA(I1X_I1X_I0)
        EA(I1X_I1X_I1)
        EA(I1X_I1X_I0X)
        EA(I1X_I1X_I1X)
        EA(I1X_I1X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // i1[local], local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(I1X_R_L)
        EA(I1X_R_I0)
        EA(I1X_R_I1)
        EA(I1X_R_I0X)
        EA(I1X_R_I1X)
        EA(I1X_R_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], local -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(R_L_L)
        EA(R_L_I0)
        EA(R_L_I1)
        EA(R_L_I0X)
        EA(R_L_I1X)
        EA(R_L_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], i0[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(R_I0_L)
        EA(R_I0_I0)
        EA(R_I0_I1)
        EA(R_I0_I0X)
        EA(R_I0_I1X)
        EA(R_I0_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], i1[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(R_I1_L)
        EA(R_I1_I0)
        EA(R_I1_I1)
        EA(R_I1_I0X)
        EA(R_I1_I1X)
        EA(R_I1_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], i0[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(R_I0X_L)
        EA(R_I0X_I0)
        EA(R_I0X_I1)
        EA(R_I0X_I0X)
        EA(R_I0X_I1X)
        EA(R_I0X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], i1[local] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        EA(R_I1X_L)
        EA(R_I1X_I0)
        EA(R_I1X_I1)
        EA(R_I1X_I0X)
        EA(R_I1X_I1X)
        EA(R_I1X_R)

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        // local[const uint8], local[const uint8] -> X
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
