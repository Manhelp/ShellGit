#!/bin/bash
# form /etc/fstab read

File=/etc/fstab
{
	read line1
	read line2
} < $File

echo "First line in $File is:"
echo "$line1"
echo .
echo "Second line in RFile is:"
echo "$line2"

exit 0
