/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

namespace ExtendedAddress {
    // L   : Local stack frame (1 byte for stack frame location)
    // In  : Indirection[n] fixed offset (1 byte for offset value)
    // InX : Indirection[n] local offset (1 byte for stack frame location to offset)
    // R   : Local stack frame reference (1 bytes for stack location, 1 more for fixed offset)
    enum {

        // Three operand distinct, 5 byte

        // [Opcode] [Address] [Operand 0] [Operand 1] [Operand 2]

        //_L_L_L,     // Covered by _LLL
        //_L_L_I0,    // Covered by _LLI
        _L_L_I1,
        _L_L_I0X,
        _L_L_I1X,
        _L_L_R,

        //_L_I0_L,    // Covered by _LIL
        _L_I0_I0,
        //_L_I0_I1,   // Covered by _LII
        _L_I0_I0X,
        _L_I0_I1X,
        _L_I0_R,

        _L_I1_L,
        _L_I1_I0,
        _L_I1_I1,
        _L_I1_I0X,
        _L_I1_I1X,
        _L_I1_R,

        _L_I0X_L,
        _L_I0X_I0,
        _L_I0X_I1,
        _L_I0X_I0X,
        _L_I0X_I1X,
        _L_I0X_R,

        _L_I1X_L,
        _L_I1X_I0,
        _L_I1X_I1,
        _L_I1X_I0X,
        _L_I1X_I1X,
        _L_I1X_R,

        _L_R_L,
        _L_R_I0,
        _L_R_I1,
        _L_R_I0X,
        _L_R_I1X,
        _L_R_R,

        //_I0_L_L,    // Covered by _ILL
        _I0_L_I0,
        //_I0_L_I1,   // Covered by _ILI
        _I0_L_I0X,
        _I0_L_I1X,
        _I0_L_R,

        _I0_I0_L,
        _I0_I0_I0,
        _I0_I0_I1,
        _I0_I0_I0X,
        _I0_I0_I1X,
        _I0_I0_R,

        //_I0_I1_L,   // Covered by _IIL
        _I0_I1_I0,
        _I0_I1_I1,
        _I0_I1_I0X,
        _I0_I1_I1X,
        _I0_I1_R,

        _I0_I0X_L,
        _I0_I0X_I0,
        _I0_I0X_I1,
        _I0_I0X_I0X,
        _I0_I0X_I1X,
        _I0_I0X_R,

        _I0_I1X_L,
        _I0_I1X_I0,
        _I0_I1X_I1,
        _I0_I1X_I0X,
        _I0_I1X_I1X,
        _I0_I1X_R,

        _I0_R_L,
        _I0_R_I0,
        _I0_R_I1,
        _I0_R_I0X,
        _I0_R_I1X,
        _I0_R_R,

        _I1_L_L,
        _I1_L_I0,
        _I1_L_I1,
        _I1_L_I0X,
        _I1_L_I1X,
        _I1_L_R,

        _I1_I0_L,
        _I1_I0_I0,
        _I1_I0_I1,
        _I1_I0_I0X,
        _I1_I0_I1X,
        _I1_I0_R,

        _I1_I1_L,
        _I1_I1_I0,
        _I1_I1_I1,
        _I1_I1_I0X,
        _I1_I1_I1X,
        _I1_I1_R,

        _I1_I0X_L,
        _I1_I0X_I0,
        _I1_I0X_I1,
        _I1_I0X_I0X,
        _I1_I0X_I1X,
        _I1_I0X_R,

        _I1_I1X_L,
        _I1_I1X_I0,
        _I1_I1X_I1,
        _I1_I1X_I0X,
        _I1_I1X_I1X,
        _I1_I1X_R,

        _I1_R_L,
        _I1_R_I0,
        _I1_R_I1,
        _I1_R_I0X,
        _I1_R_I1X,
        _I1_R_R,

        _I0X_L_L,
        _I0X_L_I0,
        _I0X_L_I1,
        _I0X_L_I0X,
        _I0X_L_I1X,
        _I0X_L_R,

        _I0X_I0_L,
        _I0X_I0_I0,
        _I0X_I0_I1,
        _I0X_I0_I0X,
        _I0X_I0_I1X,
        _I0X_I0_R,

        _I0X_I1_L,
        _I0X_I1_I0,
        _I0X_I1_I1,
        _I0X_I1_I0X,
        _I0X_I1_I1X,
        _I0X_I1_R,

        _I0X_I0X_L,
        _I0X_I0X_I0,
        _I0X_I0X_I1,
        _I0X_I0X_I0X,
        _I0X_I0X_I1X,
        _I0X_I0X_R,

        _I0X_I1X_L,
        _I0X_I1X_I0,
        _I0X_I1X_I1,
        _I0X_I1X_I0X,
        _I0X_I1X_I1X,
        _I0X_I1X_R,

        _I0X_R_L,
        _I0X_R_I0,
        _I0X_R_I1,
        _I0X_R_I0X,
        _I0X_R_I1X,
        _I0X_R_R,

        _I1X_L_L,
        _I1X_L_I0,
        _I1X_L_I1,
        _I1X_L_I0X,
        _I1X_L_I1X,
        _I1X_L_R,

        _I1X_I0_L,
        _I1X_I0_I0,
        _I1X_I0_I1,
        _I1X_I0_I0X,
        _I1X_I0_I1X,
        _I1X_I0_R,

        _I1X_I1_L,
        _I1X_I1_I0,
        _I1X_I1_I1,
        _I1X_I1_I0X,
        _I1X_I1_I1X,
        _I1X_I1_R,

        _I1X_I0X_L,
        _I1X_I0X_I0,
        _I1X_I0X_I1,
        _I1X_I0X_I0X,
        _I1X_I0X_I1X,
        _I1X_I0X_R,

        _I1X_I1X_L,
        _I1X_I1X_I0,
        _I1X_I1X_I1,
        _I1X_I1X_I0X,
        _I1X_I1X_I1X,
        _I1X_I1X_R,

        _I1X_R_L,
        _I1X_R_I0,
        _I1X_R_I1,
        _I1X_R_I0X,
        _I1X_R_I1X,
        _I1X_R_R,

        _R_L_L,
        _R_L_I0,
        _R_L_I1,
        _R_L_I0X,
        _R_L_I1X,
        _R_L_R,

        _R_I0_L,
        _R_I0_I0,
        _R_I0_I1,
        _R_I0_I0X,
        _R_I0_I1X,
        _R_I0_R,

        _R_I1_L,
        _R_I1_I0,
        _R_I1_I1,
        _R_I1_I0X,
        _R_I1_I1X,
        _R_I1_R,

        _R_I0X_L,
        _R_I0X_I0,
        _R_I0X_I1,
        _R_I0X_I0X,
        _R_I0X_I1X,
        _R_I0X_R,

        _R_I1X_L,
        _R_I1X_I0,
        _R_I1X_I1,
        _R_I1X_I0X,
        _R_I1X_I1X,
        _R_I1X_R,

        _R_R_L,
        _R_R_I0,
        _R_R_I1,
        _R_R_I0X,
        _R_R_I1X,
        _R_R_R,

        _MAX
    };
};

