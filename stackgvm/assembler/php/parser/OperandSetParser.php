<?php

/**
 * OperandSetParser
 *
 * Given an input OperandCaseMap, translates a comma separated operand string into a the expected opcode and operand
 * data suitable for the next stage of processing.
 */
class OperandSetParser {

    private $oCaseMap    = null;
    private $oKindParser = null;

    public function __construct(OperandCaseMap $oCaseMap) {
        $this->oCaseMap    = $oCaseMap;
        $this->oKindParser = OperandParserFactory::get()->getParser(OperandKind::KIND);
        $this->oKindParser->setKinds($this->oCaseMap->getKinds());
    }

    public function parse(string $sExpression) {
        $aOperands = explode(',', preg_replace('/\s+/', '', $sExpression));
        $this->assertOperandCount($aOperands);
        $aKind = [];
        foreach ($aOperands as $i => $sOperand) {
            $aKind[$i] = $this->oKindParser->parse($sOperand);
        }
        $sOpcode = $this->oCaseMap->getOperandForCase($aKind);
        $aParsed = [];
        $aParsers = $this->oCaseMap->getParsers();
        foreach ($aOperands as $i => $sOperand) {
            $aParsed[$i] = new Operand(
                $aKind[$i],
                $aParsers[$aKind[$i]]->parse($sOperand),
                $sOperand
            );
        }
        return (object)[
            "opcode"   => $sOpcode,
            "operands" => $aParsed
        ];
    }

    private function assertOperandCount(array $aOperands) {
        $iOperandCount = count($aOperands);
        $iMinOperands  = $this->oCaseMap->getMinOperandCount();
        $iMaxOperands  = $this->oCaseMap->getMaxOperandCount();
        if ($iOperandCount < $iMinOperands || $iOperandCount > $iMaxOperands) {
            throw new ParseException(sprintf(
                "Invalid operand count %d, expected %d - %d",
                $iOperandCount,
                $iMinOperands,
                $iMaxOperands
            ));
        }
    }

}

