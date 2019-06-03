<?php

require_once 'parser/Parser.php';
require_once 'parser/LineKindParser.php';
require_once 'parser/LineBlankParser.php';
require_once 'parser/LineLabelParser.php';
require_once 'parser/LineCodeSymbolParser.php';
require_once 'parser/LineDataSymbolParser.php';
require_once 'parser/LineInstructionParser.php';
require_once 'parser/LineParserFactory.php';
require_once 'parser/OperandKindParser.php';
require_once 'parser/ConstIntExpressionParser.php';
require_once 'parser/OperandLocalParser.php';
require_once 'parser/OperandIndirectParser.php';
require_once 'parser/OperandIntegerLiteralParser.php';
require_once 'parser/OperandLabelParser.php';
require_once 'parser/OperandNoOpParser.php';
require_once 'parser/OperandSymbolParser.php';
require_once 'parser/OperandParserFactory.php';
require_once 'parser/OperandSetParser.php';
require_once 'definition/InstructionDefinitionLoader.php';
