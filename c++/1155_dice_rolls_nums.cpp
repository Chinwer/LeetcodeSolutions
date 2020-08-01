/*
 * 1155. Number of Dice Rolls With Target Sum
 *
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 *
 * Return the number of possible ways (out of f^d total ways) modulo
 * 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.
 *
 * Constraints:
 *   - 1 <= d, f <= 30
 *   - 1 <= target <= 1000
 */

#include "header.h"

class Solution {
    public:
        int numRollsToTarget(int d, int f, int target) {
            // dp[i][j] represents the number of possible ways
            // that makes the sum equals j after i rolls
            int total = d * f;
            const int mod = 1e9 + 7;
            if (target > total) {
                return 0;
            }
            vector<vector<int>> dp(d + 1, vector(total + 1, 0));
            for (int i = 1; i <= f; i++) {
                dp[1][i] = 1;
            }
            for (int i = 2; i <= d; i++) {
                for (int j = 1; j <= total; j++) {
                    for (int k = 1; k <= f; k++) {
                        int score = j - k >= 0 ? dp[i - 1][j - k] : 0;
                        dp[i][j] = (dp[i][j] + score) % mod;
                    }
                }
            }
            return dp[d][target];
        }
};
