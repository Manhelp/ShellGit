#!/bin/bash

a=2
let --a && echo " TRUE" || echo " FALSE"
b=1
let b-- && echo " TRUE" || echo " FALSE"

(( c = a<4 ? 9 : 11 ))
echo "c=$c"
