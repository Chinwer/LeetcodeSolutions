/*
 * 559. Maximum Depth of N-ary Tree
 *
 * Given a n-ary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 * Nary-Tree input serialization is represented in their level order
 * traversal, each group of children is separated by the null value (See examples).
 *
 * Constraints:
 *
 * The depth of the n-ary tree is less than or equal to 1000.
 * The total number of nodes is between [0, 10^4].
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
        int maxDepth(Node* root) {
            // return recursion(root);
            return iteration(root);
        }

        int iteration(Node *root) {
            if (!root) {
                return 0;
            }
            int depth = 0;
            Node *cur;
            queue<Node *> q;
            q.push(root);
            while (!q.empty()) {
                depth++;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    cur = q.front();
                    q.pop();
                    int s = cur->children.size();
                    for (int j = 0; j < s; j++) {
                        q.push(cur->children[j]);
                    }
                }
            }
            return depth;
        }

        int recursion(Node *root) {
            if (!root) {
                return 0;
            }
            int sub_depth = 0;
            int size = root->children.size();
            for (int i = 0; i < size; i++) {
                int depth = recursion(root->children[i]);
                sub_depth = max(depth, sub_depth);
            }
            return sub_depth + 1;
        }
};
