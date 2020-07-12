/*
 * 75. Sort Colors
 *
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 * Note: You are not suppose to use the library's sort function for this problem.

 * Follow up:

 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 */

#include "header.h"

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            /* two-pass solution */

            // vector<int> cnt(3, 0);
            // for (int num : nums) {
            //     cnt[num]++;
            // }
            // int i = 0;
            // for (int j = 0; j < 3; j++) {
            //     for (int k = 0; k < cnt[j]; k++) {
            //         nums[i++] = j;
            //     }
            // }

            /* optimized one-pass solution */
            int size = nums.size();
            int i = 0, left = 0, right = size - 1;
            while (i < right) {
                if (nums[i] == 1) {
                    i++;
                } else if (nums[i] == 0) {
                    int tmp = nums[i];
                    nums[i] = nums[left];
                    nums[left] = tmp;
                    left++;
                    i++;
                } else {
                    int tmp = nums[i];
                    nums[i] = nums[right];
                    nums[right] = tmp;
                    right--;
                    /**************************************
                     * Attention! DO NOT INCREMENT i HERE
                     * Explanation:
                     *   numbers to the left of i have been scanned by now,
                     *   however, the number exchanged from nums[right] has not.
                     **************************************/
                    // i++;
                }
            }
        }
};
