#!/usr/bin/awk -f
BEGIN {FS=","}
{total=$5+$6+$7+$8+$9
avg=total/5
print $1, avg}
