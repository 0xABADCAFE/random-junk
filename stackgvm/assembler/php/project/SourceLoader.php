<?php

/**
 * SourceLoader
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
            'cpp -xc -nostdinc -Isdk/' .
            $this->oProject->getTargetName() . '/include ' .
            $sCurrentPath);
        $this->aSource[$sCurrentPath] = explode("\n", preg_replace('/^#.*?$\n*/m', '', $sContent));
    }

}


