/*
 * 1372. Longest ZigZag Path in a Binary Tree
 *
 * Given a binary tree root, a ZigZag path for a binary tree is defined as follow:
 *
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right then move to the right child of the
 * current node otherwise move to the left child.
 * Change the direction from right to left or right to left.
 * Repeat the second and third step until you can't move in the tree.
 * Zigzag length is defined as the number of nodes visited - 1.
 * (A single node has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 * Constraints:
 *
 * Each tree has at most 50000 nodes..
 * Each node's value is between [1, 100].
 */

#include "header.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        int res = 0;
        // f(u) is the length of longest zigzag path from root
        // to u with u being the left child of its parent node.
        // g(u) is the length of longest zigzag path from root
        // to u with u being the right child of its parent node.
        unordered_map<TreeNode *, int> f, g;

    public:
        int longestZigZag(TreeNode* root) {
            // if (!root) {
            //     return 0;
            // }
            // dfs(root, true, 0);
            // dfs(root, false, 0);
            // return res;

            // bfs_dp(root);
            // int res = 0;
            // for (const auto &u : f) {
            //     res = max(res, max(u.second, g[u.first]));
            // }
            // return res;

            dfs_dp(root);
            return res;
        }

        vector<int> dfs_dp(TreeNode *root) {
            if (!root) {
                return { -1, -1 };
            }
            vector<int> ret(2);
            vector<int> l = dfs_dp(root->left);
            vector<int> r = dfs_dp(root->right);
            ret[0] = l[1] + 1;
            ret[1] = r[0] + 1;
            res = max(res, max(ret[0], ret[1]));
            return ret;
        }

        void bfs_dp(TreeNode *root) {
            queue<pair<TreeNode *, TreeNode *>> q;
            f[root] = g[root] = 0;
            q.push({ root, nullptr });
            while (!q.empty()) {
                auto fr = q.front();
                q.pop();
                auto child = fr.first;
                auto parent = fr.second;
                f[child] = g[child] = 0;
                // state transfer equation:
                // f[child] = g[father(child)] + 1; (u is the left child)
                // g[child] = f[father(child)] + 1; (u is the right child)
                if (parent) {
                    if (parent->left == child) {
                        f[child] = g[parent] + 1;
                    }
                    if (parent->right == child) {
                        g[child] = f[parent] + 1;
                    }
                }
                if (child->left) {
                    q.push({ child->left, child });
                }
                if (child->right) {
                    q.push({ child->right, child });
                }
            }
        }

        void dfs(TreeNode *root, bool is_left, int len) {
            res = max(res, len);
            if (is_left) {
                if (root->left) {
                    dfs(root->left, false, len + 1);
                }
                if (root->right) {
                    dfs(root->right, true, 1);
                }
            } else {
                if (root->right) {
                    dfs(root->right, true, len + 1);
                }
                if (root->left) {
                    dfs(root->left, false, 1);
                }
            }
        }
};
