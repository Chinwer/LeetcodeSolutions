/*
 * 259. 3Sum Smaller
 * Given an array of n integers nums and a target, find the number of index
 * triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] +
 * nums[j] + nums[k] < target.
 *
 * Follow up: Could you solve it in O(n2) runtime?
 */

#include "header.h"

class Solution {
    public:
        int threeSumSmaller(vector<int>& nums, int target) {
            int size = nums.size();
            if (size < 3) {
                return 0;
            }

            sort(nums.begin(), nums.end());

            int res = 0;
            for (int i = 0; i < size - 2; i++) {
                int l = i + 1, r = size - 1;
                while (l < r) {
                    if (nums[l] + nums[r] < target) {
                        res += r - l;
                        l++;
                    } else {
                        r--;
                    }
                }
            }

            return res;
        }
};
