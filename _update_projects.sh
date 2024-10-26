#!/bin/bash

projects="
fixlang-minilib-app
fixlang-minilib-binary
fixlang-minilib-collection
fixlang-minilib-common
fixlang-minilib-comonad
fixlang-minilib-crypto
fixlang-minilib-examples
fixlang-minilib-io
fixlang-minilib-json
fixlang-minilib-math
fixlang-minilib-media
fixlang-minilib-monad
fixlang-minilib-net
fixlang-minilib-regexp
fixlang-minilib-text
fixlang-minilib-thread
fixlang-minilib-xml
"

function split_push() {
    local n=$1
    git checkout $dev
    git subtree split -P _projects/$n -b $n
    #git remote add $n https://github.com/pt9999/$n
    git checkout $n
    git push -u $n $n:main
}

dev=split-projects2
for n in $projects; do
    (
        echo "=== $n ==="
        set -ex
        #split_push $n
        #git rm -r _projects/$n
        #git submodule add https://github.com/pt9999/$n _projects/$n
    )
done
git checkout $dev
