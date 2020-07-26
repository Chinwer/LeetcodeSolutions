/*
 * 740. Delete and Earn
 *
 * Given an array nums of integers, you can perform operations on the array.
 *
 * In each operation, you pick any nums[i] and delete it to earn nums[i] points.
 * After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
 *
 * You start with 0 points.
 * Return the maximum number of points you can earn by applying such operations.
 *
 * Note:
 *   - The length of nums is at most 20000
 *   - Each element nums[i] is an integer in the range [1, 10000].
 */

#include "header.h"

class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            int n = nums.size();
            if (!n) {
                return 0;
            }
            if (n == 1) {
                return nums[0];
            }
            int max_ = 0;
            for (int num : nums) {
                max_ = max(max_, num);
            }
            vector<int> cnt(max_ + 1);
            for (int num : nums) {
                cnt[num]++;
            }
            vector<int> dp(max_ + 1);
            dp[1] = cnt[1];
            dp[2] = max(dp[1], 2 * cnt[2]);
            for (int i = 3; i <= max_; i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
            }
            return dp[max_];
        }
};
