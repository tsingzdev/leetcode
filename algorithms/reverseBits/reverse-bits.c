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

/*reference: https://graphics.stanford.edu/~seander/bithacks.html*/

#include <stdio.h>
#include <stdint.h>

void printBits(uint32_t n) {
    int i =32;
    while (i--) {
        if ((n>>i) & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    int i = 31;
    while(i--) {
        ret += n&0x01;
        n>>= 1;
        ret <<= 1;
    }
    ret += n&0x01;
    return ret;
}

int main () {
    uint32_t n = 43261596;
    uint32_t m = 1; 
    uint32_t p = 2147483648; 

    printBits(m);
    printBits(n);
    printBits(p);
    printf("%d\n", reverseBits(m));
    printf("%d\n", reverseBits(n));
    printf("%d\n", reverseBits(p));
    return 0;
}

