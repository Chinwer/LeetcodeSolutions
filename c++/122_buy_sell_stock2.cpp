/*
 * 122. Best Time to Buy and Sell Stock II
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete as
 * many transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times). Note: You may not engage in multiple transactions at the
 * same time (i.e., you must sell the stock before you buy again).
 */

#include "header.h"

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // return one_way_traversal(prices);
            // return dynamic_programming(prices);
            return optimized_dp(prices);
        }

        int optimized_dp(vector<int> &prices) {
            int n = prices.size();
            int dp_0 = 0, dp_1 = -prices[0];
            for (int i = 1; i < n; i++) {
                int tmp = dp_0;
                dp_0 = max(dp_0, dp_1 + prices[i]);
                dp_1 = max(dp_1, tmp - prices[i]);
            }
            return dp_0;
        }

        int dynamic_programming(vector<int> &prices) {
            // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
            // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

            // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])

            int n = prices.size();
            if (n < 2) {
                return 0;
            }
            vector<vector<int>> dp(n, vector(2, 0));
            dp[0][1] = -prices[0];
            for (int i = 1; i < n; i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
            return dp[n - 1][0];
        }

        int one_way_traversal(vector<int> &prices) {
            int res = 0;
            int size = prices.size();
            for (int i = 0; i < size - 1; i++) {
                if (prices[i + 1] > prices[i]) {
                    res += prices[i + 1] - prices[i];
                }
            }
            return res;
        }
};
