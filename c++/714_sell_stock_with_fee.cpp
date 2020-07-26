/*
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 *
 * Your are given an array of integers prices, for which the
 * i-th element is the price of a given stock on day i; and
 * a non-negative integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you
 * need to pay the transaction fee for each transaction.
 * You may not buy more than 1 share of a stock at a time
 * (ie. you must sell the stock share before you buy again.)
 *
 * Return the maximum profit you can make.
 *
 * Note:
 *
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 */

#include "header.h"

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            int dp_0 = 0, dp_1 = INT_MIN;
            for (int i = 0; i < n; i++) {
                int tmp = dp_0;
                dp_0 = max(dp_0, dp_1 + prices[i]);
                dp_1 = max(dp_1, tmp - prices[i] - fee);
            }
            return dp_0;
        }
};
