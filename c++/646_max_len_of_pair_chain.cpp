/*
 * 646. Maximum Length of Pair Chain
 *
 * You are given n paris of numebrs. In every pair, the first number is
 * always smaller thant hte second number.
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and
 * only if b < c. Chain of pairs can be formed in this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be
 * formed. You needn't use up all the given pairs. You can select pairs
 * in any order.
 *
 * Note:
 *   1. The number of given pairs will be in the range [1, 1000].
 */

#include "header.h"

class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            int n = pairs.size();
            if (!n) {
                return 0;
            }
            sort(pairs.begin(), pairs.end(), compare);
            int i = 1, res = 1, last = pairs[0][1];
            while (i < n) {
                if (pairs[i][0] <= last) {
                    i++;
                    continue;
                }
                res++;
                last = pairs[i][1];
                i++;
            }
            return res;
        }

        static bool compare(const vector<int> &pair1, const vector<int> &pair2) {
            return pair1[1] < pair2[1];
        }
};
