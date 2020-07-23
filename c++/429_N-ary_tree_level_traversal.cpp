/*
 * 429. N-ary Tree Level Order Traversal
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value.
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
        vector<vector<int>> levelOrder(Node* root) {
            return iteration(root);
        }

        vector<vector<int>> iteration(Node *root) {
            if (!root) {
                return {};
            }
            Node *cur;
            queue<Node *> q;
            vector<vector<int>> res;
            q.push(root);
            while (!q.empty()) {
                vector<int> nums;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    nums.push_back(cur->val);
                    int s = cur->children.size();
                    for (int j = 0; j < s; j++) {
                        q.push(cur->children[j]);
                    }
                }
                if (!nums.empty()) {
                    res.push_back(nums);
                }
            }
            return res;
        }
};
