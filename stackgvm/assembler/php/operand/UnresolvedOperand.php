<?php

/**
 * UnresolvedOperand
 *
 * Intermediate class from which all unresolved Operand types are derived.
 */

class UnresolvedOperand extends Operand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, $value, $sSource);
        $this->aBytes = [-1, -1];
    }
};
