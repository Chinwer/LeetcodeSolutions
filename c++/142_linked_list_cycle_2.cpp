/*
 * 142. Linkes List Cycle II
 *
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 *
 * To represent a cycle in the given linked list,
 * we use an integer pos which represents the position (0-indexed)
 * in the linked list where tail connects to. If pos is -1, then there
 * is no cycle in the linked list.
 *
 * Note: Do not modify the linked list.
 *
 * Follow-up:
 * Can you solve it without using extra space?
 */

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val): val(val), next(NULL) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (!head || !(head->next)) {
                return NULL;
            }
            ListNode *slow = head, *fast = head, *p;
            do {
                slow = slow->next;
                if (!(fast->next) || !(fast->next->next)) {
                    return NULL;
                }
                fast = fast->next->next;
            } while (slow != fast);

            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
};
