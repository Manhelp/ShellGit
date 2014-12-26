#!/bin/bash

echo "Pls. choose your profession?"
select  in "Worker" "Doctor" "Teacher" "student" "Other"
do
	echo "The \$REPLY is $REPLY."
	echo "Your preofession is $var."
	break
done
