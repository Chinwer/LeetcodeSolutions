/*
 * Given a matrix of M x N elements (M rows, N columns),
 * return all elements of the matrix in diagonal order as shown in the below image.
 *
 * Note:
 * The total number of elements of the given matrix will not exceed 10,000.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
            if (matrix.empty()) {
                return vector<int>();
            }

            int direction = 1;
            int cur_row = 0, cur_col = 0;
            int row_num = matrix.size(), col_num = matrix[0].size();

            vector<int> res;
            while (cur_row < row_num && cur_col < col_num) {
                res.push_back(matrix[cur_row][cur_col]);
                int new_row = cur_row - direction;
                int new_col = cur_col + direction;
                if (new_row < 0 || new_row == row_num ||
                    new_col < 0 || new_col == col_num) {
                    // the next cell is out of bounds
                    if (direction == 1) {
                        // is going up-right now
                        cur_row += (cur_col + 1 == col_num) ? 1 : 0;
                        cur_col += (cur_col + 1 < col_num) ? 1 : 0;
                    } else {
                        // is going down-left now
                        cur_col += (cur_row + 1 == row_num) ? 1 : 0;
                        cur_row += (cur_row + 1 < row_num) ? 1 : 0;
                    }
                    direction *= -1;
                } else {
                    cur_row = new_row;
                    cur_col = new_col;
                }
            }
            return res;
        }
};
