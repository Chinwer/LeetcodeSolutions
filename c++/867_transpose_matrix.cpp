/*
 * 867. Transpose Matrix
 * Given a matrix A, return the transpose of A.
 *
 * The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 *
 * Note:
 *
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            int rows = A.size();
            int cols = A[0].size();
            vector<vector<int>> res(cols, vector<int>(rows));
            for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    res[i][j] = A[j][i];
                }
            }

            return res;
        }
};
