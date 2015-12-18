#!/bin/bash

#https://leetcode.com/problems/transpose-file/ 

awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt


# Solution 2
#awk '
#{ 
#    for(i=1; i<=NF; ++i) {
#        if (word[i] == "") {
#            word[i] = $i
#        } else{
#            word[i] = word[i]" "$i
#        }
#    }
#} 
#
#END { 
#    for(i=1; i<=NF; ++i) {
#        print word[i]
#    }
#}' file.txt
#
