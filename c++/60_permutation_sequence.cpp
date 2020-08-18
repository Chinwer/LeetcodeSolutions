/*
 * 60. Permutation Sequence
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * "123", "132", "213", "231", "312", "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note:
 *   - Given n will be between 1 and 9 inclusive.
 *   - Given k will be between 1 and n! inclusive.
 */

#include "header.h"

class Solution {
    private:
        vector<int> fac;

    public:
        string getPermutation(int n, int k) {
            fac.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                fac[i] = fac[i - 1] * i;
            }

            // return solution1(n, k);
            return solution2(n, --k);
        }

        string solution2(int n, int k) {
            string res, nums;
            for (int i = 1; i <= n; i++) {
                nums += i + 48;
            }
            for (int i = n - 1; i >= 0; i--) {
                int idx = k / fac[i];
                res += nums[idx];
                nums.erase(nums.begin() + idx);
                k -= idx * fac[i];
            }
            return res;
        }

        string solution1(int n, int k) {
            string res;
            vector<bool> visited(n + 1, false);
            backtrack(n, k, res, visited);
            return res;
        }

        void backtrack(int n, int k, string &res, vector<bool> &visited) {
            int s = res.size();
            if (s == n) {
                return;
            }
            int cnt = fac[n - s - 1];
            for (int i = 1; i <= n; i++) {
                if (visited[i]) {
                    continue;
                }
                if (cnt < k) {
                    k -= cnt;
                    continue;
                }
                res += to_string(i);
                visited[i] = true;
                backtrack(n, k, res, visited);
            }
        }
};
