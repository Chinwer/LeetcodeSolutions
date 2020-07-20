/*
 * 111. Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children
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
        int minDepth(TreeNode* root) {
            // return dfs(root);
            return bfs(root);
        }

        int bfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            queue<TreeNode *> q;
            TreeNode *cur = root;
            q.push(cur);
            int depth = 0;
            while (!q.empty()) {
                depth++;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    if (!cur->left && !cur->right) {
                        return depth;
                    }
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                }
            }
            return depth;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int ldepth = dfs(root->left);
            int rdepth = dfs(root->right);
            if ((root->left && root->right) || (!root->left && !root->right)) {
                return min(ldepth, rdepth) + 1;
            }
            if (root->left) {
                return ldepth;
            }
            return rdepth;
        }
};
