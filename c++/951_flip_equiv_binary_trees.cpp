/*
 * 951. Flip Equivalent Binary Trees
 *
 * For a binary tree T, we can define a flip operation as follows:
 * choose any node, and swap the left and right child subtrees.
 *
 * A binary tree X is flip equivalent to a binary tree Y if and only if
 * we can make X equal to Y after some number of flip operations.
 *
 * Write a function that determines whether two binary trees are flip equivalent.
 * The trees are given by root nodes root1 and root2.
 *
 * Note:
 *
 * Each tree will have at most 100 nodes.
 * Each value in each tree will be a unique integer in the range [0, 99].
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
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            return recursion(root1, root2);
        }

        bool recursion(TreeNode *root1, TreeNode *root2) {
            if (!root1 && !root2) {
                return true;
            }
            if (!root1 || !root2) {
                return false;
            }
            if (root1->val != root2->val) {
                return false;
            }
            bool res1 = recursion(root1->left, root2->left)
                && recursion(root1->right, root2->right);
            bool res2 = recursion(root1->left, root2->right)
                && recursion(root1->right, root2->left);
            return res1 || res2;
        }
};
