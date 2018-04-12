/*URL:https://leetcode.com/problems/binary-tree-inorder-traversal/#/description
 *Given a binary tree, return the inorder traversal of its nodes' values.

 *For example:
 *Given binary tree [1,null,2,3],
 1
 \
 2
 /
 3
 * return [1,3,2].

 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * */

/*
#include<stdio.h>
#include<stdlib.h>
*/

// Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct StackNode {
    struct TreeNode *val;
    struct StackNode *next;
}

struct Stack {
    struct StackNode *top_pt;
    int size;
}
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[2048], *p, *pre;
    int *arr, pos, n;

    arr = (int*) malloc(2048*sizeof(int));

    pos = n = 0;
    pre = NULL;

    p = root;
    while(p) {
        stack[pos++] = p;
        p = p->left;
    }

    while(pos) {
        p = stack[--pos];
        arr[n++] = p->val;

        p = p->right;
        while(p) {
            stack[pos++] = p;
            p = p->left;
        }
    }
    *returnSize = n;
    return arr;
}

