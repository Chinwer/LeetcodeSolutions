/*
 * 494. Target Sum
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers
 * equal to target S.
 *
 * Constraints:
 *   - The lenght of the given array is positive and will not exceed 20.
 *   - The sum of elements in the given array will not exceed 1000.
 *   - Your output ansewr is guaranteed to be fitted in a 32-bit integer.
 */

#include "header.h"

class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            int n = nums.size();
            vector<map<int, int>> dp(n);
            dp[0][nums[0]] += 1;
            dp[0][-nums[0]] += 1;
            for (int i = 1; i < n; i++) {
                for (auto it : dp[i - 1]) {
                    int sum1 = it.first + nums[i];
                    int sum2 = it.first - nums[i];
                    dp[i][sum1] += it.second;
                    dp[i][sum2] += it.second;
                }
            }
            return dp[n - 1][S];
        }
};
