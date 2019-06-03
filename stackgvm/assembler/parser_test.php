#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

$oParser = new OperandSetParser(
    new OperandCaseMap([
        "A" => [],
    ])
);

print_r($oParser);

$aOperanExamples = [
    '',
];

foreach ($aOperanExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        print_r($oParser->parse($sExample));
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}

