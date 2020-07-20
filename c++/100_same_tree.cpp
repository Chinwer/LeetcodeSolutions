/*
 * 100. Same Tree
 *
 * Given two binary trees, write a function to check if they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // return bfs(p, q);
            return dfs(p, q);
        }

        bool dfs(TreeNode *p, TreeNode *q) {
            if (!p && !q) {
                return true;
            }
            if (!p || !q) {
                return false;
            }
            if (p->val != q->val) {
                return false;
            }
            if ((p->left && !q->left) ||
                (!p->left && q->left)) {
                return false;
            }
            if ((p->right && !q->right) ||
                (!p->right && q->right)) {
                return false;
            }
            return dfs(p->left, q->left) &&
                dfs(p->right, q->right);
        }

        bool bfs(TreeNode *p, TreeNode *q) {
            if (!p && !q) {
                return true;
            }
            if (!p || !q) {
                return false;
            }
            TreeNode *pnode, *qnode;
            queue<TreeNode *> pnodes, qnodes;
            pnodes.push(p);
            qnodes.push(q);
            while (!pnodes.empty() || !qnodes.empty()) {
                int psize = pnodes.size();
                int qsize = qnodes.size();
                if (psize != qsize) {
                    return false;
                }
                for (int i = 0; i < psize; i++) {
                    pnode = pnodes.front();
                    qnode = qnodes.front();
                    pnodes.pop();
                    qnodes.pop();
                    if (pnode->val != qnode->val) {
                        return false;
                    }
                    if ((pnode->left && !qnode->left) ||
                        (!pnode->left && qnode->left)) {
                        return false;
                    }
                    if ((pnode->right && !qnode->right) ||
                        (!pnode->right && qnode->right)) {
                        return false;
                    }
                    if (pnode->left) {
                        pnodes.push(pnode->left);
                    }
                    if (pnode->right) {
                        pnodes.push(pnode->right);
                    }
                    if (qnode->left) {
                        qnodes.push(qnode->left);
                    }
                    if (qnode->right) {
                        qnodes.push(qnode->right);
                    }
                }
            }
            return true;
        }
};
