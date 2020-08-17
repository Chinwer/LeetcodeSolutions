/*
 * 956. Tallest Billboard
 *
 * You are installing a billboard and want it to have the largest height.
 * The billboard will have two steel supports, one on each side.
 * Each steel support must be an equal height.
 *
 * You have a collection of rods which can be welded together.
 * For example, if you have rods of lengths 1, 2, and 3, you can weld them
 * together to make a support of length 6.
 *
 * Return the largest possible height of your billboard installation.
 * If you cananot support the billboard, return 0.
 *
 * Note:
 *   - 0 <= rods.length <= 20
 *   - 1 <= rods[i] <= 1000
 *   - The sum of rods is at most 5000.
 */

#include "header.h"

class Solution {
    public:
        int tallestBillboard(vector<int>& rods) {
            // return solution1(rods);
            return solution2(rods);
        }

        int solution2(vector<int> &rods) {
            int n = rods.size();
            unordered_map<int, int> dp;
            dp[0] = 0;
            for (int rod : rods) {
                auto tmp = dp;
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    int key = it->first;
                    int val = it->second;
                    dp[key - rod] = max(dp[key - rod], tmp[key]);
                    dp[key + rod] = max(dp[key + rod], tmp[key] + rod);
                }
            }
            return dp[0];
        }

        int solution1(vector<int> &rods) {
            int n = rods.size();
            int sum = accumulate(rods.begin(), rods.end(), 0);
            vector<int> dp(sum + 1, 0);

            for (int i = 0; i < n; i++) {
                vector<int> tmp = dp;
                for (int j = 0; j <= sum; j++) {
                    if (tmp[j] < j) {
                        continue;
                    }
                    int k = j + rods[i];
                    dp[k] = max(dp[k], tmp[j] + rods[i]);
                    k = abs(j - rods[i]);
                    dp[k] = max(dp[k], tmp[j] + rods[i]);
                }
            }
            return dp[0] / 2;
        }
};
