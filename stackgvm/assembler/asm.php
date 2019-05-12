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


LineParserFactory::get()->getParser(LineKind::INSTRUCTION)->importDefinitions(
    'config/opcode.json',
    [
        'config/flow.json',
        'config/move.json',
        'config/arithmetic.json',
        'config/logic.json'
    ]
);

require_once('php/assembler/Assembler.php');

$oAssebler = new Assembler(
    new SourceLoader(
        new Project('example/project.json')
    ),
    LineParserFactory::get()
);
$oAssebler->assemble();
