/*
 * 面试题 08.13. Pile Box LCCI
 *
 * You have a stack of n boxes, with widths wi, depth di, and heights hi.
 * The boxes cannot be rotated and can only be stacked on top of one another
 * if each box in the stack is strictly larger than the box above it in width,
 * height, and depth. Implement a method to compute the height of the tallest
 * possible stack. The height of a stack is the sum of the heights of each box.
 *
 * The input use [wi, di, hi] to represents each box.
 *
 * Note:
 *   - box.length <= 3000
 */

#include "header.h"

class Solution {
    public:
        int pileBox(vector<vector<int>>& box) {
            int n = box.size();
            vector<int> dp(n);
            sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b) {
                return a[0] < b[0];
            });

            dp[0] = box[0][2];
            int res = dp[0];
            for (int i = 1; i < n; i++) {
                dp[i] = box[i][2];
                for (int j = 0; j < i; j++) {
                    if (box[j][0] < box[i][0] &&
                        box[j][1] < box[i][1] &&
                        box[j][2] < box[i][2]) {
                        dp[i] = max(dp[i], dp[j] + box[i][2]);
                    }
                }
                res = max(res, dp[i]);
            }
            return res;
        }
};
