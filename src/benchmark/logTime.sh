#!/bin/bash

JVMName=$1
JavaProgram=$2

TIMEFORMAT='%U'
time {
	$JVMName $JavaProgram &> /dev/null
}
