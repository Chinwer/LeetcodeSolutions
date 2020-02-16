/*
 * 1275. Find Winner on a Tic Tac Toe Game
 * Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
 *
 * Here are the rules of Tic-Tac-Toe:
 *
 * Players take turns placing characters into empty squares (" ").
 * The first player A always places "X" characters, while the second player
 * B always places "O" characters. "X" and "O" characters are always placed into
 * empty squares, never on filled ones. The game ends when there are 3 of the
 * same (non-empty) character filling any row, column, or diagonal. The game
 * also ends if all squares are non-empty. No more moves can be played if the
 * game is over. Given an array moves where each element is another array of
 * size 2 corresponding to the row and column of the grid where they mark their
 * respective character in the order in which A and B play.
 *
 * Return the winner of the game if it exists (A or B), in case the game ends in
 * a draw return "Draw", if there are still movements to play return "Pending".
 *
 * You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the
 * grid is initially empty and A will play first.
 *
 * Constraints:
 *
 * 1 <= moves.length <= 9
 * moves[i].length == 2
 * 0 <= moves[i][j] <= 2
 * There are no repeated elements on moves.
 * moves follow the rules of tic tac toe.
 *
 */

#include "header.h"

class Solution {
    public:
        string tictactoe(vector<vector<int>>& moves) {
            int a = 0, b = 0;
            int win[8] = { 7, 56, 73, 84, 146, 273, 292, 448 };

            for (int i = 0; i < moves.size(); i++) {
                if (i % 2) {
                    // B places characters
                    b ^= 1 << (3 * moves[i][0] + moves[i][1]);
                } else {
                    // A places characters
                    a ^= 1 << (3 * moves[i][0] + moves[i][1]);
                }
            }
            for (int w : win) {
                if ((a & w) == w) {
                    return "A";
                }
                if ((b & w) == w) {
                    return "B";
                }
            }

            return moves.size() < 9 ? "Pending" : "Draw";
        }
};
