/*
 * 1051. Height Checker
 * Students are asked to stand in non-decreasing order of heights for an annual
 * photo.
 *
 * Return the minimum number of students that must move in order for all
 * students to be standing in non-decreasing order of height.
 *
 * Constraints:
 *
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
 */

#include "header.h"

class Solution {
    public:
        int heightChecker(vector<int>& heights) {
            // Method 1, O(n), draw from the bucket sorting idea
           
            // int res = 0;
            // int size = heights.size();
            // vector<int> cnt(101, 0);
            // vector<int> acc(101, 0);

            // for (int h : heights) {
            //     cnt[h]++;
            // }
            // for (int i = 1; i < 101; i++) {
            //     acc[i] = acc[i - 1] + cnt[i];
            // }

            // for (int i = 0; i < size; i++) {
            //     if (i < acc[heights[i] - 1] || i >= acc[heights[i]]) {
            //         res += 1;
            //     }
            // }

            // return res;

            // Method 2, O(nlogn), sort heights first

            // int res = 0;
            // int size = heights.size();
            // vector<int> origin(heights);
            // sort(heights.begin(), heights.end());

            // for (int i = 0; i < size; i++) {
            //     res += heights[i] != origin[i];
            // }

            // return res;

            // Method 3, optimized method 1
            vector<int> cnt(101, 0);
            for (int h : heights) {
                cnt[h]++;
            }

            int res = 0;
            for (int i = 1, j = 0; i < 101; i++) {
                while (cnt[i]-- > 0) {
                    res += heights[j++] != i;
                }
            }
            return res;
        }
};
