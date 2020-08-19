/*
 * 79. Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * Constraints:
 *   - board and word consists only of lowercase and uppercase English letters.
 *   - 1 <= board.length <= 200
 *   - 1 <= board[i].length <= 200
 *   - 1 <= word.length <= 10^3
 */

#include "header.h"

class Solution {
    private:
        int m, n;
        string word;
        vector<vector<char>> grid;
        vector<int> dr = { 0, 0, -1, 1 };
        vector<int> dc = { 1, -1, 0, 0 };

    public:
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            n = board[0].size();
            grid = board;
            this->word = word;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != word[0]) {
                        continue;
                    }
                    char tmp = grid[i][j];
                    grid[i][j] = '#';
                    if (dfs(i, j, 1)) {
                        return true;
                    }
                    grid[i][j] = tmp;
                }
            }
            return false;
        }

        bool dfs(int r, int c, int idx) {
            if (idx == word.size()) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                if (!continuable(new_r, new_c, idx)) {
                    continue;
                }
                char tmp = grid[new_r][new_c];
                grid[new_r][new_c] = '#';
                if (dfs(new_r, new_c, idx + 1)) {
                    return true;
                }
                grid[new_r][new_c] = tmp;
            }
            return false;
        }

        bool continuable(int r, int c, int idx) {
            return r >= 0 && r < m
                && c >= 0 && c < n
                && grid[r][c] == word[idx];
        }
};
