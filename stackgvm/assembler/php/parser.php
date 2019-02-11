<?php

class ConstIntExpressionParser {

    private $iMin, $iMax;

    public function __construct(int $iMin, int $iMax) {
        $this->iMin = min($iMin, $iMax);
        $this->iMax = max($iMin, $iMax);
    }

    public function parse(string $sExpression) : int {
        $sExpression = preg_replace('/\s+/', '', $sExpression);
        $this->assertNotEmpty($sExpression);
        $this->assertAllowedCharacters($sExpression);
        $this->assertBalancedParenthesis($sExpression);

        $cExp = create_function("", 'return ' . $sExpression . ';');
        if (false === $cExp) {
            throw new ParseException("Invalid Structure");
        }
        $iVal = $cExp();
        if (!is_integer($iVal)) {
            throw new TypeException("Not a valid integer " . $iVal);
        }
        if ($iVal < $this->iMin || $iVal > $this->iMax) {
            throw new RangeException("Value outside allowed range ");
        }
        return $iVal;
    }

    private function assertNotEmpty(string $sExpression) {
        if ('0' !== $sExpression && empty($sExpression)) {
            throw new InvalidArgumentException("Empty Expression");
        }
    }

    private function assertAllowedCharacters(string $sExpression) {
        if (!preg_match("/^[0-9\s\(\)\+\-\*]+$/", $sExpression)) {
            throw new ParseException("Invalid Characters in expression " . $sExpression);
        }
        if (!preg_match("/\d+/", $sExpression)) {
            throw new ParseException("Missing digits in expression " . $sExpression);
        }
    }

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

