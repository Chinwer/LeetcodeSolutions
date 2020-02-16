/*
 * 1346. Check If N and Its Double Exist
 * Given an array arr of integers, check if there exists two integers N and M
 * such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * Constraints:
 *
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 */

#include "header.h"

class Solution {
    public:
        bool checkIfExist(vector<int>& arr) {
            map<int, int> hash;
            for (int a : arr) {
                if (hash[a]) {
                    return true;
                }
                hash[2 * a]++;
                if (a % 2 == 0) {
                    hash[a / 2]++;
                }
            }
            return false;
        }
};
