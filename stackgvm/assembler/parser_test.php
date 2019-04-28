#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

echo "OperandSetParser test\n";

$aThreeOperandExamples = [
    '(0), (0), (1)',
    '(i0 + 2), (0), (i1 + 2)',
    '(i0 + 2), (3), (i1 + (5 + (7*2) ) )',
    '(i0 + 1), (i0 + 2), (i1 + 3)'
];

$oParser = new OperandSetParser(new OperandCaseMap([
    [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::LOCAL],   // LLL
    [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::LOCAL],   // ILL
    [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::INDEX_0], // LLI
    [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::INDEX_1], // ILI
    [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::LOCAL],   // LIL
    [OperandKind::INDEX_0, OperandKind::INDEX_1, OperandKind::LOCAL],   // IIL
    [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::INDEX_1], // LII
]));
foreach ($aThreeOperandExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r( $oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}
