/*
 * 661. Image Smoother
 * Given a 2D integer matrix M representing the gray scale of an image, you need
 * to design a smoother to make the gray scale of each cell becomes the average
 * gray scale (rounding down) of all the 8 surrounding cells and itself. If a
 * cell has less than 8 surrounding cells, then use as many as you can.
 *
 * Note:
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            // Method 1
            // int row = M.size();
            // int col = M[0].size();
            // vector<vector<int>> res(row, vector<int>(col));
            // for (int r = 0; r < row; r++) {
            //     for (int c = 0; c < col; c++) {
            //         int sum = M[r][c];
            //         int cnt = 1;
            //         if (c - 1 >= 0) {
            //             cnt++;
            //             sum += M[r][c - 1];
            //             if (r - 1 >= 0) {
            //                 cnt++;
            //                 sum += M[r - 1][c - 1];
            //             }
            //             if (r + 1 < row) {
            //                 cnt++;
            //                 sum += M[r + 1][c - 1];
            //             }
            //         }
            //         if (c + 1 < col) {
            //             cnt++;
            //             sum += M[r][c + 1];
            //             if (r - 1 >= 0) {
            //                 cnt++;
            //                 sum += M[r - 1][c + 1];
            //             }
            //             if (r + 1 < row) {
            //                 cnt++;
            //                 sum += M[r + 1][c + 1];
            //             }
            //         }
            //         if (r - 1 >= 0) {
            //             cnt++;
            //             sum += M[r - 1][c];
            //         }
            //         if (r + 1 < row) {
            //             cnt++;
            //             sum += M[r + 1][c];
            //         }
            //         M[r][c] = (sum / cnt);
            //     }
            // }
            // return res;

            // Method 2
            // int rows = M.size();
            // int cols = M[0].size();
            // vector<vector<int>> res(rows, vector<int>(cols));

            // for (int r = 0; r < rows; r++) {
            //     M[r].insert(M[r].begin(), -1);
            //     M[r].push_back(-1);
            // }
            // M.insert(M.begin(), vector<int>(cols + 2, -1));
            // M.push_back(vector<int>(cols + 2, -1));

            // for (int r = 0; r < rows; r++) {
            //     for (int c = 0; c < cols; c++) {
            //         int sum = 0;
            //         int cnt = 0;
            //         for (int i = -1; i <= 1; i++) {
            //             for (int j = -1; j <= 1; j++) {
            //                 int val = M[r + 1 + i][c + 1 + j];
            //                 if (val != -1) {
            //                     cnt++;
            //                     sum += val;
            //                 }
            //             }
            //         }
            //         res[r][c] = (sum / cnt);
            //     }
            // }
            // return res;


            // Method 3(Simplified method 1)
            int rows = M.size();
            int cols = M[0].size();
            vector<vector<int>> res(rows, vector<int>(cols));
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    int cnt = 0, sum = 0;
                    for (int i = r - 1; i <= r + 1; i++) {
                        for (int j = c - 1; j <= c + 1; j++) {
                            if (0 <= i && i < rows && 0 <= j && j < cols) {
                                cnt++;
                                sum += M[i][j];
                            }
                        }
                    }
                    res[r][c] = sum / cnt;
                }
            }
            return res;
        }
};
