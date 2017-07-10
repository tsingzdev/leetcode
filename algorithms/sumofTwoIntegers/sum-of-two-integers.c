/*URL: https://leetcode.com/problems/sum-of-two-integers/#/description
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 * */

int getSum(int a, int b) {
        while (b) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
        
}
