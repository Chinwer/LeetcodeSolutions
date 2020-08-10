/*
 * 1039. Minimum Score Triangulation of Polygon
 *
 * Given N, consider a convex N-sided polygon with vertices labelled
 * A[0], A[i], ..., A[N - 1] in clockwise order.
 *
 * Suppose you triangulate the polygon into N - 2 triangles. For each
 * triangle, the value of that triangle is the product of the lables of the
 * vertices, and the total score of the triangulation is the sum of these
 * values over all N - 2 triangles in the triangulation.
 *
 * Return the smallest possible total score that you can achieve with
 * some triangulation of the polygon.
 *
 * Note:
 *   1. 3 <= A.length <= 50
 *   2. 1 <= A[i] <= 100
 */

#include "header.h"

class Solution {
    public:
        int minScoreTriangulation(vector<int>& A) {
            int n = A.size();
            vector<vector<int>> dp(n, vector(n, INT_MAX));
            for (int i = 0; i < n - 1; i++) {
                dp[i][i + 1] = 0;
            }
            for (int i = n - 2; i >= 0; i--) {
                for (int j = i + 2; j < n; j++) {
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]
                        );
                    }
                }
            }
            return dp[0][n - 1];
        }
};
