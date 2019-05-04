#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

echo "Testing non commutative triple operand set\n";

$oParser = new OperandSetParser(new OperandCaseMap([
    40 => [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::LOCAL],   // LLL
    41 => [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::LOCAL],   // ILL
    42 => [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::INDEX_0], // LLI
    43 => [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::INDEX_1], // ILI
    44 => [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::LOCAL],   // LIL
    45 => [OperandKind::INDEX_0, OperandKind::INDEX_1, OperandKind::LOCAL],   // IIL
    46 => [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::INDEX_1], // LII
]));

$aThreeOperandExamples = [
    '(0), (0), (1)',
    '(i0 + 2), (0), (i1 + 2)',
    '(i0 + 2), (3), (i1 + (5 + (7*2) ) )',
    '(i0 + 1), (i0 + 2), (i1 + 3)'
];

foreach ($aThreeOperandExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r($oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}

echo "Testing two operand with 16-bit signed offset\n";

$oParser = new OperandSetParser(new OperandCaseMap([
    100 => [OperandKind::LOCAL,   OperandKind::LOCAL,   OperandKind::JUMP_16], // LLJ
    101 => [OperandKind::INDEX_0, OperandKind::LOCAL,   OperandKind::JUMP_16], // ILJ
    102 => [OperandKind::LOCAL,   OperandKind::INDEX_0, OperandKind::JUMP_16], // LIJ
    103 => [OperandKind::INDEX_0, OperandKind::INDEX_1, OperandKind::JUMP_16], // ILJ
]));

$aThreeOperandExamples = [
    '(0), (0), #-32768',
    '(i0 + 7), (100), #(1<<4)&((1<<15)-1)',
    '(i0 + 4%3), (1 < 2 ? 10 : 20), #0'
];

foreach ($aThreeOperandExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r($oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
        throw $oError;
    }
}
