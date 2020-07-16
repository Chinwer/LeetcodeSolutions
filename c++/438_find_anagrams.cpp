/*
 * 438. Find All Anagrams in a String
 *
 * Given a string s and non-empty string p, find all the start indices
 * of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of
 * both strings s and p will not be larger than 20100.
 *
 * The order of output does not matter.
 */

#include "header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> need, window;
        for (char c : p) {
            need[c]++;
        }

        vector<int> res;
        int left = 0, right = 0, valid = 0;
        int slen = s.length(), size = need.size(), plen = p.length();
        while (right < slen) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (right - left >= plen) {
                if (valid == size) {
                    res.push_back(left);
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};
