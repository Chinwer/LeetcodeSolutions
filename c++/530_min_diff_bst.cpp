/*
 * 530. Minimum Absolute Difference in BST
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 * Note: There are at least two nodes in this BST.
 */

#include <stack>
#include <limits>
#include <vector>
#include <iostream>

using namespace std;

int min(int a, int b);

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    private:
        int res = INT32_MAX;
        int prev = -1;

    public:
        int getMinimumDifference(TreeNode* root) {
            inorder_iter(root);
            return res;
        }

        void inorder_iter(TreeNode* root) {
            stack<TreeNode *> s;
            while (root || !s.empty()) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }
                root = s.top();
                s.pop();
                if (prev != -1) {
                    res = min(res, root->val - prev);
                }
                prev = root->val;
                root = root->right;
            }
        }

        void inorder_recur(TreeNode* root) {
            if (!root) {
                return;
            }

            inorder_recur(root->left);
            if (prev != -1) {
                res = min(res, root->val - prev);
            }
            prev = root->val;
            inorder_recur(root->right);
        }
};
