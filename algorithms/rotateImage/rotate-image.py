#You are given an n x n 2D matrix representing an image.

#Rotate the image by 90 degrees (clockwise).

#Note:
#You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)  
        # anti-diagonal mirror 
        for i in xrange(n):
            for j in xrange(n-i):
                matrix[i][j], matrix[n-1-j][n-1-i] = matrix[n-1-j][n-1-i],matrix[i][j]


        # horizontal mirror
        for i in xrange(n/2):
            for j in xrange(n):
                matrix[i][j], matrix[n-1-i][j] = matrix[n-1-i][j], matrix[i][j]

        return matrix


class Solution2(object):
    def rotate(self, matrix):
        return [list(reversed(x)) for x in zip(*matrix)]

if __name__ == "__main__":
    matrix = [[1,2,3], [4,5,6], [7,8,9]]
    print Solution2().rotate(matrix)


