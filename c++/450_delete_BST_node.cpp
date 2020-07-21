/*
 * 450. Delete Node in a BST
 *
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 * Note: Time complexity should be O(height of tree).
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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (!root) {
                return nullptr;
            }
            if (root->val == key) {
                if (!root->left) {
                    TreeNode *p = root->right;
                    delete root;
                    return p;
                }
                if (!root->right) {
                    TreeNode *p = root->left;
                    delete root;
                    return p;
                }
                TreeNode *succ = left_most(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, root->val);
            } else if (root->val < key) {
                root->right = deleteNode(root->right, key);
            } else {
                root->left = deleteNode(root->left, key);
            }
            return root;
        }

        TreeNode* left_most(TreeNode *root) {
            while (root->left) {
                root = root->left;
            }
            return root;
        }
};
