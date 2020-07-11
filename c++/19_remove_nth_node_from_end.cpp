/*
 * 19. Remove Nth Node From End of List
 *
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Note:
 * Given n will always be valid.
 *
 * Follow up:
 * Could you do this in one pass?
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *p = slow->next;
        slow->next = p->next;
        delete p;
        ListNode *q = dummy->next;
        delete dummy;

        return q;
    }
};
