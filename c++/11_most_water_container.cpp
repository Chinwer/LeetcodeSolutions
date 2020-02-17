/*
 * 11. Container With Most Water
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
 * line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 */

#include "header.h"

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int size = height.size();
            int l = 0, r = size - 1, res = 0;

            while (l < r) {
                int h = min(height[l], height[r]);
                int capacity = h * (r - l);
                if (capacity > res) {
                    res = capacity;
                }
                if (height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }

            return res;
        }
};
