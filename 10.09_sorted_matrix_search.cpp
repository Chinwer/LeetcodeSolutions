/*
 * 10.09. Sorted Matrix Search LCCI
 *
 * Given an M x N matrix in which each row and each column is sorted inascendign order,
 * write a method to find an element.
 */

#include "header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = rows - 1, col = 0;
        while (row >= 0 && col < cols) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                col++;
            } else {
                row--;
            }
        }
        return false;
    }
};
