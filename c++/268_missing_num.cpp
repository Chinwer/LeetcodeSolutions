/*
 * 268. Missing Number
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
 * the one that is missing from the array.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it
 * using only constant extra space complexity?
 */

#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            // Hash table
            // map<int, int> dict;
            // int size = nums.size();
            // for (int i = 0; i < size; i++) {
            //     dict[nums[i]] = 1;
            // }
            // for (int i = 0; i < size; i++) {
            //     if (!dict.count(i)) {
            //         return nums[i];
            //     }
            // }
            // return -1;

            // xor
            int size = nums.size();
            int res = size;
            for (int i = 0; i < size; i++) {
                res ^= (i ^ nums[i]);
            }
            return res;
        }
};
