/*
 * 116. Populating Next Right Pointers in Each Node
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following definition:
 *
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *next;
 * }
 *
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Follow up:
 *   - You may only use constant extra space.
 *   - Recursive approach is fine, you may assume implicit stack space does
 *     not count as extra space for this problem.
 *
 * Constraints:
 *   - The number of nodes in the given tree is less than 4096.
 *   - -1000 <= node.val <= 1000.
 */

#include "header.h"

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
        Node* connect(Node* root) {
            // return bfs(root);
            return dfs(root);
        }

        Node* dfs(Node *root) {
            if (!root) {
                return nullptr;
            }
            if (root->left && root->right) {
                root->left->next = root->right;
            }
            if (root->right && root->next) {
                root->right->next = root->next->left;
            }
            dfs(root->left);
            dfs(root->right);
            return root;
        }

        Node* bfs(Node *root) {
            if (!root) {
                return nullptr;
            }
            queue<Node *> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                Node *pred = nullptr, *succ = nullptr;
                for (int i = 0; i < size; i++) {
                    pred = succ;
                    succ = q.front();
                    q.pop();
                    if (pred) {
                        pred->next = succ;
                    }
                    if (succ->left) {
                        q.push(succ->left);
                    }
                    if (succ->right) {
                        q.push(succ->right);
                    }
                }
            }
            return root;
        }
};
