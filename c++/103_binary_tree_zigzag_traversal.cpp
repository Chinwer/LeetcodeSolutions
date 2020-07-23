/*
 * 103. Binary Tree Zigzag Level Order Traversal
 *
 * Given a bianry tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (!root) {
                return {};
            }
            TreeNode *cur;
            queue<TreeNode *> q;
            q.push(root);
            bool flag = false;
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
                if (flag) {
                    reverse(nums.begin(), nums.end());
                }
                if (!nums.empty()) {
                    res.push_back(nums);
                }
                flag = !flag;
            }
            return res;
        }
};
