/*
 * 234. Palindrome Linked List
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
        bool isPalindrome(ListNode* head) {
            vector<int> nums;
            for (ListNode *p = head; p; p = p->next) {
                nums.push_back(p->val);
            }
            int size = nums.size();
            int mid = (size + 1) / 2;
            for (int i = 0; i < mid; i++) {
                if (nums[i] != nums[size - 1 - i]) {
                    return false;
                }
            }
            return true;
        }
};
