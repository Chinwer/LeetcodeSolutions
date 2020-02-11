/*
 * 653. Two Sum IV - Input is a BST
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 */

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        void go_left_branch(stack<TreeNode *> &s, TreeNode *root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
        }

        void inorder(TreeNode *root, vector<int> &nums) {
            stack<TreeNode*> s;
            s.push(root);
            root = root->left;
            while (true) {
                go_left_branch(s, root);
                if (s.empty()) {
                    return;
                }
                root = s.top();
                s.pop();
                nums.push_back(root->val);
                root = root->right;
            }
        }

        bool findTarget(TreeNode *root, int k) {
            vector<int> nums;
            inorder(root, nums);

            int low = 0;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];
                if (sum == k) {
                    return true;
                } else if (sum < k) {
                    low++;
                } else {
                    high--;
                }
            }
            return false;
        }
};
