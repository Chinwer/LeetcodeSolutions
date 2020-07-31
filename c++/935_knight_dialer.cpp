/*
 * 935. Knight Dialer
 *
 * A chess knight can move as indicated in the chess diagram below:
 *
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops. 
 * Each hop must be from one key to another numbered key.
 *
 * Each time it lands on a key (including the initial placement of the knight),
 * it presses the number of that key, pressing N digits total.
 *
 * How many distinct numbers can you dial in this manner?
 *
 * Since the answer may be large, output the answer modulo 10^9 + 7.
 *
 * Note:
 *
 *   - 1 <= N <= 5000
 */

#include "header.h"

class Solution {
    public:
        int knightDialer(int N) {
            // return original(N);
            return optimized(N);
        }

        int optimized(int N) {
            if (N == 1) {
                return 10;
            }
            int mod = 1000000007;
            vector<int> dp = { 1, 1, 1, 1 };
            for (int i = 0; i < N - 1; i++) {
                vector<int> tmp = dp;
                dp[0] = (tmp[1] + tmp[2]) % mod;
                dp[1] = (2 * tmp[0]) % mod;
                dp[2] = ((2 * tmp[0]) % mod + tmp[3]) % mod;
                dp[3] = (2 * tmp[2]) % mod;
            }
            long res = 0;
            res += (long) 4 * dp[0];
            res += (long) 2 * dp[1];
            res += (long) 2 * dp[2];
            res += (long) dp[3];
            return res % mod;
        }

        int original(int N) {
            vector<vector<int>> dp(4, vector(3, 1));
            dp[3][0] = 0;
            dp[3][2] = 0;
            int di[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
            int dj[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

            int mod = 1000000007;
            for (int n = 1; n < N; n++) {
                vector<vector<int>> tmp(4, vector(3, 0));
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (i == 3 && (j == 0 || j == 2)) {
                            continue;
                        }
                        for (int d = 0; d < 8; d++) {
                            int next_i = i + di[d];
                            int next_j = j + dj[d];
                            if (next_i >= 0 && next_i < 4 &&
                                next_j >= 0 && next_j < 3 &&
                                !(next_i == 3 && next_j != 1)
                            ) {
                                tmp[i][j] = (tmp[i][j] + dp[next_i][next_j]) % mod;
                            }
                        }
                    }
                }
                dp = tmp;
            }
            int res = 0;
            for (auto row : dp) {
                for (int d : row) {
                    res = (res + d) % mod;
                }
            }
            return res;
        }
};
