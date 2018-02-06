/*
 * Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.

*/

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for (i = 0; i< numsSize; i++) {
        while(nums[i] > 0 && nums[i]< numsSize && nums[nums[i]-1] != nums[i]) {
            int t = nums[i];
            nums[i] = nums[t-1];
            nums[t-1] = t;

        }
    }

    for(i = 0; i<numsSize; i++) {
        if(nums[i]!=i+1) {
            break;
        }
    }

    return i+1;
}

