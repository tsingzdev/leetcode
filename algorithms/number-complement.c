/*URL:https://leetcode.com/problems/number-complement/#/description
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 *
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer’s binary representation.
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 * */

int findComplement(int num) {
    long i; /*int i ;  type will result in wrong answer: Input:    2147483647
                                                    Output:   -2147483648
                                                    Expected: 0
            */
    // unsigned i; // OK 
    for (i = 1; i<= num; i<<=1) {
        num^=i;
    }
    return num;
}
