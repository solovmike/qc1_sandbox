#!/bin/bash

source ./config/local_settings.env
sshfs ${RPI_USER}@${RPI_IP}: ./mnt_rpi/
