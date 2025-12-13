#!/bin/bash

if ! [ -f fixproj.toml ]; then exit 0; fi

git log --pretty='format:%H %s' fixproj.toml | \
perl -lne '
    if (/(\w+) version (\d+.\d+.\d+)/) { 
        print "git tag $2 $1"; push(@VERS, $2) 
    }
    END { print "git push tag @VERS" if @VERS }
' | \
tee ,doit

