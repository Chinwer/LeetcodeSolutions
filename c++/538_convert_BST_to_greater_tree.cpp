/*
 * 538. Convert BST to Greater Tree
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree
 * such that every key of the original BST is changed to the original
 * key plus sum of all keys greater than the original key in BST.
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
        int sum = 0;

    public:
        TreeNode* convertBST(TreeNode* root) {
            recursion(root);
            return root;
        }

        void recursion(TreeNode *root) {
            if (!root) {
                return;
            }
            recursion(root->right);
            sum += root->val;
            root->val = sum;
            recursion(root->left);
        }
};
