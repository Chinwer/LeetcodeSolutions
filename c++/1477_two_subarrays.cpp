/*
 * 1477. Find Two Non-overlapping Sub-arrays Each With Target S
 *
 * Given an array of integers arr and an integer target.
 *
 * You have to find two non-overlapping sub-arrays of arr each
 * with sum equal target. There can be multiple answers so you
 * have to find an answer where the sum of the lengths of the
 * two sub-arrays is minimum.
 *
 * Return the minimum sum of the lengths of the two required
 * sub-arrays, or return -1 if you cannot find such two sub-arrays.
 *
 * Constraints:
 *   - 1 <= arr.length <= 10^5
 *   - 1 <= arr[i] <= 1000
 *   - 1 <= target <= 10^8
 */

#include "header.h"

class Solution {
    public:
        int minSumOfLengths(vector<int>& arr, int target) {
            int n = arr.size(), res = n + 1;
            vector<int> dp(n, INT_MAX);
            unordered_map<int, int> pre;
            pre[0] = -1;

            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
                if (i) {
                    dp[i] = dp[i - 1];
                }
                if (pre.count(sum - target)) {
                    int l_idx = pre[sum - target], len = i - l_idx;
                    if (pre[sum - target] >= 0 && dp[l_idx] != INT_MAX) {
                        res = min(res, len + dp[l_idx]);
                    }
                    dp[i] = min(dp[i], len);
                }
                pre[sum] = i;
            }
            return res == n + 1 ? -1 : res;
        }
};
