/*
 * 1339. Maximum Product of Splitted Binary Tree
 *
 * Given a binary tree root. Split the binary tree into two subtrees by
 * removing 1 edge such that the product of the sums of the subtrees are
 * maxmized.
 *
 * Since the answer may be too 
 *
 * Constraints:
 *
 * Each tree has at most 50000 nodes and at least 2 nodes.
 * Each node's value is between [1, 10000].
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
        int sum, res = 0;

    public:
        int maxProduct(TreeNode* root) {
            if (!root) {
                return 0;
            }
            sum = dfs(root);
            dfs2(root);
            return (long) res * (sum - res) % 1000000007;
        }

        // calculate the sum of all elements in tree root
        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int sum = root->val;
            sum += dfs(root->left);
            sum += dfs(root->right);
            return sum;
        }

        int dfs2(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int cur = dfs2(root->left) + dfs2(root->right) + root->val;
            if (abs(cur * 2 - sum) < abs(res * 2 - sum)) {
                res = cur;
            }
            return cur;
        }

};
