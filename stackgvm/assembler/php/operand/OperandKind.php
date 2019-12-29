<?php

/**
 * OperandKind
 *
 * Set of constants defining the possible Operand types, as well as their integer limits (if any)
 */
interface OperandKind {
    const
        KIND     =  0, // Kind (one of the remainder of this list)
        LOCAL    =  1, // Stack frame position    (-128 ... 127)
        INDIR_0  =  2, // Index[0] offset         (0 ... 255)
        INDIR_1  =  3, // Index[1] offset         (0 ... 255)
        IDX_0_PH =  4, // Index[0] placeholder
        IDX_1_PH =  5, // Index[1] placeholder
        JUMP_8   =  6, // Short jump displacement (-128 ... 127)
        JUMP_16  =  7, // Jump displacement       (-32768 ... 32767)
        SMALL_S8 =  8, // Small integer literal   (-128 ... 127),
        SMALL_U8 =  9, // Small integer literal   (0 ... 255)
        BITPOS   = 10, // Small integer literal   (0 ... 31)

        LABEL    = 11, // Local Label
        DATA_SYM = 12, // Global Data Symbol
        CODE_SYM = 13, // Global Code Symbol

        // Kinds
        MIN      = 0,
        MAX      = 13
    ;

    const LIMITS = [
        self::LOCAL    => [-128, 127],
        self::INDIR_0  => [0, 255],
        self::INDIR_1  => [0, 255],
        self::JUMP_8   => [-128, 127],
        self::JUMP_16  => [-32768, 32767],
        self::SMALL_S8 => [-128, 127],
        self::SMALL_U8 => [0, 255],
        self::BITPOS   => [0, 31]
    ];

    const SIZES = [
        self::LOCAL    => 1,
        self::INDIR_0  => 1,
        self::INDIR_1  => 1,
        self::IDX_0_PH => 0,
        self::IDX_1_PH => 0,
        self::JUMP_8   => 1,
        self::SMALL_S8 => 1,
        self::SMALL_U8 => 1,
        self::BITPOS   => 1,
        self::JUMP_16  => 2,
        self::LABEL    => 2,
        self::DATA_SYM => 2,
        self::CODE_SYM => 2
    ];

    const MAPPED = [
        'LOCAL'    => self::LOCAL,
        'INDIR_0'  => self::INDIR_0,
        'INDIR_1'  => self::INDIR_1,
        'IDX_0_PH' => self::IDX_0_PH,
        'IDX_1_PH' => self::IDX_1_PH,
        'JUMP_8'   => self::JUMP_8,
        'JUMP_16'  => self::JUMP_16,
        'SMALL_S8' => self::SMALL_S8,
        'SMALL_U8' => self::SMALL_U8,
        'BITPOS'   => self::BITPOS,
        'LABEL'    => self::LABEL,
        'DATA_SYM' => self::DATA_SYM,
        'CODE_SYM' => self::CODE_SYM,
    ];

    const
        MATCH_LOCAL    = '/^\s*\{(.*?)\}\s*$/',
        MATCH_INDIR    = '/^\s*i(\d)\[(.*?)\]\s*$/',
        MATCH_IDX      = '/^\s*i(\d)\s*$/',
        MATCH_BASE_10  = '/^\s*#{1}(.*?)\s*$/',
        MATCH_LABEL    = '/^\s*\.([A-Za-z_]{1}[0-9A-Za-z_]{0,})\s*$/',
        MATCH_CODE_SYM = '/^\s*\@([A-Za-z_]{1}[0-9A-Za-z_]{0,})\s*$/',
        MATCH_DATA_SYM = '/^\s*\$([A-Za-z_]{1}[0-9A-Za-z_]{0,})\s*$/'
    ;
}
