/*
 * 258. Add Digits
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

#include "header.h"

class Solution {
    public:
        int addDigits(int num) {
            string s = to_string(num);
            while (s.length() > 1) {
                int num = 0;
                for (char c : s) {
                    num += c - '0';
                }
                s = to_string(num);
            }
            return s[0] - '0';
        }
};
