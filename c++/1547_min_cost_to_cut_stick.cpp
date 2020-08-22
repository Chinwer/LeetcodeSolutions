/*
 * 1547. Minimum Cost to Cut a Stick
 *
 * Given a wooden stick of length n units. The stick is labelled from 0 to n.
 *
 * Given an integer array cuts where cuts[i] denotes a position you should perfom a cut at.
 *
 * You should perform the cuts in order, you can change the order of the cuts as you wish.
 *
 * The cost of one cut is the length of the stick to be cut, the total cost is the
 * sum of costs of all cuts. When you cut a stick, it will be split into two smaller
 * sticks(i.e. the sum of their lengths is the length of the stick before the cut).
 *
 * Return the minimum total cost of the cuts.
 *
 * Constraints:
 *   - 2 <= n <= 10^6
 *   - 1 <= cuts.length <= min(n - 1, 1000)
 *   - 1 <= cuts[i] <= n - 1
 *   - All the integers in cuts array are distinct.
 */

#include "header.h"

class Solution {
    private:
        const int INF = 0x3f3f3f3f;

    public:
        int minCost(int n, vector<int>& cuts) {
            int m = cuts.size();
            sort(cuts.begin(), cuts.end());
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);

            vector<vector<int>> dp(m + 2, vector(m + 2, 0));
            for (int i = m + 1; i >= 0; i--) {
                for (int j = i + 2; j < m + 2; j++) {
                    dp[i][j] = INF;
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + cuts[j] - cuts[i]
                        );
                    }
                }
            }
            return dp[0][m + 1];
        }
};
