/*
 * 31. Next Permutation
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible
 * order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding
 * outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include "header.h"

class Solution {
    public:
        void nextPermutation(vector<int> &nums) {
            int size = nums.size();
            if (size < 2) {
                return;
            }

            int i;
            for (i = size - 1; i > 0; i--) {
                if (nums[i - 1] < nums[i]) {
                    break;
                }
            }

            if (!i) {
                // for (int j = 0; j < (size + 1) / 2; j++) {
                //     int tmp = nums[j];
                //     nums[j] = nums[size - 1 - j];
                //     nums[size - 1 - j] = tmp;
                // }
                reverse(nums.begin(), nums.end());
                return;
            }

            // int target = nums[i - 1], idx = i - 1;
            // for (i++; i < size; i++) {
            //     if (nums[i] <= target) {
            //         break;
            //     }
            // }

            // int tmp = nums[--i];
            // nums[i] = target;
            // nums[idx] = tmp;

            // idx++;
            // for (int j = idx; j < (size + idx + 1) / 2; j++) {
            //     int tmp = nums[j];
            //     nums[j] = nums[size - 1 + idx - j];
            //     nums[size - 1 + idx - j] = tmp;
            // }

            int pos = i - 1;
            i = size - 1;
            while (nums[i] <= nums[pos]) {
                i--;
            }

            int tmp = nums[pos];
            nums[pos] = nums[i];
            nums[i] = tmp;

            reverse(nums.begin() + pos + 1, nums.end());
        }
};
