<?php

/**
 * Assembler class
 *
 * Main process, coordinates the conversion of source to opcode.
 */
class Assembler {

    private
        /** @var SourceLoader $oSourceLoader */
        $oSourceLoader,

        /** @var LineParserFactory $oLineParserFactory */
        $oLineParserFactory,

        /** @var AssemblerLineProcessingState $oLineProcessingState */
        $oLineProcessingState,

        /** @var string $sBuffer */
        $sBuffer,

        /** @var int $iPosition */
        $iPosition
    ;

    public function __construct(
        AssemblerConfig $oConfig,
        SourceLoader $oLoader
    ) {
        $this->oSourceLoader        = $oLoader;
        $this->oLineParserFactory   = $oConfig->getLineParserFactory();
        $this->oLineProcessingState = $oConfig->getLineProcessingState();
    }

    /**
     * Main entry point.
     */
    public function assemble() {
        $this->initBinaryBuffer();
        $aSources = $this->oSourceLoader
            ->load()
            ->getSource();
        $oLineParser = $this->oLineParserFactory->getParser(LineKind::KIND);

        foreach ($aSources as $sFile => $aLines) {
            echo $sFile, "\n";
            $this->oLineProcessingState = $this->oLineProcessingState->reset();

            try {
                foreach ($aLines as $iNum => $sLine) {
                    $iKind = $oLineParser->parse($sLine);
                    $this->oLineProcessingState = $this->oLineProcessingState->getStateForLineKind($iKind);
                    $oResult = $this->oLineParserFactory
                        ->getParser($iKind)
                        ->parse($sLine);

                    if ($iKind == LineKind::INSTRUCTION) {
                        $this->processInstruction($oResult, $sLine);
                    }
                }
            } catch (Exception $oError) {
                echo "\nCaught unexpected ", get_class($oError), " - ", $oError->getMessage(), ". Aborting file.\n";
            }
        }
    }

    private function processInstruction($oInstruction, string $sLine) {
        $aBytes = [$oInstruction->oOpcode->iByte];
        foreach ($oInstruction->aOperands as $oOperand) {
            $aBytes = array_merge($aBytes, $oOperand->aBytes);
        }

        printf("\t%3d %-60s -> %s\n", $this->iPosition, $sLine, json_encode($aBytes));

        $this->iPosition += count($aBytes);
    }

    private function initBinaryBuffer() {
        $this->sBuffer   = '';
        $this->iPosition = 0;
    }
}
