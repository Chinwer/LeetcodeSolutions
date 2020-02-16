/*
 * 1060. Find Words That Can Be Formed by Characters
 * You are given an array of strings words and a string chars.
 *
 * A string is good if it can be formed by characters from chars (each
 * character can only be used once).
 *
 * Return the sum of lengths of all good strings in words.
 *
 * Note:
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
 */

#include "header.h"

class Solution {
    public:
        int countCharacters(vector<string>& words, string chars) {
            int res = 0;
            map<char, int> cnt;
            for (char c : chars) {
                cnt[c]++;
            }
            for (string s : words) {
                bool flag = true;
                map<char, int> tmp(cnt);
                for (char c : s) {
                    if (tmp[c] > 0) {
                        tmp[c]--;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res += s.length();
                }
            }
            return res;
        }
};
