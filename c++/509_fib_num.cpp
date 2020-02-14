/*
 * 509. Fibonacci Number
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called
 * the Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 *
 * Given N, calculate F(N).
 *
 * Note:
 * 0 ≤ N ≤ 30.
 */

class Solution {
    public:
        int fib(int N) {
            // if (N < 2) {
            //     return N;
            // }

            // int res = 0;
            // int prev = 1, pprev = 0;
            // for (int i = 1; i < N; i++) {
            //     res = prev + pprev;
            //     pprev = prev;
            //     prev = res;
            // }
            // return res;

            int res[31] = {0,     1,     1,      2,      3,      5,      8,     13,
                           21,    34,    55,     89,     144,    233,    377,   610,
                           987,   1597,  2584,   4181,   6765,   10946,  17711, 28657,
                           46368, 75025, 121393, 196418, 317811, 514229, 832040};
            return res[N];
        }
};
