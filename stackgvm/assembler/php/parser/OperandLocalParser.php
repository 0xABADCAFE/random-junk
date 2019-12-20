<?php

/**
 * StackFramePositionParser
 *
 * Parses string expressions for stack frame positions
 */
class OperandLocalParser implements Parser {

    /** @var ConstIntExpressionParser $oIntExpressionParser */
    private $oIntExpressionParser;

    public function __construct(ConstIntExpressionParser $oIntExpressionParser) {
        $this->oIntExpressionParser = $oIntExpressionParser;
    }

    /**
     * @implements OperandParser::parse()
     */
    public function parse(string $sExpression) : int {
        return $this->oIntExpressionParser->parse($this->assertSyntax($sExpression));
    }

    private function assertSyntax(string $sExpression) {
        if (!preg_match(OperandKind::MATCH_LOCAL, $sExpression, $aMatches)) {
            throw new ParseException("Malformed stack position '" . $sExpression. "', integer expression must be enclosed in braces.");
        }
        return $aMatches[1];
    }
}
