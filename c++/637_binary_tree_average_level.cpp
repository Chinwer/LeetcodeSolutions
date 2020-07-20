/*
 * 637. Average of Levels in Binary Tree
 *
 * Given a non-empty tree, return the average value of the nodes
 * on each level in the form of an array.
 *
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
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
        vector<double> averageOfLevels(TreeNode* root) {
            if (!root) {
                return {};
            }
            vector<double> res;
            TreeNode *cur;
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty()) {
                double average = 0;
                int size =  q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    average += cur->val;
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                }
                res.push_back(average / size);
            }
            return res;
        }
};
