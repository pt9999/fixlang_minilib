#!/bin/bash

mkdir -p .local
cp -pui ~/.cargo/bin/fix .local/fix
docker build . -t pt9999/fix:latest
