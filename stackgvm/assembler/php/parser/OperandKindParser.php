<?php

/**
 * OperandKindParser
 *
 * Parses an expression to determine the OperandKind enumeration
 */
class OperandKindParser implements IntegerExpressionParser {

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sOperand) : int {
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
}
