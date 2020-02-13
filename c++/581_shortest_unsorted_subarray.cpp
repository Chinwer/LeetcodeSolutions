/*
 * 581. Shortest Unsorted Continuous Subarray
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too. You need to find the shortest such subarray
 * and output its length.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            // int front, back;
            // int min = INT32_MAX, max = INT32_MIN;
            // int size = nums.size();
            // int i = 0, j = size - 1;
            // while (i < size - 1 && nums[i + 1] >= nums[i]) {
            //     i++;
            // }
            // front = i;
            // while (j > 0 && nums[j - 1] <= nums[j]) {
            //     j--;
            // }
            // back = j;
            // if (back <= front) {
            //     return 0;
            // }
            // while (i <= j) {
            //     if (nums[i] < min) {
            //         min = nums[i];
            //     }
            //     if (nums[i] > max) {
            //         max = nums[i];
            //     }
            //     i++;
            // }
            // i = 0;
            // j = size - 1;
            // while (i <= front && nums[i] <= min) {
            //     i++;
            // }
            // while (j >= back && nums[j] >= max) {
            //     j--;
            // }
            // return i - j + 1;
            int size = nums.size();
            int min = INT32_MAX;
            int max = INT32_MIN;
            int l = 0, r = -1;
            for (int i = 0; i < size; i++) {
                if (nums[i] >= max) {
                    max = nums[i];
                } else {
                    r = i;
                }

                int ri = size - i - 1;
                if (nums[ri] <= min) {
                    min = nums[ri];
                } else {
                    l = ri;
                }
            }
            return r - l + 1;
        }
};
