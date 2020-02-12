/*
 * 414. Third Maximum Number
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 */

#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            // int first, second, third;
            // first = second = third = INT64_MIN;
            // for (int num : nums) {
            //     if (num > first) {
            //         third = second;
            //         second = first;
            //         first = num;
            //     } else if (num > second && num != first) {
            //         third = second;
            //         second = num;
            //     } else if (num > third && num != second && num != first) {
            //         third = num;
            //     }
            // }
            // return third == INT64_MIN ? first : third;

            set<int> s(nums.begin(), nums.end());
            auto i = s.end();
            i--;
            if (s.size() > 2) {
                i--;
                i--;
            }
            return *i;
        }
};
