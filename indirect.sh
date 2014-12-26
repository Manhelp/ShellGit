#!/bin/bash

variable1=variable3
#variable2=variable3
variable3=Hadoop

echo "variable1=$variable1"

eval tempvar=\$$variable1
echo "tempvar=$tempvar"

echo "Indirect ref variable1 is: ${!variable1}"
