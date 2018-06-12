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

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++) {
            if(nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i]) -1] *= -1;
            }
        }
        vector<int> result;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]>0) {
                result.emplace_back(i+1);
            } else {
                nums[i]*=-1;
            }
        }
        return result;
    }
};

