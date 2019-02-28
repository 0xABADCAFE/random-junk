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
            _BRAS,    // Branch to a signed 8-bit offset
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

            _BEZ,
            _BNZ,
            _BEQ,
            _BNE,
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
            _BGE,

            // Two operand branch if greater than
            _BGT,

            _DBNZ,   // Decrement local and branch if not zero
            _DBNN,   // Decrement local and branch if not negative

            // Load small literal integer
            _LOAD_SL,
            _LOAD_SI0,
            _LOAD_SI1,

            // Single bit operations
            _BSET, // Set bit in indirect
            _BCLR, // Clear bit in indirect
            _BBS,  // Branch if bit is set (indirect)
            _BBC,  // Branch if bit is clear (indirect)

            _BBC_LL,  // Branch if bit clear (local, local)

            // Two operand logical negate
            _NOT,

            // Two operand integer negate
            _NEG,

            // Three operand integer addition: Commutative, 4 unique variants
            _ADD,

            // Three operand integer subtraction: Noncommutative, 7 unique variants
            _SUB,

            // Three operand integer multiplication: Commutative, 4 unique variants
            _MUL,

            // Three operand integer division: Noncommutative, 7 unique variants
            _DIV,

            // Three operand integer modulo: Noncommutative, 7 unique variants
            _MOD,

            // Three operand logical AND: Commutative, 4 unique variants
            _AND,

            // Three operand logical OR: Commutative, 4 unique variants
            _OR,

            // Three operand logical XOR: Commutative, 4 unique variants
            _XOR,

            // Three operand logical shift left: Noncommutative, 4 supported variants
            _LSL,

            // Three operand logical shift right: Noncommutative, 4 supported variants
            _LSR,

            // Integer Maximum: Commutative, 4 unique variants
            _MAX,

            // Integer Minumum: Commutative, 4 unique variants
            _MIN,

            // Floating point specific instructions ////////////////////////////////////////////////////////////////////

            // Single operand get a random value between 0.0f and 1.0f
            _FRND,

            // Two operand branch if greater or equal
            _FBGE,

            // Two operand branch if greater than
            _FBGT,

            // Two operand, local to local handy maths functions
            _FINV,   // Reciprocal
            _FSQRT,  // Square root
            _INVSQR,  // Inverse square
            _FSIN,   // Sine
            _FCOS,   // Cosine
            _FACOS,  // Arccosine
            _FCEIL,  // Ceiling
            _FFLOOR, // Floor

            // Two operand float negate
            _FNEG,

            // Three operand float addition: Commutative, 4 unique variants
            _FADD,

            // Three operand float subtraction: Noncommutative, 7 unique variants
            _FSUB,

            // Three operand float multiplication: Commutative, 4 unique variants
            _FMUL,

            // Three operand float division: Noncommutative, 7 unique variants
            _FDIV,

            // Three operand float modulo: Noncommutative, 7 unique variants
            _FMOD,

            // Floating Point Maximum: Commutative, 4 unique variants
            _FMAX,

            // Floating Point Minimum: Commutative, 4 unique variants
            _FMIN,

            _FPOW,   // Power

            // Vector specific instructions ////////////////////////////////////////////////////////////////////////////

            // Single operandector random - produce a normalised vector with random orientation
            _VRND,

            // Vector branch if equal
            _VBEQ,

            // Vector branch if not equal
            _VBNE,

            // Two operand Vector instructions
            _VCOPY,

            // Vector negate
            _VNEG,

            // Vector normalize
            _VNORM,

            // Vector magnitude (scalar result)
            _VMAG,

            // Three operand vector instructions

            // Vector addition: Commutative, 4 unique variants
            _VADD,

            // Vector subtraction: Noncommutative, 7 unique variants
            _VSUB,

            // Dot product (scalar result): Commutative, 4 unique variants
            _VDOT,

            // Cross product (vector result): Noncommutative, 7 unique variants
            _VCROSS,

            // Vector multiply by float: Commutative, 7 variants due to different input operand types
            _VFMUL,

            _MAX_OPCODE
        };
    };
};

#endif
