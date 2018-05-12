#https://leetcode.com/problems/single-number-ii/#/description
# Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
# 
# Note:
# 
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
# 
# Example 1:
# 
# Input: [2,2,3,2]
# Output: 3
# Example 2:
# 
# Input: [0,1,0,1,0,1,99]
# Output: 99

import collections

class Solution(object):
    def singleNumber (self, A):
        one, two = 0, 0
        for x in A:
            one, two = (~x & one) | (x & ~one & ~two), (~x &two) | (x &one)
        return one

class Solution2(object):
    def singleNumber (self ,A):
        one, two, carry = 0, 0 ,0
        for x in A:
            two |= one & x
            one^=x
            carry = one & two
            one &= ~carry
            two &= ~carry
        return one    

class Solution3(object):
    def singleNumber (self, nums):
        return (collections.Counter(list(set(nums)) *3) - collections.Counter(nums)).keys()[0]

if __name__ == '__main__':
    print Solution3().singleNumber([1,1,1,2,2,2,6])
