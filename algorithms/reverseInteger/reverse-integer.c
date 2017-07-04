/*https://leetcode.com/problems/reverse-integer/#/description
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.*/


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


