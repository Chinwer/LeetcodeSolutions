/*
 * 1740. Max Black Square LCCI
 *
 * Imagine you have a square matrix, where each cell (pixel) is
 * either black or white Design an algorithm to find the maximum
 * subsquare such that all four borders are filled with black pixels.
 *
 * Return an array [r, c, size], where r, c are the row number
 * and the column number of the subsquare's upper left corner
 * respectively, and size is the side length of the subsquare.
 * If there are more than one answers, return the one that has
 * smallest r. If there are more than one answers that have the
 * same r, return the one that has smallest c. If there's no
 * answer, return an empty array.
 *
 * Note:
 *   - matrix.length == matrix[0].length <= 200
 */

#include "header.h"

class Solution {
    public:
        vector<int> findSquare(vector<vector<int>>& matrix) {
            int n = matrix.size();
            if (!n) {
                return {};
            }
            int r = -1, c = -1, max_len = 0;
            // dp[i][j][0]: right
            // dp[i][j][1]: down
            vector<vector<vector<int>>> dp(n + 1, vector(n + 1, vector(2, 0)));
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (matrix[i][j]) {
                        continue;
                    }
                    dp[i][j][0] = dp[i][j + 1][0] + 1;
                    dp[i][j][1] = dp[i + 1][j][1] + 1;
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while (len >= max_len) {
                        if (dp[i + len - 1][j][0] >= len &&
                            dp[i][j + len - 1][1] >= len) {
                            r = i;
                            c = j;
                            max_len = len;
                            break;
                        }
                        len--;
                    }
                }
            }
            if (r == -1) {
                return {};
            }
            return { r, c, max_len };
        }
};
