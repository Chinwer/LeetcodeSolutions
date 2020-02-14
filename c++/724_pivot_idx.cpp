/*
 * 724. Find Pivot Index
 * Given an array of integers nums, write a method that returns the "pivot"
 * index of this array. We define the pivot index as the index where the sum of
 * the numbers to the left of the index is equal to the sum of the numbers to
 * the right of the index. If no such index exists, we should return -1. If
 * there are multiple pivot indexes, you should return the left-most pivot
 * index.
 *
 * Note:
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
 */

#include "header.h"

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            if (nums.empty()) {
                return -1;
            }

            int sum = 0;
            int lsum = 0;
            int size = nums.size();

            for (int num : nums) {
                sum += num;
            }

            for (int i = 0; i < size; i++) {
                if (lsum * 2 == sum - nums[i]) {
                    return i;
                }
                lsum += nums[i];
            }
            return -1;
        }
};
