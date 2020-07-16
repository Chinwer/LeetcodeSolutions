/*
 * 80. Remove Duplicates from Sorted Array II
 *
 * Given a sorted array nums, remove the duplicates appeared
 * at most twice and return the new length.
 *
 * Do not allocate extra space for another array, you must do this
 * by modifying the input array in-plce with O(1) extra memory.
 */

#include "header.h"

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            int size = nums.size();
            int cnt = 1, slow = 1, fast = 1;
            while (fast < size) {
                if (nums[fast] != nums[fast - 1]) {
                    cnt = 1;
                } else {
                    cnt++;
                }
                if (cnt < 3) {
                    nums[slow++] = nums[fast++];
                } else {
                    while (fast < size && nums[fast] == nums[fast - 1]) {
                        fast++;
                    }
                }
            }
            return slow;
        }
};
