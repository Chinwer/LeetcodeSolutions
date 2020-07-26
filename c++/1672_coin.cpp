/*
 * 面试题 08.11. Coin LCCI
 *
 * Given an infinite number of quarters (25 cents), dimes(10 cents),
 * nickels (5 cents), and pennies (1 cent), write code to calculate
 * the number of ways of representing n cents.
 * (The result may be large, so you should return it modulo 1000000007)
 *
 * Notes:
 * You can assume:
 * 0 <= n <= 1000000
 */

#include "header.h"

class Solution {
    public:
        int waysToChange(int n) {
            // return dp_(n);
            return dp_optimized(n);
        }

        int dp_optimized(int n) {
            int mod = 1000000007;
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            vector<int> cents = { 1, 5, 10, 25 };
            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= n; j++) {
                    if (j >= cents[i]) {
                        dp[j] = (dp[j] + dp[j - cents[i]]) % mod;
                    }
                }
            }
            return dp[n];
        }

        int dp_(int n) {
            int mod = 1000000007;
            vector<int> cents = { 1, 5, 10, 25 };
            vector<vector<int>> dp(5, vector(n + 1, 0));
            for (int i = 0; i < 5; i++) {
                dp[i][0] = 1;
            }
            for (int i = 1; i < 5; i++) {
                for (int j = 1; j <= n; j++) {
                    if (j < cents[i - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = (
                            dp[i - 1][j] + dp[i][j - cents[i - 1]]
                        ) % mod;
                    }
                }
            }
            return dp[4][n];
        }
};
