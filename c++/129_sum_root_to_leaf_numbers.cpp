/*
 * 129. Sum Root to Leaf Numbers
 *
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * Note: A leaf is a node with no children.
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
        int sumNumbers(TreeNode* root) {
            // return dfs(root, 0);
            // return bfs(root);
            return iteration(root);
        }

        int iteration(TreeNode *root) {
            int res = 0, path = 0;
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    path = 10 * path + cur->val;
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                if (cur->right && cur->right != pre) {
                    cur = cur->right;
                } else {
                    if (!cur->left && !cur->right) {
                        res += path;
                    }
                    path = (path - cur->val) / 10;
                    s.pop();
                    pre = cur;
                    cur = nullptr;
                }
            }

            return res;
        }

        int bfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int res = 0;
            stack<pair<int, TreeNode *>> s;
            s.push(pair(root->val, root));
            while (!s.empty()) {
                int path = s.top().first;
                TreeNode *cur = s.top().second;
                s.pop();
                if (cur->left) {
                    s.push(pair(10 * path + cur->left->val, cur->left));
                }
                if (cur->right) {
                    s.push(pair(10 * path + cur->right->val, cur->right));
                }
                if (!cur->left && !cur->right) {
                    res += path;
                }
            }
            return res;
        }

        int dfs(TreeNode *root, int path) {
            if (!root) {
                return 0;
            }
            path = 10 * path + root->val;
            if (!root->left && !root->right) {
                return path;
            }
            int lsum = dfs(root->left, path);
            int rsum = dfs(root->right, path);
            return lsum + rsum;
        }
};
