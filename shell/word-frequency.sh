#!/bin/bash
# https://leetcode.com/problems/word-frequency/

# https://leetcode.com/discuss/29049/my-simple-solution-one-line-with-pipe
#cat words.txt | tr -s ' ' '\n' | sort -r | uniq -c | awk '{print $2, $1}' # buggy
#Solution 1:
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}' 

#Solution 2
#cat words.txt | tr -s '[[:space:]]' '\n'| sort | uniq -c | sort -r | sed -r -e 's/[[:space:]]*([[:digit:]]+)[[:space:]]*([[:alpha:]]+)/\2 \1/g'

