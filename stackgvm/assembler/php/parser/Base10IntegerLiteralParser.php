<?php

/**
 * Base10IntegerLiteralParser
 *
 * Parses string expressions for base-10 integer literals
 */
class Base10IntegerLiteralParser implements IntegerExpressionParser {

    /** @var ConstIntExpressionParser $oIntExpressionParser */
    private $oIntExpressionParser;

    /** @var string $sMatch */
    private $sMatch;

    /**
     * Constructor
     *
     * @param ConstIntExpressionParser $oIntExpressionParser
     */
    public function __construct(ConstIntExpressionParser $oIntExpressionParser) {
        $this->oIntExpressionParser = $oIntExpressionParser;
        $this->sMatch = "/^\s*" . OperandKind::BASE_10_LITERAL_PREFIX . "{1}(.*?)\s*$/";
    }

    /**
     * @implements IntegerExpressionParser::parse()
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
        if (!preg_match($this->sMatch, $sExpression, $aMatches)) {
            throw new ParseException("Malformed integer literal '" . $sExpression. "'");
        }
        return $aMatches[1];
    }
}
