/*
 * 144. Binary Tree Preorder Traversal
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Follow up:
 *   Recrusive solution is trivial, could you do it iteratively?
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
        vector<int> preorderTraversal(TreeNode* root) {
            // if (root) {
            //     res.push_back(root->val);
            //     preorderTraversal(root->left);
            //     preorderTraversal(root->right);
            // }
            // return res;

            stack<TreeNode*> s;
            s.push(root);
            while (!s.empty()) {
                TreeNode *node = s.top();
                s.pop();
                if (node) {
                    res.push_back(node->val);
                    s.push(node->right);
                    s.push(node->left);
                }
            }
            return res;
        }
};
