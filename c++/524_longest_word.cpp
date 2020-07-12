/*
 * 524. Longest Word in Dictionary through Deleting
 * Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
 *
 * Note:
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 */

#include "header.h"

class Solution {
    public:
        string findLongestWord(string s, vector<string>& d) {
            string res;
            int max_len = 0;
            for (string str : d) {
                int len = str.length();
                if (len < max_len) {
                    continue;
                }
                if (is_sub(s, str)) {
                    if (len > max_len) {
                        res = str;
                        max_len = len;
                    } else {
                        res = lex_sort(res, str);
                    }
                }
            }
            return res;
        }

        bool is_sub(string parent, string sub) {
            int i = 0, j = 0;
            int lp = parent.length(), ls = sub.length();
            while (i < lp && j < ls) {
                while (i < lp && parent[i] != sub[j]) {
                    i++;
                }
                if (i == lp) {
                    return false;
                }
                i++;
                j++;
            }
            return j == ls;
        }

        string lex_sort(string str1, string str2) {
            // asssert str1.length() == str2.length()
            int len = str1.length();
            for (int i = 0; i < len; i++) {
                if (str1[i] < str2[i]) {
                    return str1;
                } else if (str1[i] > str2[i]) {
                    return str2;
                }
            }
            return str1;
        }
};
