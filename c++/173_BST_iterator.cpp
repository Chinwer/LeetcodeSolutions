/*
 * 173. Binary Search Tree Iterator
 *
 * Implement an iterator over a binary search tree. YOur iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note:
 * next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    private:
        int idx = 0;
        vector<int> values;
        stack<TreeNode *> nodes;

    public:
        BSTIterator(TreeNode* root) {
            // if (!root) {
            //     return;
            // }
            // stack<TreeNode *> s;
            // TreeNode *cur = root;
            // while (cur || !s.empty()) {
            //     while (cur) {
            //         s.push(cur);
            //         cur = cur->left;
            //     }
            //     cur = s.top();
            //     s.pop();
            //     values.push_back(cur->val);
            //     cur = cur->right;
            // }
            left_most(root);
        }

        void left_most(TreeNode *root) {
            while (root) {
                nodes.push(root);
                root = root->left;
            }
        }

        /** @return the next smallest number */
        int next() {
            // return values[idx++];
            TreeNode *node = nodes.top();
            nodes.pop();
            if (node->right) {
                left_most(node->right);
            }
            return node->val;
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            // return idx < values.size();
            return !nodes.empty();
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
