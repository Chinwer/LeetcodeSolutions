/*
 * 34. Find First and Last Position of Element in Sorted Array
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

 */

#include "header.h"

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            // int n = nums.size();
            // int l = 0, r = n - 1;
            // while (l <= r && (nums[l] != target || nums[r] != target)) {
            //     int m = l + (r - l) / 2;
            //     if (nums[m] ==  target) {
            //         if (nums[l] < target) {
            //             l++;
            //         }
            //         if (nums[r] > target) {
            //             r--;
            //         }
            //     } else if (nums[m] < target) {
            //         l = m + 1;
            //     } else {
            //         r = m - 1;
            //     }
            // }
            // if (l > r) {
            //     return { -1, -1 };
            // }
            // return { l, r };

            int n = nums.size();
            if (!n) {
                return { -1, -1 };
            }
            int l = bin_search_left_bound(nums, target);
            if (l == n || nums[l] != target) {
                return { -1, -1 };
            }
            if (l == n - 1) {
                return { l, l };
            }

            int r = bin_search_right_bound(nums, target);
            return { l, r };
        }

        int bin_search_left_bound(vector<int>& nums, int target) {
            int n = nums.size();
            if (!n) {
                return -1;
            }

            int l = 0, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] == target) {
                    r = m;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            return l;
        }

        int bin_search_right_bound(vector<int>& nums, int target) {
            int n = nums.size();
            if (!n) {
                return -1;
            }

            int l = 0, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] == target) {
                    l = m + 1;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            return --l;
        }
};
