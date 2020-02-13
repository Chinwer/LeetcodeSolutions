/*
 * 665. Non-decreasing Array
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element. We define an array is
 * non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 *
 * Note: The n belongs to [1, 10,000].
 */

#include "header.h"

class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            int size = nums.size();
            if (size <= 2) {
                return true;
            }

            int cnt = 0;
            for (int i = 0; i < size - 1; i++) {
                if (nums[i + 1] < nums[i]) {
                    cnt++;
                    if (cnt > 1) {
                        return false;
                    }
                    if (i == 0 || nums[i - 1] <= nums[i + 1]) {
                        nums[i] = nums[i + 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                }
            }
            return true;
        }
};
