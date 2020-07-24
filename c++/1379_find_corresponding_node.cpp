/*
 * 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * Given two binary trees original and cloned and given a reference to a node target in the original tree.
 *
 * The cloned tree is a copy of the original tree.
 *
 * Return a reference to the same node in the cloned tree.
 *
 * Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
 *
 * Follow up: Solve the problem if repeated values on the tree are allowed.
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * The values of the nodes of the tree are unique.
 * target node is a node from the original tree and is not null.
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
        TreeNode *res;

    public:
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
            recursion(cloned, target->val);
            return res;
        }

        void recursion(TreeNode *root, int val) {
            if (!root) {
                return;
            }
            if (root->val == val) {
                res = root;
                return;
            }
            recursion(root->left, val);
            recursion(root->right, val);
        }
};
