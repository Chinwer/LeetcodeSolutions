/*
 * 1217. Play with Chips
 * There are some chips, and the i-th chip is at position chips[i].
 *
 * You can perform any of the two following types of moves any number of times (possibly zero) on any chip:
 *
 * Move the i-th chip by 2 units to the left or to the right with a cost of 0.
 * Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
 * There can be two or more chips at the same position initially.
 *
 * Return the minimum cost needed to move all the chips to the same position (any position).
 *
 * Constraints:
 *
 * 1 <= chips.length <= 100
 * 1 <= chips[i] <= 10^9
 */

#include "header.h"

class Solution {
    public:
        int minCostToMoveChips(vector<int>& chips) {
            int res = 0;
            int size = chips.size();
            for (int chip : chips) {
                res += chip % 2;
            }
            return res > size / 2 ? size - res : res;
        }
};
