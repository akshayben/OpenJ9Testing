#!/bin/bash

# Assumes you made a soft link to the openj9's java debug build, and you named it 'j9debug'
J9DebugSoftLinkName=j9debug
DumpDirectoryName=StateDump
ROMFileName=$DumpDirectoryName/ROM_Class_Dump
RAMFileName=$DumpDirectoryName/RAM_Class_Dump
ROMCommandFileName=gdbROMCommandFile
RAMCommandFileName=gdbRAMCommandFile

rm $ROMFileName
rm $RAMFileName

mkdir $DumpDirectoryName

gdb $J9DebugSoftLinkName -q --command=$ROMCommandFileName >> $ROMFileName
gdb $J9DebugSoftLinkName -q --command=$RAMCommandFileName >> $RAMFileName

# Clean up the leftover lines from GDB from the ROM dump
sed -i '1,7d' $ROMFileName
sed -i '/Switching to Thread/d' $ROMFileName
sed -i '/exited normally/d' $ROMFileName
sed -i '$ d' $ROMFileName

# Clean up the leftover lines from GDB from the RAM dump
sed -i '1,7d' $RAMFileName
sed -i '/Switching to Thread/d' $RAMFileName
sed -i '/exited normally/d' $RAMFileName
sed -i '$ d' $RAMFileName
