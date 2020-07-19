/*
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 * Note:
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            dfs(root, p, q);
            return res;
        }

        bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (!root) {
                return false;
            }
            bool left = dfs(root->left, p, q);
            bool right = dfs(root->right, p, q);
            if ((left && right) || ((root == p || root == q) && (left || right))) {
                res = root;
            }
            return left || right || root == p || root == q;
        }
};
