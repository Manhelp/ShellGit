#!/bin/bash
#WintoLin.sh: Window to linux txt change

E_WRONGARGS=65

if [ -z "$1" ]
then
	echo "Usage: 'basename $0' filename-to-convert"
	exit $E_WRONGARGS
fi

NEWFILENAME=$1.unx

CR='\015'

tr -d $CR < $1 > $NEWFILENAME

echo "Original Windows text file is \"$1\"."
echo "Converted Linux text file is \"$NEWFILENAME\"."

exit 0

