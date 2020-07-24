/*
 * 416. Partition Equal Subset Sum
 *
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such
 * that the sum of elements in both subsets is equal.
 *
 * Note:
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 */

#include "header.h"

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for (int num : nums) {
                sum += num;
            }
            // no possible partition when sum is odd
            if (sum & 1) {
                return false;
            }
            sum /= 2;
            int size = nums.size();
            vector<bool> dp(sum + 1, false);
            // vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));
            // base case
            // for (int i = 0; i <= size; i++) {
                // dp[i][0] = true;
            // }
            dp[0] = true;
            // for (int i = 1; i <= size; i++) {
                // for (int j = 1; j <= sum; j++) {
                    // if (j < nums[i - 1]) {
                        // dp[i][j] = dp[i - 1][j];
                    // } else {
                        // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                    // }
                // }
            // }
            for (int i = 0; i < size; i++) {
                for (int j = sum; j >= 0; j--) {
                    if (j >= nums[i]) {
                        dp[j] = dp[j] || dp[j - nums[i]];
                    }
                }
            }
            return dp[sum];
            // return dp[size][sum];
        }
};
