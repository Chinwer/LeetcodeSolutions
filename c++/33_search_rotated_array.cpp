/*
 * 33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */

#include "header.h"

class Solution {
    public:
        int get_rotate_pivot(vector<int>& nums) {
            int n = nums.size();
            int l = 0, r = n - 1;
            if (nums[l] < nums[r]) {
                return 0;
            }

            int pivot;
            while (l <= r) {
                pivot = l + (r - l) / 2;
                if (nums[pivot] > nums[pivot + 1]) {
                    return ++pivot;
                } else if (nums[pivot] < nums[l]) {
                    r = --pivot;
                } else {
                    l = ++pivot;
                }
            }

            return 0;
        }

        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int pivot, l = 0, r = n - 1;

            if (!n) {
                return -1;
            }
            if (n == 1) {
                return nums[0] == target ? 0 : -1;
            }

            pivot = get_rotate_pivot(nums);

            l = 0;
            r = n - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                int idx = (mid + pivot) % n;
                if (nums[idx] < target) {
                    l = mid + 1;
                } else if (nums[idx] > target) {
                    r = mid;
                } else {
                    return idx;
                }
            }
            return -1;
        }
};
