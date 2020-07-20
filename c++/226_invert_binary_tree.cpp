/*
 * 226. Invert Binary Tree
 *
 * Invert a binary tree.
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
        TreeNode* invertTree(TreeNode* root) {
            return bfs(root);
            // dfs(root);
            // return root;
        }

        void dfs(TreeNode *root) {
            if (!root) {
                return;
            }
            TreeNode *p = root->left;
            root->left = root->right;
            root->right = p;
            dfs(root->left);
            dfs(root->right);
        }

        TreeNode* bfs(TreeNode *root) {
            if (!root) {
                return nullptr;
            }
            TreeNode *cur;
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                TreeNode *p = cur->right;
                cur->right = cur->left;
                cur->left = p;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            return root;
        }
};
