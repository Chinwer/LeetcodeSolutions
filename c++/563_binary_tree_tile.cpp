/*
 * 563. Binary Tree Tilt
 *
 * Given a binary tree, return the tilt of the whole tree.
 * The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 * Note:
 * The sum of node values in any subtree won't exceed the range of 32-bit integer.
 * All the tilt values won't exceed the range of 32-bit integer.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        int res;

    public:
        int findTilt(TreeNode* root) {
            dfs(root);
            return res;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int lsum = dfs(root->left);
            int rsum = dfs(root->right);
            res += abs(lsum - rsum);
            return lsum + rsum + root->val;
        }
};
