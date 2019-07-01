#!/bin/sh

g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek.cpp   -S -o bin/aek_no_opt_x86_sse.s &
g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek_2.cpp -S -o bin/aek2_no_opt_x86_sse.s &
g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek_3.cpp -S -o bin/aek3_no_opt_x86_sse.s &
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek.cpp   -S -o bin/aek_no_opt_x64_sse.s &
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek_2.cpp -S -o bin/aek2_no_opt_x64_sse.s &
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fverbose-asm aek_3.cpp -S -o bin/aek3_no_opt_x64_sse.s &

g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer aek.cpp   -o bin/aek_no_opt_x86_sse
g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer aek_2.cpp -o bin/aek2_no_opt_x86_sse
g++ -O0 -Wall -W -m32 -march=native -mfpmath=sse -fomit-frame-pointer aek_3.cpp -o bin/aek3_no_opt_x86_sse
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer aek.cpp   -o bin/aek_no_opt_x64_sse
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer aek_2.cpp -o bin/aek2_no_opt_x64_sse
g++ -O0 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer aek_3.cpp -o bin/aek3_no_opt_x64_sse

bin/aek_no_opt_x86_sse
bin/aek2_no_opt_x86_sse
bin/aek3_no_opt_x86_sse
bin/aek_no_opt_x64_sse
bin/aek2_no_opt_x64_sse
bin/aek3_no_opt_x64_sse
