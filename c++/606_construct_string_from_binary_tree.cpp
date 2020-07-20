/*
 * 606. Construct String from Binary Tree
 *
 * You need to construct a string consists of parenthesis and integers
 * from a binary tree with the preorder traversing way.
 * The null node needs to be represented by empty parenthesis pair "()".
 * And you need to omit all the empty parenthesis pairs that don't affect
 * the one-to-one mapping relationship between the string and the original binary tree.
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
        string tree2str(TreeNode* t) {
            return dfs(t);
            // return iteration(t);
        }

        string iteration(TreeNode *t) {
            string res;
            stack<TreeNode *> s;
            TreeNode *cur = t, *pre = nullptr;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    res += to_string(cur->val) + "(";
                    cur = cur->left;
                }
                cur = s.top();
                if (cur->right && cur->right != pre) {
                    cur = cur->right;
                } else {
                    res += ")";
                    s.pop();
                    pre = cur;
                    cur = nullptr;
                }
            }
            return res.substr(1, res.size() - 2);
        }

        string dfs(TreeNode *t) {
            if (!t) {
                return "";
            }
            if (!t->left && !t->right) {
                return to_string(t->val) + "";
            }
            if  (!t->right) {
                return to_string(t->val) + "(" + dfs(t->left) + ")";
            }
            return to_string(t->val) + "(" + dfs(t->left) + ")(" + dfs(t->right) + ")";
        }
};
