#!/bin/bash

for (( i=1; i<=9; i++ ))
do
	for (( j=9; j-i>=0; j-- ))
	do
		echo -n " "
	done

	for (( n=1; n<=2*i-1; n++ ))
	do
		echo -n "*"
	done
	echo ""
done
