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
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        bucketSort(&nums);
        for (; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }

private:
    void bucketSort(vector<int> *nums) {
        int i = 0;
        while (i < nums->size()) {
            if ((*nums)[i] > 0 && (*nums)[i] <= nums->size() &&
                (*nums)[i] != (*nums)[(*nums)[i] - 1]) {
                swap((*nums)[i], (*nums)[(*nums)[i] - 1]);
            } else {
                ++i;
            }
        }
    }
};
