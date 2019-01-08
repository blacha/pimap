#!/bin/bash
mkdir bin -p
i686-w64-mingw32-g++ -o bin/pimap.exe -Wno-write-strings src/mapgen/json.c src/mapgen/map.c src/mapgen/offset.c src/mapgen/d2_client.c src/mapgen/main.c -static-libgcc -static-libstdc++
