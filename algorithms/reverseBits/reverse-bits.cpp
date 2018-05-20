/*https://leetcode.com/problems/reverse-bits/#/description
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *
 * */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int count = 32;
        while (count--) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};
