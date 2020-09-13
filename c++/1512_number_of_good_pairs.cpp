/*
 * 1512. Number of Good Pairs
 *
 * Given an array of integers nums.
 *
 * A pair (i, j) is called good if nums[i] == nums[j] and i < j.
 *
 * Return the number of good pairs.
 */

#include "header.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                res += nums[i] == nums[j];
            }
        }
        return res;
    }
};