/*
 * Interview 17.04. Missing Number
 * The array nums contains all integers from 0 to n, but one of them is missing.
 * Please find the missing one. Can you solve the problem in O(n) time
 * complexity?
 */

#include "header.h"

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int size = nums.size();
            int res = size;
            for (int i = 0; i < size; i++) {
                res ^= (i ^ nums[i]);
            }
            return res;
        }
};
