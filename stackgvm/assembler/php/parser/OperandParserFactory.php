<?php

/**
 * OperandParserFactory
 */
class OperandParserFactory {

    private static $oInstance = null;

    private $aParsers;

    public static function get() {
        if (null === self::$oInstance) {
            self::$oInstance = new self;
        }
        return self::$oInstance;
    }

    /**
     * @param int $iKind
     * @return 
     */
    public function getParser(int $iKind) {
        if (isset($this->aParsers[$iKind])) {
            return $this->aParsers[$iKind];
        }
        throw new Exception("Uknown Operand Parser for #". $iKind);
    }

    private function __construct() {
        $this->aParsers = [
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
//             OperandKind::JUMP_8  => null,
//             OperandKind::JUMP_16 => null,
//             OperandKind::SMALL_8 => null,
        ];
    }
}
