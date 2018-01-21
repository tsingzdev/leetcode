# url: https://leetcode.com/problems/powx-n/description/


# Solution 1:
class Solution:
    def myPow(self, x, n):
        """
            :type x: float
             :type n: int
             :rtype: float
             """
             return x**n


# Solution 2: Recursive
class Solution: 
    def myPow(self, x, n):
        if not n:
            return 1
        if n < 0:
            return 1/self.myPow(x, -n)
        if n % 2:
            return x*self.myPow(x, n-1)

        return self.myPow(x*x, n/2)
            
        
        
# Solution 3: iterative
class Solution:
    def myPow(self, x, n):
        if n<0:
            x = 1/x
            n = -n
        pow = 1
        while n:
            if n&1:
                pow*=x
            x*=x
            n>>=1
        return pow

