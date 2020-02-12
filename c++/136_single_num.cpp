/*
 * 136. Single Number
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int res = 0;
            for (int i : nums) {
                res ^= i;
            }
            return res;
        }
};
