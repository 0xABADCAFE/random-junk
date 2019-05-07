<?php

/**
 * LineKindParser
 *
 */
class LineKindParser implements IntegerExpressionParser {

    const MATCHED = [
        LineKind::MATCH_INSTRUCTION => LineKind::INSTRUCTION,
        LineKind::MATCH_LABEL       => LineKind::LABEL,
        LineKind::MATCH_CODE_SYMBOL => LineKind::CODE_SYMBOL,
        LineKind::MATCH_DATA_SYMBOL => LineKind::DATA_SYMBOL
    ];

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sLine) : int {
        if (empty($sLine)) {
            return LineKind::BLANK;
        }
        foreach (self::MATCHED as $sMatch => $iKind) {
            if (preg_match($sMatch, $sLine)) {
                return $iKind;
            }
        }
        throw new ParseException("Could not determine line kind '" . $sLine . "'");
    }
}
