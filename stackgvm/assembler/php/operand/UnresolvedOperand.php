<?php

/**
 * Operand
 */

class UnresolvedOperand extends Operand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, $value, $sSource);
        $this->sBytes = str_repeat('-', $this->iSize);
    }
};
