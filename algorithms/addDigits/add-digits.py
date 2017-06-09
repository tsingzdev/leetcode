#url: https://leetcode.com/problems/add-digits/#/description
# 

class Solution:
    def addDigits(self, num):
        return (num-1) % 9 +1 if num>0 else 0


if __name__ == '__main__':
    s= Solution()
    r = s.addDigits(123456)
    print r


