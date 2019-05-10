<?php

/**
 * PlaceholderIndexOperand
 *
 * Unlike other Operand types, Placeholder Operands do not have a size. Instead they exist as syntactical elements in
 * the assembler code which allow the instruction parser to resolve a given mnemonic set to a particular opcode.
 */

class PlaceholderIndexOperand extends ResolvedOperand {

    public $iIndex;

    const INDEX = [
        OperandKind::IDX_0_PH => 0,
        OperandKind::IDX_1_PH => 1
    ];

    protected function __construct(int $iKind, $value, string $sSource) {
        if (!isset(self::INDEX[$iKind])) {
            throw new InvalidArgumentException();
        }
        parent::__construct($iKind, (int)$value, $sSource);
        $this->sBytes = '';
        $this->iIndex = self::INDEX[$iKind];
    }
};
