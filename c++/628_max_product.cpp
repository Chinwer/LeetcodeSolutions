/*
 * 628. Maximum Product of Three Numbers
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 *
 * Note:
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input
 * won't exceed the range of 32-bit signed integer.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            // Sort, O(nlogn)
            //
            // int s = nums.size();
            // sort(nums.begin(), nums.end());
            // return max(nums[0] * nums[1] * nums[s - 1],
            //            nums[s - 1] * nums[s - 2] * nums[s - 3]);

            // Linear scan, O(n)
            int f_max, s_max, t_max;
            f_max = s_max = t_max = INT32_MIN;
            int f_min, s_min;
            f_min = s_min = INT32_MAX;
            for (int num : nums) {
                if (num > f_max) {
                    t_max = s_max;
                    s_max = f_max;
                    f_max = num;
                } else if (num > s_max) {
                    t_max = s_max;
                    s_max = num;
                } else if (num > t_max) {
                    t_max = num;
                }

                if (num < f_min) {
                    s_min = f_min;
                    f_min = num;
                } else if (num < s_min) {
                    s_min = num;
                }
            }
            return max(f_max * s_max * t_max,
                       f_max * f_min * s_min);
        }
};
