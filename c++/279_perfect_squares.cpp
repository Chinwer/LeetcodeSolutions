/*
 * 279. Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 8, 16, ...) which sum to n.
 */

#include "header.h"

class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1);
            for (int i = 1; i <= n; i++) {
                int min_ = INT_MAX;
                for (int j = 1; j * j <= i; j++) {
                    min_ = min(min_, dp[i - j * j] + 1);
                }
                dp[i] = min_;
            }
            return dp[n];
        }
};