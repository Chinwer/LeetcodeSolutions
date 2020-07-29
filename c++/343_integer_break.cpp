/*
 * 343. Integer Break
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the
 * maximum product you can get.
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 */

#include "header.h"

class Solution {
    public:
        int integerBreak(int n) {
            vector<int> dp(n + 1, 0);
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    dp[i] = max(dp[i], max(dp[j], j) * (i - j));
                }
            }
            return dp[n];
        }
};
