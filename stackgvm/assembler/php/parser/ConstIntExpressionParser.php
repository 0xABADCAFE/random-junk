<?php

/**
 * ConstIntExpressionParser
 *
 * Parses constant integer expressions of the form expected to comprise operands in source
 */
class ConstIntExpressionParser implements IntegerExpressionParser {

    private
        /** @var int $iMin */
        $iMin,

        /** @var int $iMax */
        $iMax
    ;

    /**
     * Constructor
     *
     * @param int $iMin - Minimum allowed value of parsed integer
     * @param int $iMax - Maximum allowed value of parsed integer
     */
    public function __construct(int $iMin, int $iMax) {
        $this->iMin = min($iMin, $iMax);
        $this->iMax = max($iMin, $iMax);
    }

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sExpression) : int {
        $sExpression = preg_replace('/\s+/', '', $sExpression);
        $this->assertNotEmpty($sExpression);
        $this->assertAllowedCharacters($sExpression);
        $this->assertBalancedParenthesis($sExpression);

        $cExp = create_function("", 'return ' . $sExpression . ';');
        if (false === $cExp) {
            throw new ParseException("Invalid Expression Structure " . $sExpression);
        }
        $iVal = $cExp();
        if (!is_integer($iVal)) {
            throw new TypeException("Expression did not yield a valid integer " . $iVal);
        }
        if ($iVal < $this->iMin || $iVal > $this->iMax) {
            throw new RangeException("Value " . $iVal  . " is outside allowed range " . $this->iMin . "..." . $this->iMax);
        }
        return $iVal;
    }

    /**
     * Assert the expression is not empty
     *
     * @param string $sExpression
     * @throw InvalidArgumentException
     */
    private function assertNotEmpty(string $sExpression) {
        if ('0' !== $sExpression && empty($sExpression)) {
            throw new InvalidArgumentException("Empty Expression");
        }
    }

    /**
     * Assert the expression does not contain any illegal character classes
     *
     * @param string $sExpression
     * @throw ParseException
     */
    private function assertAllowedCharacters(string $sExpression) {
        if (!preg_match("/^[0-9\s\(\)\+\-\*\\/\%\<\>\&\|\~\?\:\^]+$/", $sExpression)) {
            throw new ParseException("Invalid Characters in expression " . $sExpression);
        }
        if (!preg_match("/\d+/", $sExpression)) {
            throw new ParseException("Missing digits in expression " . $sExpression);
        }
    }

    /**
     * Assert the expression contains balanced parenthesis
     *
     * @param string $sExpression
     * @throw ParseException
     */
    private function assertBalancedParenthesis(string $sExpression) {
        if (preg_match("/\(\)/", $sExpression)) {
            throw new ParseException("Empty Parenthesis in expression " . $sExpression);
        }
        $iBracketTest = 0;
        $iLength = strlen($sExpression);
        for ($i = 0; $i < $iLength; $i++) {
            if ('(' === $sExpression[$i]) {
                ++$iBracketTest;
            }
            if (')' === $sExpression[$i]) {
                --$iBracketTest;
            }
        }
        if (0 !== $iBracketTest) {
            throw new ParseException("Mismatched Parenthesis in expression " . $sExpression);
        }
    }
}
