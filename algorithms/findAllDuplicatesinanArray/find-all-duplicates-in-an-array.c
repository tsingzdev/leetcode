//https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
/*Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 **/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int*ret = (int*)malloc(numsSize*sizeof(int));
    int i,j;

    memset(ret, 0, numsSize*sizeof(int));

    for(i =0,j=0; i<numsSize; i++) {
        if(ret[nums[i] -1]++)
            j++;
    }
    *returnSize = j;
    for(i =0, j=0; i<numsSize; i++) {
        if(ret[i]>1) 
            ret[j++] = i+1;
    }
    return ret;
}

