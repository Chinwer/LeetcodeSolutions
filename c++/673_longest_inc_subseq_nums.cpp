/*
 * 673. Number of Longest Increasing Subsequence
 *
 * Given an unsorted array of integers, find the number of longest
 * increasing subsequence.
 *
 * Note: Length of the given array will be not excceed 2000 and the
 * answer is guaranteed to be fit in 32-bit signed int.
 */

#include "header.h"

class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) {
                return n;
            }
            vector<int> dp(n, 1), cnts(n, 1);

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] <= nums[j]) {
                        continue;
                    }
                    if (dp[j] >= dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnts[i] = cnts[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnts[i] += cnts[j];
                    }
                }
            }

            int res = 0, max_len = 0;
            for (int len : dp) {
                max_len = max(max_len, len);
            }
            for (int i = 0; i < n; i++) {
                if (dp[i] == max_len) {
                    res += cnts[i];
                }
            }
            return res;
        }
};
