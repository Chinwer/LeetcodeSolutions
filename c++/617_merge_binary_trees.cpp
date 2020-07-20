/*
 * 617. Merge Two Binary Trees
 *
 * Given two binary trees and imagine that when you put one of them to
 * cover the other, some nodes of the two trees are overlapped while the
 * others are not.
 *
 * You need to merge them into a new binary tree. The merge rule is that
 * if two nodes overlap, then sum node values up as the new value of the
 * merged node. Otherwise, the NOT null node will be used as the node of new tree.
 *
 * Note: The merging process must start from the root nodes of both trees.
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
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            // return dfs(t1, t2);
            return iteration(t1, t2);
        }

        TreeNode* iteration(TreeNode *t1, TreeNode *t2) {
            if (!t1) {
                return t2;
            }
            stack<vector<TreeNode *>> s;
            s.push({ t1, t2 });
            while (!s.empty()) {
                vector<TreeNode *> nodes = s.top();
                s.pop();
                TreeNode *p = nodes[0];
                TreeNode *q = nodes[1];
                if (!p || !q) {
                    continue;
                }
                p->val += q->val;
                if (!p->left) {
                    p->left = q->left;
                } else {
                    s.push({ p->left, q->left });
                }
                if (!p->right) {
                    p->right = q->right;
                } else {
                    s.push({ p->right, q->right });
                }
            }
            return t1;
        }

        TreeNode* dfs(TreeNode *t1, TreeNode *t2) {
            if (!t1) {
                return t2;
            }
            if (!t2) {
                return t1;
            }
            t1->val += t2->val;
            t1->left = dfs(t1->left, t2->left);
            t1->right = dfs(t1->right, t2->right);
            return t1;
        }
};
