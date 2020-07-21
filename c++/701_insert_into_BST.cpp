/*
 * 701. Insert into a Binary Search Tree
 *
 * Given the root node of a binary search tree (BST) and a value
 * to be inserted into the tree, insert the value into the BST.
 * Return the root node of the BST after the insertion. It is
 * guaranteed that the new value does not exist in the original BST.
 *
 * Note that there may exist multiple valid ways for the insertion,
 * as long as the tree remains a BST after insertion. You can return any of them.
 *
 * Constraints:
 * The number of nodes in the given tree will be between 0 and 10^4.
 * Each node will have a unique integer value from 0 to -10^8, inclusive.
 * -10^8 <= val <= 10^8
 * It's guaranteed that val does not exist in the original BST.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            // return recursion(root, val);
            return iteration(root, val);
        }


        TreeNode* iteration(TreeNode *root, int val) {
            if (!root) {
                return new TreeNode(val);
            }
            TreeNode *parent = root, *child = root;
            while (child) {
                parent = child;
                child = child->val < val ? child->right : child->left;
            }
            if (parent->val < val) {
                parent->right = new TreeNode(val);
            } else {
                parent->left = new TreeNode(val);
            }
            return root;
        }

        TreeNode* recursion(TreeNode *root, int val) {
            if (!root) {
                return new TreeNode(val);
            }
            if (root->val < val) {
                root->right = insertIntoBST(root->right, val);
            } else {
                root->left = insertIntoBST(root->left, val);
            }
            return root;
        }
};
