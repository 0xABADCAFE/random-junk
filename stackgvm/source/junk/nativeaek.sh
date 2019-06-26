#!/bin/sh

g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x64 &
g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x64 &
g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x64 &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x86 &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x86 &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x86

g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x64_sse &
g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x64_sse &
g++ -Ofast -Wall -flto -W -march=native      -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x64_sse &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x86_sse &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x86_sse &
g++ -Ofast -Wall -flto -W -m32 -march=native -funroll-loops -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x86_sse

g++ -Ofast -Wall -flto -W -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x64_avx &
g++ -Ofast -Wall -flto -W -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x64_avx &
g++ -Ofast -Wall -flto -W -march=native -mavx      -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x64_avx &
g++ -Ofast -Wall -flto -W -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek.cpp -o bin/aek_x86_avx &
g++ -Ofast -Wall -flto -W -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_2.cpp -o bin/aek2_x86_avx &
g++ -Ofast -Wall -flto -W -m32 -march=native -mavx -funroll-loops -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations aek_3.cpp -o bin/aek3_x86_avx

#time ./aek > /dev/null
#time ./aek2 > /dev/null
