// https://leetcode.com/problems/first-missing-positive/description/
// Given an unsorted integer array, find the smallest missing positive integer.
/*
 * Example 1:
 * 
 * Input: [1,2,0]
 * Output: 3
 * Example 2:
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * Example 3:
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 */

class Solution {
    public int firstMissingPositive(int[] nums) {
        int start = 0;
        int end = nums.length -1;
        while(start <= end) {
            int index = nums[start]-1;
            if (index ==start)
                start++;
            else if (index < 0 || index>end || nums[start] == nums[index])
                nums[start] = nums[end--];
            else {
                nums[start] = nums[index];
                nums[index] = index +1;
            }
        }
        return start+1;
    }
}

