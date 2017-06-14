/*
 * URL: https://leetcode.com/problems/single-number-iii/#/description
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 *1.  The order of the result is not important. So in the above example, [5, 3] is also correct.
 *2.  Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 *
 * */
#include <stdio.h>
#include <stdlib.h>


int* singleNumber(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || returnSize == NULL) return 0;
    *returnSize = 2;
    int *ans = (int *)calloc (*returnSize, sizeof(int));

    int x = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        x^=nums[i];
    }
    int k =0;
    while (((x>>k) &1) == 0 ) k++;
    int a=0, b=0;
    for (i=0; i<numsSize; i++) {
        if(nums[i] &(1<<k)) {
            a^=nums[i];
        }
        else {
            b^=nums[i];
        }
    }

    ans[0] = a;    
    ans[1] = b;    

    return ans;
}

int main () {
    int nums[] = {1,2,1,2,3,5};
    int returnSize = 0;
    int *ans = singleNumber(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    int i;
	for (i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);

    return 0;


}

