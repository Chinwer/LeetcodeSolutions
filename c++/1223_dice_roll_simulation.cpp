/*
 * 1223. Dice Roll Simulation
 *
 * A die simulator generates a random number from 1 to 6 for each roll.
 * You introduced a constraint to the generator such that it cannot roll
 * the number i more than rollMax[i] (1-indexed) consecutive times. 
 *
 * Given an array of integers rollMax and an integer n, return the number
 * of distinct sequences that can be obtained with exact n rolls.
 *
 * Two sequences are considered different if at least one element differs
 * from each other.
 *
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Constraints:
 *
 *   - 1 <= n <= 5000
 *   - rollMax.length == 6
 *   - 1 <= rollMax[i] <= 15
 */

#include "header.h"

class Solution {
    public:
        int dieSimulator(int n, vector<int>& rollMax) {
            // return original(n, rollMax);
            return optimized(n, rollMax);
        }

        int optimized(int n, vector<int> &rollMax) {
            const int mod = 1e9 + 7;
            vector<vector<int>> dp(7, vector(16, 0));
            for (int i = 1; i < 7; i++) {
                dp[i][1] = 1;
            }

            for (int i = 1; i < n; i++) {
                vector<vector<int>> tmp(7, vector(16, 0));
                for (int j = 1; j < 7; j++) {
                    for (int k = 1; k < 7; k++) {
                        if (j == k) {
                            for (int p = 1; p < rollMax[k - 1]; p++) {
                                tmp[j][p + 1] += dp[k][p];
                                tmp[j][p + 1] %= mod;
                            }
                        } else {
                            for (int p = 1; p <= rollMax[k - 1]; p++) {
                                tmp[j][1] += dp[k][p];
                                tmp[j][1] %= mod;
                            }
                        }
                    }
                }
                dp = tmp;
            }

            int res = 0;
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= rollMax[i - 1]; j++) {
                    res = (res + dp[i][j]) % mod;
                }
            }
            return res;
        }

        int original(int n, vector<int> &rollMax) {
            const int mod = 1000000007;
            // dp[i][j][k] represents that after (i - 1) rolls of dice,
            // the number of sequences that ends with k j's
            vector<vector<vector<int>>> dp(n, vector(7, vector(16, 0)));
            for (int i = 1; i <= 6; i++) {
                dp[0][i][1] = 1;
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < 7; j++) {
                    for (int k = 1; k < 7; k++) {
                        if (j == k) {
                            for (int p = 1; p < rollMax[k - 1]; p++) {
                                dp[i][j][p + 1] += dp[i - 1][k][p];
                                dp[i][j][p + 1] %= mod;
                            }
                        } else {
                            for (int p = 1; p <= rollMax[k - 1]; p++) {
                                dp[i][j][1] += dp[i - 1][k][p];
                                dp[i][j][1] %= mod;
                            }
                        }
                    }
                }
            }

            int res = 0;
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= rollMax[i - 1]; j++) {
                    res = (res + dp[n - 1][i][j]) % mod;
                }
            }
            return res;
        }
};
