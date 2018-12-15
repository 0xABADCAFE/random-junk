<?php

$aInstMatch = array_flip([
    'hcf',
    'bras\s+(-)?\d+',
    'bra\s+(-)?\d+',
    'bcall\s+(-)?\d+',
    'call\s+\d+',
    'icall\s+\d+',
    'icall\s+\d+\(i0\)',
    'hcall\s+\d+',
    'ret',

    'move\s+(-)?\d+\s*,\s*i0',
    'move\s+(-)?\d+\s*,\s*i1',
    'move\s+(-)?\d+\s*,\s*i2',

    'move\s+(-)?\d+\s*,\s*(-)?\d+',
    'move\s+\d+\(i0\)\s*,\s*(-)?\d+',
    'move\s+(-)?\d+\s*,\s*\d+\(i0\)',
    'move\s+\d+\(i0\)\s*,\s*\d+\(i1\)',

    'bez\s+(-)?\d+\s*,\s*(-)?\d+',
    'bez\s+\d+\(i0\)\s*,\s*(-)?\d+',

    'bnz\s+(-)?\d+\s*,\s*(-)?\d+',
    'bnz\s+\d+\(i0\)\s*,\s*(-)?\d+',
]);

$aLines = explode("\n", file_get_contents("test.asm"));

foreach ($aLines as $i => $sLine) {
    $sLine2 = preg_replace('/\s+;.*?$/', '', $sLine);
    echo $sLine, "\n";
    foreach ($aInstMatch as $sMatch => $iOpcode) {
        $sRegex = '/^\s+' . $sMatch . '\s*$/';
        //echo $sRegex, "\n";
        if (preg_match($sRegex, $sLine2)) {
            echo "\t", $i, " -> ", $iOpcode, "\n";
        }
    }
}
