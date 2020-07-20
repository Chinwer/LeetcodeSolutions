/*
 * 572. Subtree of Another Tree
 *
 * Given two non-empty binary trees s and t, check whether tree t has
 * exactly the same structure and node values with a subtree of s.
 * A subtree of s is a tree consists of a node in s and all of this
 * node's descendants. The tree s could also be considered as a subtree of itself.
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
        bool res;

    public:
        bool isSubtree(TreeNode* s, TreeNode* t) {
            if (!s) {
                return false;
            }
            return is_identical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }

        bool is_identical(TreeNode *s, TreeNode *t) {
            if (!s && !t) {
                return true;
            }
            if (!s || !t) {
                return false;
            }
            int l = is_identical(s->left, t->left);
            int r = is_identical(s->right, t->right);
            if (s->val == t->val && l && r) {
                res =  true;
            }
            return s->val == t->val && l && r;
        }
};
