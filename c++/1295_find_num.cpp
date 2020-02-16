/*
 * 1295. Find Numbers with Even Number of Digits
 * Given an array nums of integers, return how many of them contain an even
 * number of digits.
 *
 * Constraints:
 *
 *1 <= nums.length <= 500
 *1 <= nums[i] <= 10^5
 */

#include "header.h"

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int res = 0;
            for (int num : nums) {
                string s = to_string(num);
                res += (1 - s.length() % 2);
            }
            return res;
        }
};
