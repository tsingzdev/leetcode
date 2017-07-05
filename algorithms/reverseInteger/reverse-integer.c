/*https://leetcode.com/problems/reverse-integer/#/description
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1) //see to: http://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c


int reverse(int x) {
    int ret = 0;
    while(x!=0) {
        int tmp = ret*10+x%10;
        x = x/10;
        if(tmp/10 !=ret) {
            ret = 0;
            break;
        }
        ret = tmp;
    }
    return ret;
}


int reverse2(int x) {
    int ret = 0;
    while (x!=0) {
        // check the over/underflow 
        if(ret > INT_MAX/10 || ret < INT_MIN/10) {
            return 0;
        }

        ret = ret*10 + x%10;
        x/=10;
    }    
    return ret;
}


#define TEST(x) printf("reverse of %d is %d\n",x, reverse2(x));

int main () {
    // basic cases
    TEST(-100);
    TEST(-123);
    TEST(123);
    // overflow cases
    TEST(1000000003);
    TEST(2147483647);
    TEST(-2147483648);
    TEST(-2147483412);

}
