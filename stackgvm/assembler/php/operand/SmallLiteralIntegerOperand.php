<?php

/**
 * Operand
 */

class SmallLiteralIntegerOperand extends ResolvedOperand {

    public function getValue() : int {
        return $this->value;
    }

    public function getBytes() : string {
        return chr($this->value);
    }
};
