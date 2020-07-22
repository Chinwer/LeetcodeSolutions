/*
 * 501. Find Mode in Binary Search Tree
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s)
 * (the most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space?
 * (Assume that the implicit stack space incurred due to recursion does not count).
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
        int res_size;
        int cur_count;
        int max_count;
        vector<int> res;
        TreeNode *pre = nullptr;

    public:
        vector<int> findMode(TreeNode* root) {
            inorder_traversal(root);
            cout << res_size << " " << max_count;
            res.resize(res_size);
            cur_count = 0;
            res_size = 0;
            pre = nullptr;
            inorder_traversal(root);
            return res;
        }

        void inorder_traversal(TreeNode *root) {
            if (!root) {
                return;
            }
            inorder_traversal(root->left);
            if (pre && root->val == pre->val) {
                cur_count++;
            } else {
                cur_count = 1;
            }
            if (cur_count > max_count) {
                res_size = 1;
                max_count = cur_count;
            } else if (cur_count == max_count) {
                if (!res.empty()) {
                    res[res_size] = root->val;
                }
                res_size++;
            }
            pre = root;
            inorder_traversal(root->right);
        }
};
