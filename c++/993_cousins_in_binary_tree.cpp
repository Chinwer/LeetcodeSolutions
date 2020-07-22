/*
 * 993. Cousins in Binary Tree
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
 *
 * Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
 *
 * We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
 *
 * Return true if and only if the nodes corresponding to the values x and y are cousins.
 *
 * Constraints:
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
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
        int x_depth = 0;
        int y_depth = 0;
        TreeNode *x_parent = nullptr;
        TreeNode *y_parent = nullptr;
    public:
        bool isCousins(TreeNode* root, int x, int y) {
            // recursion(root, nullptr, x, y, 0);
            // return x_depth == y_depth && x_parent != y_parent;
            return iteration(root, x, y);
        }

        bool iteration(TreeNode *root, int x, int y) {
            queue<TreeNode *> q;
            TreeNode *cur = root;
            q.push(cur);
            while (!q.empty()) {
                int size = q.size();
                bool x_found = false, y_found = false;
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    TreeNode *lchild = cur->left;
                    TreeNode *rchild = cur->right;
                    if (lchild && rchild) {
                        if (lchild->val == x && rchild->val == y) {
                            return false;
                        }
                        if (lchild->val == y && rchild->val == x) {
                            return false;
                        }
                    }
                    if (cur->val == x) {
                        x_found = true;
                    }
                    if (cur->val == y) {
                        y_found = true;
                    }
                    if (x_found && y_found) {
                        return true;
                    }
                    if (lchild) {
                        q.push(lchild);
                    }
                    if (rchild) {
                        q.push(rchild);
                    }
                }
            }
            return false;
        }

        void recursion(TreeNode *child, TreeNode *parent, int x, int y, int depth) {
            if (!child) {
                return;
            }
            if (child->val == x) {
                x_depth = depth;
                x_parent = parent;
            }
            if (child->val == y) {
                y_depth = depth;
                y_parent = parent;
            }
            depth++;
            recursion(child->left, child, x, y, depth);
            recursion(child->right, child, x, y, depth);
        }
};
