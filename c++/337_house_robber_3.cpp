/*
 * 337. House Robber III
 *
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this
 * place forms a binary tree". It will automatically contact the
 * police if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight
 * without alerting the police.
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
        unordered_map<TreeNode*, int> memo;

    public:
        int rob(TreeNode* root) {
            // return recursion(root);
            vector<int> res = optimized(root);
            return max(res[0], res[1]);
        }

        // Return:
        //   vector<int> res:
        //     res[0]: maximum amount without robbing the root
        //     res[1]: maximum amount with robbing the root
        vector<int> optimized(TreeNode *root) {
            if (!root) {
                return { 0, 0 };
            }
            vector<int> l = optimized(root->left);
            vector<int> r = optimized(root->right);
            int rob_ = root->val + l[0] + r[0];
            int not_rob = max(l[0], l[1]) + max(r[0], r[1]);
            return { not_rob, rob_ };
        }

        int recursion(TreeNode *root) {
            if (!root) {
                return 0;
            }
            if (memo.count(root)) {
                return memo[root];
            }
            int rob_ = root->val;
            rob_ += root->left ?
                recursion(root->left->left) + recursion(root->left->right) : 0;
            rob_ += root->right ?
                recursion(root->right->left) + recursion(root->right->right) : 0;
            int not_rob = recursion(root->left) + recursion(root->right);
            int res = max(rob_, not_rob);
            memo[root] = res;
            return res;
        }
};
