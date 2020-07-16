/*
 * 567. Permutation in String
 * Given two strings s1 and s2, write a function to return true
 * if s2 contains the permutation of s1. In other words, one of the
 * first string's permutations is the substring of the second string.
 *
 * Constraints:
 *   - The input strings only contain lower case letters.
 *   - The length of both given strins is in range [1, 10000].
 */

#include "header.h"

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            vector<int> cnt(26);
            int left = 0, right = 0;
            int len1 = s1.length(), len2 = s2.length();

            for (int i = 0; i < len1; i++) {
                cnt[s1[i] - 'a']++;
            }

            while (right < len2) {
                if (--cnt[s2[right] - 'a'] < 0) {
                    while (++cnt[s2[left++] - 'a'] != 0) {}
                } else if (right - left + 1 == len1) {
                    return true;
                }
            }
            return false;
        }
};
