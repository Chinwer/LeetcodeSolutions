/*
 * 98. Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
        bool isValidBST(TreeNode* root) {
            // return dfs(root, LONG_MIN, LONG_MAX);
            return inorder_traversal(root);
        }

        bool inorder_traversal(TreeNode *root) {
            long pre = LONG_MIN;
            stack<TreeNode *> s;
            TreeNode *cur = root;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                if (cur->val <= pre) {
                    return false;
                }
                pre = cur->val;
                cur = cur->right;
            }
            return true;
        }

        bool dfs(TreeNode *root, long lower, long upper) {
            if (!root) {
                return true;
            }
            if (root->val <= lower || root->val >= upper) {
                return false;
            }
            return dfs(root->left, lower, root->val)
                && dfs(root->right, root->val, upper);
        }
};
