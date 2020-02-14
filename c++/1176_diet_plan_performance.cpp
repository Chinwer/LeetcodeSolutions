/*
 * 1176. Diet Plan Performance
 * A dieter consumes calories[i] calories on the i-th day. 
 *
 * Given an integer k, for every consecutive sequence of k days (calories[i], calories[i+1], ..., calories[i+k-1] for all 0 <= i <= n-k), they look at T, the total calories consumed during that sequence of k days (calories[i] + calories[i+1] + ... + calories[i+k-1]):
 *
 * If T < lower, they performed poorly on their diet and lose 1 point; 
 * If T > upper, they performed well on their diet and gain 1 point;
 * Otherwise, they performed normally and there is no change in points.
 * Initially, the dieter has zero points. Return the total number of points the dieter has after dieting for calories.length days.
 *
 * Note that the total points can be negative.
 *
 * Constraints:
 *
 * 1 <= k <= calories.length <= 10^5
 * 0 <= calories[i] <= 20000
 * 0 <= lower <= upper
 */

#include "header.h"

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0;
        int res = 0;
        int size = calories.size();

        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        if (sum < lower) {
            res--;
        } else if (sum > upper) {
            res++;
        }

        for (int i = 1; i <= size - k; i++) {
            sum += (calories[i + k - 1] - calories[i - 1]);
            if (sum < lower) {
                res--;
            } else if (sum > upper) {
                res++;
            }
        }

        return res;
    }
};
