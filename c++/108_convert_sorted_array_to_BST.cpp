/*
 * 108. Convert Sorted Array to Binary Search Tree
 *
 *
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return build(nums, 0, nums.size() - 1);
        }

        TreeNode* build(vector<int> &nums, int start, int end) {
            if (start > end) {
                return nullptr;
            }
            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = build(nums, start, mid - 1);
            root->right = build(nums, mid + 1, end);
            return root;
        }
};
