/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in-place.
 *
 * Follow up:
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            /* O(m + n) space complexity */
            // if (matrix.empty()) {
            //     return;
            // }

            // int rows_num = matrix.size();
            // int cols_num = matrix[0].size();
            // vector<int> rows(rows_num, 0);
            // vector<int> cols(cols_num, 0);

            // for (int i = 0; i < rows_num; i++) {
            //     for (int j = 0; j < cols_num; j++) {
            //         if (!matrix[i][j]) {
            //             rows[i] = 1;
            //             cols[j] = 1;
            //         }
            //     }
            // }
            // for (int i = 0; i < rows_num; i++) {
            //     if (rows[i]) {
            //         matrix[i] = vector<int>(cols_num, 0);
            //     }
            // }
            // for (int i = 0; i < cols_num; i++) {
            //     if (cols[i]) {
            //         for (int j = 0; j < rows_num; j++) {
            //             matrix[j][i] = 0;
            //         }
            //     }
            // }

            /* O(1) space complexity */
            if (matrix.empty()) {
                return;
            }

            int m = matrix.size();
            int n = matrix[0].size();
            bool flag = false;

            for (int i = 0; i < m; i++) {
                if (!flag && !matrix[i][0]) {
                    flag = true;
                }
                for (int j = 1; j < n; j++) {
                    if (!matrix[i][j]) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // traverse the whole matrix starting from row 1 and column 1
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (!matrix[i][0] || !matrix[0][j]) {
                        matrix[i][j] = 0;
                    }
                }
            }

            // traverse the first row
            if (!matrix[0][0]) {
                matrix[0] = vector<int>(n, 0);
            }
            // traverse the first column
            if (flag) {
                for (int i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
};
