/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_OPCODE_HPP_
    #define _GVM_OPCODE_HPP_

namespace GVM {
    namespace Opcode {
        enum {
            // Untyped instructions ////////////////////////////////////////////////////////////////////////////////////

            _HCF = 0, // Halt and catch fire
            _BRA,     // Branch to a signed 16-bit offset
            _BCALL,   // Call an anonymous local function
            _CALL,    // Call a named function by ID
            _ICALL_L, // Call a named function by ID stored in local refrence
            _ICALL_I, // Call a named function by ID stored in an indirect reference
            _HCALL,   // Call a host function
            _RET,     // Return from the current function

            _LI0BNN,    // Load indirect to indirection[0] register and branch if not null
            _LI1BNN,    // Load indirect to indirection[1] register and branch if not null

            // Scalar instructions (float or integer) //////////////////////////////////////////////////////////////////

            _BEZ_L,    // Branch to a signed 16-bit offset if local is equal to zero
            _BEZ_I0,    // Branch to a signed 16-bit offset if indirect is equal to zero
            _BEZ_I1,
            _BNZ_L,    // Branch to a signed 16-bit offset if local is not equal to zero
            _BNZ_I0,    // Branch to a signed 16-bit offset if indirect is not equal to zero
            _BNZ_I1,
            _BEQ_LL,   // Branch to a signed 16-bit offset if two local values are equal
            _BEQ_LI,   // Branch to a signed 16-bit offset if local and indirect values are equal
            _BEQ_II,   // Branch to a signed 16-bit offset if two indirect values are equal
            _BNE_LL,   // Branch to a signed 16-bit offset if two local values are not equal
            _BNE_LI,   // Branch to a signed 16-bit offset if local and indirect values are not equal
            _BNE_II,   // Branch to a signed 16-bit offset if two indirect values are not equal

            _ADDR_LL,  // Get address of local variable into local variable
            _ADDR_I0L, // Get the address of an indirect[0] variable into local variable
            _ADDR_I1L, // Get the address of an indirect[1] variable into a local variable

            _ADDR_DL, // Load the address of a global data symbol to a local variable
            _ADDR_DI0, // Load the address of a global data symbol to an indirect[0] variable
            _ADDR_DI1, // Load the address of a global data symbol to an indirect[1] variable

            _ADDR_D0, // Load the address of a global data synbol directly into indirect[0]
            _ADDR_D1, // Load the address of a global data synbol directly into indirect[1]

            _ADDR_CL, // Load code synbol to local variable
            _ADDR_CI0, // Load code symbol to an indirect[0] variable
            _ADDR_CI1, // Load code symbol to an indirect[1] variable

            _ADDA_SI0,  // Add small integer to indirect[0]
            _ADDA_SI1,  // Add small integer to indirect[1]

            _LOAD_L0, // Load local reference directly into indirect[0]
            _LOAD_L1, // Load local reference directly into indirect[1]

            _SAVE_0L, // Save indirect[0] to local reference
            _SAVE_1L, // Save indirect[1] to local reference


            _LOAD_HL,  // Load host lookup to local

            _COPY_LL,  // Copy a local scalar to a local scalar
            _COPY_I0L,  // Copy an indirect[0] scalar to a local
            _COPY_I1L,  // Copy an indirect[1] scalar to a local

            _CPIX_I0L,
            _CPIX_I1L,

            _COPY_LI0,  // Copy a local scalar to indirect[0] variable
            _COPY_LI1,  // Copy a local scalar to indirect[1] variable
            _COPY_II,  // Copy an indirect scalar to another indirect

            _ITOF_LL,  // Cast float to integer
            _FTOI_LL,  // Cast integer to float

            // Integer specific instructions ///////////////////////////////////////////////////////////////////////////

            // Two operand branch if greater or equal
            _BGE_LL,
            _BGE_IL,
            _BGE_LI,
            _BGE_II,

            // Two operand branch if less than or equal
            _BLE_II,

            // Two operand branch if greater than
            _BGT_LL,
            _BGT_IL,
            _BGT_LI,
            _BGT_II,

            // Two operand branch if less than
            _BLT_II,

            _DBNZ_L,   // Decrement local and branch if not zero
            _DBNN_L,   // Decrement local and branch if not negative

            // Load small literal integer
            _LOAD_SL,
            _LOAD_SI0,
            _LOAD_SI1,

            // Single bit operations
            _BSET_SL, // Set bit in local
            _BSET_SI, // Set bit in indirect
            _BCLR_SL, // Clear bit in local
            _BCLR_SI, // Clear bit in indirect
            _BBS_SL,  // Branch if bit is set (fixed in local)
            _BBS_SI,  // Branch if bit is set (indirect)
            _BBC_SL,  // Branch if bit is clear (local)
            _BBC_SI,  // Branch if bit is clear (indirect)

            _BBC_LL,  // Branch if bit clear (local, local)

            // Two operand logical negate
            _NOT_LL,
            _NOT_IL,
            _NOT_LI,
            _NOT_II,

            // Two operand integer negate
            _NEG_LL,
            _NEG_IL,
            _NEG_LI,
            _NEG_II,

            // Three operand integer addition: Commutative, 4 unique variants
            _ADD_LLL,
            _ADD_ILL,
            _ADD_LLI,
            _ADD_ILI,

            // Three operand integer subtraction: Noncommutative, 7 unique variants
            _SUB_LLL,
            _SUB_ILL,
            _SUB_LLI,
            _SUB_ILI,
            _SUB_LIL,
            _SUB_IIL,
            _SUB_LII,

            // Three operand integer multiplication: Commutative, 4 unique variants
            _MUL_LLL,
            _MUL_ILL,
            _MUL_LLI,
            _MUL_ILI,

            // Three operand integer division: Noncommutative, 7 unique variants
            _DIV_LLL,
            _DIV_ILL,
            _DIV_LLI,
            _DIV_ILI,
            _DIV_LIL,
            _DIV_IIL,
            _DIV_LII,

            // Three operand integer modulo: Noncommutative, 7 unique variants
            _MOD_LLL,
            _MOD_ILL,
            _MOD_LLI,
            _MOD_ILI,
            _MOD_LIL,
            _MOD_IIL,
            _MOD_LII,

            // Three operand logical AND: Commutative, 4 unique variants
            _AND_LLL,
            _AND_ILL,
            _AND_LLI,
            _AND_ILI,

            // Three operand logical OR: Commutative, 4 unique variants
            _OR_LLL,
            _OR_ILL,
            _OR_LLI,
            _OR_ILI,

            // Three operand logical XOR: Commutative, 4 unique variants
            _XOR_LLL,
            _XOR_ILL,
            _XOR_LLI,
            _XOR_ILI,

            // Three operand logical shift left: Noncommutative, 4 supported variants
            _LSL_LLL,
            _LSL_ILL,
            _LSL_LLI,
            _LSL_ILI,

            // Three operand logical shift right: Noncommutative, 4 supported variants
            _LSR_LLL,
            _LSR_ILL,
            _LSR_LLI,
            _LSR_ILI,

            // Integer Maximum: Commutative, 4 unique variants
            _MAX_LLL,
            _MAX_ILL,
            _MAX_LLI,
            _MAX_ILI,

            // Integer Minumum: Commutative, 4 unique variants
            _MIN_LLL,
            _MIN_ILL,
            _MIN_LLI,
            _MIN_ILI,

            // Floating point specific instructions ////////////////////////////////////////////////////////////////////

            // Single operand get a random value between 0.0f and 1.0f
            _FRND_L,

            // Two operand branch if greater or equal
            _FBGE_LL,
            _FBGE_IL,
            _FBGE_LI,
            _FBGE_II,

            // Two operand branch if less than or equal
            _FBLE_II,

            // Two operand branch if greater than
            _FBGT_LL,
            _FBGT_IL,
            _FBGT_LI,
            _FBGT_II,

            // Two operand branch if less than
            _FBLT_II,

            // Two operand, local to local handy maths functions
            _FINV_LL,   // Reciprocal
            _FSQRT_LL,  // Square root
            _INVSQ_LL,  // Inverse square
            _FSIN_LL,   // Sine
            _FCOS_LL,   // Cosine
            _FACOS_LL,  // Arccosine
            _FCEIL_LL,  // Ceiling
            _FFLOOR_LL, // Floor

            // Two operand float negate
            _FNEG_LL,
            _FNEG_IL,
            _FNEG_LI,
            _FNEG_II,

            // Three operand float addition: Commutative, 4 unique variants
            _FADD_LLL,
            _FADD_ILL,
            _FADD_LLI,
            _FADD_ILI,

            // Three operand float subtraction: Noncommutative, 7 unique variants
            _FSUB_LLL,
            _FSUB_ILL,
            _FSUB_LLI,
            _FSUB_ILI,
            _FSUB_LIL,
            _FSUB_IIL,
            _FSUB_LII,

            // Three operand float multiplication: Commutative, 4 unique variants
            _FMUL_LLL,
            _FMUL_ILL,
            _FMUL_LLI,
            _FMUL_ILI,

            // Three operand float division: Noncommutative, 7 unique variants
            _FDIV_LLL,
            _FDIV_ILL,
            _FDIV_LLI,
            _FDIV_ILI,
            _FDIV_LIL,
            _FDIV_IIL,
            _FDIV_LII,

            // Three operand float modulo: Noncommutative, 7 unique variants
            _FMOD_LLL,
            _FMOD_ILL,
            _FMOD_LLI,
            _FMOD_ILI,
            _FMOD_LIL,
            _FMOD_IIL,
            _FMOD_LII,

            // Floating Point Maximum: Commutative, 4 unique variants
            _FMAX_LLL,
            _FMAX_ILL,
            _FMAX_LLI,
            _FMAX_ILI,

            // Floating Point Minimum: Commutative, 4 unique variants
            _FMIN_LLL,
            _FMIN_ILL,
            _FMIN_LLI,
            _FMIN_ILI,

            _FPOW_LLL,   // Power

            // Vector specific instructions ////////////////////////////////////////////////////////////////////////////

            // Single operandector random - produce a normalised vector with random orientation
            _VRND_L,

            // Vector branch if equal
            _VBEQ_LL,
            _VBEQ_IL,
            _VBEQ_II,

            // Vector branch if not equal
            _VBNE_LL,
            _VBNE_IL,
            _VBNE_II,

            // Two operand Vector instructions
            _VCOPY_LL,
            _VCOPY_IL,
            _VCOPY_LI,
            _VCOPY_II,

            // Vector negate
            _VNEG_LL,
            _VNEG_IL,
            _VNEG_LI,
            _VNEG_II,

            // Vector normalize
            _VNORM_LL,
            _VNORM_IL,
            _VNORM_LI,
            _VNORM_II,

            // Vector magnitude (scalar result)
            _VMAG_LL,
            _VMAG_IL,
            _VMAG_LI,
            _VMAG_II,

            // Three operand vector instructions

            // Vector addition: Commutative, 4 unique variants
            _VADD_LLL,
            _VADD_ILL,
            _VADD_LLI,
            _VADD_ILI,

            // Vector subtraction: Noncommutative, 7 unique variants
            _VSUB_LLL,
            _VSUB_ILL,
            _VSUB_LLI,
            _VSUB_ILI,
            _VSUB_LIL,
            _VSUB_IIL,
            _VSUB_LII,

            // Dot product (scalar result): Commutative, 4 unique variants
            _VDOT_LLL,
            _VDOT_ILL,
            _VDOT_LLI,
            _VDOT_ILI,

            // Cross product (vector result): Noncommutative, 7 unique variants
            _VCROSS_LLL,
            _VCROSS_ILL,
            _VCROSS_LLI,
            _VCROSS_ILI,
            _VCROSS_LIL,
            _VCROSS_IIL,
            _VCROSS_LII,

            // Vector multiply by float: Commutative, 7 variants due to different input operand types
            _VFMUL_LLL,
            _VFMUL_ILL,
            _VFMUL_LLI,
            _VFMUL_ILI,
            _VFMUL_LIL,
            _VFMUL_IIL,
            _VFMUL_LII,

            // Branch On condition (See Condition below)
            _BOC,

            _MAX
        };
    };
    namespace Condition {
        enum {
            // Bitwise equal (exact)
            _X_EQ_LS,               // Local === Small Integer Literal
            _X_EQ_I0S,              // Indirect[0] === Small Integer Literal
            _X_EQ_I1S,              // Indirect[1] === Small Integer Literal
            _X_EQ_LL,               // Local == Local
            _X_EQ_LI0,              // Local == Indirect[0]
            _X_EQ_LI1,              // Local == Indirect[1]
            _X_EQ_II,               // Indirect[0] == Indirect[1]

            // Bitwise not equal (exact)
            _X_NE_LS,               // Local !== Small Integer Literal
            _X_NE_I0S,              // Indirect[0] !== Small Integer Literal
            _X_NE_I1S,              // Indirect[1] !== Small Integer Literal
            _X_NE_LL,               // Local !== Local
            _X_NE_LI0,              // Local !== Indirect[0]
            _X_NE_LI1,              // Local !== Indirect[1]
            _X_NE_II,               // Indirect[0] !== Indirect[1]

            // Integer less than
            _I_LT_LS,               // Local < Small Integer Literal
            _I_LT_I0S,              // Indirect[0] < Small Integer Literal
            _I_LT_I1S,              // Indirect[1] < Small Integer Literal
            _I_LT_LL,               // Local < Local
            _I_LT_LI0,              // Local < Indirect[0]
            _I_LT_LI1,              // Local < Indirect[1]
            _I_LT_II,               // Indirect[0] < Indirect[1]

            // Integer less than or equal
            _I_LE_LS,               // Local <= Small Integer Literal
            _I_LE_I0S,              // Indirect[0] <= Small Integer Literal
            _I_LE_I1S,              // Indirect[1] <= Small Integer Literal
            _I_LE_LL,               // Local <= Local
            _I_LE_LI0,              // Local <= Indirect[0]
            _I_LE_LI1,              // Local <= Indirect[1]
            _I_LE_II,               // Indirect[0] <= Indirect[1]

            // Integer greater than or equal
            _I_GE_LS,               // Local >= Small Integer Literal
            _I_GE_I0S,              // Indirect[0] >= Small Integer Literal
            _I_GE_I1S,              // Indirect[1] >= Small Integer Literal
            _I_GE_LL,               // Local >= Local
            _I_GE_LI0,              // Local >= Indirect[0]
            _I_GE_LI1,              // Local >= Indirect[1]
            _I_GE_II,               // Indirect[0] >= Indirect[1]

            // Integer greater than
            _I_GT_LS,               // Local > Small Integer Literal
            _I_GT_I0S,              // Indirect[0] > Small Integer Literal
            _I_GT_I1S,              // Indirect[1] > Small Integer Literal
            _I_GT_LL,               // Local > Local
            _I_GT_LI0,              // Local > Indirect[0]
            _I_GT_LI1,              // Local > Indirect[1]
            _I_GT_II,               // Indirect[0] > Indirect[1]

            // Bit is set
            _X_BS_SL,               // Literal bit is set in local
            _X_BS_SI0,              // Literal bit is set in Indirect[0]
            _X_BS_SI1,              // Literal bit is set in Indirect[1]
            _X_BS_LL,               // Local bit is set in local
            _X_BS_LI0,              // Local bit is set in Indirect[0]
            _X_BS_LI1,              // Local bit is set in Indirect[1]

            // Bit is clear
            _X_BC_SL,               // Literal bit is clear in local
            _X_BC_SI0,              // Literal bit is clear in Indirect[0]
            _X_BC_SI1,              // Literal bit is clear in Indirect[1]
            _X_BC_LL,               // Local bit is clear in local
            _X_BC_LI0,              // Local bit is clear in Indirect[0]
            _X_BC_LI1,              // Local bit is clear in Indirect[1]

            // Float less than
            _F_LT_LL,               // Local < Local
            _F_LT_LI0,              // Local < Indirect[0]
            _F_LT_LI1,              // Local < Indirect[1]
            _F_LT_II,               // Indirect[0] < Indirect[1]

            // Float less than or equal
            _F_LE_LL,               // Local <= Local
            _F_LE_LI0,              // Local <= Indirect[0]
            _F_LE_LI1,              // Local <= Indirect[1]
            _F_LE_II,               // Indirect[0] <= Indirect[1]

            // Float greater than or equal
            _F_GE_LL,               // Local >= Local
            _F_GE_LI0,              // Local >= Indirect[0]
            _F_GE_LI1,              // Local >= Indirect[1]
            _F_GE_II,               // Indirect[0] >= Indirect[1]

            // Float greater than
            _F_GT_LL,               // Local > Local
            _F_GT_LI0,              // Local > Indirect[0]
            _F_GT_LI1,              // Local > Indirect[1]
            _F_GT_II,               // Indirect[0] > Indirect[1]

            // Float approximately equal (within epsilon)
            _F_AE_LL,               // Local ~= Local
            _F_AE_LI0,              // Local ~= Indirect[0]
            _F_AE_LI1,              // Local ~= Indirect[1]
            _F_AE_II,               // Indirect[0] ~= Indirect[1]

            // Vector identical (exact comparison)
            _V_EQ_LL,               // Local == Local
            _V_EQ_LI0,              // Local == Indirect[0]
            _V_EQ_LI1,              // Local == Indirect[1]
            _V_EQ_II,               // Indirect[0] == Indirect[1]

            // Vector approximately equal (each component within epsilon)
            _V_AE_LL,               // Local ~= Local
            _V_AE_LI0,              // Local ~= Indirect[0]
            _V_AE_LI1,              // Local ~= Indirect[1]
            _V_AE_II,               // Indirect[0] ~= Indirect[1]

            // Vector not equal
            _V_NE_LL,               // Local == Local
            _V_NE_LI0,              // Local == Indirect[0]
            _V_NE_LI1,              // Local == Indirect[1]
            _V_NE_II,               // Indirect[0] == Indirect[1]
            _MAX
        };
    };
};

#endif
