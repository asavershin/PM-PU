#! /bin/bash

subject=""

while read subject
do


touch "$subject"/`date "+%Y-%m-%d"`.log

cat >> "$subject"/`date "+%Y-%m-%d"`.log


done

echo done! 