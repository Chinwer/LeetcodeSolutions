/*
 * 764. Largest Plus Sign
 *
 * In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.
 *
 * An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.
 *
 * Note:
 *
 * N will be an integer in the range [1, 500].
 * mines will have length at most 5000.
 * mines[i] will be length 2 and consist of integers in the range [0, N-1].
 * (Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)
 */

#include "header.h"

class Solution {
    public:
        int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
            // dp[i][j][0]: left
            // dp[i][j][1]: up
            // dp[i][j][2]: right
            // dp[i][j][3]: down
            int ***dp = new int**[N];
            for (int i = 0; i < N; i++) {
                dp[i] = new int*[N];
                for (int j = 0; j < N; j++) {
                    dp[i][j] = new int[4];
                    for (int k = 0; k < 4; k++) {
                        dp[i][j][k] = 1;
                    }
                }
            }
            for (auto mine : mines) {
                for (int i = 0; i < 4; i++) {
                    dp[mine[0]][mine[1]][i] = 0;
                }
            }
            // left and up arm length
            for (int i = 1; i < N; i++) {
                for (int j = 1; j < N; j++) {
                    if (!dp[i][j][0]) {
                        continue;
                    }
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                }
            }
            // right and down arm length
            for (int i = N - 2; i >= 0; i--) {
                for (int j = N - 2; j >= 0; j--) {
                    if (!dp[i][j][0]) {
                        continue;
                    }
                    dp[i][j][2] = dp[i][j + 1][2] + 1;
                    dp[i][j][3] = dp[i + 1][j][3] + 1;
                }
            }
            int res = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int len = _min(
                        dp[i][j][0], dp[i][j][1],
                        dp[i][j][2], dp[i][j][3]
                    );
                    res = max(len, res);
                }
            }
            return res;
        }

        int _min(int a, int b, int c, int d) {
            return min(a, min(b, min(c, d)));
        }
};
