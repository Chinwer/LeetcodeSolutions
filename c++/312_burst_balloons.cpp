/*
 * 312. Burst Balloons
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with
 * a number on it represented by array nums. You are asked to burst all
 * the balloons. If the you burst balloon i you will get
 * nums[left] * nums[i] * nums[right] coins. Here left and right are
 * adjacent indices of i. After the burst, the left and right then becomes adjacent.
 *
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Note:
 *
 *   - You may imagine nums[-1] = nums[n] = 1. They are not real therefore
 *     you can not burst them.
 *   - 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 */

#include "header.h"

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            vector<int> ballons(n + 2, 1);
            for (int i = 1; i <= n; i++) {
                ballons[i] = nums[i - 1];
            }
            vector<vector<int>> dp(n + 2, vector(n + 2, 0));
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 2; j < n + 2; j++) {
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = max(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + ballons[i] * ballons[j] * ballons[k]
                        );
                    }
                }
            }
            return dp[0][n + 1];
        }
};
