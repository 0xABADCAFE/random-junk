<?php

// php gen_address.php > include/gvm_adress_modes.hpp

const ASIZE = [
    'L'   => 'LSIZE',
    'I0'  => 'ISIZE',
    'I1'  => 'ISIZE',
    'I0X' => 'ISIZE',
    'I1X' => 'ISIZE',
    'R'   => 'RSIZE',
];

const AANNOTATE = [
    'L'   => 'local',
    'I0'  => 'i0[const uint8]',
    'I1'  => 'i1[const uint8]',
    'I0X' => 'i0[local int32]',
    'I1X' => 'i1[local int32]',
    'R'   => 'local[const uint8]',
];

echo "        // This file automatically generated. Do not edit.\n\n";

$aModes = [];
$aLines = explode("\n", file_get_contents('include/gvm_opcode_address.hpp'));
foreach($aLines as $sLine) {
    if (preg_match('/^\s*(_[LIR].*),/', $sLine, $aMatches)) {
        $aModes[] = trim($aMatches[1], '_');
    }
}

foreach ($aModes as $sMode) {
    $aOperands = explode('_', $sMode);
    echo "        EA(", $sMode, ") {\n";
    echo "            // ",
        implode(
            ', ',
            array_map(
                function($sMode) {
                    return AANNOTATE[$sMode];
                },
                $aOperands
            )
        ),
        "\n";
    $iOperand = 1;
    $sOffset  = '0';

    foreach ($aOperands as $sOperand) {
        echo "            op", $iOperand++, " = ", $sOperand, "(", $sOffset, ");\n";
        $sOffset .= ' + ' . ASIZE[$sOperand];
    }

    echo
        "            return OSIZE + ",
        implode(
        ' + ',
            array_map(
                function($sMode) {
                    return ASIZE[$sMode];
                },
                $aOperands
            )
        ), ";\n";

    echo "        }\n\n";
}
