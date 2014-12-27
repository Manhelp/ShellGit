#!/usr/bin/awk -f
BEGIN{ 
	info="4,90,6.9,8,10,1,60,7.8,9.3";
	len=split(info, data,",");

	for(i=1; i<=len; i++)
		for(j=i+1; j<=len; j++){
			if(data[i] >= data[j]){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				}
			}
	for(i=1; i<=len; i++)
		print data[i];
}
