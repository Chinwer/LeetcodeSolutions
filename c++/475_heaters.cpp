/*
 * 475. Heaters
 *
 * Winter is coming! Your first job during the contest is to design a
 * standard heater with fixed warm radius to warm all the houses.
 *
 * Now, you are given positions of houses and heaters on a horizontal
 * line, find out minimum radius of heaters so that all houses could be
 * covered by those heaters.
 *
 * So, your input will be the positions of houses and heaters seperately,
 * and your expected output will be the minimum radius standard of heaters.
 *
 * Note:
 * 1. Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
 * 2. Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
 * 3. As long as a house is in the heaters' warm radius range, it can be warmed.
 * 4. All the heaters follow your radius standard and the warm radius will the same.
 */

#include "header.h"

class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());

            int res = 0;
            int size1 = houses.size(), size2 = heaters.size();
            for (int i = 0; i < size1; i++) {
                int pos = houses[i];
                int left = 0, right = size2 - 1;
                while (left < right - 1) {
                    int mid = left + (right - left) / 2;
                    if (heaters[mid] == pos) {
                        left = mid;
                        right = mid;
                    } else if (heaters[mid] > pos) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                int dist_left = abs(houses[i] - heaters[left]);
                int dist_right = abs(houses[i] - heaters[right]);
                int min_ = min(dist_left, dist_right);
                res = max(res, min_);
            }
            return res;
        }
};
