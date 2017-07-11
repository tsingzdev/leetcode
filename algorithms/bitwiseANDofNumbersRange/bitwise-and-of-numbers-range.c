/*URL: https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 *
 *
 * */
#include <stdio.h>

// Solution 1:  is Time Limit Exceeded .   
// see to this : http://bookshadow.com/weblog/2015/04/17/leetcode-bitwise-and-numbers-range/
// given the range 0 <= m <= n <= 2147483647, time complexity more than O(n) is not acceptable.
int rangeBitwiseAnd_0(int m, int n) {
    int ret= m;
    while (m<n) {
        m++;
        ret &= m;
    }
    return ret;
}

// Solution 2
int rangeBitwiseAnd(int m, int n) {
    while (m < n) {
        n = n & n-1;
    }
    return m&n;
}

// Solution 3 
// the result should be the common left header of m and n
int rangeBitwiseAnd(int m, int n) {
    int p = 0;
    int ret = 0;
    while (m!=n){
        m>>=1;
        n>>=1;
        p+=1;
    }
    ret = m<<p;
    return ret;
}

int main () {
    int m = 5, n = 7;
    printf("%d\n", rangeBitwiseAnd(m,n));
}
