/*
 * 309. Best Time to Buy and Sell Stock with Cooldown
 *
 * Say you have an array for which the ith element is
 * the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times)
 * with the following restrictions:
 *
 * After you sell your stock, you cannot buy stock on next day.
 * (ie, cooldown 1 day)
 */

#include "header.h"

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            // dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
            int n = prices.size();
            int dp_0 = 0, dp_1 = INT_MIN, dp_pre = 0;
            for (int i = 0; i < n; i++) {
                int tmp = dp_0;
                dp_0 = max(dp_0, dp_1 + prices[i]);
                dp_1 = max(dp_1, dp_pre - prices[i]);
                dp_pre = tmp;
            }
            return dp_0;
        }
};
