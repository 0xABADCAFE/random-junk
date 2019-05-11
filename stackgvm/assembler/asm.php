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

require_once('php/assembler/Assembler.php');

$oAssebler = new Assembler(
    new SourceLoader(
        new Project('example/project.json')
    ),
    LineParserFactory::get()
);
$oAssebler->assemble();
