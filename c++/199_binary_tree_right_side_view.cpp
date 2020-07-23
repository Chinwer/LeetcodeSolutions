/*
 * 199. Binary Tree Right Side View
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
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
        vector<int> rightSideView(TreeNode* root) {
            // return bfs(root);

            // dfs_recursion(root, 0);
            // return res;

            return dfs_iteration(root);
        }

        vector<int> dfs_iteration(TreeNode *root) {
            int depth = -1;
            vector<int> res;
            TreeNode *cur = root, *pre = nullptr;
            stack<TreeNode *> s;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    depth++;
                    cur = cur->left;
                }
                cur = s.top();
                if (cur->right && cur->right != pre) {
                    cur = cur->right;
                } else {
                    if (depth >= res.size()) {
                        res.resize(depth + 1);
                    }
                    res[depth] = cur->val;
                    depth--;
                    s.pop();
                    pre = cur;
                    cur = nullptr;
                }
            }
            return res;
        }

        void dfs_recursion(TreeNode *root, int depth) {
            if (!root) {
                return;
            }
            dfs_recursion(root->left, depth + 1);
            if (depth >= res.size()) {
                res.resize(depth + 1);
            }
            res[depth] = root->val;
            dfs_recursion(root->right, depth + 1);
        }

        vector<int> bfs(TreeNode *root) {
            if (!root) {
                return {};
            }
            vector<int> res;
            TreeNode *cur = root;
            queue<TreeNode *> q;
            q.push(cur);
            while (!q.empty()) {
                int size = q.size();
                res.push_back(q.front()->val);
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    if (cur->right) {
                        q.push(cur->right);
                    }
                    if (cur->left) {
                        q.push(cur->left);
                    }
                }
            }
            return res;
        }
};
