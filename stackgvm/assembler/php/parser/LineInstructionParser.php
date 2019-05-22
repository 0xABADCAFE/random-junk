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

        $oAlias = null;

        if (isset($this->aAliases[$sMnemonic])) {
            $oAlias = $this->aAliases[$sMnemonic];
            $sMnemonic = $oAlias->alias;
        }

        if (!isset($this->aOperandSetParsers[$sMnemonic])) {
            throw new ParseException("Unknown mnemonic " . $sMnemonic);
        }

        $sOperands = trim(str_replace($aMatches[1], '', $sLine));
        $aParsed   = null;
        foreach ($this->aOperandSetParsers[$sMnemonic] as $oParser) {
            try {
                $oParsed     = $oParser->parse($sOperands);
                $sOpcodeEnum = $oParsed->oOpcode->sEnum;
                if (!isset($this->aOpcodeDefs[$sOpcodeEnum])) {
                    throw new ParseException("Unknown Opcode ", $sOpcodeEnum);
                }
                $iValue = $this->aOpcodeDefs[$sOpcodeEnum];
                $oParsed->oOpcode->iByte = $iValue;

                if ($oAlias) {
                    $this->permuteOperandsForAlias($oParsed, $oAlias);
                }

                return $oParsed;
            } catch(InvalidArgumentException $oException) {
                // do nothing here
            } catch (Exception $oException) {
                echo "Error: ", get_class($oException), ":", $oException->getMessage(), "\n";
            }
        }
        return null;
    }

    private function permuteOperandsForAlias($oParsed, $oAlias) {
        $aOperands = [];
        foreach ($oAlias->permute as $iTo => $iFrom) {
            $aOperands[$iTo] = $oParsed->aOperands[$iFrom];
        }
        $oParsed->aOperands = $aOperands;
    }
}

