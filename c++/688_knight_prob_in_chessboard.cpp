/*
 * 688. Knight Probability in Chessboard
 *
 * On an NxN chessboard, a knight starts at the r-th row and c-th
 * column and attempts to make exactly K moves. The rows and
 * columns are 0 indexed, so the top-left square is (0, 0), and the
 * bottom-right square is (N-1, N-1).
 *
 * A chess knight has 8 possible moves it can make, as illustrated
 * below. Each move is two squares in a cardinal direction, then one
 * square in an orthogonal direction.
 *
 * Each time the knight is to move, it chooses one of eight possible
 * moves uniformly at random (even if the piece would go off the
 * chessboard) and moves there.
 *
 * The knight continues moving until it has made exactly K moves or
 * has moved off the chessboard. Return the probability that the knight
 * remains on the board after it has stopped moving.
 *
 * Note:
 *
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 */

#include "header.h"

class Solution {
    public:
        double knightProbability(int N, int K, int r, int c) {
            return original(N, K, r, c);
            // return optimized(N, K, r, c);
        }

        double optimized(int N, int K, int r, int c) {
            if (!K) {
                return 1;
            }
            int di[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
            int dj[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
            vector<vector<double>> dp(N, vector(N, 1.0));
            for (int k = 1; k <= K; k++) {
                vector<vector<double>> tmp(N, vector(N, 0.0));
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        for (int d = 0; d < 8; d++) {
                            int next_i = i + di[d];
                            int next_j = j + dj[d];
                            if (next_i >= 0 && next_i < N &&
                                next_j >= 0 && next_j < N) {
                                tmp[i][j] += dp[next_i][next_j] / 8;
                            }
                        }
                    }
                }
                dp = tmp;
            }
            return dp[r][c];
        }

        double original(int N, int K, int r, int c) {
            if (!K) {
                return 1;
            }
            vector<vector<vector<double>>> dp(N, vector(N, vector(K + 1, 1.0)));
            for (int k = 1; k <= K; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        double sum = 0;
                        sum += i >= 1 && j >= 2 ? dp[i - 1][j - 2][k - 1] : 0;
                        sum += i >= 2 && j >= 1 ? dp[i - 2][j - 1][k - 1] : 0;
                        sum += i >= 2 && j < N - 1 ? dp[i - 2][j + 1][k - 1] : 0;
                        sum += i >= 1 && j < N - 2 ? dp[i - 1][j + 2][k - 1] : 0;
                        sum += i < N - 1 && j < N - 2 ? dp[i + 1][j + 2][k - 1] : 0;
                        sum += i < N - 2 && j < N - 1 ? dp[i + 2][j + 1][k - 1] : 0;
                        sum += i < N - 2 && j >= 1 ? dp[i + 2][j - 1][k - 1] : 0;
                        sum += i < N - 1 && j >= 2 ? dp[i + 1][j - 2][k - 1] : 0;
                        dp[i][j][k] = sum / 8;
                    }
                }
            }
            return dp[r][c][K];
        }
};
