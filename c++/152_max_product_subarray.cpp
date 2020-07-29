/*
 * 152. Maximum Product Subarray
 *
 * Given an integer array nums, find the contiguous subarray within an
 * array (containing at least one number) which has the largest product.
 */

#include "header.h"

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // return original(nums);
            return optimized(nums);
        }

        int optimized(vector<int> &nums) {
            if (nums.empty()) {
                return 0;
            }
            int res = nums[0], n = nums.size();
            int dp_max = nums[0], dp_min = nums[0];
            for (int i = 1; i < n; i++) {
                int tmp = dp_max;
                dp_max = max(nums[i], max(dp_max * nums[i], dp_min * nums[i]));
                dp_min = min(nums[i], min(dp_min * nums[i], tmp * nums[i]));
                res = max(res, dp_max);
            }
            return res;
        }

        int original(vector<int> &nums) {
            if (nums.empty()) {
                return 0;
            }
            int res = nums[0], n = nums.size();
            vector<int> dp_max(n, 0);
            vector<int> dp_min(n, 0);
            dp_max[0] = nums[0];
            dp_min[0] = nums[0];
            for (int i = 1; i < n; i++) {
                dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
                dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
                res = max(res, dp_max[i]);
            }
            return res;
        }
};
