/*
 * 121. Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock), design an algorithm to find
 * the maximum profit. Note that you cannot sell a stock before you buy one.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // Brute force
            // int res = 0;
            // int size = prices.size();
            // for (int i = 0; i < size; i++) {
            //     for (int j = i + 1; j < size; j++) {
            //         int profit = prices[j] - prices[i];
            //         res = (res > profit ? res : profit);
            //     }
            // }
            // return res;

            // Dynamic Programming
            int res = 0;
            int size = prices.size();
            int dp = 0;
            for (int i = 1; i < size; i++) {
                dp += (prices[i] - prices[i - 1]);
                if (dp < 0) {
                    dp = 0;
                }
                res = (res > dp ? res : dp);
            }
            return res;
        }
};
