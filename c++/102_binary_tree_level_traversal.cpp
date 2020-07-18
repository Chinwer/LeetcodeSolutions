/*
 * 102. Binary Tree Level Order Traversal
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
        vector<vector<int>> res;
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            // dfs(root, 0);
            // return res;

            if (!root) {
                return res;
            }
            queue<TreeNode *> q;
            TreeNode *cur = root;
            q.push(cur);
            while (!q.empty()) {
                int size = q.size();
                vector<int> nums;
                while (size--) {
                    cur =  q.front();
                    q.pop();
                    nums.push_back(cur->val);
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                }
                if (!nums.empty()) {
                    res.push_back(nums);
                }
            }
            return res;
        }

        void dfs(TreeNode *root, int level) {
            if (!root) {
                return;
            }
            if (level >= res.size()) {
                res.push_back(vector<int>());
            }
            res[level].push_back(root->val);
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        }
};
