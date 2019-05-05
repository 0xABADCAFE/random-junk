<?php

/**
 * OperandKindParser
 *
 * Parses an expression to determine the OperandKind enumeration
 *
 * TODO - improve and generalise this, right now it's an ugly, hacky thin.g
 */
class OperandKindParser implements IntegerExpressionParser {

    // An operand can not be more than one of the following kinds
    const MUTUALLY_EXCLUSIVE_KINDS = [
        OperandKind::BITPOS,
        OperandKind::SMALL_8,
        OperandKind::JUMP_8,
        OperandKind::JUMP_16
    ];

    private $iDefaultBase10Kind = OperandKind::SMALL_8;

    public function setKinds(array $aKinds) {
        $aDistinct = array_intersect($aKinds, self::MUTUALLY_EXCLUSIVE_KINDS);
        switch (count($aDistinct)) {
            case 0:
                break;
            case 1:
                $this->iDefaultBase10Kind = (int)reset($aDistinct);
                break;
            default:
                throw new Exception();
        }
    }

    /**
     * @implements IntegerExpressionParser::parse()
     */
    public function parse(string $sOperand) : int {
        if (preg_match(OperandKind::MATCH_BASE_10, $sOperand, $aMatch)) {
            return $this->iDefaultBase10Kind;
        }

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
