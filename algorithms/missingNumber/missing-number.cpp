/* https://leetcode.com/problems/missing-number/description/
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 * 
*/

//Solution 1: 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> expected(nums.size());
        iota(expected.begin(), expected.end(), 1);
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>()) ^
            accumulate(expected.cbegin(), expected.cend(), 0, bit_xor<int>());
    }
};

//Solution 2:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num=0;
        for(int i =0; i<nums.size(); i++) {
            num^=nums[i]^(i+1);
        }
        return num;
    }
};

