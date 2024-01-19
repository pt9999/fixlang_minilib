#!/bin/bash

set -ex

IMAGE=pt9999/fix
DATE=$(date +%Y%m%d)

mkdir -p .local
cp -pui ~/.cargo/bin/fix .local/fix
docker build . -t ${IMAGE}:latest
docker tag ${IMAGE}:latest ${IMAGE}:${DATE}
