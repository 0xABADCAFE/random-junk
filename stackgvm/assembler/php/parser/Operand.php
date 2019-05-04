<?php

/**
 * Operand
 */

class Operand {
    public
        $iKind,
        $iValue,
        $sSource
    ;
    public function __construct(int $iKind, int $iValue, string $sSource) {
        $this->iKind   = $iKind;
        $this->iValue  = $iValue;
        $this->sSource = $sSource;
    }
};
