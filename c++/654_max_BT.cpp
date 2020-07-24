/*
 * 654. Maximum Binary Tree
 *
 * Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 *   - The root is the maximum number in the array.
 *   - The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 *   - The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 *
 * Construct the maximum tree by the given array and output the root node of this tree.
 *
 * Note:
 * The size of the given array will be in the range [1,1000].
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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return build(nums, 0, nums.size() - 1);
        }

        TreeNode* build(vector<int> &nums, int start, int end) {
            if (start > end) {
                return nullptr;
            }
            int max_idx, max_num = INT_MIN;
            for (int i = start; i <= end; i++) {
                if (nums[i] > max_num) {
                    max_idx = i;
                    max_num = nums[i];
                }
            }
            TreeNode *root = new TreeNode(max_num);
            root->left = build(nums, start, max_idx - 1);
            root->right = build(nums, max_idx + 1, end);
            return root;
        }
};
