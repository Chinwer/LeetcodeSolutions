/*
 * Given an input string, reverse the string word by word.
 *
 * Note:
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However,
 * your reversed string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in the reversed string.
 *  
 *
 * Follow up:
 *
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            if (s.empty()) {
                return s;
            }

            // reverse the whole string
            reverse(s.begin(), s.end());

            // reverse each word
            int idx = 0;
            int len = s.length();
            for (int start = 0; start < len; start++) {
                if (s[start] == ' ') {
                    continue;
                }
                if (idx) {
                    s[idx++] = ' ';
                }
                int end = start;
                while (end < len && s[end] != ' ') {
                    s[idx++] = s[end++];
                }

                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
            s.erase(s.begin() + idx, s.end());
            return s;
        }
};
