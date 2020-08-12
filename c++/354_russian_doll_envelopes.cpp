/*
 * 354. Russian Doll Envelopes
 *
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 *
 * Note:
 * Rotation is not allowed.
 */

#include "header.h"

class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            int n = envelopes.size();
            if (!n) {
                return 0;
            }
            sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            });

            vector<int> res;
            res.push_back(envelopes[0][1]);
            for (int i = 1; i < n; i++) {
                if (envelopes[i][1] > res.back()) {
                    res.push_back(envelopes[i][1]);
                } else {
                    auto p = lower_bound(res.begin(), res.end(), envelopes[i][1]);
                    *p = envelopes[i][1];
                }
            }
            return res.size();
        }
};
