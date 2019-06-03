<?php

/**
 * Parses a blank line. A no-op, basically.
 */
class LineBlankParser implements Parser {

    public function parse(string $sOperand) : string {
        return $sOperand;
    }
}
