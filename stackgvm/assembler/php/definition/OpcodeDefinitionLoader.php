<?php

/**
/**
 * InstructionDefinitionLoader
 *
 * Loads a set of instruction definitions from an external JSON definition file and uses them to parameterise a set
 * of OperandSetParsers for each defined instruction mnemonic,
 */
class OpcodeDefinitionLoader {

    /**
     * @param string $sPath
     * return OperandSetParser[][]
     */
    public function loadDefinition(string $sPath) {
        if (
            !file_exists($sPath) ||
            !is_readable($sPath) ||
            !($sData = file_get_contents($sPath)) ||
            empty($sData)
        ) {
            throw new Exception("Unable to read definition file " . $sPath);
        }
        return $this->processDefinitons($sData);
    }


    private function processDefinitons(string $sData) {
        $oDefinition = json_decode($sData);
        if (empty($oDefinition)) {
            throw new Exception("No definitions found in definition file");
        }
        return (array)$oDefinition;
    }


}

