/*
 * 1262. Greatest Sum Divisible by Three
 *
 * Given an array nums of integers, we need to find the maximum possible
 * sum of elements of the array such that it is divisible by three.
 *
 * Constraints:
 *   - 1 <= nums.length <= 4 * 10^4
 *   - 1 <= nums[i] <= 10^4
 */

#include "header.h"

class Solution {
    public:
        int maxSumDivThree(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp = { 0, INT_MIN, INT_MIN };

            for (int i = 0; i < n; i++) {
                vector<int> tmp = dp;
                int mod = nums[i] % 3;
                switch (mod) {
                    case 0:
                        dp[0] = max(dp[0], tmp[0] + nums[i]);
                        dp[1] = max(dp[1], tmp[1] + nums[i]);
                        dp[2] = max(dp[2], tmp[2] + nums[i]);
                        break;
                    case 1:
                        dp[0] = max(dp[0], tmp[2] + nums[i]);
                        dp[1] = max(dp[1], tmp[0] + nums[i]);
                        dp[2] = max(dp[2], tmp[1] + nums[i]);
                        break;
                    default:
                        dp[0] = max(dp[0], tmp[1] + nums[i]);
                        dp[1] = max(dp[1], tmp[2] + nums[i]);
                        dp[2] = max(dp[2], tmp[0] + nums[i]);
                        break;
                }
            }
            return dp[0];
        }
};
