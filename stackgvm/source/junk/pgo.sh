rm -f *.gcda
g++ -march=native -mtune=native -pg -fprofile-generate aek_v3.cpp -o aek3pg
echo Profiling binary...
nice -20 ./aek3pg
g++ -march=native -mtune=native -pg -fprofile-use aek_v3.cpp -o aek3pgo
echo Running optimised binary..
nice -20 ./aek3pgo

