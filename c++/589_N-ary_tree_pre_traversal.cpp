/*
 * 589. N-ary Tree Preorder Traversal
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal.
 * each group of children is separated by the null value.
 *
 * Follow up:
 *  Recursive solution is trivial, could you do it iteratively?
 *
 * Constraints:
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 */

#include "header.h"

// Definition for a Node.
class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

class Solution {
    public:
        vector<int> preorder(Node* root) {
            // return recursion(root);
            return iteration(root);
        }

        vector<int> iteration(Node *root) {
            if (!root) {
                return {};
            }
            Node *cur;
            vector<int> res;
            stack<Node *> s;
            s.push(root);
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                int size = cur->children.size();
                for (int i = size - 1; i >= 0; i--) {
                    if (cur->children[i]) {
                        s.push(cur->children[i]);
                    }
                }
            }
            return res;
        }

        vector<int> recursion(Node *root) {
            if (!root) {
                return {};
            }
            vector<int> res = { root->val };
            int size = root->children.size();
            for (int i = 0; i < size; i++) {
                vector<int> ret = recursion(root->children[i]);
                res.insert(res.end(), ret.begin(), ret.end());
            }
            return res;
        }
};
