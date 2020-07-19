/*
 * 117. Populating Next Right Pointers in Each Node II
 *
 * Given a binary tree:
 * struct Node {
     int val;
     Node *left;
     Node *right;
     Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Follow up:
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 *
 * Constraints:
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
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
            Node *cur = root;
            while (cur) {
                Node *dummy = new Node();
                Node *tail = dummy;
                while (cur) {
                    if (cur->left) {
                        tail->next = cur->left;
                        tail = tail->next;
                    }
                    if (cur->right) {
                        tail->next = cur->right;
                        tail = tail->next;
                    }
                    cur = cur->next;
                }
                cur = dummy->next;
            }
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
                Node *prev = nullptr, *succ = nullptr;
                for (int i = 0; i < size; i++) {
                    prev = succ;
                    succ = q.front();
                    q.pop();
                    if (prev) {
                        prev->next = succ;
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
