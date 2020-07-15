/*
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 */

#include "header.h"

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> cnt;
            int res = 0, len = s.length(), right = -1;
            for (int i = 0; i < len; i++) {
                if (i > 0) {
                    cnt[s[i - 1]]--;
                }
                while (right < len - 1 && !cnt[s[right + 1]]) {
                    cnt[s[right + 1]]++;
                    right++;
                }
                res = max(res, right - i + 1);
            }
            return res;
        }
}
