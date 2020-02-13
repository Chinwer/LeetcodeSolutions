/*
 * 624. Maximum Distance in Arrays
 * Given m arrays, and each array is sorted in ascending order. Now you can pick
 * up two integers from two different arrays (each array picks one) and
 * calculate the distance. We define the distance between two integers a and b
 * to be their absolute difference |a-b|. Your task is to find the maximum
 * distance.
 *
 * Note:
 * Each given array will have at least 1 number. There will be at least two
 * non-empty arrays.
 *
 * The total number of the integers in all the m arrays will
 * be in the range of [2, 10000].
 *
 * The integers in the m arrays will be in the
 * range of [-10000, 10000].
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            // int res = 0;
            // vector<pair<int, int>> min;
            // vector<pair<int, int>> max;
            // int size = arrays.size();
            // for (int i = 0; i < size; i++) {
            //     int len = arrays[i].size();
            //     min.push_back(make_pair(arrays[i][0], i));
            //     max.push_back(make_pair(arrays[i][len - 1], i));
            // }
            // sort(min.begin(), min.end());
            // sort(max.begin(), max.end());

            // int i = 0, j = size - 1;
            // res = max[j].first - min[i].first;
            // while (min[i].second == max[j].second) {
            //     int diff1 = max[j - 1].first - min[i].first;
            //     int diff2 = max[j].first - min[i + 1].first;
            //     if (diff1 < diff2) {
            //         i++;
            //         res = diff2;
            //     } else {
            //         j--;
            //         res = diff1;
            //     }
            // }
            // return res;

            int res;
            int size = arrays.size();
            int min_ = arrays[0].front();
            int max_ = arrays[0].back();
            for (int i = 1; i < size; i++) {
                int dist1 = abs(max_ - arrays[i].front());
                int dist2 = abs(arrays[i].back() - min_);
                int dist = max(dist1, dist2);

                res = max(res, dist);
                max_ = max(max_, arrays[i].back());
                min_ = min(min_, arrays[i].front());
            }
            return res;
        }
};
