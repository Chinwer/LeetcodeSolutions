/*
 * 998. Maximum Binary Tree II
 *
 * We are given the root node of a maximum tree: a tree where every node
 * has a value greater than any other value in its subtree.
 *
 * Just as in the previous problem, the given tree was constructed from
 * an list A (root = Construct(A)) recursively with the following Construct(A) routine:
 *
 *   - If A is empty, return null.
 *   - Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
 *   - The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
 *   - The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
 *   - Return root.
 *
 * Note that we were not given A directly, only a root node root = Construct(A).
 *
 * Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.
 *
 * Return Construct(B).
 *
 * Constraints:
 *
 * 1 <= B.length <= 100
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
    public:
        TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
            return build(root, val);
        }

        TreeNode* build(TreeNode *root, int val) {
            if (!root) {
                return new TreeNode(val);
            }
            if (val > root->val) {
                TreeNode *res = new TreeNode(val);
                res->left = root;
                return res;
            }
            root->right = build(root->right, val);
            return root;
        }
};
