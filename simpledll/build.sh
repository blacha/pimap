#!/bin/bash
# i686-w64-mingw32-g++ -c src/offset.c
# i686-w64-mingw32-g++ -c src/offset.c src/D2.c

i686-w64-mingw32-g++  src/offset.c src/D2.c  -o  pimap.exe -static-libgcc -static-libstdc++
