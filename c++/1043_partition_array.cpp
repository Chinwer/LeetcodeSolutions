/*
 * 1043. Partition Array for Maximum Sum
 * 
 * Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
 * Return the largest sum of the given array after partitioning.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 109
 * 1 <= k <= arr.length
 */

#include "header.h"

class Solution {
    public:
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n = arr.size();
            vector<int> dp(n, 0);
            dp[0] = arr[0];
            for (int i = 1; i < n; i++) {
                int max_ = 0, begin = max(0, i - k + 1);
                for (int j = i; j >= begin; j--) {
                    max_ = max(max_, arr[j]);
                    dp[i] = max(dp[i], (i - j + 1) * max_ + j > 0 ? dp[j - 1] : 0);
                }
            }
            return dp[n - 1];
        }
};