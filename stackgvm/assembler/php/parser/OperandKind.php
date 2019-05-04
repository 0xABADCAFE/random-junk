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
        INDEX_0 = 2, // Index[0] offset         (0 ... 255)
        INDEX_1 = 3, // Index[1] offset         (0 ... 255)
        JUMP_8  = 4, // Short jump displacement (-128 ... 127)
        JUMP_16 = 5, // Jump displacement       (-32768 ... 32767)
        SMALL_8 = 6, // Small integer literal   (-128 ... 127),

       // Kinds
       MIN     = 0,
       MAX     = 6
    ;

    const LIMITS = [
        self::LOCAL   => [-128, 127],
        self::INDEX_0 => [0, 255],
        self::INDEX_1 => [0, 255],
        self::JUMP_8  => [-128, 127],
        self::JUMP_16 => [-32768, 32767],
        self::SMALL_8 => [-128, 127]
    ];

    const MAPPED = [
        "LOCAL"   => self::LOCAL,
        "INDEX_0" => self::INDEX_0,
        "INDEX_1" => self::INDEX_1,
        "JUMP_8"  => self::JUMP_8,
        "JUMP_16" => self::JUMP_16,
        "SMALL_8" => self::SMALL_8
    ];

    const
        MATCH_LOCAL   = '/^\s*\(.*?\)\s*$/',
        MATCH_INDEX   = '/^\s*\(\s*i(\d)\s*([\+\-]{1}.*?)\)\s*$/',
        MATCH_BASE_10 = '/^\s*#{1}(.*?)\s*$/'
    ;
}
