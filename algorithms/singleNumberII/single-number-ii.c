/*URL: https://leetcode.com/problems/single-number-ii/#/description
  
*Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*
* */
# include <stdio.h>

/*Sulution 1*/
int singleNumber(int* nums, int numsSize) {
    int count[32] = {0};
    int result = 0;

    for ( int i = 0; i < 32; i++) {
        for (int j = 0; j < numsSize; j++) {
            if ((nums[j]>>i )&1) {
                count[i]++;
            }
        }     
        result|=((count[i]%3) << i);
    }
    return result;
}

/*Solution 2 */
int singleNumber2(int A[], int n) {
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones % A[i];
        ones ^= A[i];
        threes = ones & twos;

        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}

int main () {
    int a[ ]= {1,1,1,2 ,2,2,5}; 
    printf("%d\n",singleNumber2(a, 7) );
    return 0;
}
