#!/usr/bin/php
<?php

/*
$aOptions = getopt(
    '',
    [
        'srcdir:',
        'incdir:'
    ]
);
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Project {

    public function __construct(string $sProjectFile) {

    }

    public function get_source_directory() : string {
        return $this->sSourceDirectory;
    }

    public function get_include_paths() : array {
        return $this->aIncludePaths;
    }
}

class SourceLoader {

    private $aSource = [];

    public function __construct(string $sSourceDirectory, $sIncludeDirectory = null) {
        $this->validateDirectory($sSourceDirectory, 'source');
        $this->sSourceDirectory = $sSourceDirectory;
        if (null === $sIncludeDirectory) {
            $this->sIncludeDirectory = $sIncludeDirectory;
        } else {
            $this->validateDirectory($sIncludeDirectory, 'include');
            $this->sIncludeDirectory = $sIncludeDirectory;
        }

    }

    public function load() : self {
        echo "Processing files in ", $this->sSourceDirectory, "\n";
        $oSourceDirectory = dir($this->sSourceDirectory);
        while (false !== ($sFileName = $oSourceDirectory->read())) {
            $sCurrentPath = $this->sSourceDirectory . '/' . $sFileName;
            if ($this->checkFile($sCurrentPath)) {
                $this->preprocessFile($sCurrentPath);
            }
        }
        $oSourceDirectory->close();
        return $this;
    }

    public function dump() {
        print_r($this->aSource);
    }

    private function checkFile(string $sCurrentPath) : bool {
        if (is_link($sCurrentPath) || is_dir($sCurrentPath)) {
            return false;
        }
        if (strtolower(substr($sCurrentPath, -4, 4)) === '.asm') {
            if (!is_readable($sCurrentPath)) {
                throw new Exception("Unable to open ", $sCurrentPath, " for reading");
            }
            return true;
        }
        return false;
    }

    private function validateDirectory(string $sDirectory, string $sType) {
        if (
            !is_dir($sDirectory) ||
            !is_readable($sDirectory)
        ) {
            throw new Exception('Invalid ' . $sType . ' directory path');
        }
    }

    private function preprocessFile(string $sCurrentPath) {
        $sContent = shell_exec('cpp -nostdinc -I' . $this->sIncludeDirectory . ' -Isdk/test_host/include ' . $sCurrentPath);
        $this->aSource[$sCurrentPath] = preg_replace('/^#.*?$\n*/m', '', $sContent);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

(new SourceLoader('example', 'example/include'))
    ->load()
    ->dump();

