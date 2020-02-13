/*
 * 674. Longest Continuous Increasing Subsequence
 * Given an unsorted array of integers, find the length of longest continuous
 * increasing subsequence (subarray).
 * Note: Length of the array will not exceed 10,000.
 */

#include "header.h"

class Solution {
    public:
        int lengthOfLCIS(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }

            int res = 0;
            int cnt = 1;
            int size = nums.size();
            for (int i = 0; i < size - 1; i++) {
                if (nums[i + 1] > nums[i]) {
                    cnt++;
                } else {
                    res = max(res, cnt);
                    cnt = 1;
                }
            }
            return max(res, cnt);
        }
};
