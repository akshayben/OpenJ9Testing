#!/bin/bash

# Argument List: $1 = The java jvm you want to run (defaults to the name j9debug)
#		 $2 = The java program you want the jvm to run (default to just running java)(e.g. HelloWorld)
if [ -z "$1" ] ; then
	J9DebugSoftLinkName=j9debug
else
	J9DebugSoftLinkName=$1
fi

if [ -z "$2" ] ; then
	JavaProgram=
else
	JavaProgram=$2
fi

DumpDirectoryName=StateDump
ROMFileName=$DumpDirectoryName/ROM_Class_Dump
RAMFileName=$DumpDirectoryName/RAM_Class_Dump
ROMCommandFileName=gdbROMCommandFile
RAMCommandFileName=gdbRAMCommandFile

rm -f $ROMFileName
rm -f $RAMFileName

mkdir -p $DumpDirectoryName

gdb -q -batch -x $ROMCommandFileName --args $J9DebugSoftLinkName $JavaProgram >> $ROMFileName
gdb -q -batch -x $RAMCommandFileName --args $J9DebugSoftLinkName $JavaProgram >> $RAMFileName

# Clean up the leftover lines from GDB from the ROM dump
sed -i '1,5d' $ROMFileName
sed -i '/Switching to Thread/d' $ROMFileName
sed -i '/exited normally/d' $ROMFileName
sed -i '/exited with code/d' $ROMFileName

# Clean up the leftover lines from GDB from the RAM dump
sed -i '1,5d' $RAMFileName
sed -i '/Switching to Thread/d' $RAMFileName
sed -i '/exited normally/d' $RAMFileName
sed -i '/exited with code/d' $RAMFileName
