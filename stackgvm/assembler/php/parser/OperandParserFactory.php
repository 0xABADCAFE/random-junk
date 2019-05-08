<?php

/**
 * OperandParserFactory
 */
class OperandParserFactory {

    private static $oInstance = null;
    private $aParserInstances;

    // Parsers for these OperandKind values should always return distinct instances, otherwise a shared instance
    // will be used.
    const USE_CLONED_PARSER = [
        OperandKind::KIND => 1
    ];

    /**
     * Singleton
     *
     * @return OperandParserFactory
     */
    public static function get() : OperandParserFactory {
        if (null === self::$oInstance) {
            self::$oInstance = new self;
        }
        return self::$oInstance;
    }

    /**
     * @param int $iKind
     * @return Parser
     */
    public function getParser(int $iKind) : OperandParser {
        if (isset($this->aParserInstances[$iKind])) {
            if (isset(self::USE_CLONED_PARSER[$iKind])) {
                return clone $this->aParserInstances[$iKind];
            }
            return $this->aParserInstances[$iKind];
        }
        throw new Exception("Uknown Operand Parser for #". $iKind);
    }

    private function __construct() {
        $this->aParserInstances = [
            OperandKind::KIND    => new OperandKindParser(),

            OperandKind::LOCAL   => new OperandLocalParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::LOCAL][0],
                    OperandKind::LIMITS[OperandKind::LOCAL][1]
                )
            ),

            OperandKind::INDEX_0 => new OperandIndirectParser(
                0,
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::INDEX_0][0],
                    OperandKind::LIMITS[OperandKind::INDEX_0][1]
                )
            ),

            OperandKind::INDEX_1 => new OperandIndirectParser(
                1,
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::INDEX_1][0],
                    OperandKind::LIMITS[OperandKind::INDEX_1][1]
                )
            ),

            OperandKind::JUMP_8  => new OperandIntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::JUMP_8][0],
                    OperandKind::LIMITS[OperandKind::JUMP_8][1]
                )
            ),

            OperandKind::JUMP_16 => new OperandIntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::JUMP_16][0],
                    OperandKind::LIMITS[OperandKind::JUMP_16][1]
                )
            ),

            OperandKind::SMALL_8 => new OperandIntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::SMALL_8][0],
                    OperandKind::LIMITS[OperandKind::SMALL_8][1]
                )
            ),

            OperandKind::BITPOS => new OperandIntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::BITPOS][0],
                    OperandKind::LIMITS[OperandKind::BITPOS][1]
                )
            ),

            OperandKind::LABEL  => new OperandLabelParser(),
            OperandKind::SYMBOL => new OperandSymbolParser(),
        ];
    }
}
