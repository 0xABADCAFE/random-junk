#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

$oParser = new OperandSetParser(
    new OperandCaseMap([
        "_CALL" => [OperandKind::SYMBOL],
    ])
);

$aOperanExamples = [
    '@helloWorld',
    'helloWorld',
    '.helloWorld'
];

foreach ($aOperanExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r($oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
        throw $oError;
    }
}

//$oLoader = new InstructionDefinitionLoader();
//print_r($oLoader->loadDefinition('config/arithmetic.json'));
