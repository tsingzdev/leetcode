/*URL: https://leetcode.com/problems/missing-number/#/description
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 *
 * */
// Solution 1:
int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int ret = 0;
    int sum = 0;
    
    for (int i = 0; i<n; i++) {
        sum+=nums[i];        
    }
    ret = n*(n+1) /2 - sum;
    return ret;
        
}
// Solution 2:
int missingNumber(int* nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i<numsSize; i++) {
        ret = ret^ (i+1) ^ nums[i];
    }
    return ret;
}

