/*
 * 999. Available Captures for Rook
 * On an 8 x 8 chessboard, there is one white rook.  There also may be empty
 * squares, white bishops, and black pawns.  These are given as characters 'R',
 * '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and
 * lowercase characters represent black pieces.
 *
 * The rook moves as in the rules of Chess: it chooses one of four cardinal
 * directions (north, east, west, and south), then moves in that direction until it
 * chooses to stop, reaches the edge of the board, or captures an opposite colored
 * pawn by moving to the same square it occupies.  Also, rooks cannot move into the
 * same square as other friendly bishops.
 *
 * Return the number of pawns the rook can capture in one move.
 *
 * Note:
 *
 * board.length == board[i].length == 8
 * board[i][j] is either 'R', '.', 'B', or 'p'
 * There is exactly one cell with board[i][j] == 'R'
 */

#include "header.h"

class Solution {
    public:
        int numRookCaptures(vector<vector<char>>& board) {
            int rows = board.size();
            int cols = board[0].size();

            int res = 0;
            int posr, posc;
            get_pos(board, rows, cols, &posr, &posc);

            for (int i = posr - 1; i >= 0; i--) {
                if (board[i][posc] == 'B') {
                    break;
                }
                if (board[i][posc] == 'p') {
                    res++;
                    break;
                }
            }
            for (int i = posc - 1; i >= 0; i--) {
                if (board[posr][i] == 'B') {
                    break;
                }
                if (board[posr][i] == 'p') {
                    res++;
                    break;
                }
            }
            for (int i = posr + 1; i < rows; i++) {
                if (board[i][posc] == 'B') {
                    break;
                }
                if (board[i][posc] == 'p') {
                    res++;
                    break;
                }
            }
            for (int i = posc + 1; i < cols; i++) {
                if (board[posr][i] == 'B') {
                    break;
                }
                if (board[posr][i] == 'p') {
                    res++;
                    break;
                }
            }

            return res;
        }

        void get_pos(vector<vector<char>>& board, int rows, int cols, int *posr, int *posc) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j] == 'R') {
                        *posr = i;
                        *posc = j;
                        return;
                    }
                }
            }
        }
};
