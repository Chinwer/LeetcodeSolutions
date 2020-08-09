/*
 * 1504. Count Submatrices With All Ones
 *
 * Given a rows * columns matrix mat of ones and  zeros, return how
 * many submatrices have all ones.
 *
 * Constraints:
 *   - 1 <= rows <= 150
 *   - 1 <= columns <= 150
 *   - 0 <= max[i][j] <= 1
 */

#include "header.h"

// class Solution {
//     public:
//         int numSubmat(vector<vector<int>>& mat) {
//             int res = 0;
//             int m = mat.size();
//             int n = mat[0].size();
//             vector<vector<vector<int>>> dp(m, vector(n, vector(2, 0)));
//             for (int i = 0; i < n; i++) {
//                 if (!mat[0][i]) {
//                     continue;
//                 }
//                 dp[0][i][1] = 1;
//                 if (!i || !mat[0][i - 1]) {
//                     dp[0][i][0] = 1;
//                 } else {
//                     dp[0][i][0] = dp[0][i - 1][0] + 1;
//                 }
//                 res += dp[0][i][0];
//             }
//             for (int i = 1; i < m; i++) {
//                 if (!mat[i][0]) {
//                     continue;
//                 }
//                 dp[i][0][0] = 1;
//                 if (!mat[i - 1][0]) {
//                     dp[i][0][1] = 1;
//                 } else {
//                     dp[i][0][1] = dp[i - 1][0][1] + 1;
//                 }
//                 res += dp[i][0][1];
//             }
//             for (int i = 1; i < m; i++) {
//                 for (int j = 1; j < n; j++) {
//                     if (!mat[i][j]) {
//                         continue;
//                     }
//                     dp[i][j][0] = dp[i][j - 1][0] + 1;
//                     dp[i][j][1] = dp[i - 1][j][1] + 1;
//                 }
//             }
//             for (int i = 1; i < m; i++) {
//                 for (int j = 1; j < n; j++) {
//                     if (!mat[i][j]) {
//                         continue;
//                     }
//                     if (!mat[i][j - 1]) {
//                         res += dp[i][j][1];
//                         continue;
//                     }
//                     if (!mat[i - 1][j]) {
//                         res += dp[i][j][0];
//                         continue;
//                     }
//                     for (int k = 0; k <= dp[i][j - 1][0]; k++) {
//                         res += dp[i][j - k][1];
//                     }
//                 }
//             }
//             return res;
//         }
// };

class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            vector<vector<int>> dp(m, vector(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!mat[i][j]) {
                        continue;
                    }
                    if (!j) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int min_ = 150;
                    for (int k = 0; k <= i; k++) {
                        min_ = min(min_, dp[i - k][j]);
                        res += min_;
                    }
                }
            }
            return res;
        }
};
