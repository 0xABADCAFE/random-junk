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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const LINE_KIND_NAMES = [
    LineKind::BLANK       => "Blank",
    LineKind::LABEL       => "Label",
    LineKind::CODE_SYMBOL => "Function Definition",
    LineKind::DATA_SYMBOL => "Data Definition",
    LineKind::INSTRUCTION => "Instruction"
];

$oLineParser = new LineKindParser();
$aSources = (new SourceLoader(new Project('example/project.json')))
    ->load()
    ->getSource();

foreach ($aSources as $sFile => $aLines) {
    echo $sFile, ":\n";
    foreach ($aLines as $iNum => $sLine) {
        printf("\t%2d %-40s -> %s\n", $iNum, $sLine, LINE_KIND_NAMES[$oLineParser->parse($sLine)]);
    }
}
