/*
 * 410. Split Array Largest Sum
 *
 * Given an array which consists of non-negative integers and an integer m,
 * you can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 *
 * Note:
 * If n is the length of array, assume the following constraints are satisfied:
 *   - 1 <= n <= 1000
 *   - 1 <= m <= min(50, n)
 */

#include "header.h"

class Solution {
    public:
        int splitArray(vector<int>& nums, int m) {
            int n = nums.size();
            vector<long> prefix(n + 1);
            vector<vector<long>> dp(n + 1, vector(m + 1, LONG_MAX));

            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                prefix[i] = prefix[i - 1] + nums[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                int end = min(i, m);
                for (int j = 1; j <= end; j++) {
                    for (int k = 0; k < i; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            max(prefix[i] - prefix[k], dp[k][j - 1])
                        );
                    }
                }
            }
            return dp[n][m];
        }
};
