<?php

class LineInstructionParser implements Parser {

    private
        $aOpcodeDefs  = [],
        $aOperandSets = [],
        $aAliases     = []
    ;

    public function importDefinitions(string $sOpcodeDefinition, array $aDefinitions, array $aAliasDefinitions) {
        $oLoader = new OpcodeDefinitionLoader();
        $this->aOpcodeDefs = $oLoader->loadDefinition($sOpcodeDefinition);
        $this->aOperandSetParsers = [];
        $oLoader = new InstructionDefinitionLoader();
        foreach ($aDefinitions as $sDefinitionPath) {
            $this->aOperandSetParsers += $oLoader->loadDefinition($sDefinitionPath);
        }
        $this->aAliases = [];
        $oLoader = new AliasDefinitionLoader();
        foreach ($aAliasDefinitions as $sDefinitionPath) {
            $this->aAliases += $oLoader->loadDefinition($sDefinitionPath);
        }

    }

    public function parse(string $sLine) {
        if (!preg_match(LineKind::MATCH_INSTRUCTION, $sLine, $aMatches)) {
            throw new ParseException();
        }

        $sMnemonic = strtolower($aMatches[1]);
        $sOperands = trim(str_replace($aMatches[1], '', $sLine));

        // Try to use an aliased mnemonic interpretation first. This will return null if there is no such alias or
        // if there are no operand use cases for the aliased version.
        $oParsed = $this->attemptAliasedMnemonic($sMnemonic, $sOperands);
        if ($oParsed) {
            return $oParsed;
        }

        // Try to ue a non-aliased mnemonic.
        $oParsed = $this->attemptDirectMnemonic($sMnemonic, $sOperands);
        if ($oParsed) {
            return $oParsed;
        }
        throw new ParseException("Unknown or unimplemented instruction");
    }

    private function attemptAliasedMnemonic(string $sMnemonic, string $sOperands) {
        // If the mnemonic matches an alias, then we have some shuffling to do
        if (isset($this->aAliases[$sMnemonic])) {
            $oAlias = $this->aAliases[$sMnemonic];
            $sMnemonic = $oAlias->alias;
            $aOpBefore = explode(',', $sOperands);
            $aOpAfter  = [];
            foreach ($oAlias->permute as $iTo => $iFrom) {
                $aOpAfter[$iTo] = $aOpBefore[$iFrom];
            }
            $sOperands = implode(',', $aOpAfter);
            return $this->attemptDirectMnemonic($sMnemonic, $sOperands);
        }
        return null;
    }

    private function attemptDirectMnemonic(string $sMnemonic, string $sOperands) {
        if (!isset($this->aOperandSetParsers[$sMnemonic])) {
            throw new ParseException("Unknown mnemonic " . $sMnemonic);
        }
        foreach ($this->aOperandSetParsers[$sMnemonic] as $oParser) {
            try {
                $oParsed     = $oParser->parse($sOperands);
                $sOpcodeEnum = $oParsed->oOpcode->sEnum;
                if (!isset($this->aOpcodeDefs[$sOpcodeEnum])) {
                    throw new ParseException("Unknown Opcode ", $sOpcodeEnum);
                }
                $iValue = $this->aOpcodeDefs[$sOpcodeEnum];
                $oParsed->oOpcode->iByte = $iValue;

                return $oParsed;
            } catch(InvalidArgumentException $oException) {
                // do nothing here
            } catch (Exception $oException) {
                echo "Error: ", get_class($oException), ":", $oException->getMessage(), "\n";
            }
        }
        return null;
    }
}

