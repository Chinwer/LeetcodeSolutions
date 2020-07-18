/*
 * 101. Symmetric Tree
 *
 * Given a binary tree, check whether it is a mirror of itself
 * (ie, symmetric around its center).
 *
 * For example, this binary tree [1, 2, 2, 3, 4, 4, 3] is symmetric:
 *
 *       1
 *     /  \
 *    2   2
 *   / \ / \
 *  3  4 4  3
 *
 * But the following [1, 2, 2, null, 3, null, 3] is not:
 *       1
 *     /  \
 *    2   2
 *    \    \
 *    3     3
 *
 * Follow up: Solve it both recursively and iteratively.
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
        bool isSymmetric(TreeNode* root) {
            // return dfs(root, root);
            return bfs(root, root);
        }

        bool dfs(TreeNode *left, TreeNode *right) {
            if (!left && !right) {
                return true;
            }
            if (!left || !right) {
                return false;
            }
            return left->val == right->val && dfs(left->left, right->right)
                && dfs(left->right, right->left);
        }

        bool bfs(TreeNode *left, TreeNode *right) {
            queue<TreeNode *> q;
            q.push(left);
            q.push(right);
            while (!q.empty()) {
                left = q.front();
                q.pop();
                right = q.front();
                q.pop();
                if (!left && !right) {
                    continue;
                }
                if (!left || !right || left->val != right->val) {
                    return false;
                }
                q.push(left->left);
                q.push(right->right);
                q.push(left->right);
                q.push(right->left);
            }
            return true;
        }
};
