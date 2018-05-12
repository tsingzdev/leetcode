/*URL: https://leetcode.com/problems/single-number-ii/#/description

 * Given an array of integers, every element appears three times except for one, 
 * which appears exactly once. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you 
 * implement it without using extra memory?
 * 
 * Example 1:
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * Example 2:
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 * */
# include <stdio.h>

/*Sulution 1*/
/*
 *  This solution is clear & straightforward implementation.
 *  We use an array of 32 length(e.g. count[32]) to count the the bits for all of numbers. 
 *  Because the same number appear 3 times, which means the sum of i-th bits for all numbers should be 3 times.
 *  In other word, the sum of the i-th bits mod 3, it must be 0 or 1. 1 means that is the single number bit.
 *  This solution can be easy to extend to "every element appears k times except for one."
 */
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
/*
 *
 *   The following solution is popular solution on Internet, but it looks it's not easy to understand.
 *
 *   Actually, it just optimizes the above soultion.
 *
 *   Let's see how it improve the above.
 *
 *   We use three bitmasks, 
 *    1) `ones`     as a bitmask which represents the i-th bit had appeared once.
 *    2) `twos`     as a bitmask which represents the i-th bit had appeared twice.
 *    3) `threes`   as a bit mask which represents the i-th bit had appeared three times.
 *
 *    When the i-th bit had appeared for the third time, clear the i-th bit of both `ones` and `twos` to 0.
 *    The final answer will be the value of `ones`
 *
 */
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
