/*
 * 523. Continuous Subarray Sum
 *
 * Given a list of non-negative numbers and a target integer k, write a function
 * to check if the array has a continuous subarray of size at least 2 that sums
 * up to a multiple of k, that is, sums up to n * k where n is also an integer.
 *
 * Constraints:
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
 */

#include "header.h"

class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            // return dp(nums, k);
            return hashmap(nums, k);
        }

        bool hashmap(vector<int> &nums, int k) {
            int sum = 0, n = nums.size();
            unordered_map<int, int> cnt;
            cnt[0] = -1;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (k) {
                    sum %= k;
                }
                if (cnt.count(sum)) {
                    if (i - cnt[sum] > 1) {
                        return true;
                    }
                } else {
                    cnt[sum] = i;
                }
            }
            return false;
        }

        bool dp(vector<int> &nums, int k) {
            int n = nums.size();
            vector<int> prefix_sum(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    int sum = prefix_sum[j] - prefix_sum[i] + nums[i - 1];
                    if (sum == k || (k && sum % k == 0)) {
                        return true;
                    }
                }
            }
            return false;
        }
};
