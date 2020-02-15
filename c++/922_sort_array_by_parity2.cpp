/*
 * 922. Sort Array By Parity II
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 *
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 *
 * You may return any answer array that satisfies this condition.
 *
 * Note:
 *
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 */

#include "header.h"

class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& A) {
            // // even index, odd index
            // int ei = 0, oi = 1;
            // vector<int> res(A.size());
            // for (int a : A) {
            //     if (a % 2) {
            //         // a is odd
            //         res[oi] = a;
            //         oi += 2;
            //     } else {
            //         // a is even
            //         res[ei] = a;
            //         ei += 2;
            //     }
            // }
            // return res;

            // In-place algorithm
            int j = 1;
            int size = A.size();
            for (int i = 0; i < size; i += 2) {
                if (A[i] % 2) {
                    while (A[j] % 2) {
                        j += 2;
                    }
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                }
            }
            return A;
        }
};
