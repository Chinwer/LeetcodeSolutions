/*
 * 518. Coin Change 2
 *
 * You are given coins of different denominations and a total
 * amount of money. Write a function to compute the number of
 * combinations that make up that amount. You may assume that
 * you have infinite number of each kind of coin.
 *
 * Note:
 * You can assume that
 *   - 0 <= amount <= 5000
 *   - 1 <= coin <= 5000
 *   - the number of coins is less than 500
 *   - the answer is guaranteed to fit into signed 32-bit integer
 */

#include "header.h"

class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            // return bottom_up(amount, coins);
            return bottom_up_optimized(amount, coins);
        }

        int bottom_up_optimized(int amount, vector<int> &coins) {
            int n = coins.size();
            vector<int> dp(amount + 1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= amount; j++) {
                    if (j >= coins[i]) {
                        dp[j] += dp[j - coins[i]];
                    }
                }
            }
            return dp[amount];
        }

        int bottom_up(int amount, vector<int> &coins) {
            int n = coins.size();
            vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
            // base case
            for (int i = 0; i <= n; i++) {
                dp[i][0] = 1;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= amount; j++) {
                    if (j < coins[i - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                    }
                }
            }
            return dp[n][amount];
        }
};
