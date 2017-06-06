#!/bin/bash
# https://leetcode.com/problems/word-frequency/

# https://leetcode.com/discuss/29049/my-simple-solution-one-line-with-pipe

#Solution 1:
#cat words.txt | tr -s ' ' '\n' | sort -r | uniq -c | awk '{print $2, $1}' # buggy
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}' 


#Solution2: 
#awk '{for(i=1;i<=NF;i++) a[$i]++} END {for(k in a) print k,a[k]}' words.tx    t # not working, no sort
awk '{for(i=1;i<=NF;i++) a[$i]++} END {for(k in a) print k,a[k]}' words.txt     | sort -k2 -nr
