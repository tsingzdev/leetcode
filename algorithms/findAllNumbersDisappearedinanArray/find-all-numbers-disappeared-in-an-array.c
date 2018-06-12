// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * */ 

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* retSize) {
    int i, *ret;
    for(i = 0; i<numsSize; i++) {
        //nums[abs(nums[i]) - 1] *= -1; 
        nums[abs(nums[i]) - 1] = - abs( nums[abs(nums[i]) - 1] );
    }
    ret = malloc((*retSize = 0) *sizeof(int));
    for(i = 0; i<numsSize; i++) {
        if(nums[i] > 0) {
            ret = realloc(ret, ++*retSize * sizeof(int));
            ret[*retSize -1] = i+1;
        }
    }
    return ret;
}
