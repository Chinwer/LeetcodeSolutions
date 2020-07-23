/*
 * 1592. Kth Largest Node in Binary Search Tree
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
        int res, cnt;

    public:
        int kthLargest(TreeNode* root, int k) {
            recursion(root, k);
            return res;
        }

        void recursion(TreeNode *root, int k) {
            if (!root) {
                return;
            }
            recursion(root->right, k);
            cnt++;
            if (cnt == k) {
                res = root->val;
                return;
            }
            recursion(root->left, k);
        }
};
