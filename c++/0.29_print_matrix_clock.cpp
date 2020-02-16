/*
 * Interview 29. Print Matrix Clockwise
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * 限制：
 *
 * 0 <= matrix.length <= 100
 * 0 <= matrix[i].length <= 100
 */

#include "header.h"

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if (matrix.empty()) {
                return vector<int>();
            }
            int rows = matrix.size();
            int cols = matrix[0].size();
            int top = 0, bot = rows - 1;
            int left = 0, right = cols - 1;

            vector<int> res;
            while (top <= bot && left <= right) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
                for (int i = top; i <= bot; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
                for (int i = right; i >= left && top <= bot; i--) {
                    res.push_back(matrix[bot][i]);
                }
                bot--;
                for (int i = bot; i >= top && left <= right; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            return res;
        }
};
