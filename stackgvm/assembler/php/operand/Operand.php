<?php

/**
 * Operand
 *
 * Base class for parsed operand data
 */

abstract class Operand {
    public
        $iKind,
        $iSize,
        $value,
        $aBytes
    ;

    const MAPPED = [
        OperandKind::LOCAL    => 'LocalOperand',
        OperandKind::INDIR_0  => 'IndirectOperand',
        OperandKind::INDIR_1  => 'IndirectOperand',
        OperandKind::IDX_0_PH => 'PlaceholderIndexOperand',
        OperandKind::IDX_1_PH => 'PlaceHolderIndexOperand',
        OperandKind::JUMP_8   => 'ResolvedBranchTargetOperand',
        OperandKind::JUMP_16  => 'ResolvedBranchTargetOperand',
        OperandKind::SMALL_S8 => 'SmallLiteralIntegerOperand',
        OperandKind::SMALL_U8 => 'SmallLiteralIntegerOperand',
        OperandKind::BITPOS   => 'SmallLiteralIntegerOperand',
        OperandKind::LABEL    => 'UnresolvedOperand',
        OperandKind::DATA_SYM => 'UnresolvedOperand',
        OperandKind::CODE_SYM => 'UnresolvedOperand'
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
        $this->iSize   = OperandKind::SIZES[$iKind];
    }
};
