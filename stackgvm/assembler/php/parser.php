<?php

/**
 * OperandKind
 *
 * Set of constants defining the possible Operand types, as well as their integer limits (if any)
 */
interface OperandKind {
    const
       LOCAL   = 0, // Stack frame position    (-128 ... 127)
       INDEX_0 = 1, // Index[0] offset         (0 ... 255)
       INDEX_1 = 2, // Index[1] offset         (0 ... 255)
       JUMP_8  = 3, // Short jump displacement (-128 ... 127)
       JUMP_16 = 4, // Jump displacement       (-32768 ... 32767)
       SMALL_8 = 5  // Small integer literal   (-128 ... 127)
    ;

    const LIMITS = [
        self::LOCAL   => [-128, 127],
        self::INDEX_0 => [0, 255],
        self::INDEX_1 => [0, 255],
        self::JUMP_8  => [-128, 127],
        self::JUMP_16 => [-32768, 32767],
        self::SMALL_8 => [-128, 127]
    ];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * OperandCaseMap
 *
 * Defines a set of distinct operand use cases that can be used to validate a set of operands to an instruction.
 */
class OperandCaseMap {

    private $aCaseMap = null;

    /**
     * Constructor, expects array of arrays of OperandKind values
     *
     * @param int[][] $aOperandCases
     */
    public function __construct(array $aOperandCases) {
        $this->aCaseMap = array_flip(
            array_map(
                [$this, 'caseToString'],
                $aOperandCases
            )
        );
    }

    /**
     * Checks if a given set of OperandKind values (in given order) are within the defined set of cases
     *
     * @param int[] $aOperandCase
     * @return bool
     */
    public function check(array $aOperandCase) : bool {
        return isset($this->aCaseMap[$this->caseToString($aOperandCase)]);
    }

    /**
     * Maps an Operand use case into a string
     *
     * @param int[] $aOperandCase
     * @return string
     */
    private function caseToString(array $aOperandCase) : string {
        return implode('-', $aOperandCase);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * IntegerExpressionParser interface
 */
interface IntegerExpressionParser {

    /**
     * Parse a string containing an integer expression into an integer value
     *
     * @param string $sExpression
     * @return int
     */
    public function parse(string $sExpression) : int;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/**
 * StackFramePositionParser
 *
 * Parses string expressions for stack frame positions
 */
class StackFramePositionParser implements IntegerExpressionParser {

    private $oIntExpressionParser;

    public function __construct() {
        $this->oIntExpressionParser = new ConstIntExpressionParser(
            OperandKind::LIMITS[OperandKind::LOCAL][0],
            OperandKind::LIMITS[OperandKind::LOCAL][1]
        );
    }

    /**
     * @implements IntegerExpressionParser::parse()
     */
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

/**
 * IndexOffsetParser
 *
 * Parses string expressions for index pointer offsets
 */
class IndexOffsetParser implements IntegerExpressionParser {

    private $iReg;
    private $oIntExpressionParser;

    public function __construct(int $iReg) {
        $this->iReg = $iReg;
        $this->oIntExpressionParser = new ConstIntExpressionParser(
            OperandKind::LIMITS[OperandKind::INDEX_0][0],
            OperandKind::LIMITS[OperandKind::INDEX_0][1]
        );
    }

    /**
     * @implements IntegerExpressionParser::parse()
     */
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

// TODO - use a Builder Pattern to generalise for other kinds

class ThreeOperandNonCommutativeParser {

    private $aParsers = [];
    private $oCaseMap = null;

    public function __construct() {
        $this->aParsers[OperandKind::LOCAL]   = new StackFramePositionParser();
        $this->aParsers[OperandKind::INDEX_0] = new IndexOffsetParser(0);
        $this->aParsers[OperandKind::INDEX_1] = new IndexOffsetParser(1);
        $this->oCaseMap = new OperandCaseMap([
            [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::LOCAL],   // LLL
            [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::LOCAL],   // ILL
            [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::INDEX_0], // LLI
            [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::INDEX_1], // ILI
            [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::LOCAL],   // LIL
            [OperandKind::INDEX_0, OperandKind::INDEX_1, OperandKind::LOCAL],   // IIL
            [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::INDEX_1], // LII
        ]);
    }

    public function parse(string $sExpression) {
        $aOperands = explode(',', preg_replace('/\s+/', '', $sExpression));
        $this->assertOperandCount($aOperands);
        $aKind = [];
        foreach ($aOperands as $i => $sOperand) {
            $aKind[$i] = $this->determineKind($sOperand);
        }
        $this->assertOperandUseCase($aKind);
        $aParsed = [];
        foreach ($aOperands as $i => $sOperand) {
            $aParsed[$i] = (object)[
                'iKind'   => $aKind[$i],
                'iValue'  => $this->aParsers[$aKind[$i]]->parse($sOperand),
                'sSource' => $sOperand
            ];
        }
        print_r($aParsed);
    }

    private function determineKind(string $sOperand) {
        if (!preg_match('/i(\d+)/', $sOperand, $aMatch)) {
            return OperandKind::LOCAL;
        }
        switch ($aMatch[1]) {
            case 0: return OperandKind::INDEX_0;
            case 1: return OperandKind::INDEX_1;
            default:
                throw new ParseException();
        }
    }

    private function assertOperandCount(array $aOperands) {
        if (count($aOperands) != 3) {
            throw new ParseException('Invalid Operand Count');
        }
    }

    private function assertOperandUseCase(array $aOperands) {
        if (!$this->oCaseMap->check($aOperands)) {
            throw new ParseException("Invalid Operand Use Case");
        }
    }
}

