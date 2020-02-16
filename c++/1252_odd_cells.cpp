/*
 * 1252. Cells with Odd Values in a Matrix
 * Given n and m which are the dimensions of a matrix initialized by zeros and
 * given an array indices where indices[i] = [ri, ci]. For each pair of [ri,
 * ci] you have to increment all cells in row ri and column ci by 1.
 *
 * Return the number of cells with odd values in the matrix after applying the
 * increment to all indices.
 *
 * Constraints:
 *
 * 1 <= n <= 50
 * 1 <= m <= 50
 * 1 <= indices.length <= 100
 * 0 <= indices[i][0] < n
 * 0 <= indices[i][1] < m
 */

#include "header.h"

class Solution {
    public:
        int oddCells(int n, int m, vector<vector<int>>& indices) {
            /* Method 1, mock */
            // vector<vector<int>> matrix(n, vector<int>(m, 0));

            // for (vector<int> index : indices) {
            //     for (int &num : matrix[index[0]]) {
            //         num++;
            //     }
            //     for (vector<int> &row : matrix) {
            //         row[index[1]]++;
            //     }
            // }

            // int res = 0;
            // for (auto r : matrix) {
            //     for (auto n : r) {
            //         res += n % 2;
            //     }
            // }
            // return res;

            /* Method 2 count */
            int r = 0, c = 0;
            vector<int> rows(n, 0);
            vector<int> cols(m, 0);

            for (auto idx : indices) {
                rows[idx[0]]++;
                cols[idx[1]]++;
            }
            for (int row : rows) {
                if (row % 2) {
                    r++;
                }
            }
            for (int col : cols) {
                if (col % 2) {
                    c++;
                }
            }

            return m * r + n * c - 2 * r * c;
        }
};
