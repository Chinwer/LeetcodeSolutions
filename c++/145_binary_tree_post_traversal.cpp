/*
 * 145. Binary Tree Postorder Traversal
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Follow up: Recursive solution is trivial,could you do it iteratively?
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
        vector<int> postorderTraversal(TreeNode* root) {
            // if (root) {
            //     postorderTraversal(root->left);
            //     postorderTraversal(root->right);
            //     res.push_back(root->val);
            // }
            // return res;

            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                if (!(cur->right) || cur->right == pre) {
                    res.push_back(cur->val);
                    s.pop();
                    pre = cur;
                    cur = nullptr;
                } else {
                    cur = cur->right;
                }
            }
            return res;
        }
};
