/*
 * 698. Partition to K Equal Sum Subsets
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all equal.
 *
 * Note:
 *   - 1 <= k <= len(nums) <= 16.
 *   - 0 < nums[i] < 10000.
 */

#include "header.h"

class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int sum = 0, n = nums.size();
            for (int i = 0; i < n; i++) {
                sum += nums[i];
            }
            if (sum % k) {
                return false;
            }
            sum /= k;
            sort(nums.begin(), nums.end(), greater<int>());

            vector<int> subsets;
            return dfs(nums, subsets, 0, sum, k, n);
        }

        int dfs(vector<int> &nums, vector<int> &subsets,
            int pos, int sum, int k, int n) {
            if (pos == n) {
                return true;
            }
            if (nums[pos] > sum) {
                return false;
            }
            int size = subsets.size();
            for (int i = 0; i < size; i++) {
                if (subsets[i] + nums[pos] > sum) {
                    continue;
                }
                subsets[i] += nums[pos];
                if (dfs(nums, subsets, pos + 1, sum, k, n)) {
                    return true;
                }
                subsets[i] -= nums[pos];
            }

            if (size == k) {
                return false;
            }
            subsets.push_back(nums[pos]);
            if (dfs(nums, subsets, pos + 1, sum, k, n)) {
                return true;
            }
            subsets.pop_back();
            return false;
        }
};
