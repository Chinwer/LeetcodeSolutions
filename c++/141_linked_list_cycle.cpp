/*
 * 141. Linked List Cycle
 *
 * Given a linked list, determine if it has a cycle in it.
 * To represent a cycle in the given linked list, we use an integer
 * pos which represents the position (0-indexed) in the linked list
 * where tail connects to. If pos is -1, then there is no cycle in the linked list.
 *
 * Follow up:
 * Can you solve it using O(1) (i.e. constant) memory?
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (!head || !head->next) {
                return false;
            }

            ListNode *slow = head, *fast = head->next;
            while (slow != fast) {
                if (!fast || !fast->next) {
                    return false;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            return true;
        }
};
