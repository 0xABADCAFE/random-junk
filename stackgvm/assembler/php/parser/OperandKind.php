<?php

/**
 * OperandKind
 *
 * Set of constants defining the possible Operand types, as well as their integer limits (if any)
 */
interface OperandKind {
    const
       LOCAL   = 0, // Stack frame position    (-128 ... 127)
       INDEX_0 = 1, // Index[0] offset         (0 ... 255)
       INDEX_1 = 2, // Index[1] offset         (0 ... 255)
       JUMP_8  = 3, // Short jump displacement (-128 ... 127)
       JUMP_16 = 4, // Jump displacement       (-32768 ... 32767)
       SMALL_8 = 5, // Small integer literal   (-128 ... 127),

       // Kinds
       MIN     = 0,
       MAX     = 5
    ;

    const LIMITS = [
        self::LOCAL   => [-128, 127],
        self::INDEX_0 => [0, 255],
        self::INDEX_1 => [0, 255],
        self::JUMP_8  => [-128, 127],
        self::JUMP_16 => [-32768, 32767],
        self::SMALL_8 => [-128, 127]
    ];
}