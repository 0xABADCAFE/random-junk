#!/bin/sh

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek.cpp   -S -o bin/aek_fast_x86_sse.s &
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek_2.cpp -S -o bin/aek2_fast_x86_sse.s &
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek_3.cpp -S -o bin/aek3_fast_x86_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse  -fverbose-asm aek.cpp   -S -o bin/aek_fast_x64_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse  -fverbose-asm aek_2.cpp -S -o bin/aek2_fast_x64_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse  -fverbose-asm aek_3.cpp -S -o bin/aek3_fast_x64_sse.s &

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek.cpp   -o bin/aek_fast_x86_sse
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek_2.cpp -o bin/aek2_fast_x86_sse
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek_3.cpp -o bin/aek3_fast_x86_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse  aek.cpp   -o bin/aek_fast_x64_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse  aek_2.cpp -o bin/aek2_fast_x64_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse  aek_3.cpp -o bin/aek3_fast_x64_sse

bin/aek_fast_x86_sse
bin/aek2_fast_x86_sse
bin/aek3_fast_x86_sse
bin/aek_fast_x64_sse
bin/aek2_fast_x64_sse
bin/aek3_fast_x64_sse
