#!/usr/bin/php
<?php

foreach (glob('php/*.php') as $sInclude) {
    require_once($sInclude);
}

echo "Stack Frame Position Parser Test\n";

$oParser = new StackFramePositionParser();
$aStackFrameExamples = [
    '', ' ', '()', '( )', '0', '1', '((1 )', '(1))',
    '(0)', ' ( 0 ) ', '(1)',
    '(-128 - 1)', '(127 + 2 - 2*1)',
    '(1 + 7-2)', '(1 + (7) - (2*3) )',
];

foreach ($aStackFrameExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        echo $oParser->parse($sExample), "\n";
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}

echo "Index Offset Parser Test\n";

$oParser = new IndexOffsetParser(0);
$aIndexOffsetExamples = [
    '', '()', '(i0)',
    '(i0 + 0)', '(i0 - 1)', '(i0 + 255 + 1)', '(i1 + 1)',
    '(i0 - 1 + 256 - 3*16)', '(i0 - (2 * (5 + 256) - 3) + 270 + 256)'
];

foreach ($aIndexOffsetExamples as $sExample) {
    echo "\tParsing '", $sExample, "' => ";
    try {
        echo $oParser->parse($sExample), "\n";
    } catch (Exception $oError) {
        echo get_class($oError), " - ", $oError->getMessage(), "\n";
    }
}
