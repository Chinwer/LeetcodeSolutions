/*
 * 123. Best Time to Buy and Sell Stock III
 *
 * Say you have an array for which the ith element is the price
 * of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete
 * at most two transactions.
 *
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again).
 */

#include "header.h"

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
            // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

            // return solution1(prices);
            return solution1_optimized(prices);
        }

        int solution1_optimized(vector<int> &prices) {
            // dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i])
            // dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i])
            // dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i])
            // dp[i][1][1] = max(dp[i - 1][1][1], -prices[i])
            int dp_10 = 0, dp_11 = INT_MIN;
            int dp_20 = 0, dp_21 = INT_MIN;
            for (int price : prices) {
                dp_20 = max(dp_20, dp_21 + price);
                dp_21 = max(dp_21, dp_10 - price);
                dp_10 = max(dp_10, dp_11 + price);
                dp_11 = max(dp_11, -price);
            }
            return dp_20;
        }

        int solution1(vector<int> &prices) {
            int n = prices.size();
            // boundary condition
            if (n < 2) {
                return 0;
            }

            vector<vector<vector<int>>> dp(n, vector(3, vector(2, 0)));
            dp[0][0][1] = -prices[0];
            dp[0][1][1] = -prices[0];
            dp[0][2][1] = -prices[0];
            for (int i = 1; i < n; i++) {
                for (int k = 1; k <= 2; k++) {
                    dp[i][k][0] = max(
                        dp[i - 1][k][0],
                        dp[i - 1][k][1] + prices[i]
                    );
                    dp[i][k][1] = max(
                        dp[i - 1][k][1],
                        dp[i - 1][k - 1][0] - prices[i]
                    );
                }
            }
            return dp[n - 1][2][0];
        }
};
