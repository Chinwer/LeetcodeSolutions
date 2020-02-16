/*
 * Interview 0.53. Search a Number In an Sorted Array
 *
 * 统计一个数字在排序数组中出现的次数。
 */

#include "header.h"

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int pos = bin_search(nums, target);
            if (pos == -1) {
                return 0;
            }

            int l = pos - 1, r = pos + 1;
            while (l >= 0 && nums[l] == target) {
                l--;
            }
            while (r < nums.size() && nums[r] == target) {
                r++;
            }
            return r - l - 1;
        }

        int bin_search(vector<int>& nums, int target) {
            int size = nums.size();
            int low = 0, high = size;

            while (low < high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            return -1;
        }
};
