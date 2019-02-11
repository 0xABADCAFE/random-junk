<?php

class Project {
    private $oProjectData;

    public function __construct(string $sProjectFile) {
        $this->oProjectData = $this->load($sProjectFile);
    }

    public function getName() : string {
        return $this->oProjectData->name;
    }

    public function getBasePath() : string {
        return $this->oProjectData->base;
    }

    public function getSources() : array {
        return $this->oProjectData->sources;
    }

    public function getIncludePath() : string {
        return $this->oProjectData->incdir;
    }

    public function getTargetName() : string {
        return $this->oProjectData->host->name;
    }

    public function prepare() {
        $aFiles = array_map(
            function(string $sPath) {
                $sPath = $this->oProjectData->base . $sPath;
                if (
                    !file_exists($sPath) ||
                    !is_readable($sPath)
                ) {
                    throw new Exception("Invalid source path '" . $sPath . "'");
                }
                return $sPath;
            },
            $this->oProjectData->sources
        );
        $sIncludeDir = $this->oProjectData->base . $this->oProjectData->incdir;
        if (
            !is_dir($sIncludeDir) ||
            !is_readable($sIncludeDir)
        ) {
            throw new Exception("Invalid include path '" . $sIncludeDir . "'");
        }

        $this->oProjectData->sources = $aFiles;
        $this->oProjectData->incdir  = $sIncludeDir;
    }

    private function load(string $sProjectFile) {
        if (
            !file_exists($sProjectFile) ||
            !is_readable($sProjectFile)
        ) {
            throw new Exception("Unable to open project file '" . $sProjectFile . "' for reading.\n");
        }
        $oProjectData = json_decode(file_get_contents($sProjectFile));
        if (
            !($oProjectData instanceof stdClass) ||
            !isset($oProjectData->name) ||
            !is_array($oProjectData->sources) ||
            !isset($oProjectData->incdir) ||
            !isset($oProjectData->host->name)
        ) {
            throw new Exception("Invalid project file '" . $sProjectFile . "'");
        }
        $oProjectData->base = realpath(dirname($sProjectFile)) .'/';
        return $oProjectData;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    private function preprocessFile(string $sCurrentPath) {
        $sContent = shell_exec(
            'cpp -nostdinc -I' . $this->oProject->getIncludePath() .
            ' -Isdk/' . $this->oProject->getTargetName() . '/include ' .
            $sCurrentPath);
        $this->aSource[$sCurrentPath] = preg_replace('/^#.*?$\n*/m', '', $sContent);
    }

}


