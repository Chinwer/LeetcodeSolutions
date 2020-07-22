/*
 * 面试题 04.02. Minimum Height Tree LCCI
 *
 * Given a sorted (increasing order) array with unique integer elements,
 * write an algorithm to create a binary search tree with minimal height;
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
            return dfs(nums, 0, nums.size() - 1);
        }

        TreeNode* dfs(vector<int> &nums, int start, int end) {
            if (start > end) {
                return nullptr;
            }
            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = dfs(nums, start, mid - 1);
            root->right = dfs(nums, mid + 1, end);
            return root;
        }
};
