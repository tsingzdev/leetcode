//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> v;

        while(stack.size()>0 || root!=NULL) {
            if(root!=NULL) {
                stack.push_back(root);
                root = root->left;
            } else {
                if(stack.size() > 0) {
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            
            }
        }
        return v;
        
    }
};
