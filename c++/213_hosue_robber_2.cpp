/*
 * 213. House Robber II
 *
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include "header.h"

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (!n) {
                return 0;
            }
            if (n == 1) {
                return nums[0];
            }
            return max(
                rob_range(nums, 0, n - 2),
                rob_range(nums, 1, n - 1)
            );
        }

        int rob_range(vector<int> &nums, int start, int end) {
            int dp = 0, dp_1 = 0, dp_2 = 0;
            for (int i = end; i >= start; i--) {
                dp = max(dp_1, nums[i] + dp_2);
                dp_2 = dp_1;
                dp_1 = dp;
            }
            return dp;
        }
};
