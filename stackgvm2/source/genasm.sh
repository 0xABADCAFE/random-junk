#!/bin/sh
g++ -O3 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -S gvm_run.cpp -o bin/gvm_x86.asm

g++ -O3 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_ALLOW_GOTO_ -S gvm_run.cpp -o bin/gvm_allow_goto_x86.asm

g++ -O3 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_CACHE_POINTERS_ -S gvm_run.cpp -o bin/gvm_cache_ptr_x86.asm

g++ -O3 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_OPT_ALLOW_GOTO_ -S gvm_run.cpp -o bin/gvm_all_opts_x86.asm

#ppc-amigaos-g++ -O3 -Wall -W -m32 -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -S gvm_run.cpp -o bin/gvm_run_ppc.asm
