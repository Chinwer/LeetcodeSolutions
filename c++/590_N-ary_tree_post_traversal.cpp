/*
 * 590. N-ary Tree Postorder Traversal
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 *
 * Nary0Tree input serialization is represented in their level order travesral,
 * each group of children is separated by the null value.
 *
 * Follow up:
 * Recursive solution istrivial, could you do it iteratively?
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
        vector<int> postorder(Node* root) {
            // return recursion(root);
            return iteration(root);
        }

        vector<int> iteration(Node *root) {
            Node *cur;
            stack<Node *> s;
            vector<int> res;
            if (root) {
                s.push(root);
            }
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                int size = cur->children.size();
                for (int i = 0; i < size; i++) {
                    s.push(cur->children[i]);
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }

        vector<int> recursion(Node *root) {
            if (!root) {
                return {};
            }
            vector<int> res;
            int size = root->children.size();
            for (int i = 0; i < size; i++) {
                vector<int> ret = recursion(root->children[i]);
                res.insert(res.end(), ret.begin(), ret.end());
            }
            res.push_back(root->val);
            return res;
        }
};
