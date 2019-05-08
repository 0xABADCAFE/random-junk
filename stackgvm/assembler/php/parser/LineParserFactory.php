<?php

class LineParserFactory {

    private static $oInstance = null;
    private $aParserInstances;

    // Parsers for these OperandKind values should always return distinct instances, otherwise a shared instance
    // will be used.
    const USE_CLONED_PARSER = [

    ];

    /**
     * Singleton
     *
     * @return OperandParserFactory
     */
    public static function get() : LineParserFactory {
        if (null === self::$oInstance) {
            self::$oInstance = new self;
        }
        return self::$oInstance;
    }

    public function getParser(int $iKind) : Parser {
        if (isset($this->aParserInstances[$iKind])) {
            if (isset(self::USE_CLONED_PARSER[$iKind])) {
                return clone $this->aParserInstances[$iKind];
            }
            return $this->aParserInstances[$iKind];
        }
        throw new Exception("Uknown Line Parser for #". $iKind);
    }

    private function __construct() {
        $this->aParserInstances = [
            LineKind::KIND        => new LineKindParser(),
            LineKind::BLANK       => new LineBlankParser(),
            LineKind::LABEL       => new LineLabelParser(),
            LineKind::CODE_SYMBOL => new LineCodeSymbolParser(),
            LineKind::DATA_SYMBOL => new LineDataSymbolParser(),
            LineKind::INSTRUCTION => new LineInstructionParser()
        ];
    }
}
