/*
 * 1337. The K Weakest Rows in a Matrix
 * Given a m * n matrix mat of ones (representing soldiers) and
 * zeros (representing civilians), return the indexes of the k weakest rows in
 * the matrix ordered from the weakest to the strongest.
 *
 * A row i is weaker than row j, if the number of soldiers in row i is less than
 * the number of soldiers in row j, or they have the same number of soldiers but
 * i is less than j. Soldiers are always stand in the frontier of a row, that
 * is, always ones may appear first and then zeros.
 *
 * Constraints:
 *
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 */

#include "header.h"

class Solution {
    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            int added[100] = { 0 };
            int rows = mat.size(), cols = mat[0].size();
            vector<int> res;

            for (int j = 0; j < cols; j++) {
                for (int i = 0; i < rows; i++) {
                    if (mat[i][j] == 0 && !added[i]) {
                        res.push_back(i);
                        added[i] = 1;
                        if (res.size() == k) {
                            return res;
                        }
                    }
                }
            }

            for (int i = 0; i < rows; i++) {
                if (!added[i]) {
                    res.push_back(i);
                    if (res.size() == k) {
                        return res;
                    }
                }
            }

            return res;
        }
};
