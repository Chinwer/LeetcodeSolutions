/*
 * 1186. Maximum Subarray Sum with One Deletion
 *
 * Given an array of integers, return the maximum sum for a non-empty subarray
 * (contiguous elements) with at most one element deletion. In other words, you want to
 * choose a subarray and optionally delete one element from it so that there is still at least
 * one element left and the sum of the remaining elements is maximum possible.
 *
 * Note that the subarray needs to be non-empty after deleting one element.
 *
 * Constraints:
 *   - 1 <= arr.length <= 10^5
 *   - -10^4 <= arr[i] <= 10^4
 */

#include "header.h"

class Solution {
    public:
        int maximumSum(vector<int>& arr) {
            int dp1 = arr[0], dp2 = -10000;
            int n = arr.size(), res = arr[0];
            for (int i = 1; i < n; i++) {
                int tmp = dp1;
                dp1 = max(arr[i], arr[i] + dp1);
                dp2 = max(tmp, arr[i] + dp2);
                res = max(res, max(dp1, dp2));
            }
            return res;
        }
};
