/*
 * 119. Pascal's Triangle II
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle. Note that the row index starts from 0.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
             vector<int> res(1, 1);
             for (int i = 1; i <= rowIndex; i++) {
                 res.push_back(1);
                 if (i == 1) {
                     continue;
                 }
                 int tmp = (i + 1) / 2;
                 for (int j = tmp; j > 0; j--) {
                     res[j] += res[j - 1];
                 }
                 for (int j = tmp; j < i; j++) {
                     res[j] = res[i - j];
                 }
             }
             return res;
        }
};
