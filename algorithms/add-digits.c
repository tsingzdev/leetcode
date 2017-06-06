/*URL: https://leetcode.com/problems/add-digits/#/description

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

 For example:

 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

 Follow up:
 Could you do it without any loop/recursion in O(1) runtime?
 * */
#include<stdio.h>


int addDigits0(int num) {
        return 1+ (num-1)%9;
}

int addDigits(int num) {
    int ret=0;
    while(num) {
        ret+=num%10;
        num/=10;
        if(ret>=10)
            ret = ret/10+ret%10;
    }
    return ret;

}

int main () {

    printf(" %d\n", addDigits(1235));

    return 0;
}
