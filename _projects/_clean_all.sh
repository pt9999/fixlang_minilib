#!/bin/bash

set -e

for d in fix*; do (
    if [ -f $d/fixproj.toml ]; then 
        echo "Cleaning $d"
        cd $d
        fix clean
    fi
); done

(
    echo "Cleaning fixlang-minilib-examples"
    cd fixlang-minilib-examples
    make clean
)
