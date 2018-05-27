/* https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 *
 *
 * */

// Soluton 1: 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int k = 0;
		while (1) {
            if(n>m) {
                k = k+1;
            } else {
                return m<<k;
            }
            m = m>>1;
            n = n>>1;
		}
        return m;
    }
};

// Solution 2: 
//
class Solution {
    public:
        int rangeBitwiseAnd (int m , int n) {
            if (n>m) {
                return rangeBitwiseAnd(m>>1, n>>1) <<1;
            } else {
                return m;
            }
        }
}
