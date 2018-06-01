/*https://leetcode.com/problems/number-of-1-bits/#/description
 *Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

 For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 *
 * */
#include<stdio.h>
#include<stdint.h>

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n>0) {
        if(n%2) {
            ans++;
        }
        n/=2;
    }
    return ans;
}

int hammingWeight2(uint32_t n) {
    int ans = 0;
    while (n) {
        n = n & (n-1);
        ans++;
    }     
    return ans;
}

int hammingWeight3(uint32_t n) {
    int ans = 0;
    for (; n>0;n/=2) {
        if(n & 0x1)  // which means n is an odd number, euals to the chech if(n%2)
           ans++; 
    }
    return ans;
}

int main () {
    uint32_t n = 11;
    uint32_t m = 7;
    uint32_t p = 9999;
    printf("%d\n", hammingWeight2(n));
    printf("%d\n", hammingWeight2(m));
    printf("%d\n", hammingWeight2(p));
    return 0;

}


