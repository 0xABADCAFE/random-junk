#ifndef _GVM_BRANCH_MACROS_
#define _GVM_BRANCH_MACROS_

#ifdef _GVM_OPT_BCC_16_BIT_
    #define _DJ(j) _D16(j)
    #define BOC_SIZE 6
#else
    #define _DJ(j) _D8(j)
    #define BOC_SIZE 5
#endif

#define _CC(x)  _OP(BOC), (uint8)Condition::_##x

// Untyped branch if all bits equal ////////////////////////////////////////////////////////////////////////////////////
#define beq_ls(l, s, j)    _CC(X_EQ_LS),      _D8(l),  _D8(s),  _DJ(j),
#define beq_is(I, i, s, j) _CC(X_EQ_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define beq_ll(l1, l2, j)  _CC(X_EQ_LL),      _D8(l1), _D8(l2), _DJ(j),
#define beq_li(l, I, i, j) _CC(X_EQ_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define beq_ii(i1, i2, j)  _CC(X_EQ_II),      _D8(i1), _D8(i2), _DJ(j),



// Untyped continue if all bits equak (alias) //////////////////////////////////////////////////////////////////////////
#define ceq_ls(l, s, j)    _CC(X_NE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define ceq_is(I, i, s, j) _CC(X_NE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define ceq_ll(l1, l2, j)  _CC(X_NE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define ceq_li(l, I, i, j) _CC(X_NE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define ceq_ii(i1, i2, j)  _CC(X_NE_II),      _D8(i1), _D8(i2), _DJ(j),


// Untyped branch if any bits not equal ////////////////////////////////////////////////////////////////////////////////
#define bne_ls(l, s, j)    _CC(X_NE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define bne_is(I, i, s, j) _CC(X_NE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define bne_ll(l1, l2, j)  _CC(X_NE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define bne_li(l, I, i, j) _CC(X_NE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define bne_ii(i1, i2, j)  _CC(X_NE_II),      _D8(i1), _D8(i2), _DJ(j),

// Untyped continue if any bits not equal (alias) //////////////////////////////////////////////////////////////////////
#define cne_ls(l, s, j)    _CC(X_EQ_LS),      _D8(l),  _D8(s),  _DJ(j),
#define cne_is(I, i, s, j) _CC(X_EQ_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define cne_ll(l1, l2, j)  _CC(X_EQ_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cne_li(l, I, i, j) _CC(X_EQ_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define cne_ii(i1, i2, j)  _CC(X_EQ_II),      _D8(i1), _D8(i2), _DJ(j),


// Integer branch if less than /////////////////////////////////////////////////////////////////////////////////////////
#define blt_ls(l, s, j)    _CC(I_LT_LS),      _D8(l),  _D8(s),  _DJ(j),
#define blt_is(I, i, s, j) _CC(I_LT_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define blt_ll(l1, l2, j)  _CC(I_LT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define blt_li(l, I, i, j) _CC(I_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define blt_ii(i1, i2, j)  _CC(I_LT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped
#define blt_il(I, i, l, j) _CC(I_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer continue if less than (alias) ///////////////////////////////////////////////////////////////////////////////
#define clt_ls(l, s, j)    _CC(I_GE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define clt_is(I, i, s, j) _CC(I_GE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define clt_ll(l1, l2, j)  _CC(I_GE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define clt_li(l, I, i, j) _CC(I_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define clt_ii(i1, i2, j)  _CC(I_GE_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swqpped and aliased
#define clt_il(I, i, l, j) _CC(I_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer branch if less than or equal ////////////////////////////////////////////////////////////////////////////////
#define ble_ls(l, s, j)    _CC(I_LE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define ble_is(I, i, s, j) _CC(I_LE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define ble_ll(l1, l2, j)  _CC(I_LE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define ble_li(l, I, i, j) _CC(I_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define ble_ii(i1, i2, j)  _CC(I_LE_II),      _D8(i1), _D8(i2), _DJ(j),

// Opperand swapped
#define ble_il(I, i, l, j) _CC(I_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer continue if less than or equal (alias) //////////////////////////////////////////////////////////////////////
#define cle_ls(l, s, j)    _CC(I_GT_LS),      _D8(l),  _D8(s),  _DJ(j),
#define cle_is(I, i, s, j) _CC(I_GT_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define cle_ll(l1, l2, j)  _CC(I_GT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cle_li(l, I, i, j) _CC(I_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define cle_ii(i1, i2, j)  _CC(I_GT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped and aliased
#define cle_il (I, i, l, j) _CC(I_LE_LI##I),   _D8(l),  _D8(i), _DJ(j),

// Integer branch if greater than or equal /////////////////////////////////////////////////////////////////////////////
#define bge_ls(l, s, j)    _CC(I_GE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define bge_is(I, i, s, j) _CC(I_GE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define bge_ll(l1, l2, j)  _CC(I_GE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define bge_li(l, I, i, j) _CC(I_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define bge_ii(i1, i2, j)  _CC(I_GE_II),      _D8(i1), _D8(i2), _DJ(j),

#define bge_il(I, i, l, j) _CC(I_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer continue if greater than or equal (alias) ///////////////////////////////////////////////////////////////////
#define cge_ls(l, s, j)    _CC(I_LT_LS),      _D8(l),  _D8(s),  _DJ(j),
#define cge_is(I, i, s, j) _CC(I_LT_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define cge_ll(l1, l2, j)  _CC(I_LT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cge_li(l, I, i, j) _CC(I_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define cge_ii(i1, i2, j)  _CC(I_LT_II),     _D8(i1), _D8(i2),  _DJ(j),

// Operand swapped and aliased
#define cge_il(I, i, l, j) _CC(I_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer branch if greater than //////////////////////////////////////////////////////////////////////////////////////
#define bgt_ls(l, s, j)    _CC(I_GT_LS),      _D8(l),  _D8(s),  _DJ(j),
#define bgt_is(I, i, s, j) _CC(I_GT_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define bgt_ll(l1, l2, j)  _CC(I_GT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define bgt_li(l, I, i, j) _CC(I_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define bgt_ii(i1, i2, j)  _CC(I_GT_II),     _D8(i1), _D8(i2),  _DJ(j),

// Operand swapped
#define bgt_il(I, i, l, j) _CC(I_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Integer continue if greater than (alias) ////////////////////////////////////////////////////////////////////////////
#define cgt_ls(l, s, j)    _CC(I_LE_LS),      _D8(l),  _D8(s),  _DJ(j),
#define cgt_is(I, i, s, j) _CC(I_LE_I##I##S), _D8(i),  _D8(s),  _DJ(j),
#define cgt_ll(l1, l2, j)  _CC(I_LE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cgt_li(l, I, i, j) _CC(I_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define cgt_ii(i1, i2, j)  _CC(I_LE_II),     _D8(i1), _D8(i2),  _DJ(j),

// Operand swapped and aliased
#define cgt_il(I, i, l, j) _CC(I_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Untyped branch if bit is set ////////////////////////////////////////////////////////////////////////////////////////
#define bbs_sl(s, l, j)    _CC(X_BS_SL),      _D8(s),  _D8(l),  _DJ(j),
#define bbs_si(s, I, i, j) _CC(X_BS_SI##I),   _D8(s),  _D8(i),  _DJ(j),
#define bbs_ll(l1, l2, j)  _CC(X_BS_LL),      _D8(l1), _D8(l2), _DJ(j),
#define bbs_li(l, I, i, j) _CC(X_BS_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Untyped continue if bit is set (alias) //////////////////////////////////////////////////////////////////////////////
#define cbs_sl(s, l, j)    _CC(X_BC_SL),      _D8(s),  _D8(l),  _DJ(j),
#define cbs_si(s, I, i, j) _CC(X_BC_SI##I),   _D8(s),  _D8(i),  _DJ(j),
#define cbs_ll(l1, l2, j)  _CC(X_BC_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cbs_li(l, I, i, j) _CC(X_BC_LI##I),   _D8(l),  _D8(i),  _DJ(j),


// Untyped branch if bit is clear //////////////////////////////////////////////////////////////////////////////////////
#define bbc_sl(s, l, j)    _CC(X_BC_SL),      _D8(s),  _D8(l),  _DJ(j),
#define bbc_si(s, I, i, j) _CC(X_BC_SI##I),   _D8(s),  _D8(i),  _DJ(j),
#define bbc_ll(l1, l2, j)  _CC(X_BC_LL),      _D8(l1), _D8(l2), _DJ(j),
#define bbc_li(l, I, i, j) _CC(X_BC_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Untyped continue if bit is clear (alias) ////////////////////////////////////////////////////////////////////////////
#define cbc_sl(s, l, j)    _CC(X_BS_SL),      _D8(s),  _D8(l),  _DJ(j),
#define cbc_si(s, I, i, j) _CC(X_BS_SI##I),   _D8(s),  _D8(i),  _DJ(j),
#define cbc_ll(l1, l2, j)  _CC(X_BS_LL),      _D8(l1), _D8(l2), _DJ(j),
#define cbc_li(l, I, i, j) _CC(X_BS_LI##I),   _D8(l),  _D8(i),  _DJ(j),


// Float branch if less than ///////////////////////////////////////////////////////////////////////////////////////////
#define fblt_ll(l1, l2, j)  _CC(F_LT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fblt_li(l, I, i, j) _CC(F_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fblt_ii(i1, i2, j)  _CC(F_LT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped
#define fblt_il(I, i, l, j) _CC(F_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float continue if less than (alias) /////////////////////////////////////////////////////////////////////////////////
#define fclt_ll(l1, l2, j)  _CC(F_GE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fclt_li(l, I, i, j) _CC(F_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fclt_ii(i1, i2, j)  _CC(F_GE_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped and aliased
#define fclt_il(I, i, l, j) _CC(F_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float branch if less than or equal //////////////////////////////////////////////////////////////////////////////////
#define fble_ll(l1, l2, j)  _CC(F_LE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fble_li(l, I, i, j) _CC(F_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fble_ii(i1, i2, j)  _CC(F_LE_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped
#define fble_il(I, i, l, j) _CC(F_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float contimue if less than or equal (alias) ////////////////////////////////////////////////////////////////////////
#define fcle_ll(l1, l2, j)  _CC(F_GT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fcle_li(l, I, i, j) _CC(F_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fcle_ii(i1, i2, j)  _CC(F_GT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped and aliased
#define fcle_il(I, i, l, j) _CC(F_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float branch if greater than or equal ///////////////////////////////////////////////////////////////////////////////
#define fbge_ll(l1, l2, j)  _CC(F_GE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fbge_li(l, I, i, j) _CC(F_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fbge_ii(i1, i2, j)  _CC(F_GE_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped
#define fbge_il(I, i, l, j) _CC(F_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float continue if greater than or equal (alias) /////////////////////////////////////////////////////////////////////
#define fcge_ll(l1, l2, j)  _CC(F_LT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fcge_li(l, I, i, j) _CC(F_LT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fcge_ii(i1, i2, j)  _CC(F_LT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped and aliased
#define fcge_il(I, i, l, j) _CC(F_GE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float branch if greater than ////////////////////////////////////////////////////////////////////////////////////////
#define fbgt_ll(l1, l2, j)  _CC(F_GT_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fbgt_li(l, I, i, j) _CC(F_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fbgt_ii(i1, i2, j)  _CC(F_GT_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped
#define fbgt_il(I, i, l, j) _CC(F_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float continue if greater than (alias)
#define fcgt_ll(l1, l2, j)  _CC(F_LE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fcgt_li(l, I, i, j) _CC(F_LE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fcgt_ii(i1, i2, j)  _CC(F_LE_II),      _D8(i1), _D8(i2), _DJ(j),

// Operand swapped and aliased
#define fcgt_il(I, i, l, j) _CC(F_GT_LI##I),   _D8(l),  _D8(i),  _DJ(j),

// Float branch if almost equal
#define fbae_ll(l1, l2, j)  _CC(F_AE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define fbae_li(l, I, i, j) _CC(F_AE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define fbae_ii(i1, i2, j)  _CC(F_AE_II),      _D8(i1), _D8(i2), _DJ(j),


// Vector branch if equal
#define vbeq_ll(l1, l2, j)  _CC(V_EQ_LL),      _D8(l1), _D8(l2), _DJ(j),
#define vbeq_li(l, I, i, j) _CC(V_EQ_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define vbeq_ii(i1, i2, j)  _CC(V_EQ_II),      _D8(i1), _D8(i2), _DJ(j),

// Vector continue if equal (alias)
#define vceq_ll(l1, l2, j)  _CC(V_NE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define vceq_li(l, I, i, j) _CC(V_NE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define vceq_ii(i1, i2, j)  _CC(V_NE_II),      _D8(i1), _D8(i2), _DJ(j),

// Vector branch if almost equal
#define vbae_ll(l1, l2, j)  _CC(V_AE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define vbae_li(l, I, i, j) _CC(V_AE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define vbae_ii(i1, i2, j)  _CC(V_AE_II),      _D8(i1), _D8(i2), _DJ(j),

// Vector branch if not equal
#define vbne_ll(l1, l2, j)  _CC(V_NE_LL),      _D8(l1), _D8(l2), _DJ(j),
#define vbne_li(l, I, i, j) _CC(V_NE_LI##I),   _D8(l),  _D8(i),  _DJ(j),
#define vbne_ii(i1, i2, j)  _CC(V_NE_II),      _D8(i1), _D8(i2), _DJ(j),

#endif

