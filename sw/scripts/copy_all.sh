#!/bin/bash

FILES="build config docs include Makefile scripts src third_party"

set -ex

./scripts/mount_rpi.sh
mkdir -p ./mnt_rpi/quad/sw
rm -rf ./mnt_rpi/quad/sw/*
cp -r ${FILES} ./mnt_rpi/quad/sw/
./scripts/unmount_rpi.sh

