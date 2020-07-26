/*
 * 188. Best Time to Buy and Sell Stock IV
 *
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include "header.h"

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            if (k > n / 2) {
                return maxProfitInf(k, prices);
            }
            vector<vector<vector<int>>> dp(n, vector(k + 1, vector(2, 0)));
            // base case
            for (int i = 0; i <= k; i++) {
                dp[0][i][1] = -prices[0];
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= k; j++) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
            return dp[n - 1][k][0];
        }

        int maxProfitInf(int k, vector<int> &prices) {
            int res = 0, n = prices.size();
            for (int i = 0; i < n - 1; i++) {
                if (prices[i + 1] > prices[i]) {
                    res += prices[i + 1] - prices[i];
                }
            }
            return res;
        }
};
