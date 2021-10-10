#!/bin/bash

function akkerman {
    
    local temp
    local result=0
    local temp2
    local temp3
    local temp4
	if (( $1 == 0 ))
    then
        echo $(($2+1))
    fi
    if (( ($1>0) && ($2 == 0) ))
    then
        temp2=$(($1-1))
        result=$(akkerman $temp2 1)
        echo $result
    fi
    if (( ($1>0) && ($2>0) ))
    then
        temp3=$(($2-1))
        temp4=$(($1-1))
        temp=$(akkerman $1 $temp3)
        result=$(akkerman $temp4 $temp)
        echo $result
        
    fi
     
}
read a
read b
result=$(akkerman a b)
echo $result
echo done!
