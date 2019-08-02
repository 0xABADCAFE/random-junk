#!/bin/sh

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek_v1.cpp -S -o bin/aek_v1_fast_x86_sse.s &
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek_v2.cpp -S -o bin/aek_v2_fast_x86_sse.s &
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  -fverbose-asm aek_v3.cpp -S -o bin/aek_v3_fast_x86_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v1.cpp -S -o bin/aek_v1_fast_x64_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v2.cpp -S -o bin/aek_v2_fast_x64_sse.s &
g++ -Ofast -Wall -W -march=native -mfpmath=sse       -fverbose-asm aek_v3.cpp -S -o bin/aek_v3_fast_x64_sse.s &

g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek_v1.cpp -o bin/aek_v1_fast_x86_sse
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek_v2.cpp -o bin/aek_v2_fast_x86_sse
g++ -Ofast -Wall -W -m32 -march=native -mfpmath=sse  aek_v3.cpp -o bin/aek_v3_fast_x86_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v1.cpp -o bin/aek_v1_fast_x64_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v2.cpp -o bin/aek_v2_fast_x64_sse
g++ -Ofast -Wall -W -march=native -mfpmath=sse       aek_v3.cpp -o bin/aek_v3_fast_x64_sse

#bin/aek_v1_fast_x86_sse
#bin/aek_v2_fast_x86_sse
#bin/aek_v3_fast_x86_sse
#bin/aek_v1_fast_x64_sse
#bin/aek_v2_fast_x64_sse
#bin/aek_v3_fast_x64_sse
