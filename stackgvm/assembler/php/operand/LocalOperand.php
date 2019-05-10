<?php

/**
 * LocalOperand
 *
 * Represents a signed 8-bit offset within the current stack. Values less than zero refer to the calling context's
 * stack frame and are allowed so that closures can refer to variables in the parent scope.
 */

class LocalOperand extends ResolvedOperand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, $value, $sSource);
        $this->sBytes = chr((int)$value);
    }
};
