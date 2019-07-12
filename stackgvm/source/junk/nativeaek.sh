#!/bin/sh

g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x64 &
g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x64 &
g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x64 &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x86 &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x86 &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x86

g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x64_sse &
g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x64_sse &
g++ -Ofast -Wall -W -ftree-vectorize -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x64_sse &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x86_sse &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x86_sse &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x86_sse

g++ -Ofast -Wall -W -ftree-vectorize -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x64_avx &
g++ -Ofast -Wall -W -ftree-vectorize -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x64_avx &
g++ -Ofast -Wall -W -ftree-vectorize -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x64_avx &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v1.cpp -o bin/aek_v1_x86_avx &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v2.cpp -o bin/aek_v2_x86_avx &
g++ -Ofast -Wall -W -ftree-vectorize -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_v3.cpp -o bin/aek_v3_x86_avx

#time ./aek > /dev/null
#time ./aek2 > /dev/null
