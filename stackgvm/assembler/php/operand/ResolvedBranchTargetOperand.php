<?php

/**
 * Operand
 */

class ResolvedBranchTargetOperand extends ResolvedOperand {

    public function getBytes() : string {
        return chr($this->value);
    }
};
