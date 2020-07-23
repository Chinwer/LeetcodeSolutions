/*
 * 114. Flatten Binary Tree to Linked List
 *
 * Given a binary tree, flatten it to a linked list in-place.
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
    private:
        TreeNode *pre = nullptr;

    public:
        void flatten(TreeNode* root) {
            // recursion(root);
            // iteration1(root);
            // iteration2(root);
            iteration3(root);
        }

        void iteration1(TreeNode *root) {
            TreeNode *pre = nullptr;
            while (root) {
                if (!root->left) {
                    root = root->right;
                    continue;
                }
                pre = root->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }

        void iteration2(TreeNode *root) {
            if (!root) {
                return;
            }
            TreeNode *cur, *pre = nullptr;
            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                if (cur->right) {
                    s.push(cur->right);
                }
                if (cur->left) {
                    s.push(cur->left);
                }
                if (pre) {
                    pre->right = cur;
                    pre->left = nullptr;
                }
                pre = cur;
            }
        }

        void iteration3(TreeNode *root) {
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->right;
                }
                cur = s.top();
                if (cur->left && cur->left != pre) {
                    cur = cur->left;
                } else {
                    s.pop();
                    cur->left = nullptr;
                    cur->right = pre;
                    pre = cur;
                    cur = cur->left;
                }
            }
        }

        void recursion(TreeNode *root) {
            if (!root) {
                return;
            }
            recursion(root->right);
            recursion(root->left);
            root->right = pre;
            root->left = nullptr;
            pre = root;
        }
};
