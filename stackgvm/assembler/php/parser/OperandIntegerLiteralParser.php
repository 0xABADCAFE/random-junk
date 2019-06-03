<?php

/**
 * Base10IntegerLiteralParser
 *
 * Parses string expressions for base-10 integer literals
 */
class OperandIntegerLiteralParser implements Parser {

    /** @var ConstIntExpressionParser $oIntExpressionParser */
    private $oIntExpressionParser;

    /**
     * Constructor
     *
     * @param ConstIntExpressionParser $oIntExpressionParser
     */
    public function __construct(ConstIntExpressionParser $oIntExpressionParser) {
        $this->oIntExpressionParser = $oIntExpressionParser;
    }

    /**
     * @implements OperandParser::parse()
     */
    public function parse(string $sExpression) : int {
        return $this->oIntExpressionParser->parse($this->assertSyntax($sExpression));
    }

    /**
     * @param string $sExpression
     * @return string
     * @throws ParseException
     */
    private function assertSyntax(string $sExpression) {
        if (!preg_match(OperandKind::MATCH_BASE_10, $sExpression, $aMatches)) {
            throw new ParseException("Malformed integer literal '" . $sExpression. "'");
        }
        return $aMatches[1];
    }
}
