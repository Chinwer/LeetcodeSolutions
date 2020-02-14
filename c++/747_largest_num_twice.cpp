/*
 * 747. Largest Number At Least Twice of Others
 * In a given integer array nums, there is always exactly one largest element.
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array. If it is, return the index of the largest
 * element, otherwise return -1.
 *
 * Note:
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 */

#include "header.h"

class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            // Two scans
           
            // int res = -1;
            // int max_ = INT32_MIN;
            // int size = nums.size();

            // for (int i = 0; i < size; i++) {
            //     if (nums[i] > max_) {
            //         max_ = nums[i];
            //         res = i;
            //     }
            // }

            // for (int num : nums) {
            //     if (num > (max_ / 2) && num != max_) {
            //         return -1;
            //     }
            // }
            // return res;

            // One scan
            int res = 0;
            bool flag = true;
            int size = nums.size();
            for (int i = 1; i < size; i++) {
                if (nums[i] > nums[res]) {
                    if (nums[res] > nums[i] / 2) {
                        flag = false;
                    } else {
                        flag = true;
                    }
                    res = i;
                } else if (nums[i] > nums[res] / 2) {
                    flag = false;
                }
            }
            if (flag) {
                return res;
            }
            return -1;
        }
};
