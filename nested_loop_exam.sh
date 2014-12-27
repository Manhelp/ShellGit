#!/bin/bash



for (( i=0; i<=9; i++ ))
do
	for(( j=1; j<=i; j++ ))
	do
		let "temp = i*j"
		echo -n "$i*$j=$temp "
	done
	echo ""
done
