<?php

/**
 * ResolvedBranchTargetOperand
 *
 * Represents an already resolved 8 or 16-bit signed branch target.
 */

class ResolvedBranchTargetOperand extends ResolvedOperand {

    protected function __construct(int $iKind, $value, string $sSource) {
        parent::__construct($iKind, (int)$value, $sSource);
        $this->aBytes = [];
        switch ($iKind) {
            case OperandKind::JUMP_16;
                $this->aBytes[] = ((int)$value) >> 8; // fall through
            case OperandKind::JUMP_8:
                $this->aBytes[] = ((int)$value) & 0xFF;
            default:
        }
    }
};
