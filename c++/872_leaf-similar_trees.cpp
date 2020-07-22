/*
 * 872. Leaf-Similar Trees
 *
 * Consider all the leaves of a binary tree. From left to right order,
 * the values of those leaves from a leaf value sequence.
 *
 * Constraints:
 *
 * Both of the given trees will have between 1 and 200 nodes.
 * Both of the given trees will have values between 0 and 200
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
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        }
};
