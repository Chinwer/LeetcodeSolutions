/*
 * 104. Maximum Depth of Binary Tree
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
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
    public:
        int maxDepth(TreeNode* root) {
            // return dfs(root);
            return bfs(root);
        }

        int bfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int res = 0;
            queue<TreeNode *> q;
            q.push(root);
            TreeNode *cur = root;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                }
                res++;
            }
            return res;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            return max(dfs(root->left), dfs(root->right)) + 1;
        }
};
