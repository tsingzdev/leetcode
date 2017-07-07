/*URL: https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 *
 *
 * */
#include <stdio.h>

//The solution is Time Limit Exceeded .   
int rangeBitwiseAnd_0(int m, int n) {
    int ret= m;
    while (m<n) {
        m++;
        ret &= m;
    }
    return ret;
}

int rangeBitwiseAnd(int m, int n) {
    while (m < n) {
        n = n & n-1;
    }
    return m&n;
}


int main () {
    int m = 5, n = 7;
    printf("%d\n", rangeBitwiseAnd(m,n));

}
