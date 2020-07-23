/*
 * 230. Kth Smallest Element in a BST
 *
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest routine?
 *
 * Constraints:
 *
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
        int res, cnt;

    public:
        int kthSmallest(TreeNode* root, int k) {
            // recursion(root, k);
            // return res;
            return iteration(root, k);
        }

        int iteration(TreeNode *root, int k) {
            stack<TreeNode *> s;
            TreeNode *cur = root;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                k--;
                if (!k) {
                    return cur->val;
                }
                cur = cur->right;
            }
            return cur->val;
        }

        void recursion(TreeNode *root, int k) {
            if (!root) {
                return;
            }
            recursion(root->left, k);
            cnt++;
            if (cnt == k) {
                res = root->val;
                return;
            }
            recursion(root->right, k);
        }
};
