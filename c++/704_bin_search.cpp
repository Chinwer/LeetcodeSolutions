/*
 * 704. Binary Search
 * Given a sorted (in ascending order) integer array nums of n elements and a
 * target value, write a function to search target in nums. If target exists,
 * then return its index, otherwise return -1.
 *
 * Note:
 *
 * You may assume that all elements in nums are unique.
 * n will be in the range [1, 10000].
 * The value of each element in nums will be in the range [-9999, 9999].
 */

#include "header.h"

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // int l = 0, r = nums.size();
            int l = 0, r = nums.size() - 1;
            // while (l < r) {
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[m] == target) {
                    return m;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    // r = m;
                    r = m -1;
                }
            }
            return -1;
        }
};
