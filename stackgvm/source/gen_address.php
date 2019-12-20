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

const ADEBUGPRINTF = [
    'L'   => 'OPF_L',
    'I0'  => 'OPF_I0',
    'I1'  => 'OPF_I1',
    'I0X' => 'OPF_I0X',
    'I1X' => 'OPF_I1X',
    'R'   => 'OPF_R',
];

const ADEBUGVALUES = [
    'L'   => '(int8)pc[%d + OSIZE]',
    'I0'  => '(uint8)pc[%d + OSIZE]',
    'I1'  => '(uint8)pc[%d + OSIZE]',
    'I0X' => '(uint8)pc[%d + OSIZE], (int8)pc[%d + OSIZE]',
    'I1X' => '(uint8)pc[%d + OSIZE], (int8)pc[%d + OSIZE]',
    'R'   => '(int8)pc[%d + OSIZE], (uint8)pc[%d + OSIZE]',
];

const ADEBUPARMCOUNT = [
    'L'   => 1,
    'I0'  => 1,
    'I1'  => 1,
    'I0X' => 2,
    'I1X' => 2,
    'R'   => 2,
];

echo "// This file automatically generated. Do not edit.\n\n";

$aModes = [];
$aLines = explode("\n", file_get_contents('include/gvm_opcode_address.hpp'));
foreach($aLines as $sLine) {
    if (preg_match('/^\s*(_[LIR].*),/', $sLine, $aMatches)) {
        $aModes[] = trim($aMatches[1], '_');
    }
}

foreach ($aModes as $sMode) {
    $aOperands = explode('_', $sMode);
    echo "EA(", $sMode, ") {\n";
    echo "    // ",
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

    echo "    gvmDebugAddress(\n        ",
        implode(
            ' ", " ',
            array_map(
                function($sMode) {
                    return ADEBUGPRINTF[$sMode];
                },
                $aOperands
            )
        ),
        ",\n        ";


    $iOffset = 0;
    $aLines = [];
    foreach ($aOperands as $iOperand => $sMode) {
        switch (ADEBUPARMCOUNT[$sMode]) {
            case 1:
                $aLines[] = sprintf(ADEBUGVALUES[$sMode], $iOffset++);
                break;
            case 2:
                $aLines[] = sprintf(ADEBUGVALUES[$sMode], $iOffset++, $iOffset++);
                break;
        }
    }

    echo implode(",\n        ", $aLines), "\n    );\n";

    $iOperand = 1;
    $sOffset  = '0';

    foreach ($aOperands as $sOperand) {
        echo "    op", $iOperand++, " = ", $sOperand, "(", $sOffset, ");\n";
        $sOffset .= ' + ' . ASIZE[$sOperand];
    }

    echo
        "    return OSIZE + ",
        implode(
        ' + ',
            array_map(
                function($sMode) {
                    return ASIZE[$sMode];
                },
                $aOperands
            )
        ), ";\n";

    echo "}\n\n";
}
