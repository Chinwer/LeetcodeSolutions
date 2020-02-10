/*
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode *head, *p;
        if (l1->val <= l2->val) {
            head = p = l1;
            l1 = l1->next;
        } else {
            head = p = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        while (l1) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        }
        while (l2) {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
        return head;
    }
};
