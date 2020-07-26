/*
 * 198. House Robber
 *
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Constraints:
 *
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 */

#include "header.h"

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            // dp[i] represents the most money that can be robbed
            // starting from room i, which is nums[i]
            vector<int> dp(n + 2, 0);
            for (int i = n - 1; i >= 0; i--) {
                dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
            }
            return dp[0];
        }
};
