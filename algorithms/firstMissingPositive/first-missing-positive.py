#  https://leetcode.com/problems/first-missing-positive/description/
# Given an unsorted integer array, find the smallest missing positive integer.
# 
# Example 1:
# 
# Input: [1,2,0]
# Output: 3
# Example 2:
# 
# Input: [3,4,-1,1]
# Output: 2
# Example 3:
# 
# Input: [7,8,9,11,12]
# Output: 1
# Note:
# 
# Your algorithm should run in O(n) time and uses constant extra space.

class Solution(object):
    def firstMissingPositive(self, A):
        """
        :@param A, a list of integers
        :@rtype: int
        """
        i = 0;
        while i < len(A):
            if A[i] > 0 and A[i]-1 < len(A) and A[i] != A[A[i]-1]:
                A[A[i]-1] , A[i] = A[i], A[A[i]-1]
            else:
                i += 1

        for i , integer in enumerate(A):
            if integer != i+1:
                return i+1
        return len(A) +1

if __name__ == "__main__":
    print Solution().firstMissingPositive([1,2,0])
    print Solution().firstMissingPositive([3, 4, -1, 1])
