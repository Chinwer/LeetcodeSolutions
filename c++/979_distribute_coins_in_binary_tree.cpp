/*
 * 979. Distribute Coins in Binary Tree
 *
 * Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.
 *
 * In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)
 *
 * Return the number of moves required to make every node have exactly one coin.
 *
 * Note:
 *
 * 1<= N <= 100
 * 0 <= node.val <= N
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
        int distributeCoins(TreeNode* root) {
            dfs(root);
            return res;
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            res += abs(l) + abs(r);
            return l + r + root->val - 1;
        }
};
