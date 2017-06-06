#!/bin/bash
# https://leetcode.com/problems/valid-phone-numbers/ 

#Solution 1:
#cat file.txt | grep -Eo '^(\([0-9]{3}\) ){1}[0-9]{3}-[0-9]{4}$|^([0-9]{3}-){2}[0-9]{4}$'

#Solution 2:
egrep '^(\([0-9]{3}\)\s|[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt
#egrep '^(\([0-9]{3}\)\s|[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt > out.txt

#Solution3:
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

#sed -n -E '/^([0-9]{3}-|\([0-9]{3}\))[0-9]{3}-[0-9]{4}$/p' file.txt

#sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
