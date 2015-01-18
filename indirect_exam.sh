#!/bin/bash

t=cell
var=9999
cell=$var
eval tempvar=\$$t

echo "Direct refer t:$t"
echo "tempvar=$tempvar"
echo "Indirect refer t:${!t}"
