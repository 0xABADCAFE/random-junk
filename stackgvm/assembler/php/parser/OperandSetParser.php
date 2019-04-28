<?php

/**
 * OperandSetParser
 */
class OperandSetParser {

    private $oCaseMap = null;

    public function __construct(OperandCaseMap $oCaseMap) {
        $this->oCaseMap = $oCaseMap;
    }

    public function parse(string $sExpression) {
        $aOperands = explode(',', preg_replace('/\s+/', '', $sExpression));
        $this->assertOperandCount($aOperands);
        $aKind = [];
        foreach ($aOperands as $i => $sOperand) {
            $aKind[$i] = $this->determineKind($sOperand);
        }
        $this->assertOperandUseCase($aKind);
        $aParsed = [];
        $aParsers = $this->oCaseMap->getParsers();
        foreach ($aOperands as $i => $sOperand) {
            $aParsed[$i] = (object)[
                'iKind'   => $aKind[$i],
                'iValue'  => $aParsers[$aKind[$i]]->parse($sOperand),
                'sSource' => $sOperand
            ];
        }
        return $aParsed;
    }

    private function determineKind(string $sOperand) {
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

    private function assertOperandUseCase(array $aOperands) {
        if (!$this->oCaseMap->check($aOperands)) {
            throw new ParseException("Invalid Operand Use Case");
        }
    }
}

