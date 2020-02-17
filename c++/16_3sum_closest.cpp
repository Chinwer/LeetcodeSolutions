/*
 * 16. 3Sum Closest
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 */

#include "header.h"

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int size = nums.size();

            sort(nums.begin(), nums.end());

            int res = nums[0] + nums[1] + nums[2];

            for (int i = 0; i < size - 2; i++) {
                int l = i + 1, r = size - 1;
                while (l < r) {
                    int delta = abs(res - target);
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == target) {
                        return target;
                    } else if (sum < target) {
                        if (target - sum < delta) {
                            res = sum;
                        }
                        l++;
                    } else {
                        if (sum - target < delta) {
                            res = sum;
                        }
                        r--;
                    }
                }
            }

            return res;

            return res;
        }
};
