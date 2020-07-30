/*
 * 718. Maximum Length of Repeated Subarray
 *
 * Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 */
#include "header.h"

class Solution {
    public:
        int findLength(vector<int>& A, vector<int> & B) {
            int res = 0;
            int m = A.size(), n = B.size();
            // dp[i][j]: maximum common suffix length of
            // A[0...i - 1] and B[0...j - 1]
            vector<vector<int>> dp(m + 1, vector(n + 1, 0));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (A[i - 1] == B[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 0;
                    }
                    cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                    res = max(res, dp[i][j]);
                }
            }
            return res;
        }
};
