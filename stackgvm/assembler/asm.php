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

(new SourceLoader(new Project('example/project.json')))
    ->load()
    ->dump();
