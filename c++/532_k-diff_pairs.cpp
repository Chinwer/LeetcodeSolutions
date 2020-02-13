/*
 * 532. K-diff Pairs in an Array
 * Given an array of integers and an integer k, you need to find the number of
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an integer
 * pair (i, j), where i and j are both numbers in the array and their absolute
 * difference is k.
 */

#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            // int res = 0;
            // map<int, vector<bool>> dict;
            // for (int num : nums) {
            //     bool flag0 = false;
            //     bool flag1 = false;
            //     if (dict.count(num - k) && !dict[num - k][1]) {
            //         res++;
            //         dict[num - k][1] = true;
            //         flag0 = true;
            //         if (dict.count(num)) {
            //             dict[num][0] = true;
            //         }
            //     }
            //     if (dict.count(num + k) && !dict[num + k][0]) {
            //         res++;
            //         dict[num + k][0] = true;
            //         flag1 = true;
            //         if (dict.count(num)) {
            //             dict[num][1] = true;
            //         }
            //     }
            //     if (!dict.count(num)) {
            //         dict[num].push_back(flag0);
            //         dict[num].push_back(flag1);
            //     }
            // }
            // return res;

            if (k < 0) {
                return 0;
            }

            int res = 0;
            map<int, int> dict;
            for (int num : nums) {
                dict[num]++;
            }
            if (k == 0) {
                for (auto it : dict) {
                    if (it.second > 1) {
                        res++;
                    }
                }
                return res;
            } else {
                for (auto it : dict) {
                    if (dict.count(it.first + k)) {
                        res++;
                    }
                }
                return res;
            }
        }
};
