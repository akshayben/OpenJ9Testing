#!/bin/bash

JVMName=$1
JavaProgram=$2

# &> /dev/null
TIMEFORMAT='%U'
time {
if [ ! -z "$5" ]; then
	$JVMName $3 $4 $5 $JavaProgram &> /dev/null
elif [ ! -z "$4" ]; then
	$JVMName $3 $4 $JavaProgram &> /dev/null
elif [ ! -z "$3" ]; then
	$JVMName $3 $JavaProgram &> /dev/null
else
	$JVMName $JavaProgram &> /dev/null
fi
}
