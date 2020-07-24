/*
 * 1026. Maximum Difference Between Node and Ancestor
 *
 * Given the root of a binary tree, find the maximum value V for which
 * there exists different nodes A and B where V = |A.val - B.val| and A
 * is an ancestor of B.
 *
 * (A node A is an ancestor of B if either: any child of A is equal to B,
 * or any child of A is an ancestor of B.)
 *
 * Note:
 *
 * The number of nodes in the tree is between 2 and 5000.
 * Each node will have value between 0 and 100000.
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
        int res = 0;

    public:
        int maxAncestorDiff(TreeNode* root) {
            dfs(root, root->val, root->val);
            return res;
        }

        void dfs(TreeNode *root, int min_, int max_) {
            if (!root) {
                return;
            }
            res = max(res, abs(min_ - root->val));
            res = max(res, abs(max_ - root->val));
            min_ = min(min_, root->val);
            max_ = max(max_, root->val);
            dfs(root->left, min_, max_);
            dfs(root->right, min_, max_);
        }
};
