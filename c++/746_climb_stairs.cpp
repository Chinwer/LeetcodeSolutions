/*
 * 746. Min Cost Climbing Stairs
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed). Once you pay the cost, you can either climb one or two steps. You
 * need to find minimum cost to reach the top of the floor, and you can either
 * start from the step with index 0, or the step with index 1.
 *
 * Note:
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 */

#include "header.h"

class Solution {
    public:
        // Size of cost is no less than 2
        int minCostClimbingStairs(vector<int>& cost) {
            int res;
            int size = cost.size();
            int prev = 0, pprev = 0;
            for (int i = 2; i <= size; i++) {
                res = min(cost[i - 2] + pprev, cost[i - 1] + prev);
                pprev = prev;
                prev = res;
            }

            return res;
        }

        // Recursive, time limit exceeded
        int climb(vector<int>& cost, int target) {
            if (target == 1) {
                return cost[0];
            } else if (target == 2) {
                return min(cost[0], cost[1]);
            }

            return min(cost[target - 1] + climb(cost, target - 1),
                       cost[target - 2] + climb(cost, target - 2));
        }
};
