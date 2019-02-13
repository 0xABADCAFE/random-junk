#!/bin/sh
make -f Makefile_aek.x86_linux clean
make -f Makefile_aek.x86_linux
bin/gamevm_aek_x86_exe > junk/test.ppm
