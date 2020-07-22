/*
 * 938. Range Sum of BST
 *
 * Given the root node of a binary search tree,
 * return the sum of values of all nodes with value between L and R (inclusive).
 *
 * The BST is guaranteed to have unique values.
 *
 * Note:
 * The number of nodes in the tree is at most 10000.
 * The final answer is guaranteed to be less than 2^31.
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return recursion(root, L, R);
    }

    int recursion(TreeNode *root, int l, int r) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        if (root->val >= l && root->val <= r) {
            sum += root->val;
        }
        sum += recursion(root->left, l, r);
        sum += recursion(root->right, l, r);
        return sum;
    }
};
