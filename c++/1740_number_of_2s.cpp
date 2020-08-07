/*
 * 1740. Number Of 2s In Range LCCI
 *
 * Write a method to count the number of 2s that appear in all the
 * numbers between 0 and n (inclusive).
 *
 * Note:
 *   - n <= 10^9
 */

#include "header.h"

class Solution {
    public:
        int numberOf2sInRange(int n) {
            string s = to_string(n);
            int res = 0, len = s.length();
            for (int i = 0; i < len; i++) {
                int cur = s[i] - '0';
                string sub1 = s.substr(0, i);
                string sub2 = s.substr(i + 1, len - i - 1);
                int high = sub1 == "" ? 0 : stoi(sub1);
                int low = sub2 == "" ? 0 : stoi(sub2);
                if (cur > 2) {
                    res += (high + 1) * (pow(10, len - i - 1));
                } else if (cur < 2) {
                    res += high * pow(10, len - i - 1);
                } else {
                    res += high * pow(10, len - i - 1) + low + 1;
                }
            }
            return res;
        }
};
