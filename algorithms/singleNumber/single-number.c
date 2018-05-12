/*url: https://leetcode.com/problems/single-number/#/description
 
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
* 
*/
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for (int i =0; i< numsSize; i++) {
        ret^=nums[i];
    }
    return ret;
}

int main () {
    int a[] = {1, 2, 3, 4, 1, 2, 4};
    printf ("%d\n", singleNumber(a, 7));
    return 0;
}
