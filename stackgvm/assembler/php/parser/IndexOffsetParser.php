<?php

/**
 * IndexOffsetParser
 *
 * Parses string expressions for index pointer offsets
 */
class IndexOffsetParser implements IntegerExpressionParser {

    private $iReg;
    private $oIntExpressionParser;

    public function __construct(int $iReg, ConstIntExpressionParser $oIntExpressionParser) {
        $this->iReg = $iReg;
        $this->oIntExpressionParser = $oIntExpressionParser;
    }

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sExpression) : int {
        $sSubExpression = $this->assertSyntax($sExpression);
        return $this->oIntExpressionParser->parse($sSubExpression);
    }

    private function assertSyntax(string $sExpression) {
        if (!preg_match(OperandKind::MATCH_INDEX, $sExpression, $aMatches)) {
            throw new ParseException("Malformed index offset '" . $sExpression. "', integer must be enclosed in parenthesis.");
        }
        if ($this->iReg != $aMatches[1]) {
            throw new RangeException("Wrong Index");
        }
        // Return the matched subexpression
        return $aMatches[2];
    }
}
