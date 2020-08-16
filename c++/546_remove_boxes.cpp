/*
 * 546. Remove Boxes
 *
 * Given several boxes with different colors represented by different positive numbers.
 *
 * You may experience several rounds to remove boxes until there is no box left.
 * Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k * k points
 * Find the maximum points you can get.
 *
 * Constraints:
 *   - 1 <= boxes.length <= 100
 *   - 1 <= boxes[i] <= 100
 */

#include "header.h"

class Solution {
    private:
        int dp[100][100][105];

    public:
        int removeBoxes(vector<int>& boxes) {
            return recursion(boxes, 0, boxes.size() - 1, 0);
        }

        int recursion(vector<int>& boxes, int l, int r, int k) {
            if (l > r) {
                return 0;
            }
            if (dp[l][r][k]) {
                return dp[l][r][k];
            }
            while (r > l && boxes[r] == boxes[r-  1]) {
                r--;
                k++;
            }
            dp[l][r][k] = recursion(boxes, l, r - 1, 0) + pow(k + 1, 2);
            for (int i = l; i < r; i++) {
                if (boxes[i] != boxes[r]) {
                    continue;
                }
                dp[l][r][k] = max(
                    dp[l][r][k],
                    recursion(boxes, l, i, k + 1) + recursion(boxes, i + 1, r - 1, 0)
                );
            }
            return dp[l][r][k];
        }
};
