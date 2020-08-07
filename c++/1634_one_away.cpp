/*
 * 面试题 01.05. One Away LCCI
 *
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 */

#include "header.h"

class Solution {
    public:
        bool oneEditAway(string first, string second) {
            int len1 = first.length();
            int len2 = second.length();
            int len_diff = len1 - len2;
            if (abs(len_diff) > 1) {
                return false;
            }
            // make second the longer one
            if (len_diff > 0) {
                string tmp = first;
                first = second;
                second = tmp;
            }
            for (int i = 0; i < len1; i++) {
                if (first[i] != second[i]) {
                    string sub1 = first.substr(len1 == len2 ? i + 1 : i);
                    string sub2 = second.substr(i + 1);
                    return sub1 == sub2;
                }
            }
            return true;
        }
};
