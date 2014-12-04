#!/bin/bash

E_WRONG_ARGS=65
script_parameters="-a -n -m -z"
#  -a=all, -h=help,etc.

if [ $# -ne $Number_of_expected_args ]
then
	echo "Usage:`basename $0` $script_parameters"
	# `basename $0`是这个脚本的文件名
	exit $E_WRONG_ARGS
fi

