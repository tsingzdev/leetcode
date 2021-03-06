# https://leetcode.com/problems/binary-tree-inorder-traversal/description/
# Given a binary tree, return the inorder traversal of its nodes' values.
# 
# Example:
# 
# Input: [1,null,2,3]
#    1
#     \
#      2
#     /
#    3
# 
# Output: [1,3,2]
# Follow up: Recursive solution is trivial, could you do it iteratively?

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result, curr = [], root
        while curr: 
            if curr.left is None:
                result.append(curr.val)
                curr = curr.right
            else:
                node = curr.left
                while node.right and node.right!=curr:
                    node = node.right
                if node.right is None:
                    node.right = curr
                    curr = curr.left
                else:
                    result.append(curr.val)
                    node.right = None
                    curr = curr.right
        return result

class Solution2(object):        
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype List[int]
        """
        result, stack = [], [(root, False)]
        while stack:
            root, is_visited = stack.pop()
            if root is None:
                continue
            if is_visited:
                result.append(root.val)
            else:
                stack.append((root.right, False))
                stack.append((root, True))
                stack.append((root.left, False))
        return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    result = Solution().inorderTraversal(root)
    print result
