/*URL: https://leetcode.com/problems/power-of-four/#/description
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 * *
 */


bool isPowerOfFour(int num) {
    static int mask = 0b01010101010101010101010101010101;
    
    if (num a=< 0) return false;
    
    if (num & num-1) !=0 return false;

    if ((num & mask) !=0 ) return true;

    return false;
        
}
