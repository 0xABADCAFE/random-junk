<?php

/**
 * LineKindParser
 *
 */
class OperandKindParser implements IntegerExpressionParser {

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sLine) : int {
        if (empty($sLine) {
            return LineKind::BLANK;
        }
        foreach (self::MATCHED as $sMatch => $iKind) {
            if (preg_match($sMatch, $sLine)) {
                return $iKind;
            }
        }
        throw new ParseException()
    }
}
