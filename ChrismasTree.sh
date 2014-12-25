#!/bin/bash

echo ""
i=1
for (( all=3; all<=4; all++ ))
do
	for (( ; i<=2**all; i++ ))
	do
		for (( j=16; j-i>=0; j-- ))
		do
			echo -n " "
		done

		for (( n=1; n<=2*i-1; n++ ))
		do
			echo -e -n "\033[35m\005"
			#printf "%c" \c005 
		done
		echo ""
	done
	let "i = all+1"
done
#-----------------------------
for (( num=0; num<=2; num++ ))
do
	echo "               * *"
done

echo "              /***\\"
echo "             *******"
echo ""
