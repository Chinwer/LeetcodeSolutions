/*
 * 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // Greedy algorighm
            //
            // int sum = 0;
            // int res = nums[0];
            // int size = nums.size();
            // for (int i = 0; i < size; i++) {
            //     if (sum > 0) {
            //         sum += nums[i];
            //     } else {
            //         sum = nums[i];
            //     }
            //     res = res >= sum ? res : sum;
            // }
            // return res;

            // Dynamic programming
            int dp(nums[0]);
            int res = dp;
            int size = nums.size();
            for (int i = 1; i < size; i++) {
                dp = max(dp + nums[i], nums[i]);
                res = max(dp, res);
            }
            return res;
        }
};
