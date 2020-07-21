/*
 * 703. Kth Largest Element in a Stream
 *
 * Design a class to find the kth largest element in a stream.
 * Note that it is the kth largest element in the sorted order,
 *  not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts
 * an integer k and an integer array nums, which contains initial
 * elements from the stream. For each call to the method KthLargest.add,
 * return the element representing the kth largest element in the stream.
 *
 * Note:
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 */

#include "header.h"

class KthLargest {

    struct TreeNode {
        int val;
        int count;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), count(1), left(nullptr), right(nullptr) {}
        TreeNode(int val) : val(val), count(1), left(nullptr), right(nullptr) {}
    };

    private:
        int k;
        int size;
        TreeNode *root = nullptr;

    public:
        KthLargest(int k, vector<int>& nums) : k(k), size(0) {
            for (int num : nums) {
                size++;
                root = insert_node(root, num);
            }
        }

        int add(int val) {
            int k_ = k;
            root = insert_node(root, val);
            stack<TreeNode *> s;
            TreeNode *cur = root;
            s.push(cur);
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                int cnt = 1;
                if (cur->right) {
                    cnt = cur->right->count + 1;
                }
                if (cnt == k_) {
                    return cur->val;
                }
                if (cnt > k_) {
                    cur = cur->right;
                } else {
                    cur = cur->left;
                    k_ -= cnt;
                }
                s.push(cur);
            }
            return cur->val;
        }

        TreeNode* insert_node(TreeNode *root, int num) {
            if (!root) {
                return new TreeNode(num);
            }
            TreeNode *child = root,  *parent = root;
            while (child) {
                parent = child;
                child->count++;
                child = child->val > num ? child->left : child->right;
            }
            if (parent->val > num) {
                parent->left = new TreeNode(num);
            } else {
                parent->right = new TreeNode(num);
            }
            return root;
        }

        void traversal() {
            stack<TreeNode *> s;
            TreeNode *cur = root;
            while (cur || !s.empty()) {
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
