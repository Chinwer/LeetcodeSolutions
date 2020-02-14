/*
 * 832. Flipping an Image
 * Given a binary matrix A, we want to flip the image horizontally, then invert
 * it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed. 
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced
 * by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 *
 * Notes:
 *     * 1 <= A.length = A[0].length <= 20
 *     * 0 <= A[i][j] <= 1
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            int rows = A.size();
            int cols = A[0].size();
            int half = (cols - 1) / 2;
            vector<vector<int>> res(A);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j <= half; j++) {
                    int s = cols - 1 - j;
                    if (!A[i][j] && !A[i][s]) {
                        res[i][j] = 1;
                        res[i][s] = 1;
                    } else if (A[i][j] && A[i][s]) {
                        res[i][j] = 0;
                        res[i][s] = 0;
                    }
                }
            }
            return res;
        }
};
