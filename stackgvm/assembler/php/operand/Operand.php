<?php

/**
 * Operand
 */

abstract class Operand {
    public
        $iKind,
        $iSize,
        $value,
        $sBytes,
        $sSource
    ;

    const MAPPED = [
        OperandKind::LOCAL   => 'LocalOperand',
        OperandKind::INDEX_0 => 'IndirectOperand',
        OperandKind::INDEX_1 => 'IndirectOperand',
        OperandKind::JUMP_8  => 'ResolvedBranchTargetOperand',
        OperandKind::JUMP_16 => 'ResolvedBranchTargetOperand',
        OperandKind::SMALL_8 => 'SmallLiteralIntegerOperand',
        OperandKind::BITPOS  => 'SmallLiteralIntegerOperand',
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


    protected function __construct(int $iKind, $value, string $sSource) {
        $this->iKind   = $iKind;
        $this->value   = $value;
        $this->sSource = $sSource;
        $this->iSize   = OperandKind::SIZES[$iKind];
    }
};
