/*
 * 712. Minimum ASCII Delete Sum for Two Strings
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters
 * to make two strings equal.
 *
 * Note:
 *   - 0 < s1.length, s2.length <= 1000.
 *   - All elements of each strings will have an ASCII value in [97, 122].
 */

#include "header.h"

class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            int l1 = s1.length(), l2 = s2.length();
            vector<vector<int>> dp(l1 + 1, vector(l2 + 1, 0));
            for (int i = 1; i <= l1; i++) {
                dp[i][0] = s1[i - 1] + dp[i - 1][0];
            }
            for (int i = 1; i <= l2; i++) {
                dp[0][i] = s2[i - 1] + dp[0][i - 1];
            }
            for (int i = 1; i <= l1; i++) {
                for (int j = 1; j <= l2; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = min(
                            dp[i - 1][j] + s1[i - 1],
                            dp[i][j - 1] + s2[j - 1]
                        );
                    }
                }
            }
            return dp[l1][l2];
        }
};
