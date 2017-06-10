/*url: https://leetcode.com/problems/single-number/#/description
 *
Given an array of integers, every element appears twice except for one. Find that single one.
 
Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?* 
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
