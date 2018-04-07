"""
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
class Solution(object):
    def numTrees(self, n):
        """
        :type n:int
        :rtype int
        """
        if n ==0:
            return 1
        def combination(n,k):
            count =1
            # C (n,k) = (n)/1*(n-1)/2 ... *(n-k+1)/k
            for i in xrange(1, k+1):
                count = count+ (n-i+1)/i
            return count
        return combination(2*n, n) - cimbination(2*n, n-1)



         

