<?php


/**
 * OperandCaseMap
 *
 * Defines a set of distinct operand use cases that can be used to validate a set of operands to an instruction.
 */
class OperandCaseMap {

    private
        $aCaseMap     = [],
        $iMinOperands = 0,
        $iMaxOperands = 0,
        $aParsers     = []
    ;

    /**
     * Constructor, expects array of arrays of OperandKind values
     *
     * @param int[][] $aOperandCases
     */
    public function __construct(array $aOperandCases) {
        $aCount = array_map('count', $aOperandCases);
        $this->iMinOperands = min($aCount);
        $this->iMaxOperands = max($aCount);
        $this->aCaseMap = array_flip(
            array_map(
                [$this, 'caseToString'],
                $aOperandCases
            )
        );
        $aDistinct = [];
        foreach ($aOperandCases as $aOperandCase) {
            foreach ($aOperandCase as $i) {
                $aDistinct[$i] = $i;
            }
        }

        foreach ($aDistinct as $i) {
            $this->aParsers[$i] = OperandParserFactory::get()->getParser($i);
        }
    }

    /**
     * @return int
     */
    public function getMinOperandCount() : int {
        return $this->iMinOperands;
    }

    /**
     * @return int
     */
    public function getMaxOperandCount() : int {
        return $this->iMaxOperands;
    }

    /**
     * @return Parser[]
     */
    public function getParsers() : array {
        return $this->aParsers;
    }

    /**
     * @return int[]
     */
    public function getKinds() : array {
        return array_keys($this->aParsers);
    }

    /**
     * Checks if a given set of OperandKind values (in given order) are within the defined set of cases
     * and returns the associated opcode name for the use case.
     *
     * @param int[] $aOperandCase
     * @return string
     * @throws InvalidArgumentException
     */
    public function getOperandForCase(array $aOperandCase) : string {
        $sCase = $this->caseToString($aOperandCase);
        if (isset($this->aCaseMap[$sCase])) {
            return $this->aCaseMap[$sCase];
        }
        throw new InvalidArgumentException("Invalid Operand Case " . implode(",", $aOperandCase));
    }

    /**
     * Maps an Operand use case into a string
     *
     * @param int[] $aOperandCase
     * @return string
     */
    private function caseToString(array $aOperandCase) : string {
        $this->assertValid($aOperandCase);
        return implode('-', $aOperandCase);
    }

    /**
     * Assert that a set of operand kind is legal
     *
     * @param int[] $aOperandCase
     * @throw InvalidArgumentException
     */
    private function assertValid(array $aOperandCase) {
        foreach ($aOperandCase as $iCase) {
            if (
                !is_int($iCase) ||
                $iCase < OperandKind::MIN ||
                $iCase > OperandKind::MAX
            ) {
                throw new InvalidArgumentException();
            }
        }
    }
}
