<?php

/**
/**
 * AliasDefinitionLoader
 *
 * Loads a set of alias menomics that map to other mnemonics with permuted operands. This allows us to expand the
 * native branch on greater/equal, branch on greater than into the full set of less/equal, less than by choosing the
 * appropriate mirror operation and swapping the compared parameters.
 *
 * We also allow for a complete reversal of the "branch if" through a set of "continue if" aliases.
 */
class AliasDefinitionLoader {

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

