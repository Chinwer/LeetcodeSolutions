/*
 * 1022. Sum of Root To Leaf Binary Numbers
 *
 *
 * Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
 * Return the sum of these numbers.
 *
 * Note:
 * The number of nodes in the tree is between 1 and 1000.
 * node.val is 0 or 1.
 * The answer will not exceed 2^31 - 1.
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

    public:
        int sumRootToLeaf(TreeNode* root) {
            // dfs(root, 0);
            // return res;
            return iteration(root);
        }

        int iteration(TreeNode *root) {
            if (!root) {
                return 0;
            }
            int res = 0;
            stack<pair<TreeNode *, int>> s;
            s.push(pair(root, root->val));
            while (!s.empty()) {
                TreeNode *cur = s.top().first;
                int val = s.top().second;
                s.pop();
                if (!cur->left && !cur->right) {
                    res += val;
                }
                if (cur->right) {
                    s.push(pair(cur->right, (val << 1) + cur->right->val));
                }
                if (cur->left) {
                    s.push(pair(cur->left, (val << 1) + cur->left->val));
                }
            }
            return res;
        }

        void dfs(TreeNode *root, int num) {
            if (!root) {
                return;
            }
            num =  2 * num + root->val;
            if (!root->left && !root->right) {
                res += num;
            }
            dfs(root->left, num);
            dfs(root->right, num);
        }
};
