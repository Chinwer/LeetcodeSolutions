/*
 * 435. Non-overlapping Intervals
 *
 * Given a collection of intervals, find the minimum number of intervals you need
 * to remove to make the rest of the intervals non-overlapping.
 *
 * Note:
 *   1. You may assume the interval's end point is always bigger than its start point.
 *   2. Intervals like [1, 2] and [2, 3] have borders "touching" but they don't overlap each other.
 */

#include "header.h"

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int res = 0, n = intervals.size();
            sort(intervals.begin(), intervals.end(), compare);
            int i = 0, last_end = 0;
            while (i < n) {
                last_end = intervals[i++][1];
                while (i < n && intervals[i][0] < last_end) {
                    i++;
                    res++;
                }
                if (i == n) {
                    return res;
                }
            }
            return res;
        }

        static bool compare(const vector<int> &interval1, const vector<int> &interval2) {
            return interval1[1] < interval2[1];
        }
};
