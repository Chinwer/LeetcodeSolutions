/*
 * 1261. Find Elements in a Contaminated Binary Tree
 *
 * Given a binary tree with the following rules:
 *   1. root.val == 0
 *   2. If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
 *   3. If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
 *
 * Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
 *
 * You need to first recover the binary tree and then implement the FindElements class:
 *   - FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
 *   - bool find(int target) Return if the target value exists in the recovered binary tree.
 *
 * Constraints:
 *   - TreeNode.val == -1
 *   - The height of the binary tree is less than or equal to 20
 *   - The total number of nodes is between [1, 10^4]
 *   - Total calls of find() is between [1, 10^4]
 *   - 0 <= target <= 10^6
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
    private:
        TreeNode *r;

    public:
        FindElements(TreeNode* root) {
            r = build(root, 0);
        }

        TreeNode *build(TreeNode *root, int val) {
            if (!root) {
                return nullptr;
            }
            root->val = val;
            root->left = build(root->left, (val << 1) + 1);
            root->right = build(root->right, (val << 1) + 2);
            return root;
        }

    bool find(int target) {
        return find(r, target);
    }

    bool find(TreeNode *root, int target) {
        if (!root) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        return find(root->left, target) || find(root->right, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
