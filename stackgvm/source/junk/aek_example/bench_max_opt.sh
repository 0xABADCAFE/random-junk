#!/bin/sh

g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v1.cpp -S -o bin/aek_v1.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v2.cpp -S -o bin/aek_v2.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v3.cpp -S -o bin/aek_v3.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v1.cpp -o bin/aek_v1
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v2.cpp -o bin/aek_v2
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v3.cpp -o bin/aek_v3
bin/aek_v1_x64_sse
bin/aek_v2_x64_sse
bin/aek_v3_x64_sse
