/*
 * 1728. Circus Tower LCCI
 *
 * A circus is designing a tower routine consisting of people standing atop
 * one another's shoulders. For practical and aesthetic reasons, each person
 * must be both shorter and lighter than the person below him or her. Given
 * the heights and weights of each person in the circus, write a method to
 * compute the largest possible number of people in such a tower.
 *
 * Note:
 *   height.length == weight.lenght <= 10000
 */

#include "header.h"

class Solution {
    public:
        int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
            if (height.empty()) {
                return 0;
            }
            int n = height.size();
            vector<pair<int, int>> people(n);
            for (int i = 0; i < n; i++) {
                people[i] = { height[i], weight[i] };
            }
            sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
                return a.first == b.first ? a.second > b.second : a.first < b.first;
            });
            vector<int> dp;
            dp.push_back(people[0].second);
            for (int i = 1; i < n; i++) {
                if (people[i].second > dp.back()) {
                    dp.push_back(people[i].second);
                } else {
                    auto pos = lower_bound(dp.begin(), dp.end(), people[i].second);
                    *pos = people[i].second;
                }
            }
            return dp.size();
        }
};
