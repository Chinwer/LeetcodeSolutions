/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Note:
 * All given inputs are in lowercase letters a-z.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return string();
            }

            string res = strs[0];
            int len = strs.size();
            for (int i = 0; i < len; i++) {
                int j = 0;
                string s = strs[i];
                int max_len = res.length() > s.length() ? res.length() : s.length();
                while (j < max_len && res[j] == s[j]) {
                    j++;
                }
                res = s.substr(0, j);
            }
            return res;
        }
};
