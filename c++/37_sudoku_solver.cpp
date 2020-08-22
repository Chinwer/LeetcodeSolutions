/*
 * 37. Sudoku Solver
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *   - Each of the digits 1-9 must occur exactly once in each row.
 *   - Each of the digits 1-9 must occur exactly once in each column.
 *   - Each of the digits 1-9 must occur exactly once in each of the 9
 *     3x3 sub-boxes of the grid.
 *
 * Empty cells are indicated by the character '.'.
 *
 * Note:
 *   - The given board contain only digits 1-9 and the character '.'.
 *   - You may assume that the given Sudoku puzzle will have a single
 *     unique solution.
 *   - The given board size is always 9x9.
 */

#include "header.h"

class Solution {
    private:
        int m, n;

    public:
        void solveSudoku(vector<vector<char>>& board) {
            m = board.size();
            n = board[0].size();
            backtrack(0, 0, board);
        }

        bool backtrack(int r, int c, vector<vector<char>> &board) {
            if (r == m) {
                return true;
            }
            if (c == n) {
                return backtrack(r + 1, 0, board);
            }
            if (board[r][c] != '.') {
                return backtrack(r, c + 1, board);
            }
            for (char ch = '1'; ch <= '9'; ch++) {
                if (!is_valid(r, c, ch, board)) {
                    continue;
                }
                board[r][c] = ch;
                if (backtrack(r, c + 1, board)) {
                    return true;
                }
                board[r][c] = '.';
            }
            return false;
        }

        bool is_valid(int r, int c, char ch, vector<vector<char>> &board) {
            for (int i = 0; i < 9; i++) {
                if (board[r][i] == ch) {
                    return false;
                }
                if (board[i][c] == ch) {
                    return false;
                }
                if (board[r - r % 3 + i / 3][c - c % 3 + i % 3] == ch) {
                    return false;
                }
            }
            return true;
        }
};
