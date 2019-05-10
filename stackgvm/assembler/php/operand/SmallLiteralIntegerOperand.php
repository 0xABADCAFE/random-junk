<?php

/**
 * SmallLiteralIntegerOperand
 *
 * Represents a single byte (signed or unsigned) small integer literal
 */

class SmallLiteralIntegerOperand extends ResolvedOperand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, $value, $sSource);
        $this->sBytes = chr((int)$value);
    }
};
