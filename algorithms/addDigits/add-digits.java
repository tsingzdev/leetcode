/*URL: https://leetcode.com/problems/add-digits/description/
 *
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * Example:
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 *              Since 2 has only one digit, return it.
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

class Solution {
    public int addDigits(int num) {
        return (num>9 ? ((num%9 == 0 ) ? 9 : num%9) : num);
    }

    public int addDigits2(int num) {
        while(num > 9) {
            num = num%10+ num/10;
        } 
        return num; 
    }
}
