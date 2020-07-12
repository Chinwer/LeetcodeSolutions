/*
 * 1234. Replace the Substring for Balanced String
 *
 *
 * You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

 * A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

 * Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

 * Return 0 if the string is already balanced.
 *
 * Constraints:

 * 1 <= s.length <= 10^5
 * s.length is a multiple of 4
 * s contains only 'Q', 'W', 'E' and 'R'.
 */

#include "header.h"

class Solution {
    public:
        int balancedString(string s) {
            map<char, int> cnt;
            int len = s.length(), res = len;
            for (char c : s) {
                cnt[c]++;
            }
            int left = 0, right = 0, average = len / 4;
            while (right < len) {
                // update the letter counts outside the sliding windows
                cnt[s[right]]--;
                while (
                    left < len
                    && cnt['Q'] <= average
                    && cnt['W'] <= average
                    && cnt['E'] <= average
                    && cnt['R'] <= average
                ) {
                    res = min(res, right - left + 1);
                    cnt[s[left]]++;
                    left++;
                }
                right++;
            }
            return res;
        }
};
