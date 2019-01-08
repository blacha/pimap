#!/bin/bash
# i686-w64-mingw32-g++ -c src/offset.c
# i686-w64-mingw32-g++ -c src/offset.c src/D2.c

i686-w64-mingw32-g++ -o pimap.exe -Wno-write-strings src/json.c src/map.c src/offset.c src/d2_client.c -static-libgcc -static-libstdc++
