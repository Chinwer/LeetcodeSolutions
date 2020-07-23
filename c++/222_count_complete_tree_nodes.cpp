/*
 * 222. Count Complete Tree Nodes
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
        int countNodes(TreeNode* root) {
            // return dfs_recursion(root);
            return dfs_iteration(root);
        }

        int dfs_iteration(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int res = 0;
            int left = height(root->left);
            while (root) {
                int right = height(root->right);
                if (left == right) {
                    res += (1 << left);
                    root = root->right;
                } else {
                    res += (1 << right);
                    root = root->left;
                }
                left--;
            }
            return res;
        }

        int height(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int res = 0;
            while (root) {
                res++;
                root = root->left;
            }
            return res;
        }

        int dfs_recursion(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int lcnt = dfs_recursion(root->left);
            int rcnt = dfs_recursion(root->right);
            return lcnt + rcnt + 1;
        }
};
