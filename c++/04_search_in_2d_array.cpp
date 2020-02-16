#include "header.h"

class Solution {
    public:
        bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
            // int rows = matrix.size();
            // if (!rows) {
            //     return false;
            // }
            // int cols = matrix[0].size();
            // if (!cols) {
            //     return false;
            // }

            // for (int i = 0; i < rows; i++) {
            //     if (matrix[i][0] > target) {
            //         return false;
            //     }
            //     if (matrix[i][cols - 1] < target) {
            //         continue;
            //     }

            //     int pos = bin_search(matrix[i], target);
            //     if (pos != -1) {
            //         return true;
            //     }
            // }

            // return false;

            int c = 0, r = matrix.size() - 1;
            while (r >= 0 && c < matrix[0].size()) {
                if (matrix[r][c] > target) {
                    r--;
                } else if (matrix[r][c] < target) {
                    c++;
                } else {
                    return true;
                }
            }
            return false;
        }

        int bin_search(vector<int> row, int target) {
            int len = row.size();
            int low = 0, high = len;

            while (low < high) {
                int mid = low + (high - low) / 2;
                if (row[mid] == target) {
                    return mid;
                } else if (row[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            return -1;
        }
};
