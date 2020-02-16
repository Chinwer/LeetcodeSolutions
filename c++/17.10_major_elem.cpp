/*
 * 17.10. Find Majority Element
 */

#include "header.h"

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int candidate;
            int cnt = 0, size = nums.size();

            for (int num : nums) {
                if (!cnt) {
                    candidate = num;
                }
                cnt += (candidate == num ? 1 : -1);
            }

            if (!cnt) {
                return -1;
            }
            return candidate;
        }
};
