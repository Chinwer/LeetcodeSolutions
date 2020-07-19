/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree
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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            map<int, int> pos;
            int presize = preorder.size(), insize = inorder.size();
            for (int i = 0; i < insize; i++) {
                pos[inorder[i]] = i;
            }
            return build(preorder, 0, presize - 1, inorder, 0, insize - 1, pos);
        }

        TreeNode *build(vector<int> &pre, int prestart, int preend,
            vector<int> &in, int instart, int inend, map<int, int> &pos) {
            if (instart > inend || prestart > preend) {
                return nullptr;
            }
            int root_val = pre[prestart];
            int root_idx = pos[root_val];
            int nums_left = root_idx - instart;
            TreeNode *root = new TreeNode(root_val);
            root->left = build(pre, prestart + 1, prestart + nums_left,
                in, instart, root_idx - 1, pos);
            root->right = build(pre, prestart + nums_left + 1, preend,
                in, root_idx + 1, inend, pos);
            return root;
        }
};
