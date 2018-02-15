#!/usr/bin/env bash

# Checking if only exactly one argument was given
# $# is the number of arguments
if [[ !  $# -eq 1 ]]
then
	echo
	echo "Wrong nr. of arguments passed, usage is 'p9b.sh <number until which to create files>'"
	exit 1
fi

echo "Starting with argument $1..."

# This is an example that will run from 01 to 12
for n in {01..12}
do
	echo "ex1: prob$n"
	#mkdir "prob$n"
done

# "((" can also be used for C-style loops -> (( i=1; i<=4; i++)), this being the only alternative when wanting a variable top limit
for ((i=1; i <= $1; i++))
do
	if (( i <= 9 ))
	then
		echo "ex2: prob0$i"
		#mkdir "prob0$i"
	else
		echo "ex2: prob$i"
		#mkdir "prob$i"
	fi
done

echo "Done!"
