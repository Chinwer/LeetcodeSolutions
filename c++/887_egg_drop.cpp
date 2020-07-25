/*
 * 887. Super Egg Drop
 *
 * You are given K eggs, and you have access to a building with N floors from 1 to N. 
 *
 * Each egg is identical in function, and if an egg breaks, you cannot drop it again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg dropped at
 * a floor higher than F will break, and any egg dropped at or below floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop it from any
 * floor X (with 1 <= X <= N). 
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with certainty what F is,
 * regardless of the initial value of F?
 *
 * Note:
 *
 * 1 <= K <= 100
 * 1 <= N <= 10000
 */

#include "header.h"

class Solution {
    public:
        int superEggDrop(int K, int N) {
            /* Time limit exceede when input is (4, 10000) */
            // return bottom_up(K, N);

            // int i = 0;
            // vector<vector<int>> dp(N + 1, vector(K + 1, 0));
            // while (dp[i][K] < N) {
            //     i++;
            //     for (int j = 1; j <= K; j++) {
            //         dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
            //     }
            // }
            // return i;

            int i = 0;
            vector<int> dp(K + 1, 0);
            while (dp[K] < N) {
                i++;
                for (int j = K; j > 0; j--) {
                    dp[j] = dp[j] + dp[j - 1] + 1;
                }
            }
            return i;
        }

        int bottom_up(int K, int N) {
            if (K == 0 || N == 0) {
                return 0;
            }
            if (K == 1) {
                return N;
            }
            if (N == 1) {
                return 1;
            }
            vector<vector<int>> dp(K + 1, vector(N + 1, 0));
            for (int i = 1; i <= K; i++) {
                for (int j = 1; j <= N; j++) {
                    dp[i][j] = j;
                }
            }
            for (int i = 2; i <= K; i++) {
                for (int j = 1; j <= N; j++) {
                    for (int k = 1; k < j; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            max(dp[i - 1][k - 1], dp[i][j - k]) + 1
                        );
                    }
                }
            }
            return dp[K][N];
        }
};
