<?php

/**
 * LineKind
 *
 * Enumerates the different kinds of lines expected within source code and defines high level matching expressions.
 */
interface LineKind {
    const
        KIND        = 0, // Kind (one of the remainder of this list)
        BLANK       = 1,
        LABEL       = 2,
        CODE_SYMBOL = 3,
        DATA_SYMBOL = 4,
        INSTRUCTION = 5
    ;

    const
        MATCH_LABEL       = '/^(\.[_A-Za-z]{1}[_0-9A-Za-z]{0,})\:\s*$/',
        MATCH_CODE_SYMBOL = '/^(@[_A-Za-z]{1}[_0-9A-Za-z]{0,})\:\s*$/',
        MATCH_DATA_SYMBOL = '/^(\$[_A-Za-z]{1}[_0-9A-Za-z]{0,})\:\s*$/',
        MATCH_INSTRUCTION = '/^\s+([a-zA-Z0-9\.]{1,}).*?$/'
    ;
}
