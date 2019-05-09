<?php

/**
 * Operand
 */

class IndirectOperand extends ResolvedOperand {

    public $iIndex;

    const INDEX = [
        OperandKind::INDIR_0 => 0,
        OperandKind::INDIR_1 => 1
    ];

    protected function __construct(int $iKind, $value, string $sSource) {
        if (!isset(self::INDEX[$iKind])) {
            throw new InvalidArgumentException();
        }
        parent::__construct($iKind, (int)$value, $sSource);
        $this->sBytes = chr($value);
        $this->iIndex = self::INDEX[$iKind];
    }
};
