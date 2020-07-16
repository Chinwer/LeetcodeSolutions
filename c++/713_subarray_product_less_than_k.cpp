/*
 * 713. Subarray Product Less Than K
 *
 * You are given an array of positive integers nums.
 *
 * Count and print the number of (contiguous) subarrays where the
 * product of all the elements in the subarray is less than k.
 *
 * Note:

 * 0 < nums.length <= 50000.
 * 0 < nums[i] < 1000.
 * 0 <= k < 10^6.
 */

#include "header.h"

class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if (k <= 1) {
                return 0;
            }

            int size = nums.size();
            int res = 0, left = 0, prod = 1;
            for (int i = 0; i < size; i++) {
                prod *= nums[i];
                while (prod >= k) {
                    prod /= nums[left];
                    left++;
                }
                res += i - left + 1;
            }
            return res;
        }
};
