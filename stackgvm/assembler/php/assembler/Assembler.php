<?php

/**
 * Assembler class
 */
class Assembler {

    const LINE_KIND_NAMES = [
        LineKind::BLANK       => "Blank",
        LineKind::LABEL       => "Label",
        LineKind::CODE_SYMBOL => "Function Definition",
        LineKind::DATA_SYMBOL => "Data Definition",
        LineKind::INSTRUCTION => "Instruction"
    ];

    private
        $oSourceLoader,
        $oLineParserFactory,
        $oLineProcessingState,
        $sBuffer,
        $iPosition
    ;

    public function __construct(
        SourceLoader $oLoader,
        LineParserFactory $oLineParserFactory,
        AssemblerLineProcessingState $oLineProcessingState
    ) {
        $this->oSourceLoader        = $oLoader;
        $this->oLineParserFactory   = $oLineParserFactory;
        $this->oLineProcessingState = $oLineProcessingState;
    }

    public function assemble() {
        $this->initBinaryBuffer();
        $aSources = $this->oSourceLoader
            ->load()
            ->getSource();
        $oLineParser = $this->oLineParserFactory->getParser(LineKind::KIND);

        foreach ($aSources as $sFile => $aLines) {
            echo $sFile, ":\n";
            $this->oLineProcessingState = $this->oLineProcessingState->reset();

            try {
                foreach ($aLines as $iNum => $sLine) {
                    $iKind = $oLineParser->parse($sLine);

                    $this->oLineProcessingState = $this->oLineProcessingState->getStateForLineKind($iKind);

                    $oResult = $this->oLineParserFactory
                        ->getParser($iKind)
                        ->parse($sLine);

                    if ($iKind == LineKind::INSTRUCTION) {
                        print_r($oResult);
                        $this->iPosition++;
                        foreach ($oResult->aOperands as $oOperand) {
                            $this->iPosition += $oOperand->iSize;
                        }
                    }
                }
            } catch (Exception $oError) {
                echo "Caught unexpected ", get_class($oError), " - ", $oError->getMessage(), ". Aborting file.\n";
            }
        }
    }

    private function initBinaryBuffer() {
        $this->sBuffer   = '';
        $this->iPosition = 0;
    }
}
