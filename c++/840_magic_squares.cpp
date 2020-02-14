/*
 * 840. Magic Squares In Grid
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
 * such that each row, column, and both diagonals all have the same sum.

 * Given an grid of integers, how many 3 x 3 "magic square" subgrids are there? 
 * (Each subgrid is contiguous).
 *
 * Note:

 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * 0 <= grid[i][j] <= 15
 */

#include "header.h"

class Solution {
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int res = 0;
            int rows = grid.size();
            int cols = grid[0].size();
            if (rows < 3 || cols < 3) {
                return 0;
            }

            for (int i = 1; i < rows - 1; i++) {
                for (int j = 1; j < cols - 1; j++) {
                    int top1 = grid[i - 1][j - 1];
                    int top2 = grid[i - 1][j];
                    int top3 = grid[i - 1][j + 1];
                    int mid1 = grid[i][j - 1];
                    int mid2 = grid[i][j];
                    int mid3 = grid[i][j + 1];
                    int dow1 = grid[i + 1][j - 1];
                    int dow2 = grid[i + 1][j];
                    int dow3 = grid[i + 1][j + 1];

                    int mul = 1;
                    bool flag = false;
                    for (int r = i - 1; r <= i + 1; r++) {
                        for (int c = j - 1; c <= j + 1; c++) {
                            if (grid[r][c] > 9) {
                                flag = true;
                                break;
                            }
                            mul *= grid[r][c];
                        }
                    }
                    if (flag || mul != 362880) {
                        continue;
                    }

                    int sum = top1 + top2 + top3;
                    if (mid1 + mid2 + mid3 == sum &&
                        dow1 + dow2 + dow3 == sum &&
                        top1 + mid1 + dow1 == sum &&
                        top2 + mid2 + dow2 == sum &&
                        top3 + mid3 + dow3 == sum &&
                        top1 + mid2 + dow3 == sum &&
                        top3 + mid2 + dow1 == sum) {
                        res++;
                    }
                }
            }
            return res;
        }
};
