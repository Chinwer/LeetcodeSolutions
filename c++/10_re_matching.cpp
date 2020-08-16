/*
 * 10. Regular Expression Matching
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *   - '.' Matches any single character.
 *   - '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *   - s could be empty and contains only lowercase letters a-z.
 *   - p could be empty and contains only lowercase letters a-z, and
 *     characters like . or *.
 */

#include "header.h"

class Solution {
    public:
        bool isMatch(string s, string p) {
            int ls = s.length(), lp = p.length();
            vector<vector<bool>> dp(ls + 1, vector(lp + 1, false));

            dp[0][0] = true;
            for (int i = 0; i <= ls; i++) {
                for (int j = 1; j <= lp; j++) {
                    if (p[j - 1] != '*') {
                        if (match(s, p, i, j)) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    } else {
                        dp[i][j] = dp[i][j - 2];
                        if (match(s, p, i, j - 1)) {
                            dp[i][j] = dp[i - 1][j] || dp[i][j];
                        }
                    }
                }
            }
            return dp[ls][lp];
        }

        bool match(string &s, string &p, int i, int j) {
            if (!i) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        }
};
