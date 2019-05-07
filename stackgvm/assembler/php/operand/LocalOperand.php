<?php

/**
 * Operand
 */

class LocalOperand extends ResolvedOperand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, $value, $sSource);
        $this->sBytes = chr((int)$value);
    }
};
