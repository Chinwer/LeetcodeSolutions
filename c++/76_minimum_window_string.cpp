/*
 * 76. Minimum Window Substring
 *
 * Given a string S and a string T, find the minimum window in S
 * which will contain all the characters in T in complexity O(n).
 *
 * Note:
 *   - If there is no such window in S that covers all characters in T,
 *     return the empty string "".
 *   - If there is such window, you are guaranteed that there will
 *      always be only one unique minimum window in S.
 */

#include "header.h"

class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> need, window;
            for (char c : t) {
                need[c]++;
            }

            int start = 0, len = INT_MAX;
            int valid = 0, slow = 0, fast = 0, slen = s.length();
            while (fast < slen) {
                char c = s[fast];
                fast++;
                if (need.count(c)) {
                    window[c]++;
                    if (window[c] == need[c]) {
                        valid++;
                    }
                }
                while (valid == need.size()) {
                    if (fast - slow < len) {
                        len = fast - slow;
                        start = slow;
                    }
                    char d = s[slow];
                    slow++;
                    if (need.count(d)) {
                        if (window[d] == need[d]) {
                            valid--;
                        }
                        window[d]--;
                    }
                }
            }
            return len == INT_MAX ? "" : s.substr(start, len);
        }
};
