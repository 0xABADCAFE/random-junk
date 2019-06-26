#!/bin/sh

clang++ -Ofast -Wall -W -mcpu=native -mtune=native -flto -fomit-frame-pointer -fno-exceptions card_raytracer.cpp -o aek
clang++ -Ofast -Wall -W -mcpu=native -mtune=native -flto -fomit-frame-pointer -fno-exceptions card_raytracer2.cpp -o aek2
clang++ -Ofast -Wall -W -mcpu=native -mtune=native -flto -fomit-frame-pointer -fno-exceptions aek_3.cpp -o aek3


time ./aek > gold.ppm
time ./aek2 > gold2.ppm
time ./aek3 > gold3.ppm

