#!/bin/bash
#https://leetcode.com/problems/tenth-line/

cnt=0
while read line && [ $cnt -le 10 ]; do
    let 'cnt = cnt + 1'
    if [ $cnt -eq 10 ]; then
        echo $line
        exit 0
    fi
done < file.txt

