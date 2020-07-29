/*
 * 1191. K-Concatenation Maximum Sum
 *
 *
 * Given an integer array arr and an integer k, modify the array by
 * repeating it k times.
 *
 * For example, if arr = [1, 2] and k = 3 then the modified array
 * will be [1, 2, 1, 2, 1, 2].
 *
 * Return the maximum sub-array sum in the modified array.
 * Note that the length of the sub-array can be 0 and its sum in
 * that case is 0.
 *
 * As the answer can be very large, return the answer modulo 10^9 + 7.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
 */

#include "header.h"

class Solution {
    public:
        int kConcatenationMaxSum(vector<int>& arr, int k) {
            if (arr.empty() || !k) {
                return 0;
            }
            int n = arr.size();
            int mod = 1000000007;
            int sum = 0, max_sum = INT_MIN;
            int prefix = arr[0], max_pre = prefix;
            int suffix = arr[n - 1], max_suf = suffix;
            for (int i = 1; i < n; i++) {
                prefix += arr[i];
                max_pre = max(max_pre, prefix);
            }
            for (int i = n - 2; i >= 0; i--) {
                suffix += arr[i];
                max_suf = max(max_suf, suffix);
            }
            for (int i = 0; i < n; i++) {
                if (sum <= 0) {
                    sum = arr[i];
                } else {
                    sum += arr[i];
                }
                max_sum = max(max_sum, sum);
            }
            if (k == 1) {
                return max_sum;
            }
            int two_max = (max_pre + max_suf) % mod;
            int k_max = (
                (long) max_pre +
                (long) max_suf +
                (long) (k - 2) * prefix
            ) % mod;
            return max(0, max(max_sum, max(two_max, k_max)));
        }
};
