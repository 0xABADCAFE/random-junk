#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

/*
$aOptions = getopt(
    '',
    [
        'srcdir:',
        'incdir:'
    ]
);
*/

//$oLoader = new InstructionDefinitionLoader();
//print_r($oLoader->loadDefinition('config/arithmetic.json'));

LineParserFactory::get()->getParser(LineKind::INSTRUCTION)->importDefinitions([
    'config/flow.json',
    'config/move.json',
    'config/arithmetic.json',
    'config/logic.json'
]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const LINE_KIND_NAMES = [
    LineKind::BLANK       => "Blank",
    LineKind::LABEL       => "Label",
    LineKind::CODE_SYMBOL => "Function Definition",
    LineKind::DATA_SYMBOL => "Data Definition",
    LineKind::INSTRUCTION => "Instruction"
];

$aSources = (new SourceLoader(new Project('example/project.json')))
    ->load()
    ->getSource();

$oLineParser = LineParserFactory::get()->getParser(LineKind::KIND);

foreach ($aSources as $sFile => $aLines) {
    echo $sFile, ":\n";
    foreach ($aLines as $iNum => $sLine) {
        $iKind = $oLineParser->parse($sLine);
        printf("\t%02d %-40s\n\n\t\t%s:", $iNum, $sLine, LINE_KIND_NAMES[$oLineParser->parse($sLine)]);
        echo str_replace(
            "\n", "\n\t\t",
            ("\n" . print_r(LineParserFactory::get()->getParser($iKind)->parse($sLine),1))
        ), "\n";
    }
}
