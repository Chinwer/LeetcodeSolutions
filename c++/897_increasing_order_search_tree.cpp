/*
 * 897. Increasing Order Search Tree
 *
 * Given a binary search tree, rearrange the tree in-order so that
 * the leftmost node in the tree is now the root of the tree,
 * and every node has no left child and only 1 right child.
 *
 * Constraints:
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
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
        TreeNode *cur;

    public:
        TreeNode* increasingBST(TreeNode* root) {
            // return iteration(root);
            TreeNode *p = new TreeNode(0);
            cur = p;
            recursion(root);
            TreeNode *res = p->right;
            delete p;
            return res;
        }

        void recursion(TreeNode *root) {
            if (!root) {
                return;
            }
            recursion(root->left);
            root->left = nullptr;
            cur->right = root;
            cur = root;
            recursion(root->right);
        }

        TreeNode* iteration(TreeNode *root) {
            bool flag = false;
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                if (!flag) {
                    root = cur;
                    flag = true;
                }
                if (pre) {
                    pre->right = cur;
                    cur->left = nullptr;
                }
                pre = cur;
                cur = cur->right;
            }
            return root;
        }
};
