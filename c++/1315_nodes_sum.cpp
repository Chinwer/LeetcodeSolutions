/*
 * 1315. Sum of Nodes with Even-Valued Grandparent
 *
 * Given a binary tree, return the sum of values of nodes with even-valued grandparent.
 * (A grandparent of a node is the parent of its parent, if it exists.)
 *
 * If there are no nodes with an even-valued grandparent, return 0.
 *
 * Constraints:
 *
 * The number of nodes in the tree is between 1 and 10^4.
 * The value of nodes is between 1 and 100.
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
        int sumEvenGrandparent(TreeNode* root) {
            return dfs(root, nullptr, nullptr);
        }

        int dfs(TreeNode *root, TreeNode *parent, TreeNode *grand) {
            if (!root) {
                return 0;
            }
            int sum = 0;
            if (grand && !(grand->val & 1)) {
                sum += root->val;
            }
            sum += dfs(root->left, root, parent);
            sum += dfs(root->right, root, parent);
            return sum;
        }
};
