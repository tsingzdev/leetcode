# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# Given a string, find the length of the longest substring without repeating characters.
# 
# Examples:
# 
# Given "abcabcbb", the answer is "abc", which the length is 3.
# 
# Given "bbbbb", the answer is "b", with the length of 1.
# 
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic, res, start, = {}, 0, 0
        for i, ch in enumerate(s):
           if ch in dic:
               # update the res
               res = max(res, i-start)
               start = max(start, dic[ch]+1)
           dic[ch]=i
        return max(res, len(s)-start)  
