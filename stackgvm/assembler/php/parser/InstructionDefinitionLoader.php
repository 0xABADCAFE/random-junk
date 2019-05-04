<?php

/**
 *
 */
class InstructionDefinitionLoader {

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
        print_r($oDefinition);
        $aResult = [];

        foreach($oDefinition as $sMnemonic => $aOperandData) {
            $sMnemonic = strtolower(trim($sMnemonic));
            $aResult[$sMnemonic] = $this->processDefinition($aOperandData);
        }
        return $aResult;
    }

    /**
     * Each mnemonic may map to more than one actual instruction definition. For example, "load" will have map to
     * variants that have quite different use case semantics. We process the raw object data into the appropriate
     * OperandCaseMap instances and return them.
     *
     * This is all done using in the following orgy of closures and array mapping.
     */
    private function processDefinition(array $aOperandData) {
        return array_map(
            // Convert each variant into an OperandCaseMap instance
            function ($oOperandData) {
                // Instantiate an OperandCaseMap for the described use cases
                return new OperandCaseMap(
                    array_map(
                        // Transform the array of strings into the corresponding array of constant integer
                        // operand types.
                        function (array $aKinds) {
                            return array_map(
                                // Transform the single string into it's corresponding constant integer operand type.
                                function (string $sKind) {
                                    // Sanitise string and check it has an integer mapped value
                                    $sKind = strtoupper(trim($sKind));
                                    if (isset(OperandKind::MAPPED[$sKind])) {
                                        return OperandKind::MAPPED[$sKind];
                                    }
                                    throw new Exception("Invalid OperandKind " . $sKind);
                                },
                                $aKinds
                            );
                        },
                        (array)$oOperandData
                    )
                );
            },
            $aOperandData
        );


    }
}

