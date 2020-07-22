/*
 * 965. Univalued Binary Tree
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * Return true if and only if the given tree is univalued.
 *
 * Note:
 * The number of nodes in the given tree will be in the range [1, 100].
 * Each node's value will be an integer in the range [0, 99].
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
        bool isUnivalTree(TreeNode* root) {
            return recursion(root);
        }

        bool recursion(TreeNode *root) {
            bool l = !root->left ||
                (root->left->val == root->val && recursion(root->left));
            bool r = !root->right ||
                (root->right->val == root->val && recursion(root->right));
            return l && r;
        }
};
