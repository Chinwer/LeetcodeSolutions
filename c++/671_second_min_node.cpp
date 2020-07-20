/*
 * 671. Second Minimum Node In a Binary Tree
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or
 * zero sub-node. If the node has two sub-nodes, then this node's value
 * is the smaller value among its two sub-nodes. More formally, the
 * property root.val = min(root.left.val, root.right.val) always holds.
 *
 * Given such a binary tree, you need to output the second minimum value
 * in the set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
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
        long first = (long) INT_MAX + 1;
        long second = (long) INT_MAX + 1;

    public:
        int findSecondMinimumValue(TreeNode* root) {
            dfs(root);
            return second == (long) INT_MAX + 1 ? -1 : second;
        }

        void dfs(TreeNode *root) {
            if (!root) {
                return;
            }
            int val = root->val;
            if (val < first) {
                second = first;
                first = val;
            } else if (val < second && val != first) {
                second = val;
            }
            dfs(root->left);
            dfs(root->right);
        }
};
