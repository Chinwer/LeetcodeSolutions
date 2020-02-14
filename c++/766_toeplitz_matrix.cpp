/*
 * 766. Toeplitz Matrix
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same element. Now given an M x N matrix, return True if and only if the
 * matrix is Toeplitz.
 *
 * Note:
 * matrix will be a 2D array of integers.
 * matrix will have a number of rows and columns in range [1, 20].
 * matrix[i][j] will be integers in range [0, 99].
 *
 * Follow up:
 *
 * What if the matrix is stored on disk, and the memory is limited such that you
 * can only load at most one row of the matrix into the memory at once?
 *
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 */

#include "header.h"

class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            // int rows = matrix.size();
            // int cols = matrix[0].size();
            // if (rows == 1 || cols == 1) {
            //     return true;
            // }

            // int start;
            // for (start = rows - 2; start >= 0; start--) {
            //     int r = start;
            //     int c = 0;
            //     while (++r < rows && ++c < cols) {
            //         if (matrix[r][c] != matrix[r - 1][c - 1]) {
            //             return false;
            //         }
            //     }
            // }

            // for (start = 1; start < cols; start++) {
            //     int r = 0;
            //     int c = start;
            //     while (++r < rows && ++c < cols) {
            //         if (matrix[r][c] != matrix[r - 1][c - 1]) {
            //             return false;
            //         }
            //     }
            // }

            // return true;

            int rows = matrix.size();
            int cols = matrix[0].size();
            if (rows < 2 || cols < 2) {
                return true;
            }

            for (int r = 1; r < rows; r++) {
                for (int c = 1; c < cols; c++) {
                    if (matrix[r][c] != matrix[r - 1][c - 1]) {
                        return false;
                    }
                }
            }
            return true;
        }
};
