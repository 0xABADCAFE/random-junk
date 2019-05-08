<?php

/**
 * OperandParser interface
 */
interface OperandParser {

    /**
     * Parse a string containing an integer expression into an integer value
     *
     * @param string $sExpression
     * @return mixed
     * @throw Exception
     */
    public function parse(string $sExpression);
}
