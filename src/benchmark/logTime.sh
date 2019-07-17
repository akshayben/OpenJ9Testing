#!/bin/bash

JVMName=$1
JavaProgram=$2

TIMEFORMAT='%U'
time {
if [ "$#" -ne 5 ]; then
	$JVMName $3 $4 $5 $JavaProgram &> /dev/null
elif [ "$#" -ne 4 ]; then
	$JVMName $3 $4 $JavaProgram &> /dev/null
elif [ "$#" -ne 3 ]; then
	$JVMName $3 $JavaProgram &> /dev/null
else
	$JVMName $JavaProgram &> /dev/null
fi
}
