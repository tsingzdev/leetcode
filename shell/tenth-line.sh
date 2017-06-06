#!/bin/bash
#https://leetcode.com/problems/tenth-line/

#Solution1:
cnt=0
while read line && [ $cnt -le 10 ]; do
    let 'cnt = cnt + 1'
    if [ $cnt -eq 10 ]; then
        echo $line
        exit 0
    fi
done < file.txt


#Solution 2:
tail -n+10 file1.txt | head -1

#Solution 3:
sed -n 10p file1.txt
