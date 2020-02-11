/*
 * 217. Contains Duplicate
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 */

#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> dict;
            for (int num : nums) {
                if (dict.count(num)) {
                    return true;
                } else {
                    dict[num] = 0;
                }
            }
            return false;
        }
};
