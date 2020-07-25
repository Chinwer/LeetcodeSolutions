/*
 * 1143. Longest Common Subsequence
 *
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
 *
 * If there is no common subsequence, return 0.
 *
 * Constraints:
 *
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 */

#include "header.h"

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int len1 = text1.length();
            int len2 = text2.length();
            vector<vector<int>> dp(len1 + 1, vector(len2 + 1, 0));
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (text1[i - 1] == text2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[len1][len2];
        }
};
