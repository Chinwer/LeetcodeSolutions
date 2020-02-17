/*
 * 611. Valid Triangle Number
 * Given an array consists of non-negative integers, your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 *
 * Note:
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 */

#include "header.h"

class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            int size = nums.size();
            if (size < 3) {
                return 0;
            }

            sort(nums.begin(), nums.end());

            int res = 0;
            for (int i = 0; i < size - 2; i++) {
                if (!nums[i]) {
                    continue;
                }

                int l, r = i + 2;
                for (l = i + 1; l < size - 1; l++) {
                    while (r < size) {
                        if (nums[i] + nums[l] <= nums[r]) {
                            break;
                        }
                        r++;
                    }
                    res += r - l - 1;
                }
            }

            return res;
        }
};
