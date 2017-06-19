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


int main () {
    uint32_t n = 11;
    printf("%d\n", hammingWeight2(n));
    return 0;
}
