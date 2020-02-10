/*
 * 989. Add to Array-Form of Integer
 * For a non-negative integer X, the array-form of X is an array of its digits
 * in left to right order.  For example, if X = 1231, then the array form
 * is [1,2,3,1]. Given the array-form A of a non-negative integer X, return the
 * array-form of the integer X+K.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> addToArrayForm(vector<int>& A, int K) {
            vector<int> res;
            int aux = K;
            for (int i = A.size() - 1; i >= 0; i--) {
                res.push_back((A[i] + aux) % 10);
                aux /= 10;
            }
            while (aux != 0) {
                res.push_back(aux % 10);
                aux /= 10;
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
