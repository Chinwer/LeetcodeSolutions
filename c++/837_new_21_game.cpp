/*
 * 837. New 21 Game
 *
 *
 * Alice plays the following game, loosely based on the card game "21".
 *
 * Alice starts with 0 points, and draws numbers while she has less than
 * K points.  During each draw, she gains an integer number of points
 * randomly from the range [1, W], where W is an integer.  Each draw is
 * independent and the outcomes have equal probabilities.
 *
 * Alice stops drawing numbers when she gets K or more points.  What is
 * the probability that she has N or less points?
 *
 * Note:
 *
 * 0 <= K <= N <= 10000
 * 1 <= W <= 10000
 * Answers will be accepted as correct if they are within 10^-5 of the correct answer.
 * The judging time limit has been reduced for this question.
 */

#include "header.h"

class Solution {
    public:
        double new21Game(int N, int K, int W) {
            double sum = 0;
            vector<double> dp(K + W, 0);
            int end = min(N, K + W - 1);
            for (int i = K; i <= end; i++) {
                dp[i] = 1;
                sum += dp[i];
            }
            for (int i = K - 1; i >= 0; i--) {
                dp[i] = sum / W;
                sum += dp[i] - dp[i + W];
            }
            return dp[0];
        }
};
