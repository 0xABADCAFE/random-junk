/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

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

