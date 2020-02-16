/*
 * 5340. Count Negative Numbers in a Sorted Matrix
 * Given a m * n matrix grid which is sorted in non-increasing order both
 * row-wise and column-wise. 
 *
 * Return the number of negative numbers in grid.
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * -100 <= grid[i][j] <= 100
 */

#include "header.h"

class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            // Brute force
            // int res = 0;
            // for (auto row : grid) {
            //     for (auto n : row) {
            //         res += n < 0;
            //     }
            // }
            // return res;

            int res = 0;
            int rows = grid.size();
            int cols = grid[0].size();

            for (int i = 0; i < rows; i++) {
                if (grid[i][cols - 1] >= 0) {
                    continue;
                }
                if (grid[i][0] < 0) {
                    res += (rows - i) * cols;
                    break;
                }
                int j = 0;
                while (j < cols && grid[i][j] >= 0) {
                    j++;
                }
                res += cols - j;
            }

            return res;
        }
};
