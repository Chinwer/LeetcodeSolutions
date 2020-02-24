/*
 * 270. Closest Binary Search Tree Value
 * Given a non-empty binary search tree and a target value, find the value in
 * the BST that is closest to the target.
 *
 * Note:
 *
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to
 * the target.
 *
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
        int res;
        double delta = INT32_MAX;
        long pred = LONG_MIN;

    public:
        int closestValue(TreeNode* root, double target) {
            // vector<int> nums;
            // inorder(nums, root);
            // return bin_search(nums, target);

            // return inorder(root, target);

            // return inorder_optimized(root, target);

            return bin_traverse(root, target);
        }

        void inorder(vector<int>& nums, TreeNode* root) {
            stack<TreeNode*> stack;
            while (root || !stack.empty()) {
                while (root) {
                    stack.push(root);
                    root = root->left;
                }

                root = stack.top();
                stack.pop();

                nums.push_back(root->val);

                root = root->right;
            }
        }

        int bin_search(vector<int>& nums, double target) {
            int res, l = 0, r = nums.size();

            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] < target) {
                    double diff = target - nums[m];
                    if (diff < delta) {
                        delta = diff;
                        res = nums[m];
                    }
                    l = m + 1;
                } else {
                    double diff = nums[m] - target;
                    if (diff < delta) {
                        delta = diff;
                        res = nums[m];
                    }
                    r = m;
                }
            }
            return res;
        }

        int inorder(TreeNode* root, double target) {
            stack<TreeNode*> s;
            while (root || !s.empty()) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }

                root = s.top();
                s.pop();

                double diff = abs(root->val - target);
                if (diff < delta) {
                    delta = diff;
                    res = root->val;
                }

                root = root->right;
            }
            return res;
        }

        int inorder_optimized(TreeNode* root, double target) {
            stack<TreeNode*> s;
            while (root || !s.empty()) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }

                root = s.top();
                s.pop();

                if (pred <= target && target < root->val) {
                    return abs(pred - target) < abs(root->val - target)
                        ? (int) pred : root->val;
                }

                pred = root->val;
                root = root->right;
            }
            return (int) pred;
        }

        int bin_traverse(TreeNode* root, double target) {
            res = root->val;
            while (root) {
                res = abs(root->val - target) < abs(res - target)
                    ? root->val : res;
                root = target < root->val ? root->left : root->right;
            }
            return res;
        }
};
