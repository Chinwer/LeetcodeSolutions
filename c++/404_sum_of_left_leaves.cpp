/*
 * 404. Sum of Left Leaves
 *
 * Find the sum of all left leaves in a given binary tree.
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
        int sumOfLeftLeaves(TreeNode* root) {
            // return dfs(root);
            return iterate(root);
        }

        int dfs(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int sum = 0;
            int lsum = dfs(root->left);
            int rsum = dfs(root->right);
            TreeNode *lchild = root->left;
            if (lchild && !lchild->left && !lchild->right) {
                sum = lchild->val;
            }
            return sum + lsum + rsum;
        }

        int iterate(TreeNode *root) {
            int sum = 0;
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    if ( pre && pre->left == cur && !cur->left && !cur->right) {
                        sum += cur->val;
                    }
                    pre = cur;
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
            return sum;
        }
};
