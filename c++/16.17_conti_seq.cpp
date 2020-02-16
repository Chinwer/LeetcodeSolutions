/*
 * Interview 16.17. Contiguous Sequence
 */

#include "header.h"

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = INT32_MIN, sum = INT32_MIN;

            for (int num : nums) {
                if (sum > 0) {
                    sum += num;
                } else {
                    sum = num;
                }
                res = res < sum ? sum : res;
            }

            return res;
        }
};
