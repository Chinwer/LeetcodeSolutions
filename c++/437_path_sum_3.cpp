/*
 * 437. Path Sum III
 * You are given a binary tree in which each node contains an integer value.
 * Find the number of paths that sum to a given value.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
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
        int res = 0;
        unordered_map<int, int> path_sum;

    public:
        int pathSum(TreeNode* root, int sum) {
            // if (!root) {
            //     return 0;
            // }
            // return count(root, sum) +
            //     pathSum(root->left, sum) + pathSum(root->right, sum);
            if (!root) {
                return 0;
            }
            path_sum[0] = 1;
            dfs(root, sum, 0);
            return res;
        }

        void dfs(TreeNode *root, int sum, int cur_sum) {
            if (!root) {
                return;
            }
            cur_sum += root->val;
            res += path_sum[cur_sum - sum];
            path_sum[cur_sum]++;
            dfs(root->left, sum, cur_sum);
            dfs(root->right, sum, cur_sum);
            path_sum[cur_sum]--;
        }

        int count(TreeNode *root, int sum) {
            if (!root) {
                return 0;
            }
            sum -= root->val;
            int res = sum == 0;
            return res + count(root->left, sum) + count(root->right, sum);
        }
};
