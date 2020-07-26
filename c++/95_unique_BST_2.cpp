/*
 * 95. Unique Binary Search Trees II
 *
 * Given an integer n, generate all structurally unique BST's
 * that store values 1...n.
 *
 * Constraints:
 *   0 <= n <= 8
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
    public:
        vector<TreeNode*> generateTrees(int n) {
            if (!n) {
                return {};
            }
            return generateTrees(1, n);
        }

        vector<TreeNode*> generateTrees(int start,int end) {
            if (start > end) {
                return { nullptr };
            }
            vector<TreeNode*> res;
            for (int i = start; i <= end; i++) {
                auto lres = generateTrees(start, i - 1);
                auto rres = generateTrees(i + 1, end);
                for (auto lchild : lres) {
                    for (auto rchild : rres) {
                        TreeNode *root = new TreeNode(i);
                        root->left = lchild;
                        root->right = rchild;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
};
