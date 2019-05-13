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

$oAssebler = new Assembler(
    new SourceLoader(
        new Project('example/project.json')
    ),
    LineParserFactory::get(),
    AssemblerLineProcessingState::create()
);
$oAssebler->assemble();
