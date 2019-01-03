#!/bin/sh

g++ -O3 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations card_raytracer.cpp -o aek
g++ -O3 -Wall -W -march=native -mfpmath=sse -fomit-frame-pointer -fno-exceptions -fexpensive-optimizations card_raytracer2.cpp -o aek2

time ./aek > gold.ppm
time ./aek2 > gold2.ppm
