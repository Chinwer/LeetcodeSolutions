/*
 * 1093. Statistics from a Large Sample
 *
 * We sampled integers between 0 and 255, and stored the results in an array count:
 * count[k] is the number of integers we sampled equal to k.
 *
 * Return the minimum, maximum, mean, median, and mode of the sample respectively,
 *  as an array of floating point numbers.  The mode is guaranteed to be unique.
 *
 * Constraints:
 *
 * count.length == 256
 * 1 <= sum(count) <= 10^9
 * The mode of the sample that count represents is unique.
 * Answers within 10^-5 of the true value will be accepted as correct.
 */

#include "header.h"

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int size = count.size(), cnt = 0;
        double sum = 0, mode = 0, max_cnt = 0;
        double min_ = INT_MAX, max_ = INT_MIN, median = 0;
        for (int i = 0; i < size; i++) {
            cnt += count[i];
            sum += i * count[i];
            if (count[i] > max_cnt) {
                mode = i;
                max_cnt = count[i];
            }
        }
        int prefix_sum = 0;
        if (cnt % 2) {
            // odd number of numbers, median: (cnt - 1) / 2
            int mid = (cnt - 1) / 2;
            for (int i = 0; i < size; i++) {
                if (prefix_sum < mid && prefix_sum + count[i] >= mid) {
                    median = i;
                }
                if (count[i]) {
                    min_ = min((int) min_, i);
                    max_ = max((int) max_, i);
                    prefix_sum += count[i];
                }
            }
        } else {
            // even number of numbers: (cnt - 1) / 2, (cnt + 1) / 2
            int mid1 = (cnt + 1) / 2, mid2 = (cnt + 3) / 2;
            for (int i = 0; i < size; i++) {
                if (prefix_sum < mid1 && prefix_sum + count[i] >= mid1) {
                    median += i;
                }
                if (prefix_sum < mid2 && prefix_sum + count[i] >= mid2) {
                    median += i;
                }
                if (count[i]) {
                    min_ = min((int) min_, i);
                    max_ = max((int) max_, i);
                    prefix_sum += count[i];
                }
            }
            median /= 2;
        }

        return vector<double>{ min_, max_, sum / cnt, median, mode };
    }
};
