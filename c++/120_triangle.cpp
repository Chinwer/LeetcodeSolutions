/*
 * 120. Triangle
 *
 * Given a triangle, find the minium path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * Note:
 * Bonus point if you are able to do this uing only O(n) extra space,
 * where n is the total number of rows in the triangle.
 */

#include "header.h"

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            // return top_down(triangle);
            return bottom_up(triangle);
        }

        int bottom_up(vector<vector<int>> &triangle) {
            int n = triangle.size();
            vector<int> dp(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                int size = triangle[i].size();
                for (int j = 0; j < size; j++) {
                    dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
                }
            }
            return dp[0];
        }

        int top_down(vector<vector<int>> &triangle) {
            if (triangle.empty()) {
                return 0;
            }
            int n = triangle.size();
            vector<int> dp(n, 0);
            dp[0] = triangle[0][0];
            for (int i = 1; i < n; i++) {
                int size = triangle[i].size();
                dp[size - 1] = dp[size - 2] + triangle[i][size - 1];
                for (int j = size - 2; j > 0; j--) {
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
                dp[0] += triangle[i][0];
            }
            int res = INT_MAX;
            for (int d : dp) {
                res = min(res, d);
            }
            return res;
        }
};
