/*
 * 107. Binary Tree Level Order Traversal II
 *
 * Given a binary tree, return the bottom-up level order traversal
 * of its nodes' values. (ie, from left to right, level by level
 * form leaf to root).
 *
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            // return bfs(root);
            int depth = get_depth(root);
            vector<vector<int>> res(depth);
            dfs(root, 0, depth, res);
            return res;
        }

        void dfs(TreeNode *root, int cur_depth,
            int depth, vector<vector<int>> &res) {
            if (!root) {
                return;
            }
            res[depth - 1 - cur_depth].push_back(root->val);
            dfs(root->left, cur_depth + 1, depth, res);
            dfs(root->right, cur_depth + 1, depth, res);
        }

        int get_depth(TreeNode *root) {
            if (!root) {
                return 0;
            }
            return max(get_depth(root->left), get_depth(root->right)) + 1;
        }

        vector<vector<int>> bfs(TreeNode* root) {
            if (!root) {
                return {};
            }
            TreeNode *cur;
            queue<TreeNode *> q;
            q.push(root);
            vector<vector<int>> res;
            while (!q.empty()) {
                vector<int> nums;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
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
            reverse(res.begin(), res.end());
            return res;
        }
};
