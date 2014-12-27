#!/usr/bin/awk -f
BEGIN {FS=":";
	if(ARGC>2){
		username=ARGV[1];
		delete ARGV[1];
	}
	else{
		while(!username){
			print "Pls.Enter a name";
			getline username<"-"
		}
	}
}
$1~username {print FNR,$1, $6}
