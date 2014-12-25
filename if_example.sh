#!/bin/bash

if [ -e if_file ]
then
	echo "the file if_fiel is exists!"
else
	touch if_file
	echo "The file if_file is created successfully!"
fi

if [ -r if_file ]
then
	echo "The file can read."
fi

if [ -w if_file ]
then
	echo "The file can write."
fi

if [ -x if_file ]
then
	echo "The file can execute."
fi
