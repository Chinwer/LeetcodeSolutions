/*
 * 814. Binary Tree Pruning
 *
 * We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
 *
 * Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
 *
 * (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
 *
 * Note:
 *
 * The binary tree will have at most 100 nodes.
 * The value of each node will only be 0 or 1.
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
        TreeNode* pruneTree(TreeNode* root) {
            recursion(root);
            return root;
        }

        bool recursion(TreeNode *root) {
            if (!root) {
                return false;
            }
            bool l = recursion(root->left);
            if (!l) {
                root->left = nullptr;
            }
            bool r = recursion(root->right);
            if (!r) {
                root->right = nullptr;
            }
            return l || r || root->val == 1;
        }
};
