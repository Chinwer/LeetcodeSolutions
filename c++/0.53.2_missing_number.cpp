/*
 * Interview 53-II Missing Number In 0 ~ n-1
 */

#include "header.h"

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int size = nums.size();
            int res = size;
            for (int i = 0; i < size; i++) {
                res ^= i ^ nums[i];
            }
            return res;
        }
};
