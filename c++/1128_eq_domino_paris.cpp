/*
 * 1128. Number of Equivalent Domino Pairs
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] =
 * [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is,
 * one domino can be rotated to be equal to another domino.
 *
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
 * and dominoes[i] is equivalent to dominoes[j].
 *
 * Constraints:
 *
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 */

#include "header.h"

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int res = 0;
            vector<int> cnt(100, 0);
            for (vector<int> d : dominoes) {
                int min, max;
                if (d[0] < d[1]) {
                    min = d[0];
                    max = d[1];
                } else {
                    min = d[1];
                    max = d[0];
                }
                res += cnt[10 * min + max]++;
            }
            return res;
        }
};
