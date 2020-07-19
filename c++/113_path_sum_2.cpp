/*
 * 113. Path Sum II
 *
 * Given a binary tree and a sum, find all root-to-leaf paths
 * where each path's sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
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
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<int> path;
            // dfs(root, sum, path, 0);
            iterate(root, sum, path, 0);
            return res;
        }

        void iterate(TreeNode *root, int sum, vector<int> &path, int s) {
            stack<TreeNode *> nodes;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !nodes.empty()) {
                while (cur) {
                    s += cur->val;
                    nodes.push(cur);
                    path.push_back(cur->val);
                    cur = cur->left;
                }
                cur = nodes.top();
                if (!cur->right || cur->right == pre) {
                    if (!cur->left && !cur->right && s == sum) {
                        res.push_back(path);
                    }
                    pre = cur;
                    nodes.pop();
                    s -= cur->val;
                    path.pop_back();
                    cur = nullptr;
                } else {
                    cur = cur->right;
                }
            }
        }

        void dfs(TreeNode *root, int sum, vector<int> &path, int s) {
            if (!root) {
                return;
            }
            path.push_back(root->val);
            s += root->val;
            if (s == sum && !root->left && !root->right) {
                res.push_back(path);
                path.pop_back();
                return;
            }
            dfs(root->left, sum, path, s);
            dfs(root->right, sum, path, s);
            path.pop_back();
        }
};
