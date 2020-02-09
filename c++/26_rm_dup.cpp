/*
 * 26. Remove Duplicates from Sorted Array
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length. Do not allocate extra
 * space for another array, you must do this by modifying the input array
 * in-place with O(1) extra memory.
 *
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0;
            int j = 1;
            int size = nums.size();
            if (!size) {
                return 0;
            }
            while (j < size) {
                if (nums[j] == nums[i]) {
                    j++;
                } else {
                    nums[++i] = nums[j++];
                }
            }
            return ++i;
        }
};
