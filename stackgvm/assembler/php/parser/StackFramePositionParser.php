<?php

/**
 * StackFramePositionParser
 *
 * Parses string expressions for stack frame positions
 */
class StackFramePositionParser implements IntegerExpressionParser {

    /** @var ConstIntExpressionParser $oIntExpressionParser */
    private $oIntExpressionParser;

    public function __construct(ConstIntExpressionParser $oIntExpressionParser) {
        $this->oIntExpressionParser = $oIntExpressionParser;
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
