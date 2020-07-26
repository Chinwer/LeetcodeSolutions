/*
 * 303. Range Sum Query - Immutable
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */

#include "header.h"

class NumArray {
    private:
        vector<int> dp;

    public:
        NumArray(vector<int>& nums) {
            int n = nums.size();
            dp.resize(n + 1, 0);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                dp[i + 1] = dp[i] + nums[i];
            }
        }

        int sumRange(int i, int j) {
            return dp[j + 1] - dp[i];
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
