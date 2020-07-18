/*
 * 94. Binary Tree Inorder Traversal
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
        vector<int> res;
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            // if (root) {
            //     inorderTraversal(root->left);
            //     res.push_back(root->val);
            //     inorderTraversal(root->right);
            // }
            // return res;

            stack<TreeNode *> s;
            TreeNode *node = root;
            while (node || !s.empty()) {
                while (node) {
                    s.push(node);
                    node = node->left;
                }
                node = s.top();
                s.pop();
                res.push_back(node->val);
                node = node->right;
            }
            return res;
        }
};
