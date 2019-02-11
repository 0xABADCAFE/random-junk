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
            throw new RangeException("Value outside allowed range " . $this->iMin . "..." . $this->iMax);
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class StackFramePositionParser {

    private $oIntExpressionParser;

    public function __construct() {
        $this->oIntExpressionParser = new ConstIntExpressionParser(-128, 127);
    }

    public function parse(string $sExpression) : int {
        $this->assertSyntax($sExpression);
        return $this->oIntExpressionParser->parse($sExpression);
    }

    private function assertSyntax(string $sExpression) {
        if (!preg_match("/^\s*\(.*?\)\s*$/", $sExpression)) {
            throw new ParseException("Malformed stack position '" . $sExpression. "', integer must be enclosed in parenthesis.");
        }
    }
}

class IndexOffsetParser {
    private $iReg;
    private $oIntExpressionParser;

    public function __construct(int $iReg) {
        $this->iReg = $iReg;
        $this->oIntExpressionParser = new ConstIntExpressionParser(0, 255);
    }

    public function parse(string $sExpression) : int {
        $sSubExpression = $this->assertSyntax($sExpression);
        return $this->oIntExpressionParser->parse($sSubExpression);
    }

    private function assertSyntax(string $sExpression) {
        if (!preg_match("/^\s*\(\s*i(\d)\s*([\+\-]{1}.*?)\)\s*$/", $sExpression, $aMatches)) {
            throw new ParseException("Malformed index offset '" . $sExpression. "', integer must be enclosed in parenthesis.");
        }
        if ($this->iReg != $aMatches[1]) {
            throw new RangeException("Wrong Index Pointer");
        }
        // Return the matched subexpression
        return $aMatches[2];
    }
}
