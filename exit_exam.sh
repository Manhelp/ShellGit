#!/bin/bash

echo "please input a string: "
read str

if [ -z "$str" ]
then
	echo "What you input is null!"
	exit 1
fi
