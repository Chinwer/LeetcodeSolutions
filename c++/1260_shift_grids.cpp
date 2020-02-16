/*
 * 1260. Shift 2D Grid
 * Given a 2D grid of size m x n and an integer k. You need to shift the grid k
 * times.
 *
 * In one shift operation:
 *
 * Element at grid[i][j] moves to grid[i][j + 1].
 * Element at grid[i][n - 1] moves to grid[i + 1][0].
 * Element at grid[m - 1][n - 1] moves to grid[0][0].
 * Return the 2D grid after applying shift operation k times.
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 50
 * 1 <= n <= 50
 * -1000 <= grid[i][j] <= 1000
 * 0 <= k <= 100
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int rows = grid.size();
            int cols = grid[0].size();
            int nums = rows * cols;
            vector<vector<int>> res(rows, vector<int>(cols));

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    // new idx
                    int nidx = (i * cols + j + k) % nums;
                    int ni = nidx / cols;
                    int nj = nidx % cols;
                    res[ni][nj] = grid[i][j];
                }
            }

            return res;
        }
};
