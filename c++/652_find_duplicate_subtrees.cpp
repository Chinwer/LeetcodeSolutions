/*
 * 652. Find Duplicate Subtrees
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
 *
 * Two trees are duplicate if they have the same structure with same node values.
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
        vector<TreeNode*> res;
        unordered_map<string, int> cnt;

    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            dfs(root);
            return res;
        }

        string dfs(TreeNode *root) {
            if (!root) {
                return "#";
            }
            string ret = to_string(root->val) + ",";
            ret += dfs(root->left) + ",";
            ret += dfs(root->right);
            cnt[ret]++;
            if (cnt[ret] == 2) {
                res.push_back(root);
            }
            return ret;
        }
};
