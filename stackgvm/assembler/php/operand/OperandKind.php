<?php

/**
 * OperandKind
 *
 * Set of constants defining the possible Operand types, as well as their integer limits (if any)
 */
interface OperandKind {
    const
        KIND    = 0, // Kind (one of the remainder of this list)
        LOCAL   = 1, // Stack frame position    (-128 ... 127)
        INDIR_0 = 2, // Index[0] offset         (0 ... 255)
        INDIR_1 = 3, // Index[1] offset         (0 ... 255)
        JUMP_8  = 4, // Short jump displacement (-128 ... 127)
        JUMP_16 = 5, // Jump displacement       (-32768 ... 32767)
        SMALL_8 = 6, // Small integer literal   (-128 ... 127),
        BITPOS  = 7, // Small integer literal   (0 ... 31)

        LABEL   = 8, // Local Label
        SYMBOL  = 9, // Global Symbol

        // Kinds
        MIN     = 0,
        MAX     = 9
    ;

    const LIMITS = [
        self::LOCAL   => [-128, 127],
        self::INDIR_0 => [0, 255],
        self::INDIR_1 => [0, 255],
        self::JUMP_8  => [-128, 127],
        self::JUMP_16 => [-32768, 32767],
        self::SMALL_8 => [-128, 127],
        self::BITPOS  => [0, 31]
    ];

    const SIZES = [
        self::LOCAL   => 1,
        self::INDIR_0 => 1,
        self::INDIR_1 => 1,
        self::JUMP_8  => 1,
        self::SMALL_8 => 1,
        self::BITPOS  => 1,
        self::JUMP_16 => 2,
        self::LABEL   => 2,
        self::SYMBOL  => 2
    ];

    const MAPPED = [
        "LOCAL"   => self::LOCAL,
        "INDIR_0" => self::INDIR_0,
        "INDIR_1" => self::INDIR_1,
        "JUMP_8"  => self::JUMP_8,
        "JUMP_16" => self::JUMP_16,
        "SMALL_8" => self::SMALL_8,
        "BITPOS"  => self::BITPOS,
        "LABEL"   => self::LABEL,
        "SYMBOL"  => self::SYMBOL
    ];

    const
        MATCH_LOCAL    = '/^\s*\(.*?\)\s*$/',
        MATCH_INDIR    = '/^\s*\(\s*i(\d)\s*([\+\-]{1}.*?)\)\s*$/',
        MATCH_BASE_10  = '/^\s*#{1}(.*?)\s*$/',
        MATCH_LABEL    = '/^\s*\.([A-Za-z]{1}[0-9A-Za-z]{0,})\s*$/',
        MATCH_SYMBOL   = '/^\s*\@([A-Za-z]{1}[0-9A-Za-z]{0,})\s*$/'
    ;
}
