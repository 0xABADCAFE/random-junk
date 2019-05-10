<?php

class LineInstructionParser implements Parser {

    private $aOperandSets = [];

    public function importDefinitions(array $aDefinitions) {
        $this->aOperandSetParsers = [];
        $oLoader = new InstructionDefinitionLoader();
        foreach ($aDefinitions as $sDefinitionPath) {
            $this->aOperandSetParsers += $oLoader->loadDefinition($sDefinitionPath);
        }
    }

    public function parse(string $sLine) {
        if (!preg_match(LineKind::MATCH_INSTRUCTION, $sLine, $aMatches)) {
            throw new ParseException();
        }
        $sMnemonic = strtolower($aMatches[1]);
        if (!isset($this->aOperandSetParsers[$sMnemonic])) {
            throw new ParseException("Unknown mnemonic " . $sMnemonic);
        }

        $sOperands = trim(str_replace($aMatches[1], '', $sLine));
        $aParsed   = null;
        foreach ($this->aOperandSetParsers[$sMnemonic] as $oParser) {
            try {
                $oParsed = $oParser->parse($sOperands);
                $oParsed->source = $sLine;
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

