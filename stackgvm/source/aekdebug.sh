#!/bin/sh
make -f Makefile_aek_debug.x86_linux clean
make -f Makefile_aek_debug.x86_linux
bin/gamevm_aek_debug_x86_exe > junk/aek_debug_full.txt 2>&1
g++ -O1 junk/card_rt_main_loop.cpp -o junk/aek_debug_main_loop
junk/aek_debug_main_loop > junk/aek_native_main_debug.txt 2>&1

grep sample junk/aek_debug_full.txt > junk/vm_sample.txt
grep sample junk/aek_native_main_debug.txt > junk/nat_sample.txt
meld junk/vm_sample.txt junk/nat_sample.txt
#less junk/aek_debug_full.txt
