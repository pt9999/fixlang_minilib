#!/bin/bash

set -e

function gendoc () {
    local dir=$1
    (
        cd $dir
        if [ ! -d lib ]; then return; fi
        local files=$(find lib -name "*.fix")
        local modules=$(perl -lne 'print "$1" if /^module\s+([\w\.]+);/' $files)
        echo "=== $dir ==="
        #echo dir=$dir files=$files modules=$modules
        fix docs -m $modules
        rm -rf doc
        mkdir -p doc
        mv -v Minilib.*.md doc
    )
}

for dir in "$@"; do
    gendoc $dir
done
