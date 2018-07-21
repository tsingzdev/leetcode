# https://leetcode.com/problems/permutations/description/
# Given a collection of distinct integers, return all possible permutations.
# 
# Example:
# 
# Input: [1,2,3]
# Output:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]

class Solution(object):
    def permute(self, num):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        result = []
        used = [False] * len(num)
        self.permuteRecu(result, used, [], num)
        return result

    def permuteRecu(self, result, used, cur, num):
        if len(cur) == len(num):
            result.append(cur + [])
            return

        for i in xrange(len(num)):
            if not used[i]:
                used[i] = True
                cur.append(num[i])
                self.permuteRecu(result, used, cur, num)
                cur.pop()
                used[i] = False

if __name__ == "__main__":
    print Solution().permute([1,2,3])

