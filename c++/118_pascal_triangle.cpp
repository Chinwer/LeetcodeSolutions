/*
 * 118. Pascal's Triangle
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res(numRows);
            for (int i = 0; i < numRows; i++) {
                res[i] = vector<int>(i + 1, 1);
                for (int j = 1; j < i; j++) {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
            return res;
        }
};
