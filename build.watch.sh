#!/bin/bash
while true; do
    echo "Build"
    ./build.mapgen.sh
    echo "Build Done"
    inotifywait -qre close_write src/mapgen;
done
