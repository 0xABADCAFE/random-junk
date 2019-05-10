<?php

/**
 * OperandKindParser
 *
 * Parses an expression to determine the OperandKind enumeration
 *
 * TODO - improve and generalise this, right now it's an ugly, hacky thin.g
 */
class OperandKindParser implements Parser {

    // An operand can not be more than one of the following kinds
    const MUTUALLY_EXCLUSIVE_KINDS = [
        OperandKind::BITPOS,
        OperandKind::SMALL_S8,
        OperandKind::SMALL_U8,
        OperandKind::JUMP_8,
        OperandKind::JUMP_16
    ];

    const INDIR_MAPPED = [
        0 => OperandKind::INDIR_0,
        1 => OperandKind::INDIR_1
    ];

    const IDX_PH_MAPPED = [
        0 => OperandKind::IDX_0_PH,
        1 => OperandKind::IDX_1_PH
    ];

    private $iDefaultBase10Kind = OperandKind::SMALL_S8;

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
     * @implements OperandParser::parse()
     */
    public function parse(string $sOperand) : int {
        if (preg_match(OperandKind::MATCH_BASE_10, $sOperand, $aMatch)) {
            return $this->iDefaultBase10Kind;
        }

        if (preg_match(OperandKind::MATCH_LABEL, $sOperand)) {
            return OperandKind::LABEL;
        }

        if (preg_match(OperandKind::MATCH_DATA_SYM, $sOperand)) {
            return OperandKind::DATA_SYM;
        }

        if (preg_match(OperandKind::MATCH_CODE_SYM, $sOperand)) {
            return OperandKind::CODE_SYM;
        }

        if (preg_match(OperandKind::MATCH_IDX, $sOperand, $aMatch)) {
            if (isset(self::IDX_PH_MAPPED[$aMatch[1]])) {
                return self::IDX_PH_MAPPED[$aMatch[1]];
            }
            throw new ParseException("Invalid idx register spec: " . $aMatch[1]);
        }

        if (!preg_match('/i(\d+)/', $sOperand, $aMatch)) {
            return OperandKind::LOCAL;
        }

        switch ($aMatch[1]) {
            case 0: return OperandKind::INDIR_0;
            case 1: return OperandKind::INDIR_1;
            default:
                throw new ParseException();
        }
    }
}
