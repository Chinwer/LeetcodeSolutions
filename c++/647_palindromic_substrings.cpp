/*
 * 647. Palindromic Substrings
 *
 * Given a string, your task is to count how many palindromic
 * substrings in this string.
 *
 * The substrings with different start indexes or end indexes are
 * counted as different substrings even they consist of same characters.
 *
 * Note:
 *   1. The input string length won't exceed 1000.
 */

#include "header.h"

class Solution {
    public:
        int countSubstrings(string s) {
            // return dynamic_programming(s);
            return center_spread(s);
        }

        int center_spread(string s) {
            int res = 0;
            int n = s.length(), end = 2 * n - 1;
            for (int i = 0; i < end; i++) {
                int l = i / 2;
                int r = l + i % 2;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                    res++;
                }
            }
            return res;
        }

        int dynamic_programming(string s) {
            int n = s.length();
            vector<vector<bool>> dp(n, vector(n, false));
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] != s[j]) {
                        continue;
                    }
                    if (j == i + 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    res += dp[i][j];
                }
            }
            return res;
        }
};
