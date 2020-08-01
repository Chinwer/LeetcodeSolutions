/*
 * 813. Largest Sum of Averages
 *
 * We partition a row of numbers A into at most K adjacent (non-empty)
 * groups, then our score is the sum of the average of each group.
 * What is the largest score we can achieve?
 *
 * Note that our partition must use every number in A, and that scores
 * are not necessarily integers.
 *
 * Note:
 *   - 1 <= A.length <= 100.
 *   - 1 <= A[i] <= 10000.
 *   - 1 <= K <= A.length.
 *   - Answers within 10^-6 of the correct answer will be accepted as correct.
 */

#include "header.h"

class Solution {
    public:
        double largestSumOfAverages(vector<int>& A, int K) {
            // return original(A, K);
            return optimized(A, K);
        }

        double optimized(vector<int> &A, int K) {
            int n = A.size();
            // prefix sum of A
            vector<double> prefix(n + 1);
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + A[i];
            }
            vector<double> dp(n);

            // base case
            double sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                sum += A[i];
                dp[i] = sum / (n - i);
            }

            for (int k = 2; k <= K; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        double average = (prefix[j] - prefix[i]) / (j - i);
                        dp[i] = max(dp[i], dp[j] + average);
                    }
                }
            }
            return dp[0];
        }

        double original(vector<int> &A, int K) {
            int n = A.size();
            // prefix sum of A
            vector<double> prefix(n + 1);
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + A[i];
            }
            // dp[i][k] represents the largest sum of averages of
            // partitioning A[i...n - 1] (i included) into k groups
            vector<vector<double>> dp(n, vector(K + 1, 0.0));

            // base case: 1 group
            double sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                sum += A[i];
                dp[i][1] = sum / (n - i);
            }

            // state transfer equation:
            // dp[i][k] = max(dp[j][k - 1] + averages[i...j - 1]), (i < j < n), in which
            // averages[i...j] represents average of numbers A[i]...A[j] (i, j included)
            for (int k = 2; k <= K; k++) {
                for (int i = n - 1; i >= 0; i--) {
                    for (int j = i + 1; j < n; j++) {
                        // averages[i...j - 1] = (prefix[j] - prefix[i]) / (j - i)
                        double average = (prefix[j] - prefix[i]) / (j - i);
                        dp[i][k] = max(dp[i][k], dp[j][k - 1] + average);
                    }
                }
            }
            return dp[0][K];
        }
};
