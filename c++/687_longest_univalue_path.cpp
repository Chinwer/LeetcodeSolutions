/*
 * 687. Longest Univalue Path
 *
 * Given a binary tree, find the length of the longest path where each node
 * in the path has the same value. This path may or may not pass through the root.
 * The length of path between two nodes is represented by the number of edges between them.
 *
 * Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
        int res = 0;

    public:
        int longestUnivaluePath(TreeNode* root) {
            check(root);
            return res;
        }

        int check(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int l = check(root->left);
            int r = check(root->right);
            int lmax = 0, rmax = 0;
            if (root->left && root->left->val == root->val) {
                lmax += l + 1;
            }
            if (root->right && root->right->val == root->val) {
                rmax += r + 1;
            }
            res = max(res, lmax + rmax);
            return max(lmax, rmax);
        }
};
