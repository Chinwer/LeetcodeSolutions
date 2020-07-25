/*
 * 452. Minimum Number of Arrows to Burst Ballons
 *
 * There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
 *
 * An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
 */

#include "header.h"

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            int n = points.size(), res = 0;
            sort(points.begin(), points.end(), compare);
            int i = 0, last_end = 0;
            while (i < n) {
                res++;
                last_end = points[i++][1];
                while (i < n && points[i][0] <= last_end) {
                    i++;
                }
            }
            return res;
        }

        static bool compare(const vector<int> &point1, const vector<int> point2) {
            return point1[1] < point2[1];
        }
};
