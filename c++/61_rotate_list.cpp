/*
 * 61. Rotate List
 * Given a linked list, rotate the list to the right by k places,
 * where k is non-negative.
 */

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head) {
                return NULL;
            }
            int len = 0;
            ListNode *p = head, *q = head;
            while (p) {
                len++;
                q = p;
                p = p->next;
            }
            k %= len;
            p = head;
            q->next = head;
            q = head;

            for (int i = 0; i < len - k; i++) {
                p = q;
                q = q->next;
            }
            p->next = NULL;
            return q;
        }
};
