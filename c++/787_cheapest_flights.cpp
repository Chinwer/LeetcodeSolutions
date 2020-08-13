/*
 * 787. Cheapest Flights Within K Stops
 *
 * There are n cities connected by m flights. Each flight start from city u and arrives at v with
 * a price w.
 *
 * Now given all the cities and flights, together with starting city src and the destination dst,
 * your task is to find the cheapest price from src to dst with up to k stops. If there is no such
 * route, output -1.
 *
 * Constraints:
 *   - The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
 *   - The size of flights will be in range [0, n * (n - 1) / 2].
 *   - The format of each flight will be (src, dst, price).
 *   - The price of each flight will be in the range [1, 10000].
 *   - k is in the range of [0, n - 1].
 *   - There will not be any duplicated flights or self cycles.
 */

#include "header.h"

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
            int MAX = 1e9;
            vector<int> dp(n, MAX);
            dp[src] = 0;
            for (int i = 0; i <= K; i++) {
                vector<int> tmp(dp);
                for (vector<int> &f : flights) {
                    tmp[f[1]] = min(tmp[f[1]], f[2] + dp[f[0]]);
                }
                dp = tmp;
            }
            return dp[dst] == MAX ? -1 : dp[dst];
        }
};
