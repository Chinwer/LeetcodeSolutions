/*
 * 112. Path Sum
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
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
        bool hasPathSum(TreeNode *root, int sum) {
            // return dfs(root, sum);
            return bfs(root, sum);
        }

        bool bfs(TreeNode *root, int sum) {
            if (!root) {
                return false;
            }
            queue<int> q_sum;
            queue<TreeNode *> q_nodes;
            q_nodes.push(root);
            q_sum.push(root->val);
            int cur_sum = 0;
            TreeNode *cur = root;
            while (!q_nodes.empty()) {
                int size = q_nodes.size();
                cur = q_nodes.front();
                cur_sum = q_sum.front();
                q_sum.pop();
                q_nodes.pop();
                if (cur_sum == sum && !cur->left && !cur->right) {
                    return true;
                }
                if (cur->left) {
                    q_nodes.push(cur->left);
                    q_sum.push(cur_sum + cur->left->val);
                }
                if (cur->right) {
                    q_nodes.push(cur->right);
                    q_sum.push(cur_sum + cur->right->val);
                }
            }
            return false;
        }

        bool dfs(TreeNode* root, int sum) {
            if (!root) {
                return false;
            }
            if (sum == root->val && !root->left && !root->right) {
                return true;
            }
            return dfs(root->left, sum - root->val)
                || dfs(root->right, sum - root->val);
        }
};
