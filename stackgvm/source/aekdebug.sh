#!/bin/sh
make -f Makefile_aek_debug.x86_linux clean
make -f Makefile_aek_debug.x86_linux
bin/gamevm_aek_debug_x86_exe > junk/aek_debug_full.txt 2>&1
less junk/aek_debug_full.txt
