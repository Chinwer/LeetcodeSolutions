/*
 * 面试题 08.02. Robot in a Grid LCCI
 *
 * Imagine a robot sitting on the upper left corner of grid with r rows
 * and c columns. The robot can only move in two directions, right and
 * down, but certain cells are "off limits" such that the robot cannot
 * step on them. Design an algorithm to find a path for the robot from
 * the top left to the bottom right.
 *
 * "off limits" and empty grid are represented by 1 and 0 respectively.
 *
 * Return a valid path, consisting of row number and column number
 * of grids in the path.
 *
 * Note: r, c, <= 100
 */

#include "header.h"

class Solution {
    private:
        int m, n;
        vector<vector<int>> res;
        vector<vector<int>> grid;

    public:
        vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
            // grid = obstacleGrid;
            // m = grid.size();
            // n = grid[0].size();

            // vector<vector<int>> path = {{ 0, 0 }};
            // dfs(path);
            // return res;

            // grid[i][j] = 1: can not go anywhere
            // grid[i][j] = 2: can go down here
            // grid[i][j] = 3: can go right here
            vector<vector<int>> res;
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
                return res;
            }
            obstacleGrid[0][0] = 2;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (obstacleGrid[i][j] <= 1) {
                        continue;
                    }
                    if (i < m - 1 && !obstacleGrid[i + 1][j]) {
                        obstacleGrid[i + 1][j] = 2;
                    }
                    if (j < n - 1 && !obstacleGrid[i][j + 1]) {
                        obstacleGrid[i][j + 1] = 3;
                    }
                }
            }
            if (obstacleGrid[m - 1][n - 1] <= 1) {
                return res;
            }
            res.resize(m + n - 1);
            int r = m - 1, c = n - 1;
            for (int i = m + n - 2; i >= 0; i--) {
                res[i] = { r, c };
                if (obstacleGrid[r][c] == 2) {
                    r--;
                } else {
                    c--;
                }
            }
            return res;
        }

        void dfs(vector<vector<int>> &path) {
            if (!res.empty()) {
                return;
            }
            vector<int> last = path[path.size() - 1];
            int i = last[0], j = last[1];
            if (!grid[i][j]) {
                grid[i][j] = 1;
                if (i < m - 1) {
                    path.push_back({ i + 1, j });
                    dfs(path);
                    path.pop_back();
                }
                if (j < n - 1) {
                    path.push_back({ i, j + 1 });
                    dfs(path);
                    path.pop_back();
                }
                if (i == m - 1 && j == n - 1) {
                    res = path;
                }
            }
        }
};
