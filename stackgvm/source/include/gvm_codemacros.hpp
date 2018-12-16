/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_CODEMACROS_HPP_
    #define _GVM_CODEMACROS_HPP_

#define vec3(x, y, z) Scalar(x), Scalar(y), Scalar(z)

#define BEGIN_GDATA_TABLE(name) Scalar* name[] = { 0,
#define END_GDATA_TABLE ,0 };
#define BEGIN_GFUNC_TABLE(name) FuncInfo name[] = { { 0, 0, 0, 0, 0 },
#define END_GFUNC_TABLE    ,{ 0, 0, 0, 0, 0 } };

#define BEGIN_GHOST_TABLE(name) HostCall name[] = { 0,
#define END_GHOST_TABLE ,0 };

#define GFUNC(name) uint8 _gvm_##name [] =


#define _OP(x)  (uint8)Opcode::_##x
#define _D8(x)  (uint8)(x)
#define _D16(x) (uint8)((x) >> 8), (uint8)((x) & 0xFF)

#define SYM(x)  (uint8)((x) >> 8), (uint8)((x) & 0xFF)
#define OFS(x)  (uint8)((x) >> 8), (uint8)((x) & 0xFF)

#define LOC(x)  L, x
#define IND(x)  I, x

#define hcf              _OP(HCF),
#define bras(j)          _OP(BRAS),         _D8(j),
#define bra(j)           _OP(BRA),          _D8(j),
#define bcall(j)         _OP(BCALL),        _D16(j),
#define call(f)          _OP(CALL),         _D16(f),
#define icall_l(l)       _OP(ICALL_L),      _D8(l),
#define icall_i(i)       _OP(ICALL_I),      _D8(i),
#define hcall(f)         _OP(HCALL),        _D16(f),
#define ret              _OP(RET),
#define libnn(I,i,j)     _OP(LI##I##BNN),   _D8(i),   _D16(j),
#define bez_l(l,j)       _OP(BEZ_L),        _D8(l),   _D16(j),
#define bez_i(i,j)       _OP(BEZ_I),        _D8(i),   _D16(j),
#define bnz_l(l,j)       _OP(BNZ_L),        _D8(l),   _D16(j),
#define bnz_i(i,j)       _OP(BNZ_I),        _D8(i),   _D16(j),
#define beq_ll(l1,l2,j)  _OP(BEQ_LL),       _D8(l1),  _D8(l2), _D16(j),
#define beq_li(l,i,j)    _OP(BEQ_LI),       _D8(l),   _D8(i),  _D16(j),
#define beq_ii(i1,i2,j)  _OP(BEQ_II),       _D8(i1),  _D8(i2), _D16(j),

#define addr_ll(l1,l2)   _OP(ADDR_LL),      _D8(l1),  _D8(l2),
#define addr_il(I,i,l)   _OP(ADDR_I##I##L), _D8(i),   _D8(l),
#define addr_dl(G,l)     _OP(ADDR_DL),      _D16(G),  _D8(l),
#define addr_d(G,I)      _OP(ADDR_D##I),    _D16(G),
#define addr_cl(f,l)     _OP(ADDR_CL),      _D16(f),  _D8(l),
#define addr_ci(f,I,i)   _OP(ADDR_CI##I)    _D16(f),  _D8(i),


#define load_li(l,I)      _OP(LOAD_L##I),    _D8(l),
#define save_il(I,l)      _OP(SAVE_##I##L),  _D8(l),
#define load_hl(h,l)      _OP(LOAD_HL),      _D8(h), _D8(l),

#define copy_ll(l1,l2)      _OP(COPY_LL),      _D8(l1), _D8(l2),
#define copy_il(I,i,l)      _OP(COPY_I##I##L), _D8(i),  _D8(l),
#define cpix_il(I,i,l1,l2)  _OP(CPIX_I##I##L), _D8(i),  _D8(l1), _D8(l2),
#define copy_li(l,I,i)      _OP(COPY_LI##I),   _D8(l),  _D8(i),
#define copy_ii(i1,i2)      _OP(COPY_II),      _D8(i1), _D8(i2),

#define itof_ll(l1,l2)    _OP(ITOF_LL),      _D8(l1), _D8(l2),
#define ftoi_ll(l1,l2)    _OP(FTOI_LL),      _D8(l1), _D8(l2),

//
// // Two operand branch if greater or equal
#define bge_ll(l1,l2,j)   _OP(BGE_LL),       _D8(l1), _D8(l2),  _D16(j),
#define bge_il(i,l,j)     _OP(BGE_IL),       _D8(i),  _D8(l),   _D16(j),
#define bge_li(l,i,j)     _OP(BGE_LI),       _D8(l),  _D8(i),   _D16(j),
#define bge_ii(i1,i2,j)   _OP(BGE_II),       _D8(i1), _D8(i2),  _D16(j),
//
// // Two operand branch if greater than
#define bgt_ll(l1,l2,j)   _OP(BGT_LL),       _D8(l1), _D8(l2),  _D16(j),
#define bgt_il(i,l,j)     _OP(BGT_IL),       _D8(i),  _D8(l),   _D16(j),
#define bgt_li(l,i,j)     _OP(BGT_LI),       _D8(l),  _D8(i),   _D16(j),
#define bgt_ii(i1,i2,j)   _OP(BGT_II),       _D8(i1), _D8(i2),  _D16(j),
//
#define dbnz_l(l,j)       _OP(DBNZ_L),       _D8(l),  _D16(j),
#define dbnn_l(l,j)       _OP(DBNN_L),       _D8(l),  _D16(j),

//
// // Load small literal integer
#define load_sl(v,l)      _OP(LOAD_SL),      _D8(v),  _D8(l),
#define load_si(v,I,i)    _OP(LOAD_SI##I),      _D8(v),  _D8(l),

//
// // Single bit operations
#define bset_l(b,l) _OP(BSET_SL), _D8(b), _D8(l),
#define bset_i(b,i) _OP(BSET_SI), _D8(b), _D8(i),

#define bclr_l(b,x) _OP(BCLR_SL), _D8(b), _D8(l),
#define bclr_i(b,x) _OP(BCLR_SI), _D8(b), _D8(i),

#define bbs_l(b,l,j) _OP(BBS_SL), _D8(b), _D8(l), _D16(j),
#define bbs_i(b,i,j) _OP(BBS_SI), _D8(b), _D8(i), _D16(j),
#define bbc_l(b,l,j) _OP(BBC_SL), _D8(b), _D8(l), _D16(j),
#define bbc_i(b,i,j) _OP(BBC_SI), _D8(b), _D8(i), _D16(j),
//
// // Two operand logical negate
#define not_ll(l1,l2) _OP(NOT_LL),       _D8(l1), _D8(l2),
#define not_il(i,l)   _OP(NOT_IL),       _D8(i),  _D8(l),
#define not_li(l,i)   _OP(NOT_LI),       _D8(l),  _D8(i),
#define not_ii(i1,i2) _OP(NOT_II),       _D8(i1), _D8(i2),
//
// // Two operand integer negate
#define neg_ll(l1,l2) _OP(NEG_LL),       _D8(l1), _D8(l2),
#define neg_il(i,l)   _OP(NEG_IL),       _D8(i),  _D8(l),
#define neg_li(l,i)   _OP(NEG_LI),       _D8(l),  _D8(i),
#define neg_ii(i1,i2) _OP(NEG_II),       _D8(i1), _D8(i2),
//
// // Three operand integer addition: Commutative, 4 unique variants
#define add_lll(l1,l2,l3) _OP(ADD_LLL), _D8(l1), _D8(l2), _D8(l3),
#define add_ill(i,l1,l2)  _OP(ADD_ILL), _D8(i),  _D8(l1), _D8(l2),
#define add_lli(l1,l2,i)  _OP(ADD_LLI), _D8(l1), _D8(l2), _D8(i),
#define add_ili(i1,l,i2)  _OP(ADD_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand integer subtraction: Noncommutative, 7 unique variants
#define sub_lll(l1,l2,l3) _OP(SUB_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define sub_ill(i,l1,l2)  _OP(SUB_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define sub_lli(l1,l2,i)  _OP(SUB_LLI),  _D8(l1), _D8(l2), _D8(i),
#define sub_ili(i1,l,i2)  _OP(SUB_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define sub_lil(l1,i,l2)  _OP(SUB_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define sub_iil(i1,i2,l)  _OP(SUB_IIL),  _D8(i1), _D8(i2), _D8(l),
#define sub_lii(l,i1,i2)  _OP(SUB_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Three operand integer multiplication: Commutative, 4 unique variants
#define mul_lll(l1,l2,l3)  _OP(MUL_LLL), _D8(l1), _D8(l2), _D8(l3),
#define mul_ill(i,l1,l2)   _OP(MUL_ILL), _D8(i),  _D8(l1), _D8(l2),
#define mul_lli(l1,l2,i)   _OP(MUL_LLI), _D8(l1), _D8(l2), _D8(i),
#define mul_ili(i1,l,i2)   _OP(MUL_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand integer division: Noncommutative, 7 unique variants
#define div_lll(l1,l2,l3) _OP(DIV_LLL), _D8(l1), _D8(l2), _D8(l3),
#define div_ill(i,l1,l2)  _OP(DIV_ILL), _D8(i),  _D8(l1), _D8(l2),
#define div_lli(l1,l2,i)  _OP(DIV_LLI), _D8(l1), _D8(l2), _D8(i),
#define div_ili(i1,l,i2)  _OP(DIV_ILI), _D8(i1), _D8(l),  _D8(i2),
#define div_lil(l1,i,l2)  _OP(DIV_LIL), _D8(l1), _D8(i),  _D8(l2),
#define div_iil(i1,i2,l)  _OP(DIV_IIL), _D8(i1), _D8(i2), _D8(l),
#define div_lii(l,i1,i2)  _OP(DIV_LII), _D8(l),  _D8(i1), _D8(i2),
//
// // Three operand integer modulo: Noncommutative, 7 unique variants
#define mod_lll(l1,l2,l3) _OP(MOD_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define mod_ill(i,l1,l2)  _OP(MOD_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define mod_lli(l1,l2,i)  _OP(MOD_LLI),  _D8(l1), _D8(l2), _D8(i),
#define mod_ili(i1,l,i2)  _OP(MOD_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define mod_lil(l1,i,l2)  _OP(MOD_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define mod_iil(i1,i2,l)  _OP(MOD_IIL),  _D8(i1), _D8(i2), _D8(l),
#define mod_lii(l,i1,i2)  _OP(MOD_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Three operand logical AND: Commutative, 4 unique variants
#define and_lll(l1,l2,l3)  _OP(AND_LLL), _D8(l1), _D8(l2), _D8(l3),
#define and_ill(i,l1,l2)   _OP(AND_ILL), _D8(i),  _D8(l1), _D8(l2),
#define and_lli(l1,l2,i)   _OP(AND_LLI), _D8(l1), _D8(l2), _D8(i),
#define and_ili(i1,l,i2)   _OP(AND_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand logical OR: Commutative, 4 unique variants
#define or_lll(l1,l2,l3)  _OP(OR_LLL), _D8(l1), _D8(l2), _D8(l3),
#define or_ill(i,l1,l2)   _OP(OR_ILL), _D8(i),  _D8(l1), _D8(l2),
#define or_lli(l1,l2,i)   _OP(OR_LLI), _D8(l1), _D8(l2), _D8(i),
#define or_ili(i1,l,i2)   _OP(OR_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand logical XOR: Commutative, 4 unique variants
#define xor_lll(l1,l2,l3)  _OP(XOR_LLL), _D8(l1), _D8(l2), _D8(l3),
#define xor_ill(i,l1,l2)   _OP(XOR_ILL), _D8(i),  _D8(l1), _D8(l2),
#define xor_lli(l1,l2,i)   _OP(XOR_LLI), _D8(l1), _D8(l2), _D8(i),
#define xor_ili(i1,l,i2)   _OP(XOR_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand logical shift left: Noncommutative, 4 supported variants
#define lsl_lll(l1,l2,l3)  _OP(LSL_LLL), _D8(l1), _D8(l2), _D8(l3),
#define lsl_ill(i,l1,l2)   _OP(LSL_ILL), _D8(i),  _D8(l1), _D8(l2),
#define lsl_lli(l1,l2,i)   _OP(LSL_LLI), _D8(l1), _D8(l2), _D8(i),
#define lsl_ili(i1,l,i2)   _OP(LSL_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand logical shift right: Noncommutative, 4 supported variants
#define lsr_lll(l1,l2,l3)  _OP(LSR_LLL), _D8(l1), _D8(l2), _D8(l3),
#define lsr_ill(i,l1,l2)   _OP(LSR_ILL), _D8(i),  _D8(l1), _D8(l2),
#define lsr_lli(l1,l2,i)   _OP(LSR_LLI), _D8(l1), _D8(l2), _D8(i),
#define lsr_ili(i1,l,i2)   _OP(LSR_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Integer Maximum: Commutative, 4 unique variants
#define max_lll(l1,l2,l3)  _OP(MAX_LLL), _D8(l1), _D8(l2), _D8(l3),
#define max_ill(i,l1,l2)   _OP(MAX_ILL), _D8(i),  _D8(l1), _D8(l2),
#define max_lli(l1,l2,i)   _OP(MAX_LLI), _D8(l1), _D8(l2), _D8(i),
#define max_ili(i1,l,i2)   _OP(MAX_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Integer Minumum: Commutative, 4 unique variants
#define min_lll(l1,l2,l3)  _OP(MIN_LLL), _D8(l1), _D8(l2), _D8(l3),
#define min_ill(i,l1,l2)   _OP(MIN_ILL), _D8(i),  _D8(l1), _D8(l2),
#define min_lli(l1,l2,i)   _OP(MIN_LLI), _D8(l1), _D8(l2), _D8(i),
#define min_ili(i1,l,i2)   _OP(MIN_ILI), _D8(i1), _D8(l),  _D8(i2),


//
// // Floating point specific instructions ////////////////////////////////////////////////////////////////////
//

#define frnd_l(l)            _OP(FRND_L),        _D8(l),

// // Two operand branch if greater or equal
#define fbge_ll(l1,l2,j)     _OP(FBGE_LL),       _D8(l1), _D8(l2),  _D16(j),
#define fbge_il(i,l,j)       _OP(FBGE_IL),       _D8(i),  _D8(l),   _D16(j),
#define fbge_li(l,i,j)       _OP(FBGE_LI),       _D8(l),  _D8(i),   _D16(j),
#define fbge_ii(i1,i2,j)     _OP(FBGE_II),       _D8(i1), _D8(i2),  _D16(j),
//
// // Two operand branch if greater than
#define fbgt_ll(l1,l2,j)     _OP(FBGT_LL),       _D8(l1), _D8(l2),  _D16(j),
#define fbgt_il(i,l,j)       _OP(FBGT_IL),       _D8(i),  _D8(l),   _D16(j),
#define fbgt_li(l,i,j)       _OP(FBGT_LI),       _D8(l),  _D8(i),   _D16(j),
#define fbgt_ii(i1,i2,j)     _OP(FBGT_II),       _D8(i1), _D8(i2),  _D16(j),
//
// // Two operand, local to local handy maths functions
#define finv_ll(l1,l2)   _OP(FINV_LL),  _D8(l1), _D8(l2),
#define fsqrt_ll(l1,l2)  _OP(FSQRT_LL), _D8(l1), _D8(l2),
#define fisqr_ll(l1,l2)  _OP(INVSQ_LL), _D8(l1), _D8(l2),
#define fsin_ll(l1,l2)   _OP(FSIN_LL),  _D8(l1), _D8(l2),
#define fcos_ll(l1,l2)   _OP(FCOS_LL),  _D8(l1), _D8(l2),
#define facos_l(l1,l2)l  _OP(FACOS_LL), _D8(l1), _D8(l2),
//
//
// // Two operand float negate
#define fneg_ll(l1,l2)     _OP(FNEG_LL),       _D8(l1), _D8(l2),
#define fneg_il(i,l)       _OP(FNEG_IL),       _D8(i),  _D8(l),
#define fneg_li(l,i)       _OP(FNEG_LI),       _D8(l),  _D8(i),
#define fneg_ii(i1,i2)     _OP(FNEG_II),       _D8(i1), _D8(i2),
//
// // Three operand float addition: Commutative, 4 unique variants
#define fadd_lll(l1,l2,l3)  _OP(FADD_LLL), _D8(l1), _D8(l2), _D8(l3),
#define fadd_ill(i,l1,l2)   _OP(FADD_ILL), _D8(i),  _D8(l1), _D8(l2),
#define fadd_lli(l1,l2,i)   _OP(FADD_LLI), _D8(l1), _D8(l2), _D8(i),
#define fadd_ili(i1,l,i2)   _OP(FADD_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand float subtraction: Noncommutative, 7 unique variants
#define fsub_lll(l1,l2,l3) _OP(FSUB_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define fsub_ill(i,l1,l2)  _OP(FSUB_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define fsub_lli(l1,l2,i)  _OP(FSUB_LLI),  _D8(l1), _D8(l2), _D8(i),
#define fsub_ili(i1,l,i2)  _OP(FSUB_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define fsub_lil(l1,i,l2)  _OP(FSUB_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define fsub_iil(i1,i2,l)  _OP(FSUB_IIL),  _D8(i1), _D8(i2), _D8(l),
#define fsub_lii(l,i1,i2)  _OP(FSUB_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Three operand float multiplication: Commutative, 4 unique variants
#define fmul_lll(l1,l2,l3)  _OP(FMUL_LLL), _D8(l1), _D8(l2), _D8(l3),
#define fmul_ill(i,l1,l2)   _OP(FMUL_ILL), _D8(i),  _D8(l1), _D8(l2),
#define fmul_lli(l1,l2,i)   _OP(FMUL_LLI), _D8(l1), _D8(l2), _D8(i),
#define fmul_ili(i1,l,i2)   _OP(FMUL_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Three operand float division: Noncommutative, 7 unique variants
#define fdiv_lll(l1,l2,l3) _OP(FDIV_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define fdiv_ill(i,l1,l2)  _OP(FDIV_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define fdiv_lli(l1,l2,i)  _OP(FDIV_LLI),  _D8(l1), _D8(l2), _D8(i),
#define fdiv_ili(i1,l,i2)  _OP(FDIV_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define fdiv_lil(l1,i,l2)  _OP(FDIV_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define fdiv_iil(i1,i2,l)  _OP(FDIV_IIL),  _D8(i1), _D8(i2), _D8(l),
#define fdiv_lii(l,i1,i2)  _OP(FDIV_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Three operand float modulo: Noncommutative, 7 unique variants
#define fmod_lll(l1,l2,l3) _OP(FMOD_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define fmod_ill(i,l1,l2)  _OP(FMOD_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define fmod_lli(l1,l2,i)  _OP(FMOD_LLI),  _D8(l1), _D8(l2), _D8(i),
#define fmod_ili(i1,l,i2)  _OP(FMOD_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define fmod_lil(l1,i,l2)  _OP(FMOD_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define fmod_iil(i1,i2,l)  _OP(FMOD_IIL),  _D8(i1), _D8(i2), _D8(l),
#define fmod_lii(l,i1,i2)  _OP(FMOD_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Floating Point Maximum: Commutative, 4 unique variants
#define fmax_lll(l1,l2,l3)  _OP(FMAX_LLL), _D8(l1), _D8(l2), _D8(l3),
#define fmax_ill(i,l1,l2)   _OP(FMAX_ILL), _D8(i),  _D8(l1), _D8(l2),
#define fmax_lli(l1,l2,i)   _OP(FMAX_LLI), _D8(l1), _D8(l2), _D8(i),
#define fmax_ili(i1,l,i2)   _OP(FMAX_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Floating Point Minimum: Commutative, 4 unique variants
#define fmin_lll(l1,l2,l3)  _OP(FMIN_LLL), _D8(l1), _D8(l2), _D8(l3),
#define fmin_ill(i,l1,l2)   _OP(FMIN_ILL), _D8(i),  _D8(l1), _D8(l2),
#define fmin_lli(l1,l2,i)   _OP(FMIN_LLI), _D8(l1), _D8(l2), _D8(i),
#define fmin_ili(i1,l,i2)   _OP(FMIN_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Vector specific instructions ////////////////////////////////////////////////////////////////////////////
//
// // Vector branch if equal
#define vbeq_ll(l1,l2,j) _OP(VBEQ_LL), _D8(l1), _D8(l2), _D16(j),
#define vbeq_il(i,l,j)   _OP(VBEQ_IL), _D8(i),  _D8(l),  _D16(j),
#define vbeq_ii(i1,i2,j) _OP(VBEQ_II), _D8(i1), _D8(i2), _D16(j),
//
// // Vector branch if not equal
#define vbne_ll(l1,l2,j) _OP(VBNE_LL), _D8(l1), _D8(l2), _D16(j),
#define vbne_il(i,l,j)   _OP(VBNE_IL), _D8(i),  _D8(l),  _D16(j),
#define vbne_ii(i1,i2,j) _OP(VBNE_II), _D8(i1), _D8(i2), _D16(j),
//
// // Two operand Vector instructions
#define vcopy_ll(l1,l2)     _OP(VCOPY_LL),       _D8(l1), _D8(l2),
#define vcopy_il(i,l)       _OP(VCOPY_IL),       _D8(i),  _D8(l),
#define vcopy_li(l,i)       _OP(VCOPY_LI),       _D8(l),  _D8(i),
#define vcopy_ii(i1,i2)     _OP(VCOPY_II),       _D8(i1), _D8(i2),
//
// // Vector negate
#define vneg_ll(l1,l2)     _OP(VNEG_LL),       _D8(l1), _D8(l2),
#define vneg_il(i,l)       _OP(VNEG_IL),       _D8(i),  _D8(l),
#define vneg_li(l,i)       _OP(VNEG_LI),       _D8(l),  _D8(i),
#define vneg_ii(i1,i2)     _OP(VNEG_II),       _D8(i1), _D8(i2),
//
// // Vector normalize
#define vnorm_ll(l1,l2)     _OP(VNORM_LL),       _D8(l1), _D8(l2),
#define vnorm_il(i,l)       _OP(VNORM_IL),       _D8(i),  _D8(l),
#define vnorm_li(l,i)       _OP(VNORM_LI),       _D8(l),  _D8(i),
#define vnorm_ii(i1,i2)     _OP(VNORM_II),       _D8(i1), _D8(i2),
//
// // Vector magnitude (scalar result)
#define vmag_ll(l1,l2)     _OP(VMAG_LL),       _D8(l1), _D8(l2),
#define vmag_il(i,l)       _OP(VMAG_IL),       _D8(i),  _D8(l),
#define vmag_li(l,i)       _OP(VMAG_LI),       _D8(l),  _D8(i),
#define vmag_ii(i1,i2)     _OP(VMAG_II),       _D8(i1), _D8(i2),
//
// // Three operand vector instructions
//
// // Vector addition: Commutative, 4 unique variants
#define vadd_lll(l1,l2,l3)  _OP(VADD_LLL), _D8(l1), _D8(l2), _D8(l3),
#define vadd_ill(i,l1,l2)   _OP(VADD_ILL), _D8(i),  _D8(l1), _D8(l2),
#define vadd_lli(l1,l2,i)   _OP(VADD_LLI), _D8(l1), _D8(l2), _D8(i),
#define vadd_ili(i1,l,i2)   _OP(VADD_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Vector subtraction: Noncommutative, 7 unique variants
#define vsub_lll(l1,l2,l3) _OP(VSUB_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define vsub_ill(i,l1,l2)  _OP(VSUB_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define vsub_lli(l1,l2,i)  _OP(VSUB_LLI),  _D8(l1), _D8(l2), _D8(i),
#define vsub_ili(i1,l,i2)  _OP(VSUB_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define vsub_lil(l1,i,l2)  _OP(VSUB_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define vsub_iil(i1,i2,l)  _OP(VSUB_IIL),  _D8(i1), _D8(i2), _D8(l),
#define vsub_lii(l,i1,i2)  _OP(VSUB_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Dot product (scalar result): Commutative, 4 unique variants
#define vdot_lll(l1,l2,l3)  _OP(VDOT_LLL), _D8(l1), _D8(l2), _D8(l3),
#define vdot_ill(i,l1,l2)   _OP(VDOT_ILL), _D8(i),  _D8(l1), _D8(l2),
#define vdot_lli(l1,l2,i)   _OP(VDOT_LLI), _D8(l1), _D8(l2), _D8(i),
#define vdot_ili(i1,l,i2)   _OP(VDOT_ILI), _D8(i1), _D8(l),  _D8(i2),
//
// // Cross product (vector result): Noncommutative, 7 unique variants
#define vcross_lll(l1,l2,l3) _OP(VCROSS_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define vcross_ill(i,l1,l2)  _OP(VCROSS_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define vcross_lli(l1,l2,i)  _OP(VCROSS_LLI),  _D8(l1), _D8(l2), _D8(i),
#define vcross_ili(i1,l,i2)  _OP(VCROSS_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define vcross_lil(l1,i,l2)  _OP(VCROSS_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define vcross_iil(i1,i2,l)  _OP(VCROSS_IIL),  _D8(i1), _D8(i2), _D8(l),
#define vcross_lii(l,i1,i2)  _OP(VCROSS_LII),  _D8(l),  _D8(i1), _D8(i2),
//
// // Vector multiply by float: Commutative, 7 variants due to different input operand types
#define vfmul_lll(l1,l2,l3) _OP(VFMUL_LLL),  _D8(l1), _D8(l2), _D8(l3),
#define vfmul_ill(i,l1,l2)  _OP(VFMUL_ILL),  _D8(i),  _D8(l1), _D8(l2),
#define vfmul_lli(l1,l2,i)  _OP(VFMUL_LLI),  _D8(l1), _D8(l2), _D8(i),
#define vfmul_ili(i1,l,i2)  _OP(VFMUL_ILI),  _D8(i1), _D8(l),  _D8(i2),
#define vfmul_lil(l1,i,l2)  _OP(VFMUL_LIL),  _D8(l1), _D8(i),  _D8(l2),
#define vfmul_iil(i1,i2,l)  _OP(VFMUL_IIL),  _D8(i1), _D8(i2), _D8(l),
#define vfmul_lii(l,i1,i2)  _OP(VFMUL_LII),  _D8(l),  _D8(i1), _D8(i2),

#endif
