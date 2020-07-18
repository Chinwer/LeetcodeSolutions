/*
 * 154. Find Minimum in Rotated Sorted Array II
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Note:
 *
 * - This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * - Would allow duplicates affect the run-time complexity? How and why?
 */

#include "header.h"

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int size = nums.size();
            int left = 0, right = size - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < nums[right]) {
                    right = mid;
                } else if (nums[mid] > nums[right]) {
                    left = ++mid;
                } else {
                    right--;
                }
            }
            return nums[left];
        }
};
