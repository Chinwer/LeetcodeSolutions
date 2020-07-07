/*
 * 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Given an array of integers arr and two integers k and threshold.
 * Return the number of sub-arrays of size k and average greater than or equal to threshold.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^4
 * 1 <= k <= arr.length
 * 0 <= threshold <= 10^4
 */


#include "header.h"

using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            /* brute force (TIME LIMIT EXCEEDED) */
            // int res = 0;
            // // iteration times
            // int iter_times = arr.size() - k;
            // for (int i = 0; i < iter_times; i++) {
            //     int sum = 0;
            //     for (int j = 0; j < k; j++) {
            //         sum += arr[i + j];
            //     }
            //     if (sum / k >= threshold) {
            //         res++;
            //     }
            // }
            // return res;


            // optimization 1
            int res = 0, sum = 0;
            int iter_times = arr.size() - k + 1;

            for (int i = 0; i < k; i++) {
                sum += arr[i];
            }
            if (sum / k >= threshold) {
                res++;
            }
            for (int i = 1; i < iter_times; i++) {
                sum -= arr[i - 1];
                sum += arr[i + k - 1];
                if (sum / k >= threshold) {
                    res++;
                }
            }
            return res;
        }
};
