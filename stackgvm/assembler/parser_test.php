#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

$oParser = new OperandSetParser(
    new OperandCaseMap([
        "A" => [OperandKind::SYMBOL],
        "B" => [OperandKind::LABEL],
        "C" => [OperandKind::JUMP_16]
    ])
);

$aOperanExamples = [
    'helloWorld',
    '@helloWorld',
    '.helloWorld',
    '#32767'
];

foreach ($aOperanExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r($oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}

//$oLoader = new InstructionDefinitionLoader();
//print_r($oLoader->loadDefinition('config/arithmetic.json'));
