#!/bin/sh
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_x86.asm &
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_address_x86.asm &
g++ -Ofast -Wall -W -fPIC -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_address_PIC_x86.asm &

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_ALLOW_GOTO_ -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_allow_goto_x86.asm &

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_cache_ptr_x86.asm &

g++ -Ofast -Wall -W -fPIC -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_OPT_ALLOW_GOTO_  -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_all_opts_x86.asm &
g++ -Ofast -Wall -W -fPIC -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_OPT_ALLOW_GOTO_  -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_adddress_all_opts_x86.asm &

g++ -Ofast -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_x64.asm &
g++ -Ofast -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_address_x64.asm &
g++ -Ofast -Wall -W -fPIC -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_address_PIC_x64.asm &

g++ -Ofast -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_OPT_ALLOW_GOTO_ -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_allow_goto_x64.asm &

g++ -Ofast -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_cache_ptr_x64.asm &
g++ -Ofast -Wall -W -fPIC -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_OPT_ALLOW_GOTO_  -D_GVM_ANNOTATE_ASM_ -S gvm_run.cpp -o bin/gvm_run_all_opts_x64.asm &
g++ -Ofast -Wall -W -fPIC -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_64 -D_GVM_OPT_64BIT_PURE_ -D_GVM_OPT_CACHE_POINTERS_ -D_GVM_OPT_ALLOW_GOTO_  -D_GVM_ANNOTATE_ASM_ -S gvm_address.cpp -o bin/gvm_address_opts_x64.asm &

#ppc-amigaos-g++ -Ofast -Wall -W -m32 -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations -D_GVM_HOST_OS=_GVM_HOST_LINUX_INTEL_32 -S gvm_run.cpp -o bin/gvm_run_run_ppc.asm
