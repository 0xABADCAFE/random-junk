<?php
/**
 * AssemblerLineProcessingState
 *
 * Simple state machine that keeps track of what the current statements being
 * assebmled represent and validates that each new line is of an appropriate
 * kind for that state. Certain line kinds will trigger a change of state.
 *
 */
class AssemblerLineProcessingState {

    /**
     * Allowed States
     */
    const
        INIT = 0,
        CODE = 1,
        DATA = 2
    ;

    /**
     * @var AssemblerLineProcessingState[] $aStates
     */
    private static $aStates = null;

    /**
     * @var int[] $aAllowedLineKinds
     */
    private $aAllowedLineKinds = null;

    /**
     * @var string $sStateName
     */
    private $sStateName = null;

    /**
     * Get the initial AssemblerLineProcessingState, used at the start of processing
     *
     * @return AssemblerLineProcessingState
     */
    public static function create() {
        if (null === self::$aStates) {
            self::defineStates();
        }
        return self::$aStates[self::INIT];
    }

    /**
     * Get the AssemblerLineProcessingState implied by the next line. This is where the validation happens. If the
     * provided Kind is not in the set allowed for the current state, an exception is thrown. Otherwise the
     * AssemblerLineProcessingState to use for the next test is returned.
     *
     * @param int $iLineKind
     * @return AssemblerLineProcessingState
     */
    public function getStateForLineKind(int $iLineKind) : self {
        if (isset($this->aAllowedLineKinds[$iLineKind])) {
            return self::$aStates[$this->aAllowedLineKinds[$iLineKind]];
        }
        throw new DomainException(LineKind::NAMES[$iLineKind] . ' is not valid during ' . $this->sStateName);
    }

    /**
     * Reset back to the initial state
     */
    public function reset() {
        return self::$aStates[self::INIT];
    }

    /**
     * Constructor. Accepts a map of enumerated line kinds to enumerated state types.
     */
    private function __construct(array $aAllowedLineKinds, string $sStateName) {
        $this->aAllowedLineKinds = $aAllowedLineKinds;
        $this->sStateName        = $sStateName;
    }

    private static function defineStates() {
        self::$aStates = [
            self::INIT => new self([
                LineKind::BLANK       => self::INIT, // No change on blank lines
                LineKind::CODE_SYMBOL => self::CODE, // Switch to CODE state
                LineKind::DATA_SYMBOL => self::DATA  // Switch to DATA state
            ], 'Initialisation'),

            self::CODE => new self([
                LineKind::BLANK       => self::CODE, // No change on blank lines
                LineKind::LABEL       => self::CODE, // Remain in CODE state for labels
                LineKind::INSTRUCTION => self::CODE, // Remain in CODE state for instructions
                LineKind::CODE_SYMBOL => self::CODE, // Remain in CODE state for function declarations
                LineKind::DATA_SYMBOL => self::DATA  // Switch to DATA state for data declarations
            ], 'Code Processing'),

            self::DATA => new self([
                LineKind::BLANK       => self::DATA, // No change for blank lines
                LineKind::DATA_SYMBOL => self::DATA, // Remain in DATA state for data declratations
                LineKind::DATA_RECORD => self::DATA, // Remain in DATA state for data record
                LineKind::CODE_SYMBOL => self::CODE, // Swotch to CODE state for function declarations
            ], 'Data Processing')
        ];
    }
}
