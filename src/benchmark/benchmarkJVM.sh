#!/bin/bash

# Argument List: $1 = The java jvm you want to run (defaults to the name java)
#		 $2 = The java program you want the jvm to run (default to just running java)(e.g. HelloWorld)
#		 $3...$10 = Extra arguments for the JVM
if [ -z "$1" ] ; then
	JVMName=java
else
	JVMName=$1
fi

if [ -z "$2" ] ; then
	JavaProgram=
else
	JavaProgram=$2
fi

# Other configurable arguments
FileDump=BenchmarkNumbers

# File cleanup
rm -f $FileDump

# Loop and find the timing of each invokation
counter=1
while [ $counter -le 10 ]
do
	bash logTime.sh $JVMName $JavaProgram $3 $4 $5 $6 $7 $8 $9 $10 &>> $FileDump
	((counter++))
done

# Run through the data and perform some statistical analysis
javac CalculateStatistics.java
java CalculateStatistics $PWD/$FileDump
