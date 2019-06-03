<?php

/**
 * Parser
 *
 * Top level interface for parser classes. All expect string inputs but return more domain specific types.
 */
interface Parser {

    public function parse(string $sInput);

}
