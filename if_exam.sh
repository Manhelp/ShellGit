#!/bin/bash

echo "Please input a integer: "
read integer

if [ "$integer" -lt 15 ]
then
	echo "The integer which you input is lower than 15."
else
	echo "The integer which you input is greater than 15."
fi

