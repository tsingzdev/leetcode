// https://leetcode.com/problems/two-sum/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 *
 */

// 1) Traverse the array one by one
// 2) just put the 'target - num[i]' into the map£¬
// so when checking the next num[i], if found it existed 
// in the map, means we found the second one.

class Solution:{ 
    public:
        vector<int> twoSum (vector<int> &numbers, int target) {
            unordered_map<int, int> m;
            vector<int> result;
            for (int i = 0; i< numbers.size(); i++) {
                // not found the second one
                if (m.find(numbers[i]) ==m.end() ) {
                    // store thr first one position into the second one's key 
                    m[target - numbers[i]] = i;
                } else {
                    //found the second one
                    result.push_back(m[numbers[i]]);
                    result.push_back(i);
                    break;
                }
            }
            return result;
        }

};
