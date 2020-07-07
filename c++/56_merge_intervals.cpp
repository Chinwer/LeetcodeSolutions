/*
 * Given a collection of intervals, merge all overlapping intervals.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.empty()) {
                return vector<vector<int>>();
            }
            sort(intervals.begin(), intervals.end(), compare);
            vector<vector<int>> res(1, intervals[0]);
            int len = intervals.size();
            for (int i = 1; i < len; i++) {
                if (overlapped(res.back(), intervals[i])) {
                    res.back() = merge(res.back(), intervals[i]);
                } else {
                    res.push_back(intervals[i]);
                }
            }
            return res;
        }

        static bool compare(const vector<int>& interval1, const vector<int>& interval2) {
            return interval1[0] < interval2[0];
        }

        // left bound of interval1 is less than or equal to that of interval2
        bool overlapped(const vector<int>& interval1, const vector<int>& interval2) {
            return interval1[1] >= interval2[0];
        }

        // left bound of interval1 is less than or equal to that of interval2
        vector<int> merge(const vector<int>& interval1, const vector<int>& interval2) {
            int right_bound = interval1[1] >= interval2[1] ? interval1[1] : interval2[1];
            return vector<int>{interval1[0], right_bound};
        }
}
