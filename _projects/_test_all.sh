#!/bin/bash

set -ex

for d in fix*; do (
#for d in fix*-{text,thread}; do (
    cd $d
    if [ -f fixproj.toml ]; then
        fix clean
        fix test
    fi
); done

cd fixlang-minilib-examples
make clean
make all
