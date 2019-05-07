<?php

/**
 *
 */

class SourceLoader {

    private $oProject = null;
    private $aSource  = [];

    public function __construct(Project $oProject) {
        $this->oProject = $oProject;
    }

    public function load() : self {
        $this->oProject->prepare();
        foreach ( $this->oProject->getSources() as $sCurrentPath) {
            $this->preprocessFile($sCurrentPath);
        }
        return $this;
    }

    public function dump() {
        print_r($this->aSource);
    }

    public function getSource() : array {
        return $this->aSource;
    }

    private function preprocessFile(string $sCurrentPath) {
        $sContent = shell_exec(
            'cpp -nostdinc -Isdk/' .
            $this->oProject->getTargetName() . '/include ' .
            $sCurrentPath);
        $this->aSource[$sCurrentPath] = preg_replace('/^#.*?$\n*/m', '', $sContent);
    }

}

