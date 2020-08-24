/*
 * 980. Unique Paths III
 *
 * On a 2-dimensional grid, there are 4 types of squares:
 *   - 1 represents the starting square. There is exactly one starting square.
 *   - 2 represents the ending square. There is exactly one ending square.
 *   - 0 represents empty squares we can walk over.
 *   - -1 represents obstacles that we cannot walk over.
 *
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 *
 * Note:
 *   - 1 <= grid.length * grid[0].length <= 20
 */

#include "header.h"

class Solution {
    private:
        int res = 0, m, n;
        vector<vector<int>> g;
        int dr[4] = { 0, 0, -1, 1 };
        int dc[4] = { 1, -1, 0, 0 };

    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            g = grid;
            m = grid.size();
            n = grid[0].size();
            int zero_cnt = 0, start_r, start_c;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] == 1) {
                        start_r = i;
                        start_c = j;
                    }
                    zero_cnt += g[i][j] == 0;
                }
            }
            dfs(start_r, start_c, zero_cnt + 1);
            return res;
        }

        void dfs(int r, int c, int zero_cnt) {
            int num = g[r][c];
            if (num == 2) {
                res += zero_cnt == 0;
                return;
            }

            g[r][c] = -2;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (valid(nr, nc)) {
                    dfs(nr, nc, zero_cnt - 1);
                }
            }
            g[r][c] = num;
        }

        bool valid(int r, int c) {
            return 0 <= r && r < m
                && 0 <= c && c < n
                && (g[r][c] == 0 ||
                    g[r][c] == 2);
        }
};
