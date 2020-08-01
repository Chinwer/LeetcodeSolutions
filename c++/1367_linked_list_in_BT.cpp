/*
 * 1367. Linked List in Binary Tree
 *
 * Given a binary tree root and a linked list with head as the first node.
 *
 * Return True if all the elements in the linked list starting from the
 * head correspond to some downward path connected in the binary tree
 * otherwise return False.
 *
 * In this context downward path means a path that starts at some node
 * and goes downwards.
 *
 * Constraints:
 *   - 1 <= node.val <= 100 for each node in the linked list and binary tree.
 *   - The given linked list will contain between 1 and 100 nodes.
 *   - The given binary tree will contain between 1 and 2500 nodes.
 */

#include "header.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isSubPath(ListNode* head, TreeNode* root) {
            if (!root) {
                return false;
            }
            return dfs(head, root) || isSubPath(head, root->left)
                || isSubPath(head, root->right);
        }

        bool dfs(ListNode *head, TreeNode *root) {
            if (!head) {
                return true;
            }
            if (!root) {
                return false;
            }
            if (root->val != head->val) {
                return false;
            }
            return dfs(head->next, root->left)
                || dfs(head->next, root->right);
        }
};
