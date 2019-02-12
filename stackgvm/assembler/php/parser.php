<?php

interface IntegerExpressionParser {
    public function parse(string $sExpression) : int;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ConstIntExpressionParser implements IntegerExpressionParser {

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
            throw new RangeException("Value " . $iVal  . " is outside allowed range " . $this->iMin . "..." . $this->iMax);
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

class StackFramePositionParser implements IntegerExpressionParser {

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IndexOffsetParser implements IntegerExpressionParser {
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
            throw new RangeException("Wrong Index");
        }
        // Return the matched subexpression
        return $aMatches[2];
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreeOperandNonCommutativeParser {
/*
            _FSUB_LLL,
            _FSUB_ILL,
            _FSUB_LLI,
            _FSUB_ILI,
            _FSUB_LIL,
            _FSUB_IIL,
            _FSUB_LII,
*/
    const
       KIND_L  = 0,
       KIND_I0 = 1,
       KIND_I1 = 2
    ;

    public function parse(string $sExpression) {
        $aOperands = explode(',', preg_replace('/\s+/', '', $sExpression));
        $this->assertOperandCount($aOperands);
        $aKind = [];
        foreach ($aOperands as $sOperand) {
            $aKind[] = $this->determineKind($sOperand);
        }
        print_r($aKind);
    }

    private function determineKind(string $sOperand) {
        if (!preg_match('/i(\d+)/', $sOperand, $aMatch)) {
            return self::KIND_L;
        }
        switch ($aMatch[1]) {
            case 0: return self::KIND_I0;
            case 1: return self::KIND_I1;
            default:
                throw new ParseException();
        }
    }

    private function assertOperandCount(array $aOperands) {
        if (count($aOperands) != 3) {
            throw new Exception();
        }
    }
}

