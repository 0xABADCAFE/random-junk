<?php

/**
 * Config
 */
class AssemblerConfig {

    public function __construct(string $sConfigFile) {
        $oConfigData = $this->load($sConfigFile);
        LineParserFactory::get()->getParser(LineKind::INSTRUCTION)->importDefinitions(
            $oConfigData->opcodes,
            $oConfigData->mnemonics,
            $oConfigData->aliases
        );
    }

    public function getLineParserFactory() {
        return LineParserFactory::get();
    }

    public function getLineProcessingState() {
        return AssemblerLineProcessingState::create();
    }

    private function load(string $sConfigFile) {
        if (
            !file_exists($sConfigFile) ||
            !is_readable($sConfigFile)
        ) {
            throw new Exception("Unable to open config file '" . $sConfigFile . "' for reading.\n");
        }
        $oConfigData = json_decode(file_get_contents($sConfigFile));
        if (
            !($oConfigData instanceof stdClass) ||
            !isset($oConfigData->name) ||
            !is_array($oConfigData->mnemonics) ||
            !is_array($oConfigData->aliases) ||
            !isset($oConfigData->opcodes)
        ) {
            throw new Exception("Invalid project file '" . $sConfigFile . "'");
        }
        $oConfigData->base = realpath(dirname($sConfigFile)) .'/';
        return $oConfigData;
    }
}

