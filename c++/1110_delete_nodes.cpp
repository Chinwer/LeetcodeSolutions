/*
 * 1110. Delete Nodes And Return Forest
 *
 * Given the root of a binary tree, each node in the tree has a distinct value.
 *
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 *
 * Return the roots of the trees in the remaining forest.  You may return the result in any order.
 *
 * Constraints:
 *
 * The number of nodes in the given tree is at most 1000.
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
//     private:
//         vector<TreeNode*> res;

//     public:
//         vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//             root = dfs(root, to_delete);
//             if (root) {
//                 res.push_back(root);
//             }
//             return res;
//         }

//         TreeNode* dfs(TreeNode *root, vector<int> &to_delete) {
//             if (!root) {
//                 return nullptr;
//             }
//             root->left = dfs(root->left, to_delete);
//             root->right = dfs(root->right, to_delete);
//             int idx = -1, size = to_delete.size();
//             for (int i = 0; i < size; i++) {
//                 if (root->val == to_delete[i]) {
//                     idx = i;
//                     break;
//                 }
//             }
//             if (idx != -1) {
//                 if (root->left) {
//                     res.push_back(root->left);
//                 }
//                 if (root->right) {
//                     res.push_back(root->right);
//                 }
//                 root = nullptr;
//             }
//             return root;
//         }
// };

class Solution {
    private:
        set<int> s;
        vector<TreeNode*> res;

    public:
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            s = set(to_delete.begin(), to_delete.end());
            dfs(root, false);
            return res;
        }

        bool dfs(TreeNode *root, bool parent_exists) {
            if (!root) {
                return false;
            }
            bool flag = s.count(root->val);
            if (dfs(root->left, !flag)) {
                root->left = nullptr;
            }
            if (dfs(root->right, !flag)) {
                root->right = nullptr;
            }
            if (!flag && !parent_exists) {
                res.push_back(root);
            }
            return flag;
        }
};
