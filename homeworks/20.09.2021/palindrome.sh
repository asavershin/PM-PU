#!/bin/bash

line=$1

enil=$(echo $line|rev)

lenght=${#line}


if [[ ${line:0: $((lenght/2))} == ${enil:0: $((lenght/2))} ]]; then
	echo $line is palindrome
else
	echo $line is not palindrome
fi      



         
echo succesful!
