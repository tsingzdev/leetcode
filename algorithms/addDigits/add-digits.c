/*URL: https://leetcode.com/problems/add-digits/#/description

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

 For example:

 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

 Follow up:
 Could you do it without any loop/recursion in O(1) runtime?
 * */
#include <stdio.h>
#include <assert.h>


int addDigits0(int num) {
        return 1+ (num-1)%9;
}

int addDigits1(int num) {
    int ret=0;
    while(num) {
        ret+=num%10;
        num/=10;

        if(ret>=10)
            ret = ret/10+ret%10;
    }
    return ret;
}

int addDigits2(int num) {
    while (num > 9) {
        num = num/10 + num%10;
    }
    return num;
}

int addDigits(int num) {
    return num > 9 ? ((num%9)==0 ? 9 : num%9  ) :num;
}

int main () {

    assert(addDigits(0)==0);
    assert(addDigits(1)==1);
    assert(addDigits(18)==9);
    assert(addDigits(12345)==6);
    printf("all tests passed!\n");

    printf(" %d\n", addDigits(1235));

    return 0;
}
