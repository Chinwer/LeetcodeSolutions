/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 * Constraints:
 *
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // return recursion(root, p, q);
            return iteration(root, p, q);
        }

        TreeNode* iteration(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode *cur = root;
            int pval = p->val, qval = q->val;
            while (cur) {
                if (pval > cur->val && qval > cur->val) {
                    cur = cur->right;
                } else if (pval < cur->val && qval < cur->val) {
                    cur = cur->left;
                } else {
                    return cur;
                }
            }
            return cur;
        }

        TreeNode* recursion(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (!root) {
                return nullptr;
            }
            int pval = p->val, qval = q->val;
            if (pval > root->val && qval > root->val) {
                return recursion(root->right, p, q);
            }
            if (pval < root->val && qval < root->val) {
                return recursion(root->left, p, q);
            }
            return root;
        }
};
