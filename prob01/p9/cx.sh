#!/usr/bin/env bash

# Checking if only exactly one argument was given
# $# is the number of arguments
if [[ !  $# -eq 1 ]];
then
	echo
	echo "Wrong nr. of arguments passed, usage is 'cx.sh <name of .c file to compile and run>'"
	exit 1
fi

# &> means redirecting stdout (>) and stderr (&) to chosen file
# /dev/null is basically a black hole, anything that is written there is deleted. So we are simply "trashing" the compilation output

# Removing compiled file
rm -f $1.o &> /dev/null

# Compiling the corresponding .c file
gcc -Wall -o $1.o $1.c &> /dev/null

# Checking for successful compilation
if [[ ! $? -eq 0 ]]
then
	echo
	echo "COMPILATION ERROR"
	exit 2
fi

# If compilation successful, execute program:

./$1.o
