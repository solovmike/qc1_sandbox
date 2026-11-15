#!/bin/bash

MOUNT_POINT="./mnt_rpi/"

source ./config/local_settings.env

if ! mountpoint -q "$MOUNT_POINT"; then
	sshfs ${RPI_USER}@${RPI_IP}: ${MOUNT_POINT}
fi
