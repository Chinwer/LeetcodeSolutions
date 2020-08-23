/*
 * 1467. Probability of a Two Boxes Having The Same Number of Distinct Balls
 *
 * Given 2n balls of k distince colors. You will be given an integer array
 * balls of size k where balls[i] is the number of balls of color i.
 *
 * All the balls will be shuffled uniformly at random, then we will distribute
 * the first n balls to the first box and the remaining n balls to the other box
 * (Please read the explanation of the second example carefully).
 *
 * Please note that the two boxes are considered different. For example, if we
 * have two balls of colors a and b, and two boxes [] and (), then the
 * distribution [a](b) is considered different than the distribution [b](a)
 * (Please read the explanation of the first example carefully).
 *
 * We want to calculate the probability that the two boxes have the same
 * number of distinct balls.
 *
 * Constraints:
 *   - 1 <= balls.length <= 8
 *   - 1 <= balls[i] <= 6
 *   - sum(balls) is even.
 *   - Answers within 10^-5 of the actual value will be accepted as correct.
 */

#include "header.h"

class Solution {
    private:
        int n;
        int left[10] = { 0 };
        long long fac[11] = { 0 };
        double power2[11] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

    public:
        double getProbability(vector<int>& balls) {
            n = balls.size();
            int sum = accumulate(balls.begin(), balls.end(), 0);

            // calculate fac
            fac[0] = 1;
            for (int i = 1; i <= 10; i++) {
                fac[i] = fac[i - 1] * i;
            }
            // calculate left
            left[n - 1] = balls[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                left[i] = left[i + 1] + balls[i];
            }
            // q = C(2n, n) / 2^(2n)
            double q = 1;
            for (int i = 1; i <= sum / 2; i++) {
                q *= (i + sum / 2) * 1.0 / i / 4;
            }
            return dfs(0, 0, 0, balls) / q;
        }

        // C(a, b) = a! / (b! * (a - b)!)
        int C(int a, int b) {
            return fac[a] / (fac[b] * fac[a - b]);
        }

        double dfs(int m, int gsum, int gcolor, vector<int> &balls) {
            if (m == n) {
                return !gsum && !gcolor;
            }
            if (abs(gsum) > left[m]) {
                return 0;
            }
            double ret = 0;
            for (int i = 0; i <= balls[m]; i++) {
                int delta = i == 0 ? -1 : (i == balls[m] ? 1 : 0);
                ret += C(balls[m], i) / power2[balls[m]] *
                    dfs(m + 1, gsum + i - (balls[m] - i), gcolor + delta, balls);
            }
            return ret;
        }
};
