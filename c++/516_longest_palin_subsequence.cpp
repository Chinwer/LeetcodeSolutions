/*
 * 516. Longest Palindromic Subsequence
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 *
 * Constraints:
 *   - 1 <= s.length <= 1000
 *   - s consists only of lowercase English letters.
 */

#include "header.h"

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector<vector<int>> dp(n, vector(n, 0));
            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }
            for (int i = n - 2; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[0][n - 1];
        }
};
