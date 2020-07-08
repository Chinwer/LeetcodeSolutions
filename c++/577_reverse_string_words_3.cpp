/*
 * 577. Reverse Words in a String III
 *
 * Given a string, you need to reverse the order of characters in
 * each word within a sentence while still preserving whitespace and initial word order.
 *
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            if (s.empty()) {
                return s;
            }

            int len = s.length();
            for (int start = 0; start < len; start++) {
                if (s[start] == ' ') {
                    continue;
                }
                int end = start;
                while (end < len && s[end] != ' ') {
                    end++;
                }
                reverse(s.begin() + start, s.begin() + end);
                start = end;
            }
            return s;
        }
};
