/*
 * 86. Partition List
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode *cur = head;
            ListNode *left = new ListNode(0), *right = new ListNode(0);
            ListNode *lp = left, *rp = right;
            while (cur) {
                if (cur->val < x) {
                    lp->next = cur;
                    lp = lp->next;
                } else {
                    rp->next = cur;
                    rp = rp->next;
                }
                cur = cur->next;
            }
            if (!(left->next) || !(right->next)) {
                delete left;
                delete right;
                return head;
            }
            ListNode *new_head = left->next;
            rp->next = NULL;
            lp->next = right->next;
            delete left;
            delete right;
            return new_head;
        }
};
