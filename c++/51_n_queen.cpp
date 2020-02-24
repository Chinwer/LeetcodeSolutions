/*
 * 51. N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 */

#include "header.h"

class Solution {
    private:
        vector<vector<string>> res;
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            backtrack(board, 0);
            return res;
        }

        void backtrack(vector<string> &board, int row) {
            if (row == board.size()) {
                res.push_back(board);
                return;
            }

            int n = board.size();
            for (int col = 0; col < n; col++) {
                if (isvalid(board, row, col)) {
                    board[row][col] = 'Q';
                    backtrack(board, row + 1);
                    board[row][col] = '.';
                }
            }
        }

        bool isvalid(vector<string> &board, int row, int col) {
            int n = board.size();
            for (int i = 0; i < n; i++) {
                if (board[i][col] == 'Q') {
                    return false;
                }
            }

            for (int i = row - 1, j = col + 1;
                 i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }

            for (int i = row - 1, j = col - 1;
                 i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }
            return true;
        }

};
