/*
 * 48. Rotate Image
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Note:
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 *
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            if (matrix.empty()) {
                return;
            }

            // transpose the matrix
            int rows = matrix.size();
            int cols = matrix[0].size();
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < i; j++) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }

            // reverse each row
            int mid = (cols + 1) / 2;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < mid; j++) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][cols - 1 - j];
                    matrix[i][cols - 1 - j] = tmp;
                }
            }
        }
};
