/*
 * 1130. Minimum Cost Tree From Leaf Values
 *
 * Given an array arr of positive integers, consider all binary trees such that:
 *
 *   - Each node has either 0 or 2 children;
 *   - The values of arr correspond to the values of each leaf in an in-order
 *     traversal of the tree.  (Recall that a node is a leaf if and only if it
 *     has 0 children.)
 *   - The value of each non-leaf node is equal to the product of the largest
 *     leaf value in its left and right subtree respectively.
 *
 * Among all possible binary trees considered, return the smallest possible sum
 * of the values of each non-leaf node.  It is guaranteed this sum fits into a
 * 32-bit integer.
 *
 * Constraints:
 *
 *   - 2 <= arr.length <= 40
 *   - 1 <= arr[i] <= 15
 *   - It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).
 */

#include "header.h"

class Solution {
    public:
        int mctFromLeafValues(vector<int>& arr) {
            // return dynamic_programming(arr);
            return monotonic_stack(arr);
        }

        int monotonic_stack(vector<int>& arr) {
            int res = 0;
            stack<int> s;
            s.push(INT_MAX);

            for (int a : arr) {
                while (s.top() <= a) {
                    int t = s.top();
                    s.pop();
                    res += t * min(s.top(), a);
                }
                s.push(a);
            }
            while (s.size() > 2) {
                int t = s.top();
                s.pop();
                res += t * s.top();
            }

            return res;
        }

        int dynamic_programming(vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector(n, 0));
            vector<vector<int>> max_(n, vector(n, 0));

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int max_val = arr[i];
                    for (int k = i + 1; k <= j; k++) {
                        max_val = max(max_val, arr[k]);
                    }
                    max_[i][j] = max_val;
                }
            }
            for (int i = 0; i < n - 1; i++) {
                dp[i][i + 1] = arr[i] * arr[i + 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 2; j < n; j++) {
                    int min_ = INT_MAX;
                    for (int k = i; k < j; k++) {
                        min_ = min(
                            min_,
                            dp[i][k] + dp[k + 1][j] + max_[i][k] * max_[k + 1][j]
                        );
                        dp[i][j] = min_;
                    }
                }
            }
            return dp[0][n - 1];
        }
};
