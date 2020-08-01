/*
 * 1423. Maximum Points You Can Obtain from Cards
 *
 * There are several cards arranged in a row, and each card has an
 * associated number of points The points are given in the integer
 * array cardPoints.
 *
 * In one step, you can take one card from the beginning or from the
 * end of the row. You have to take exactly k cards.
 *
 * Your score is the sum of the points of the cards you have taken.
 *
 * Given the integer array cardPoints and the integer k, return the
 * maximum score yo 
 *
 * Constraints:
 *   - 1 <= cardPoints.length <= 10^5
 *   - 1 <= cardPoints[i] <= 10^4
 *   - 1 <= k <= cardPoints.length
 */

#include "header.h"

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            // return original(cardPoints, k);
            return sliding_window(cardPoints, k);
        }

        int sliding_window(vector<int>& cardPoints, int k) {
            int sum = 0, n = cardPoints.size();
            for (int i = 0; i < k; i++) {
                sum += cardPoints[i];
            }
            int res = sum;
            for (int i = 0; i < k; i++) {
                sum += cardPoints[n - i - 1] - cardPoints[k - i - 1];
                res = max(res, sum);
            }
            return res;
        }

        // time limit exceeded
        int original(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            vector<vector<vector<int>>> dp(n, vector(n, vector(k + 1, 0)));
            for (int kk = 1; kk <= k; kk++) {
                for (int i = 0; i < n; i++) {
                    // base case
                    dp[i][i][kk] = cardPoints[i];
                    for (int j = i + 1; j < n; j++) {
                        dp[i][j][kk] = max(
                            dp[i + 1][j][kk - 1] + cardPoints[i],
                            dp[i][j - 1][kk - 1] + cardPoints[j]
                        );
                    }
                }
            }
            return dp[0][n - 1][k];
        }
};
