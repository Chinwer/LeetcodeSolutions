/*
 * 110. Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            return dfs(root) != -1;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int lh = dfs(root->left);
            if (lh == -1) {
                return -1;
            }
            int rh = dfs(root->right);
            if (rh == -1 || abs(lh - rh) > 1) {
                return -1;
            }
            return max(lh, rh) + 1;
        }
};
