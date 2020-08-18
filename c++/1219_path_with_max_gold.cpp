/*
 * 1219. Path with Maximum Gold
 *
 * In a gold mine grid of size m * n, each cell in this mine has an integer
 * representing the amount of gold in that cell, 0 if it is empty.
 *
 * Return the maximum amount of gold you can collect under the conditions:
 *   - Every time you are located in a cell you will collect all the gold in that cell.
 *   - From your position you can walk one step to the left, right, up or down.
 *   - You can't visit the same cell more than once.
 *   - Never visit a cell with 0 gold.
 *   - You can start and stop collecting gold from any position in the grid that has some gold.
 *
 * Constraints:
 *   - 1 <= grid.length, grid[i].length <= 15
 *   - 0 <= grid[i][j] <= 100
 *   - There are at most 25 cells containing gold.
 */

#include "header.h"

class Solution {
    private:
        int res, m, n;
        vector<vector<int>> grid;
        // up, down, left, right
        vector<int> dc = { 0, 0, -1, 1 };
        vector<int> dr = { -1, 1, 0, 0 };

    public:
        int getMaximumGold(vector<vector<int>>& grid) {
            this->grid = grid;
            m = grid.size(), n = grid[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    dfs(i, j, 0);
                }
            }
            return res;
        }

        void dfs(int r, int c, int sum) {
            int tmp = grid[r][c];
            sum += tmp;
            res = max(res, sum);
            grid[r][c] = 0;
            for (int i = 0; i < 4; i++) {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                if (new_r < 0 || new_r >= m ||
                    new_c < 0 || new_c >= n) {
                    continue;
                }
                if (grid[new_r][new_c] == 0) {
                    continue;
                }
                dfs(new_r, new_c, sum);
            }
            grid[r][c] = tmp;
        }
};
