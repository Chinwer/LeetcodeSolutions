/*
 * 808. Soup Servings
 *
 * There are two types of soup: type A and type B.
 * Initially we have N ml of each type of soup.
 * There are four kinds of operations.
 *
 * Serve 100 ml of soup A and 0 ml of soup B
 * Serve 75 ml of soup A and 25 ml of soup B
 * Serve 50 ml of soup A and 50 ml of soup B
 * Serve 25 ml of soup A and 75 ml of soup B
 * When we serve some soup, we give it to someone and we no longer have it.
 * Each turn, we will choose from the four operations with equal probability 0.25.
 * If the remaining volume of soup is not enough to complete the operation,
 * we will serve as much as we can.  We stop once we no longer have some quantity
 * of both types of soup.
 *
 * Note that we do not have the operation where all 100 ml's of soup B are used first.  
 *
 * Return the probability that soup A will be empty first, plus half the probability
 * that A and B become empty at the same time.
 *
 * Notes:
 *
 * 0 <= N <= 10^9. 
 * Answers within 10^-6 of the true value will be accepted as correct.
 */

#include "header.h"

class Solution {
    public:
        double soupServings(int N) {
            // (100, 0) => (4, 0)
            // (75, 25) => (3, 1)
            // (50, 50) => (2, 2)
            // (25, 75) => (1, 3)
            N = ceil(N / 25);
            if (N >= 500) {
                return 1;
            }
            vector<vector<double>> dp(N + 1, vector(N + 1, 0.0));
            dp[0][0] = 0.5;
            for (int i = 1; i <= N; i++) {
                dp[0][i] = 1;
            }
            for (int i = 1; i <= N; i++) {
                int i1 = i < 4 ? 0 : i - 4;
                int i2 = i < 3 ? 0 : i - 3;
                int i3 = i < 2 ? 0 : i - 2;
                for (int j = 1; j <= N; j++) {
                    int j1 = j < 2 ? 0 : j - 2;
                    int j2 = j < 3 ? 0 : j - 3;
                    dp[i][j] = 0.25 * (
                        dp[i1][j] + dp[i2][j - 1] +
                        dp[i3][j1] + dp[i - 1][j2]
                    );
                }
            }
            return dp[N][N];
        }
};
