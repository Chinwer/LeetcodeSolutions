/*
 * 面试题 04.04. Check Balance LCCI
 *
 * Implement a function to check if a binary tree is balanced.
 * For the purposes of this question, a balanced tree is defined
 * to be a tree such that the heights of the two subtrees of
 * any node never differ by more than one.
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
