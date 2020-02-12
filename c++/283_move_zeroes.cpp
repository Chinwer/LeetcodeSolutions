/*
 * 283. Move Zeroes
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Note:
 *     You must do this in-place without making a copy of the array.
 *     Minimize the total number of operations.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            // // Double pointers
            // int size = nums.size();
            // if (!size) {
            //     return;
            // }

            // int i = 0, j = 0;
            // // Find the first zero element
            // while (i < size && nums[i] != 0) {
            //     i++;
            // }
            // j = i + 1;
            // // Find the first non-zero element
            // while (j < size && nums[j] == 0) {
            //     j++;
            // }
            // while (j < size) {
            //     int tmp = nums[i];
            //     nums[i] = nums[j];
            //     nums[j] = tmp;
            //     do {
            //         i++;
            //     } while (i < size && nums[i] != 0);
            //     do {
            //         j++;
            //     } while (j < size && nums[j] == 0);
            // }

            int i = 0;
            for (int num : nums) {
                if (num) {
                    nums[i++] = num;
                }
            }
            while (i < nums.size()) {
                nums[i++] = 0;
            }
        }
};
