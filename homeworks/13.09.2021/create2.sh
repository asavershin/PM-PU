#! /bin/bash

exec 2> /dev/null 

mkdir $1

echo "enter the subjects, if you want to end, press ctrl+d"

subject=""

while read subject 
	do

		mkdir $1/"$subject"/
	done

cp ~/Desktop/terminal/subject.sh ~/Desktop/terminal/semestr2/

echo succesful!

cd semestr2

./subject.sh