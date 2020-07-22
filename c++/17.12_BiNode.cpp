/*
 * 面试题 17.12. BiNode LCCI
 *
 * The data structure TreeNode is used for binary tree,
 * but it can also used to represent a single linked list
 * (where left is null, and right is the next node in the list).
 * Implement a method to convert a binary search tree (implemented with TreeNode)
 * into a single linked list. The values should be kept in order and the operation
 * should be performed in place (that is, on the original data structure).
 *
 * Return the head node of the linked list after converting.
 *
 * Note: This problem is slightly different from the original one in the book.
 *
 * Note:
 * The number of nodes will not exceed 100000.
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
        TreeNode* convertBiNode(TreeNode* root) {
            // return iteration(root);
            TreeNode *dummy = new TreeNode(0);
            cur = dummy;
            recursion(root);
            TreeNode *res = dummy->right;
            delete dummy;
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
            bool flag;
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
