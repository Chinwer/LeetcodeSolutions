/*
 * 257. Binary Tree Paths
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
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
        vector<string> res;

    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            // string path = "";
            // recursion(root, path);
            // return res;

            // return iteration(root);

            return bfs(root);
        }

        vector<string> bfs(TreeNode *root) {
            if (!root) {
                return {};
            }
            string path;
            TreeNode *cur;
            vector<string> res;
            queue<string> paths;
            queue<TreeNode *> nodes;
            nodes.push(root);
            paths.push(to_string(root->val));
            while (!nodes.empty()) {
                int size = nodes.size();
                for (int i = 0; i < size; i++) {
                    cur = nodes.front();
                    nodes.pop();
                    path = paths.front();
                    paths.pop();
                    if (!cur->left && !cur->right) {
                        res.push_back(path);
                    } else {
                        path += "->";
                    }
                    if (cur->left) {
                        nodes.push(cur->left);
                        paths.push(path + to_string(cur->left->val));
                    }
                    if (cur->right) {
                        nodes.push(cur->right);
                        paths.push(path + to_string(cur->right->val));
                    }
                }
            }
            return res;
        }

        vector<string> iteration(TreeNode *root) {
            string path;
            vector<string> res;
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = nullptr;

            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    path.append(to_string(cur->val));
                    if (!cur->left && !cur->right) {
                        res.push_back(path);
                    } else {
                        path += "->";
                    }
                    cur = cur->left;
                }
                cur = s.top();
                if (cur->right && cur->right != pre) {
                    cur = cur->right;
                } else {
                    string str = to_string(cur->val);
                    if (cur->left || cur->right) {
                        str += "->";
                    }
                    path.erase(path.length() - str.length(), str.length());
                    s.pop();
                    pre = cur;
                    cur = nullptr;
                }
            }
            return res;
        }

        void recursion(TreeNode *root, string &path) {
            if (!root) {
                return;
            }
            string str = to_string(root->val);
            if (root->left || root->right) {
                str.append("->");
            }
            path.append(str);
            if (!root->left && !root->right) {
                res.push_back(path);
            }
            recursion(root->left, path);
            recursion(root->right, path);
            path.erase(path.length() - str.length(), str.length());
        }
};
