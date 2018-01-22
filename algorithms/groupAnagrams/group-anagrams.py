# https://leetcode.com/problems/group-anagrams/description/

# Given an array of strings, group anagrams together.

import collections
class Solution(object):
    def groupAnagrams(self, strs):
        """
            :type strs: List[str]
             :rtype: List[List[str]]
             """
         
        anagrams_map, result = collections.defaultdict(list), []        
        for s in strs:
           sorted_str = ("").join(sorted(s))
           anagrams_map[sorted_str].append(s)
        for anagram in anagrams_map.values():
            anagram.sort()
            result.append(anagram)
        return result


if __name__ == "__main__":
    result = Solution().groupAnagrams(["cat", "dog", "act", "mac"])
    print result
