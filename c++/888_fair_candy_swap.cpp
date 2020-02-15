/*
 * 888. Fair Candy Swap
 * Alice and Bob have candy bars of different sizes: A[i] is the size of the
 * i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of
 * candy that Bob has.
 *
 * Since they are friends, they would like to exchange one candy bar each so
 * that after the exchange, they both have the same total amount of candy.  (The
 * total amount of candy a person has is the sum of the sizes of candy bars they
 * have.)
 *
 * Return an integer array ans where ans[0] is the size of the candy bar that
 * Alice must exchange, and ans[1] is the size of the candy bar that Bob must
 * exchange.
 *
 * If there are multiple answers, you may return any one of them.  It is
 * guaranteed an answer exists.
 *
 * Note:
 *
 * 1 <= A.length <= 10000
 * 1 <= B.length <= 10000
 * 1 <= A[i] <= 100000
 * 1 <= B[i] <= 100000
 * It is guaranteed that Alice and Bob have different total amounts of candy.
 * It is guaranteed there exists an answer.
 */

#include "header.h"

class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
            int suma = 0;
            int sumb = 0;
            for (int a : A) {
                suma += a;
            }
            for (int b : B) {
                sumb += b;
            }

            map<int, int> dict;
            int delta = (suma - sumb) / 2;
            for (int a : A) {
                dict[a]++;
            }
            for (int b : B) {
                if (dict[b + delta]) {
                    return vector<int>{ b + delta, b };
                }
            }
            return { 0, 0 };
        }
};
