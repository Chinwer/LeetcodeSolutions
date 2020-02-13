/*
 * 566. Reshape the Matrix
 * In MATLAB, there is a very useful function called 'reshape', which can
 * reshape a matrix into a new one with different size but keep its original
 * data. You're given a matrix represented by a two-dimensional array, and two
 * positive integers r and c representing the row number and column number of
 * the wanted reshaped matrix, respectively. The reshaped matrix need to be
 * filled with all the elements of the original matrix in the same
 * row-traversing order as they were. If the 'reshape' operation with given
 * parameters is possible and legal, output the new reshaped matrix; Otherwise,
 * output the original matrix.
 *
 * Note:
 * The height and width of the given matrix is in range [1, 100].
 * The given r and c are all positive.
 */

#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
            int row = nums.size();
            int col = nums[0].size();
            int size = row * col;
            if (r * c != size) {
                return nums;
            }

            vector<vector<int>> res(r, vector<int>(c));
            for (int i = 0; i < size; i++) {
                res[i / c][i % c] = nums[i / col][i % col];
            }
            return res;
        }
};
