/*
 * 543. Diameter of Binary Tree
 *
 * Given a binary tree, you need to compute the length of the diameter
 * of the tree. The diameter of a binary tree is the length of the
 * longest path between any two nodes in a tree. This path may or may
 * not pass through the root.
 *
 * Note: The length of path between two nodes is represented by the
 * number of edges between them.
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
        int diameterOfBinaryTree(TreeNode* root) {
            dfs(root);
            return res;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int ldepth = dfs(root->left);
            int rdepth = dfs(root->right);
            res = max(res, ldepth + rdepth);
            return max(ldepth, rdepth) + 1;
        }
};
