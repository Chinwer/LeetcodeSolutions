/*
 * 280. Wiggle Sort
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <=
 * nums[1] >= nums[2] <= nums[3]...
 */

#include "header.h"

class Solution {
    public:
        void swap(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        void wiggleSort(vector<int> &nums) {
            int n = nums.size();
            for (int i = 0; i < n - 1; i++) {
                if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
};
