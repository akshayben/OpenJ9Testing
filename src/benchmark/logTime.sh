#!/bin/bash

JVMName=$1
JavaProgram=$2

TIMEFORMAT='%U'
time {
	$JVMName $3 $4 $5 $JavaProgram &> /dev/null
}
