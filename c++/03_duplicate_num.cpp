/*
 * Interview 03. Duplicate Numbers in an Array
 */

#include "header.h"

class Solution {
    public:
        int findRepeatNumber(vector<int>& nums) {
            // map<int, int> hash;
            // for (int num : nums) {
            //     if (++hash[num] > 1) {
            //         return num;
            //     }
            // }
            // return -1;

            // In-place
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                while (nums[i] != i) {
                    if (nums[i] == nums[nums[i]]) {
                        return nums[i];
                    }
                    int tmp = nums[i];
                    nums[i] = nums[tmp];
                    nums[tmp] = tmp;
                }
            }
            return -1;
        }
};
