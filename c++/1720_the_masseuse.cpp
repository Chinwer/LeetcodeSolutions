/*
 * 1720. The Masseuse LCCI
 *
 * A popular masseuse receives a sequence of back-to-back appointment
 * requests and is debating which ones to accept. She needs a break
 * between appointments and therefore she cannot accept any adjacent
 * requests. Given a sequence of back-to-back appoint­ ment requests,
 * find the optimal (highest total booked minutes) set the masseuse
 * can honor. Return the number of minutes.
 *
 * Note: This problem is slightly different from the original one in the book.
 */

#include "header.h"

class Solution {
    public:
        int massage(vector<int>& nums) {
            // int n = nums.size();
            // vector<int> dp(n + 2, 0);
            // for (int i = n - 1; i >= 0; i--) {
            //     dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
            // }
            // return dp[0];

            int n = nums.size();
            int dp, dp_1 = 0, dp_2 = 0;
            for (int i = n - 1; i >= 0; i--) {
                dp = max(dp_1, dp_2 + nums[i]);
                dp_2 = dp_1;
                dp_1 = dp;
            }
            return dp;
        }
};
