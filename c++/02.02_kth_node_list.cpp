/*
 * 面试题 02.02. Kth Node From End of List LCCI
 *
 * Implement an algorithm to find the kth to last element of a singly linked list.
 * Return the value of the element.
 *
 * Note:
 *
 * k is always valid.
 */

#include "header.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        int kthToLast(ListNode* head, int k) {
            ListNode *left = head, *right = head;
            for (int i = 1; i < k; i++) {
                right = right->next;
            }
            while (right->next) {
                left = left->next;
                right = right->next;
            }
            return left->val;
        }
};
