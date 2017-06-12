#https://leetcode.com/problems/single-number-ii/#/description

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
