/*
 * 1046. Last Stone Weight
 *
 * We have a collection of stones, each stone has a positive integer weight.
 *
 * Each turn, we choose the two heaviest stones and smash them together. 
 * Suppose the stones have weights x and y with x <= y. 
 * The result of this smash is:
 *
 *   - If x == y, both stones are totally destroyed;
 *   - If x != y, the stone of weight x is totally destroyed,
 * and the stone of weight y has new weight y-x.
 *
 * At the end, there is at most 1 stone left.  Return the weight of this
 * stone (or 0 if there are no stones left.)
 *
 * Note:
 *   - 1 <= stones.length <= 30
 *   - 1 <= stones[i] <= 1000
 */

#include "header.h"

class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            while (stones.size() > 1) {
                sort(stones.begin(), stones.end(), less<int>());
                int n = stones.size();
                int s1 = stones[n - 1], s2 = stones[n - 2];
                stones.pop_back();
                stones.pop_back();
                if (s1 != s2) {
                    stones.push_back(s1 - s2);
                }
            }
            return stones.empty() ? 0 : stones[0];
        }
};
