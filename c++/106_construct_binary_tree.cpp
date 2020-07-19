/*
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            /* O(n^2) time complexity */
            // if (inorder.empty() || postorder.empty()) {
            //     return nullptr;
            // }
            // int insize = inorder.size(), postsize = postorder.size();
            // int root_val = postorder[postsize - 1];
            // TreeNode *root = new TreeNode(root_val);
            // for (int i = 0; i < insize; i++) {
            //     if (inorder[i] == root_val) {
            //         vector<int> in_left(inorder.begin(), inorder.begin() + i);
            //         vector<int> in_right(inorder.begin() + i + 1, inorder.end());
            //         vector<int> post_left(postorder.begin(), postorder.begin() + i);
            //         vector<int> post_right(postorder.begin() + i, postorder.end() - 1);
            //         root->left = buildTree(in_left, post_left);
            //         root->right = buildTree(in_right, post_right);
            //     }
            // }
            // return root;

            /* O(n) time complexity */
            map<int, int> pos;
            int insize = inorder.size(), postsize = postorder.size();
            for (int i = 0; i < insize; i++) {
                pos[inorder[i]] = i;
            }
            return build(inorder, 0, insize - 1, postorder, 0, postsize - 1, pos);
        }

        TreeNode *build(vector<int> &inorder, int instart, int inend,
            vector<int> &postorder, int poststart, int postend, map<int, int> &pos) {
            if (instart > inend || poststart > postend) {
                return nullptr;
            }
            int root_val = postorder[postend];
            int root_idx = pos[root_val];
            TreeNode *root = new TreeNode(root_val);
            root->left = build(inorder, instart, root_idx - 1,
                postorder, poststart, poststart + root_idx - instart - 1, pos);
            root->right = build(inorder, root_idx + 1, inend,
                postorder, poststart + root_idx - instart, postend - 1, pos);
            return root;
        }
};
