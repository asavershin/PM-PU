#!/bin/bash

for((i=33;i<=255;i++)) do 
	printf "$i --> ";
	printf \\$(printf '%03o\t' "$i");
	printf '\n' ;
done;
printf "\n"