#!/bin/bash

declare -i i;
declare -i n;
declare -i pre;
declare -i rs;

if [ "$#" = "1" ]; then
	n="$1"
else
	read -p "input the n (number):" n
fi

echo "Calculate f($n)..."
i=0;
rs=0;		# the current num f(n)
pre=0;	# the previous num f(n-1)

while [ "$i" != "$n" ]
do
	i=$(( $i+1 ))
	if [ "$n" -lt "0" ]; then
		echo "n($n) must be assigned non-negative"
		exit 1
	fi
	if [ "$i" = "0" ]; then
		pre=0;
		rs=0;
	elif [ "$i" = "1" ]; then
		pre=0;
		rs=1;
	else
		rs=$(( $rs+$pre ));
		pre=$(( $rs-$pre ));
	fi
	echo -n "$rs ";
done
echo -e "\nThe th-$n fibonacci is f($n)=$rs"
