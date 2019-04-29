<?php

/**
 * OperandParserFactory
 */
class OperandParserFactory {

    private static $oInstance = null;

    private $aParsers;

    /**
     * Singleton
     *
     * @return OperandParserFactory
     */
    public static function get() {
        if (null === self::$oInstance) {
            self::$oInstance = new self;
        }
        return self::$oInstance;
    }

    /**
     * @param int $iKind
     * @return Parser
     */
    public function getParser(int $iKind) {
        if (isset($this->aParsers[$iKind])) {
            return $this->aParsers[$iKind];
        }
        throw new Exception("Uknown Operand Parser for #". $iKind);
    }

    private function __construct() {
        $this->aParsers = [
            OperandKind::KIND    => new OperandKindParser(),

            OperandKind::LOCAL   => new StackFramePositionParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::LOCAL][0],
                    OperandKind::LIMITS[OperandKind::LOCAL][1]
                )
            ),

            OperandKind::INDEX_0 => new IndexOffsetParser(
                0,
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::INDEX_0][0],
                    OperandKind::LIMITS[OperandKind::INDEX_0][1]
                )
            ),

            OperandKind::INDEX_1 => new IndexOffsetParser(
                1,
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::INDEX_1][0],
                    OperandKind::LIMITS[OperandKind::INDEX_1][1]
                )
            ),

            OperandKind::JUMP_8  => new Base10IntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::JUMP_8][0],
                    OperandKind::LIMITS[OperandKind::JUMP_8][1]
                )
            ),

            OperandKind::JUMP_16 => new Base10IntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::JUMP_16][0],
                    OperandKind::LIMITS[OperandKind::JUMP_16][1]
                )
            ),

            OperandKind::SMALL_8 => new Base10IntegerLiteralParser(
                new ConstIntExpressionParser(
                    OperandKind::LIMITS[OperandKind::SMALL_8][0],
                    OperandKind::LIMITS[OperandKind::SMALL_8][1]
                )
            ),
        ];
    }
}
