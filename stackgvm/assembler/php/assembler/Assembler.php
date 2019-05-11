<?php

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
        $oLineParserFactory
    ;

    public function __construct(SourceLoader $oLoader, LineParserFactory $oLineParserFactory) {
        $this->oSourceLoader      = $oLoader;
        $this->oLineParserFactory = $oLineParserFactory;
    }

    public function assemble() {
        $aSources = $this->oSourceLoader
            ->load()
            ->getSource();

        $oLineParser = $this->oLineParserFactory->getParser(LineKind::KIND);

        foreach ($aSources as $sFile => $aLines) {
            echo $sFile, ":\n";
            foreach ($aLines as $iNum => $sLine) {
                $iKind = $oLineParser->parse($sLine);
                printf(
                    "\t%02d %-40s\n\n\t\t%s:",
                    $iNum,
                    $sLine,
                    self::LINE_KIND_NAMES[
                        $oLineParser->parse($sLine)
                    ]
                );
                echo str_replace(
                    "\n", "\n\t\t",
                    ("\n" .
                        print_r(
                            $this->oLineParserFactory
                                ->getParser($iKind)
                                ->parse($sLine),
                            1
                        )
                    )
                ), "\n";
            }
        }
    }
}
