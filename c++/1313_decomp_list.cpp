/*
 * 1133. Decompress Run-Length Encoded List
 *
 * We are given a list nums of integers representing a list compressed with
 * run-length encoding.
 *
 * Consider each adjacent pair of elements [a, b] = [nums[2*i],
 * nums[2*i+1]] (with i >= 0).  For each such pair, there are a elements with
 * value b in the decompressed list.
 *
 * Return the decompressed list.
 *
 * Constraints:
 *
 * 2 <= nums.length <= 100
 * nums.length % 2 == 0
 * 1 <= nums[i] <= 100
 */

#include "header.h"

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int last = nums.size() / 2;
        for (int i = 0; i < last; i++) {
            int tmp = 2 * i;
            for (int j = 0; j < nums[tmp]; j++) {
                res.push_back(nums[tmp + 1]);
            }
        }
        return res;
    }
};
