/*
 * 322. Coin Change
 *
 * You are given coins of different denominations and a total amount of amoney amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

#include "header.h"

class Solution {
    private:
        vector<int> memo;

    public:
        int coinChange(vector<int>& coins, int amount) {
            memo = vector(amount + 1, -2);
            return top_down(coins, amount);
            // return bottom_up(coins, amount);
        }

        int top_down(vector<int> &coins, int amount) {
            if (!amount) {
                return 0;
            }
            if (amount < 0) {
                return -1;
            }
            if (memo[amount] != -2) {
                return memo[amount];
            }
            int res = INT_MAX;
            for (int coin : coins) {
                int subres = top_down(coins, amount - coin);
                if (subres != -1) {
                    res = min(res, subres + 1);
                }
            }
            memo[amount] = res == INT_MAX ? -1 : res;
            return memo[amount];
        }

        int bottom_up(vector<int> &coins, int amount) {
            vector<int> dp(amount + 1, amount + 1);
            // base case
            dp[0] = 0;
            for (int i = 0; i <= amount; i++) {
                for (int coin : coins) {
                    if (i < coin) {
                        continue;
                    }
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
            return (dp[amount] == amount + 1) ? -1 : dp[amount];
        }
};
