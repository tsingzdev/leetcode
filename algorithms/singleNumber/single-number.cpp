/*url: https://leetcode.com/problems/single-number/#/description
 
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
* 
*/
/*
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>() );

    }
};

/*
int main () {
    vector<int> nums =  {1, 2, 3, 4, 1, 2, 4};
    Solution s;
    printf ("%d\n", s.singleNumber(nums, 7));
    return 0;
}
*/
