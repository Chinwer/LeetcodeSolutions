/*
 * 15. 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the sum
 * of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int size = nums.size();
            if (size < 3) {
                return {};
            }

            sort(nums.begin(), nums.end());

            vector<vector<int>> res;
            for (int i = 0; i < size - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                if (nums[i] > 0) {
                    return res;
                }
                int l = i + 1;
                int r = size - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum < 0) {
                        l++;
                    } else if (sum > 0) {
                        r--;
                    } else {
                        res.push_back({ nums[i], nums[l], nums[r] });
                        while (l < r && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        l++;
                        while (l < r && nums[r] == nums[r - 1]) {
                            r--;
                        }
                        r--;
                    }
                }
            }

            return res;
        }
};
