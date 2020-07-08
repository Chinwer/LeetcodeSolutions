/*
 * Given a string which consists of lowercase or uppercase letters,
 * find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        int longestPalindrome(string s) {
            map<char, int> cnt;
            for (char c : s) {
                cnt[c]++;
            }
            int res = 0, has_odd = 0;
            for (auto it = cnt.begin(); it != cnt.end(); it++) {
                if (!(it->second % 2)) {
                    res += it->second;
                } else {
                    has_odd = 1;
                    res += it->second - 1;
                }
            }
            return res + has_odd;
        }
};
