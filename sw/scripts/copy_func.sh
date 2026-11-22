#!/bin/bash

#set -x

copy() {
	SSH_SOCKET="./build/ssh_socket"

	FILES="$1"
	if [[ "$(basename $PWD)" == "sw" ]]; then 
		source ./config/local_settings.env
		ssh -M -S ${SSH_SOCKET} -o ControlPersist=1m -fN ${RPI_USER}@${RPI_IP}
		ssh -S ${SSH_SOCKET} -o ControlMaster=auto ${RPI_USER}@${RPI_IP} 'rm -rf ~/qc1_sw'
		ssh -S ${SSH_SOCKET} -o ControlMaster=auto ${RPI_USER}@${RPI_IP} 'mkdir ~/qc1_sw'
		scp -o ControlPath=${SSH_SOCKET} -o ControlMaster=auto -r ${FILES} ${RPI_USER}@${RPI_IP}:~/qc1_sw/
		ssh -S ${SSH_SOCKET} -O exit ${RPI_USER}@${RPI_IP}
	else
		echo "executed from wrong dir"
		exit 1 
	fi
}

