/*
 * 923. 3Sum With Multiplicity
 *
 *
 * Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
 * As the answer can be very large, return it modulo 10^9 + 7.
 *
 * Note:

 * 3 <= A.length <= 3000
 * 0 <= A[i] <= 100
 * 0 <= target <= 300
 */

#include "header.h"

class Solution {
    public:
        int threeSumMulti(vector<int>& A, int target) {
            sort(A.begin(), A.end());
            long mod = pow(10, 9) + 7;
            int res = 0, size = A.size();
            for (int i = 0; i < size - 2; i++) {
                int left = i + 1, right = size - 1;;
                while (left < right) {
                    int sum = A[i] + A[left] + A[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        int l = left, r = right;
                        int left_cnt = 1, right_cnt = 1;
                        while (left < right && A[left] == A[left + 1]) {
                            left++;
                            left_cnt++;
                        }
                        while (left < right && A[right] == A[right - 1]) {
                            right--;
                            right_cnt++;
                        }
                        if (left == right) {
                            int nums = r - l + 1;
                            res += nums * (nums - 1) / 2;
                        } else {
                            res += left_cnt * right_cnt;
                        }
                        left++;
                        right--;
                        res %= mod;
                    }
                }
            }
            return res;
        }
};
