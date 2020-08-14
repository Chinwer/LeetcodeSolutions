/*
 * 264. Ugly Number II
 *
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 *
 * Note:
 *   1. 1 is typically treated as an ugly number.
 *   2. n does not exceed 1690.
 */

#include "header.h"

class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> dp(n);
            dp[0] = 1;
            int i1 = 0, i2 = 0, i3 = 0;
            for (int i = 1; i < n; i++) {
                dp[i] = min(dp[i1] * 2, min(dp[i2] * 3, dp[i3] * 5));
                if (dp[i] == dp[i1] * 2) {
                    i1++;
                }
                if (dp[i] == dp[i2] * 3) {
                    i2++;
                }
                if (dp[i] == dp[i3] * 5) {
                    i3++;
                }
            }
            return dp[n - 1];
        }
};
