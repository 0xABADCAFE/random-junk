<?php

/**
 * Operand
 */

abstract class Operand {
    public
        $iKind,
        $value,
        $sSource
    ;

    const MAPPED = [
        OperandKind::LOCAL   => 'ResolvedOperand',
        OperandKind::INDEX_0 => 'ResolvedOperand',
        OperandKind::INDEX_1 => 'ResolvedOperand',
        OperandKind::JUMP_8  => 'ResolvedOperand',
        OperandKind::JUMP_16 => 'ResolvedOperand',
        OperandKind::SMALL_8 => 'ResolvedOperand',
        OperandKind::BITPOS  => 'ResolvedOperand',
        OperandKind::LABEL   => 'UnresolvedOperand',
        OperandKind::SYMBOL  => 'UnresolvedOperand'
    ];

    public static function create(int $iKind, $value, string $sSource) {
        if (!isset(self::MAPPED[$iKind])) {
            throw new Exception("Unmapped Operand Kind");
        }
        $sKind = self::MAPPED[$iKind];
        return new $sKind($iKind, $value, $sSource);
    }

    public function __construct(int $iKind, $value, string $sSource) {
        $this->iKind   = $iKind;
        $this->value   = $value;
        $this->sSource = $sSource;
    }
};
