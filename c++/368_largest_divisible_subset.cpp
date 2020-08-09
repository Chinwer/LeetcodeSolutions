/*
 * 368. Largest Divisible Subset
 *
 * Given a set of distinct positive integers, find the largest subset such
 * that every pair (S_i, S_j) of elements in this subset satisfies:
 *
 * S_i % S_j = 0 or S_j % S_i = 0
 *
 * If there are multiple solutions, return any subset is fine.
 */

#include "header.h"

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            if (!n) {
                return {};
            }
            sort(nums.begin(), nums.end());
            int maxSize = 1, maxIndex = 0;
            vector<int> dp(n, 1);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                if (maxSize < dp[i]) {
                    maxIndex = i;
                    maxSize = dp[i];
                }
            }

            vector<int> res;
            for (int i = maxIndex; i >= 0; i--) {
                if (nums[maxIndex] % nums[i] == 0 && dp[i] == maxSize) {
                    res.push_back(nums[i]);
                    maxSize--;
                    maxIndex = i;
                }
            }
            return res;
        }
};
