/*
 * 153. Find Minimum in Rotated Sorted Array
 *
 * Suppose an array sorted in ascending order is rotated at
 * some pivot unknown to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            // O(n) time complexity solution

            // int size = nums.size();
            // for (int i = 0; i < size - 1; i++) {
            //     if (nums[i + 1] < nums[i]) {
            //         return nums[i + 1];
            //     }
            // }
            // return nums[0];

            // binary search
            int n = nums.size();
            int l = 0, r = n - 1;
            if (n == 1 || nums[l] < nums[r]) {
                return nums[0];
            }

            int pivot;
            while (l <= r) {
                pivot = l + (r - l) / 2;
                if (nums[pivot] > nums[pivot + 1]) {
                    return nums[++pivot];
                } else if (nums[pivot] < nums[l]) {
                    r = --pivot;
                } else {
                    l = ++pivot;
                }
            }
            return nums[0];
        }
};
