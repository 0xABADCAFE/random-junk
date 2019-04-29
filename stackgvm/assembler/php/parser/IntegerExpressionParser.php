<?php

/**
 * IntegerExpressionParser interface
 */
interface IntegerExpressionParser {

    /**
     * Parse a string containing an integer expression into an integer value
     *
     * @param string $sExpression
     * @return int
     * @throw Exception
     */
    public function parse(string $sExpression) : int;
}
