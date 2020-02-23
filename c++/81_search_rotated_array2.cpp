/*
 * 81. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 */

#include "header.h"

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int n = nums.size();
            int l = 0, r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[m] == target) {
                    return true;
                }
                if (nums[m] == nums[l]) {
                    l++;
                    continue;
                }

                if (nums[l] < nums[m]) {
                    if (nums[l] <= target && target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if (nums[m] < target && target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
            return false;
        }
};
