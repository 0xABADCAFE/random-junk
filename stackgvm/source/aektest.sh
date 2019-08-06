#!/bin/sh
make -f Makefile_aek.x86_linux clean
make -f Makefile_aek.x86_linux
bin/gvm_aek_x86_exe > junk/test.ppm
