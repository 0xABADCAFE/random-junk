<?php

/**
 *
 */
class OperandNoOpParser implements Parser {

    public function parse(string $sOperand) : string {
        return $sOperand;
    }
}
